/*
 * QPU 4x4 매트릭스 곱셈 예제 (Float)
 *
 * 이 예제는 V3D QPU를 직접 사용하여 두 4x4 행렬을 곱하는 프로그램입니다.
 * C[i][j] = Sum(A[i][k] * B[k][j])
 *
 * V3D 16-way SIMD를 사용하여 16개의 쓰레드가 각각 결과 행렬 C의 하나의 요소를 계산합니다.
 * Thread ID (0~15)가 C의 index (row*4 + col)에 대응됩니다.
 */

#include "broadcom/common/v3d_device_info.h"
#include "broadcom/qpu/qpu_disasm.h"
#include "broadcom/qpu/qpu_instr.h"
#include <drm-uapi/v3d_drm.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <unistd.h>
#include <xf86drm.h>

/*
 * 계산할 데이터 (4x4 Matrix):
 */

#define MATRIX_DIM 4
#define MATRIX_SIZE (MATRIX_DIM * MATRIX_DIM)

int render_fd;

/* QPU 프로그램을 저장할 버퍼 */
static uint64_t qpu_code[1024];
static int qpu_code_size = 0;

/* QPU 명령어를 버퍼에 추가하는 헬퍼 함수 */
static void emit_qpu_instr(const struct v3d_device_info* devinfo,
                           struct v3d_qpu_instr* instr)
{
    if (qpu_code_size >= 1024)
    {
        fprintf(stderr, "QPU code buffer overflow\n");
        exit(1);
    }

    uint64_t packed;
    bool ok = v3d_qpu_instr_pack(devinfo, instr, &packed);

    if (!ok)
    {
        fprintf(stderr, "Failed to pack QPU instruction at index %d\n", qpu_code_size);
        return;
    }

    qpu_code[qpu_code_size++] = packed;
}

static void set_small_imm(const struct v3d_device_info* devinfo, struct v3d_qpu_instr* instr, int mux_slot, uint32_t val)
{
    uint32_t packed;
    if (!v3d_qpu_small_imm_pack(devinfo, val, &packed))
    {
        fprintf(stderr, "Failed to pack small immediate %u\n", val);
        exit(1);
    }
    instr->raddr_b = (uint8_t)packed;

    // mux_slot: 0=add.a, 1=add.b, 2=mul.a, 3=mul.b
    switch (mux_slot)
    {
    case 0:
        instr->sig.small_imm_a = true;
        instr->alu.add.a.raddr = packed;
        break;
    case 1:
        instr->sig.small_imm_b = true;
        instr->alu.add.b.raddr = packed;
        break;
    case 2:
        instr->sig.small_imm_c = true;
        instr->alu.mul.a.raddr = packed;
        break;
    case 3:
        instr->sig.small_imm_d = true;
        instr->alu.mul.b.raddr = packed;
        break;
    }
}

static void init_alu_instr(struct v3d_qpu_instr* instr)
{
    memset(instr, 0, sizeof(*instr));
    instr->type = V3D_QPU_INSTR_TYPE_ALU;
    instr->alu.add.op = V3D_QPU_A_NOP;
    instr->alu.mul.op = V3D_QPU_M_NOP;
}

/*
 * QPU 매트릭스 곱셈 프로그램 생성
 */
void generate_qpu_matrix_mul(const struct v3d_device_info* devinfo)
{
    struct v3d_qpu_instr instr;

    printf("QPU 매트릭스 곱셈 프로그램 생성 중...\n");
    printf("V3D 버전: %d.%d\n", devinfo->ver / 10, devinfo->ver % 10);

    /*
     * 1. Uniform 로드
     * Uniform 스트림에서 3개의 32비트 값(주소)을 레지스터 파일(rf)로 로드합니다.
     * V3D QPU는 Uniform FIFO에서 데이터를 읽어와서 지정된 레지스터에 저장합니다.
     */

    // rf0 = Matrix A 주소 로드
    // ldunifrf: Uniform을 읽어서 Register File에 저장하는 시그널
    // sig_addr: 저장할 레지스터 주소 (여기서는 rf0)
    init_alu_instr(&instr);
    instr.sig.ldunifrf = true;
    instr.sig_addr = 0;
    emit_qpu_instr(devinfo, &instr);

    // rf1 = Matrix B 주소 로드
    // rf1에 두 번째 Uniform 값(B 주소) 저장
    init_alu_instr(&instr);
    instr.sig.ldunifrf = true;
    instr.sig_addr = 1;
    emit_qpu_instr(devinfo, &instr);

    // rf2 = Matrix C (Output) 주소 로드
    // rf2에 세 번째 Uniform 값(C 주소) 저장
    init_alu_instr(&instr);
    instr.sig.ldunifrf = true;
    instr.sig_addr = 2;
    emit_qpu_instr(devinfo, &instr);

    /*
     * 2. Thread ID 및 Row/Col 계산
     * QPU는 SIMD 프로세서로, 16개의 쓰레드(Lane)가 동시에 실행됩니다.
     * 각 쓰레드는 고유의 Element ID (EIDX)를 가집니다. (0 ~ 15)
     * 이를 이용하여 자신이 처리할 Matrix C의 Row와 Column을 계산합니다.
     * Matrix Index = Row * 4 + Col = EIDX
     */

    // rf3 = EIDX (Thread ID 0~15) 획득
    // V3D_QPU_A_EIDX: 현재 쓰레드의 ID를 반환하는 ALU 연산
    init_alu_instr(&instr);
    instr.alu.add.op = V3D_QPU_A_EIDX;
    instr.alu.add.waddr = 3;
    emit_qpu_instr(devinfo, &instr);

    // rf4 = Row Index 계산
    // Row = EIDX / 4 = EIDX >> 2
    // V3D_QPU_A_SHR: Shift Right 연산
    init_alu_instr(&instr);
    instr.alu.add.op = V3D_QPU_A_SHR;
    instr.alu.add.a.raddr = 3;            // rf3 (EIDX)
    set_small_imm(devinfo, &instr, 1, 2); // small immediate 2 (Shift Amount)
    instr.alu.add.waddr = 4;              // rf4에 Row 저장
    emit_qpu_instr(devinfo, &instr);

    // rf5 = Col Index 계산
    // Col = EIDX % 4 = EIDX & 3
    // V3D_QPU_A_AND: Bitwise AND 연산
    init_alu_instr(&instr);
    instr.alu.add.op = V3D_QPU_A_AND;
    instr.alu.add.a.raddr = 3;            // rf3 (EIDX)
    set_small_imm(devinfo, &instr, 1, 3); // small immediate 3 (Mask)
    instr.alu.add.waddr = 5;              // rf5에 Col 저장
    emit_qpu_instr(devinfo, &instr);

    /*
     * 3. Accumulator 초기화
     * 결과 값을 누적할 레지스터(rf6)를 0으로 초기화합니다.
     * Float 0.0은 비트 표현으로 0x00000000 이므로, XOR로 0을 만들면 됩니다.
     */

    // rf6 = 0.0
    // XOR rf6, rf6, rf6 -> rf6 = 0
    init_alu_instr(&instr);
    instr.alu.add.op = V3D_QPU_A_XOR;
    instr.alu.add.a.raddr = 6;
    instr.alu.add.b.raddr = 6;
    instr.alu.add.waddr = 6;
    emit_qpu_instr(devinfo, &instr);

    /*
     * 4. 행렬 곱셈 루프 (Loop Unrolling)
     * C[row][col] = Sum(A[row][k] * B[k][col]) for k=0..3
     * 효율성을 위해 루프를 풀어서(unrolled) 4번 반복합니다.
     */

    for (int k = 0; k < MATRIX_DIM; k++)
    {
        // === [Step 4-1] A[row][k]의 메모리 주소 계산 ===
        // Address A = BaseA + (IndexA * 4 bytes)
        // IndexA = (Row * 4) + k

        // rf9 = Row * 4 = rf4 << 2
        init_alu_instr(&instr);
        instr.alu.add.op = V3D_QPU_A_SHL;
        instr.alu.add.a.raddr = 4;            // Row (rf4)
        set_small_imm(devinfo, &instr, 1, 2); // Shift 2
        instr.alu.add.waddr = 9;              // Temp (rf9)
        emit_qpu_instr(devinfo, &instr);

        // rf9 = rf9 + k (k가 0이 아닐 경우)
        if (k > 0)
        {
            init_alu_instr(&instr);
            instr.alu.add.op = V3D_QPU_A_ADD;
            instr.alu.add.a.raddr = 9;
            set_small_imm(devinfo, &instr, 1, k); // k
            instr.alu.add.waddr = 9;
            emit_qpu_instr(devinfo, &instr);
        }

        // Offset in bytes = IndexA * 4 = rf9 << 2
        // 실제 바이트 단위 오프셋으로 변환 (float는 4바이트)
        init_alu_instr(&instr);
        instr.alu.add.op = V3D_QPU_A_SHL;
        instr.alu.add.a.raddr = 9;
        set_small_imm(devinfo, &instr, 1, 2);
        instr.alu.add.waddr = 9; // rf9 = Byte Offset for A
        emit_qpu_instr(devinfo, &instr);

        // rf7 = BaseA(rf0) + Offset(rf9)
        // 최종 A 요소의 메모리 주소 계산
        init_alu_instr(&instr);
        instr.alu.add.op = V3D_QPU_A_ADD;
        instr.alu.add.a.raddr = 0; // BaseA
        instr.alu.add.b.raddr = 9; // OffsetA
        instr.alu.add.waddr = 7;   // rf7 = Addr A
        emit_qpu_instr(devinfo, &instr);

        // === [Step 4-2] B[k][col]의 메모리 주소 계산 ===
        // Address B = BaseB + (IndexB * 4 bytes)
        // IndexB = (k * 4) + Col

        // rf10 = (k * 4) + Col(rf5)
        // k*4는 상수이므로 바로 더합니다.
        int k_offset = k * 4;
        init_alu_instr(&instr);
        instr.alu.add.op = V3D_QPU_A_ADD;
        instr.alu.add.a.raddr = 5;                   // Col (rf5)
        set_small_imm(devinfo, &instr, 1, k_offset); // k*4
        instr.alu.add.waddr = 10;                    // Temp (rf10)
        emit_qpu_instr(devinfo, &instr);

        // Offset in bytes = IndexB * 4 = rf10 << 2
        init_alu_instr(&instr);
        instr.alu.add.op = V3D_QPU_A_SHL;
        instr.alu.add.a.raddr = 10;
        set_small_imm(devinfo, &instr, 1, 2);
        instr.alu.add.waddr = 10;
        emit_qpu_instr(devinfo, &instr);

        // rf8 = BaseB(rf1) + Offset(rf10)
        // 최종 B 요소의 메모리 주소 계산
        init_alu_instr(&instr);
        instr.alu.add.op = V3D_QPU_A_ADD;
        instr.alu.add.a.raddr = 1;  // BaseB
        instr.alu.add.b.raddr = 10; // OffsetB
        instr.alu.add.waddr = 8;    // rf8 = Addr B
        emit_qpu_instr(devinfo, &instr);

        // === [Step 4-3] 메모리에서 A와 B 로드 (TMU) ===
        // V3D는 TMU(Texture Memory Unit)를 통해 일반 메모리를 읽습니다.
        // 읽기 요청(Write TMUA) -> 대기 -> 읽기 결과 수신(ldtmu) 순서입니다.

        // Request TMU Read A
        // rf7(Addr A)를 TMUA 레지스터에 쓰면 읽기 요청이 전송됩니다.
        init_alu_instr(&instr);
        instr.alu.add.op = V3D_QPU_A_MOV;
        instr.alu.add.a.raddr = 7;                // Addr A
        instr.alu.add.waddr = V3D_QPU_WADDR_TMUA; // TMU Address Register
        instr.alu.add.magic_write = true;
        emit_qpu_instr(devinfo, &instr);

        // Request TMU Read B
        // rf8(Addr B)를 TMUA 레지스터에 씁니다.
        // 큐에 순서대로 쌓이므로 A 요청 후 B 요청이 들어갑니다.
        init_alu_instr(&instr);
        instr.alu.add.op = V3D_QPU_A_MOV;
        instr.alu.add.a.raddr = 8; // Addr B
        instr.alu.add.waddr = V3D_QPU_WADDR_TMUA;
        instr.alu.add.magic_write = true;
        emit_qpu_instr(devinfo, &instr);

        // Wait/Delay (TMU latency)
        // 메모리 읽기는 시간이 걸립니다. 결과를 읽기 전에 NOP으로 지연을 줍니다.
        // 실제로는 더 많은 클럭이 필요할 수 있지만, ldtmu가 데이터 도착시까지 stall 하므로 안전합니다.
        init_alu_instr(&instr);
        instr.alu.add.op = V3D_QPU_A_NOP;
        emit_qpu_instr(devinfo, &instr);

        // Read A -> rf11
        // ldtmu 시그널을 보내면 FIFO에서 가장 먼저 도착한 데이터(A)를 읽어옵니다.
        init_alu_instr(&instr);
        instr.sig.ldtmu = true;
        instr.sig_addr = 11; // rf11에 A 데이터 저장
        emit_qpu_instr(devinfo, &instr);

        // Read B -> rf12
        // 다시 ldtmu 시그널을 보내면 그 다음 도착한 데이터(B)를 읽어옵니다.
        init_alu_instr(&instr);
        instr.sig.ldtmu = true;
        instr.sig_addr = 12; // rf12에 B 데이터 저장
        emit_qpu_instr(devinfo, &instr);

        // === [Step 4-4] 곱셈 및 누적 (MAC) ===

        // rf13 = rf11(A) * rf12(B) (Floating Point Multiply)
        // V3D_QPU_M_FMUL: 실수 곱셈 연산
        init_alu_instr(&instr);
        instr.alu.mul.op = V3D_QPU_M_FMUL;
        instr.alu.mul.a.raddr = 11;
        instr.alu.mul.b.raddr = 12;
        instr.alu.mul.waddr = 13; // rf13에 곱셈 결과 임시 저장
        emit_qpu_instr(devinfo, &instr);

        // rf6 = rf6 + rf13 (Floating Point Add)
        // 기존 누적값(rf6)에 곱셈 결과(rf13)를 더합니다.
        init_alu_instr(&instr);
        instr.alu.add.op = V3D_QPU_A_FADD;
        instr.alu.add.a.raddr = 6;
        instr.alu.add.b.raddr = 13;
        instr.alu.add.waddr = 6; // rf6에 결과 누적
        emit_qpu_instr(devinfo, &instr);
    }

    /*
     * 5. 결과(rf6)를 메모리에 저장 (Matrix C)
     * Address C = BaseC + (IndexC * 4 bytes)
     * IndexC = EIDX (각 쓰레드가 하나의 요소를 담당하므로)
     */

    // rf14 = EIDX(rf3) * 4 = rf3 << 2
    // Matrix C에서의 바이트 오프셋 계산
    init_alu_instr(&instr);
    instr.alu.add.op = V3D_QPU_A_SHL;
    instr.alu.add.a.raddr = 3;            // EIDX
    set_small_imm(devinfo, &instr, 1, 2); // Shift 2
    instr.alu.add.waddr = 14;             // rf14 = Byte Offset C
    emit_qpu_instr(devinfo, &instr);

    // rf15 = BaseC(rf2) + Offset(rf14)
    // 최종 C 요소의 메모리 주소
    init_alu_instr(&instr);
    instr.alu.add.op = V3D_QPU_A_ADD;
    instr.alu.add.a.raddr = 2;  // BaseC
    instr.alu.add.b.raddr = 14; // OffsetC
    instr.alu.add.waddr = 15;   // rf15 = Addr C
    emit_qpu_instr(devinfo, &instr);

    // TMU Write Request
    // V3D 4.x 이상에서 TMU 쓰기는 TMUD(Data) -> TMUA(Address) 순서로 진행합니다.

    // tmud = rf6 (Result Data)
    // 먼저 데이터를 TMUD 레지스터에 기록합니다.
    init_alu_instr(&instr);
    instr.alu.add.op = V3D_QPU_A_MOV;
    instr.alu.add.a.raddr = 6; // rf6 (결과값)
    instr.alu.add.waddr = V3D_QPU_WADDR_TMUD;
    instr.alu.add.magic_write = true;
    emit_qpu_instr(devinfo, &instr);

    // tmua = rf15 (Address)
    // 주소를 TMUA 레지스터에 기록하면, TMUD에 있던 데이터가 해당 주소로 쓰여집니다.
    init_alu_instr(&instr);
    instr.alu.add.op = V3D_QPU_A_MOV;
    instr.alu.add.a.raddr = 15; // rf15 (주소)
    instr.alu.add.waddr = V3D_QPU_WADDR_TMUA;
    instr.alu.add.magic_write = true;
    emit_qpu_instr(devinfo, &instr);

    // TMU Write Complete Wait
    // TMUWT: 이전의 모든 TMU 쓰기 작업이 완료될 때까지 대기합니다.
    // 메모리 정합성을 위해 필요합니다.
    init_alu_instr(&instr);
    instr.alu.add.op = V3D_QPU_A_TMUWT;
    emit_qpu_instr(devinfo, &instr);

    /*
     * 6. 프로그램 종료
     * thrsw: Thread Switch 시그널.
     * 마지막 쓰레드가 종료됨을 알리고, 쉐이더 프로그램을 마칩니다.
     * 종료 후에는 2개의 Delay Slot(NOP)이 필요합니다.
     */
    init_alu_instr(&instr);
    instr.sig.thrsw = true;
    instr.alu.add.op = V3D_QPU_A_NOP;
    emit_qpu_instr(devinfo, &instr);

    // Delay slots (Last 2 instructions)
    for (int i = 0; i < 2; i++)
    {
        init_alu_instr(&instr);
        instr.alu.add.op = V3D_QPU_A_NOP;
        emit_qpu_instr(devinfo, &instr);
    }

    printf("QPU 프로그램 생성 완료: %d 명령어\n\n", qpu_code_size);
}

/*
 * Helper functions
 */
void disassemble_qpu_program(const struct v3d_device_info* devinfo)
{
    printf("=== QPU 프로그램 디스어셈블 ===\n");
    for (int i = 0; i < qpu_code_size; i++)
    {
        printf("%2d: 0x%016lx  ", i, qpu_code[i]);
        struct v3d_qpu_instr instr;
        if (v3d_qpu_instr_unpack(devinfo, qpu_code[i], &instr))
            printf("%s", v3d_qpu_disasm(devinfo, qpu_code[i]));
        else
            printf("(invalid instruction)");
        printf("\n");
    }
    printf("\n");
}

/*
 * GPU 메모리 관리
 */
struct gpu_buffer
{
    int fd;
    uint32_t handle;
    uint32_t size;
    void* map;
    uint64_t offset;
};

static struct gpu_buffer* create_gpu_buffer(int drm_fd, uint32_t size)
{
    struct gpu_buffer* buf = calloc(1, sizeof(struct gpu_buffer));
    if (!buf)
        return NULL;

    buf->fd = drm_fd;
    buf->size = size;

    struct drm_v3d_create_bo create = { .size = size };
    if (ioctl(drm_fd, DRM_IOCTL_V3D_CREATE_BO, &create) < 0)
    {
        free(buf);
        return NULL;
    }

    buf->handle = create.handle;
    buf->offset = create.offset;

    struct drm_v3d_mmap_bo mmap_bo = { .handle = buf->handle };
    if (ioctl(drm_fd, DRM_IOCTL_V3D_MMAP_BO, &mmap_bo) < 0)
    {
        free(buf);
        return NULL;
    }

    buf->map = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, drm_fd, mmap_bo.offset);
    if (buf->map == MAP_FAILED)
    {
        free(buf);
        return NULL;
    }

    return buf;
}

static void destroy_gpu_buffer(struct gpu_buffer* buf)
{
    if (!buf)
        return;
    if (buf->map && buf->map != MAP_FAILED)
        munmap(buf->map, buf->size);
    if (buf->handle)
    {
        struct drm_gem_close close = { .handle = buf->handle };
        ioctl(buf->fd, DRM_IOCTL_GEM_CLOSE, &close);
    }
    free(buf);
}

/*
 * 메인 실행 함수
 */
int execute_on_gpu(void)
{
    struct gpu_buffer *code_bo = NULL, *input_a_bo = NULL, *input_b_bo = NULL, *output_bo = NULL, *uniforms_bo = NULL;
    int ret = -1;

    printf("\n=== 실제 GPU 실행 ===\n");

    if (render_fd < 0)
        return -1;

    // Buffer Allocation
    code_bo = create_gpu_buffer(render_fd, 4096);
    input_a_bo = create_gpu_buffer(render_fd, MATRIX_SIZE * sizeof(float));
    input_b_bo = create_gpu_buffer(render_fd, MATRIX_SIZE * sizeof(float));
    output_bo = create_gpu_buffer(render_fd, MATRIX_SIZE * sizeof(float));
    uniforms_bo = create_gpu_buffer(render_fd, 3 * sizeof(uint32_t));

    if (!code_bo || !input_a_bo || !input_b_bo || !output_bo || !uniforms_bo)
    {
        printf("Failed to allocate buffers\n");
        goto cleanup;
    }

    // Data Initialization
    memcpy(code_bo->map, qpu_code, qpu_code_size * sizeof(uint64_t));

    float* input_a = (float*)input_a_bo->map;
    float* input_b = (float*)input_b_bo->map;
    float* output = (float*)output_bo->map;

    // Initialize Matrix A with some float values
    // A[i][j] = (i + j) * 1.5
    printf("Matrix A:\n");
    for (int i = 0; i < MATRIX_DIM; i++)
    {
        for (int j = 0; j < MATRIX_DIM; j++)
        {
            input_a[i * MATRIX_DIM + j] = (float)((i + j + 1) * 1.1f);
            printf("%6.2f ", input_a[i * MATRIX_DIM + j]);
        }
        printf("\n");
    }

    // Initialize Matrix B with different float values
    // B[i][j] = (i - j) * 0.5 + 10.0
    printf("Matrix B:\n");
    for (int i = 0; i < MATRIX_DIM; i++)
    {
        for (int j = 0; j < MATRIX_DIM; j++)
        {
            input_b[i * MATRIX_DIM + j] = (float)((i * MATRIX_DIM + j) * 0.5f + 1.25f);
            printf("%6.2f ", input_b[i * MATRIX_DIM + j]);
        }
        printf("\n");
    }

    // Uniforms
    uint32_t* uniforms = (uint32_t*)uniforms_bo->map;
    uniforms[0] = (uint32_t)input_a_bo->offset;
    uniforms[1] = (uint32_t)input_b_bo->offset;
    uniforms[2] = (uint32_t)output_bo->offset;

    // Dispatch
    uint32_t bo_handles[] = { code_bo->handle, input_a_bo->handle, input_b_bo->handle, output_bo->handle, uniforms_bo->handle };
    struct drm_v3d_submit_csd submit = { 0 };

    submit.cfg[0] = (1 << 16);                            // WG Count X=1
    submit.cfg[1] = (1 << 16);                            // WG Count Y=1
    submit.cfg[2] = (1 << 16);                            // WG Count Z=1
    submit.cfg[3] = (16 & 0xff) | (1 << 8);               // WG Size=16, 1 WGS per SG
    submit.cfg[4] = 1;                                    // Num Batches
    submit.cfg[5] = (uint32_t)code_bo->offset | (1 << 1); // Single Seg
    submit.cfg[6] = (uint32_t)uniforms_bo->offset;

    submit.bo_handles = (uintptr_t)bo_handles;
    submit.bo_handle_count = 5;

    if (ioctl(render_fd, DRM_IOCTL_V3D_SUBMIT_CSD, &submit) < 0)
    {
        perror("Submit failed");
        goto cleanup;
    }

    // Wait
    struct drm_v3d_wait_bo wait = { .handle = output_bo->handle, .timeout_ns = 1000000000 };
    if (ioctl(render_fd, DRM_IOCTL_V3D_WAIT_BO, &wait) < 0)
    {
        perror("Wait failed");
        goto cleanup;
    }

    // Verification
    printf("\nMatrix C (Result):\n");
    bool success = true;
    for (int i = 0; i < MATRIX_DIM; i++)
    {
        for (int j = 0; j < MATRIX_DIM; j++)
        {
            float val = output[i * MATRIX_DIM + j];
            printf("%7.2f ", val);

            // Calculate Expected Result on CPU
            float expected = 0.0f;
            for (int k = 0; k < MATRIX_DIM; k++)
            {
                expected += input_a[i * MATRIX_DIM + k] * input_b[k * MATRIX_DIM + j];
            }

            // Compare with epsilon
            float diff = val - expected;
            if (diff < 0)
                diff = -diff;
            if (diff > 0.01f)
            {
                printf(" [Fail Expected %.2f] ", expected);
                success = false;
            }
        }
        printf("\n");
    }

    if (success)
    {
        printf("\nPASSED! GPU Matrix Mult Success!\n");
        ret = 0;
    }
    else
    {
        printf("\nFAILED! Result mismatch.\n");
    }

cleanup:
    destroy_gpu_buffer(code_bo);
    destroy_gpu_buffer(input_a_bo);
    destroy_gpu_buffer(input_b_bo);
    destroy_gpu_buffer(output_bo);
    destroy_gpu_buffer(uniforms_bo);
    return ret;
}

int main(int argc, char** argv)
{
    render_fd = open("/dev/dri/renderD128", O_RDWR);
    if (render_fd < 0)
    {
        printf("Cannot open render node. Trying to simulate or skip.\n");
        // For compilation and device info only in this context?
        // But we need device info to generate code.
        // Assuming V3D for code generation if device is missing?
        // Just mocking devinfo for generation.
    }

    struct v3d_device_info devinfo = { .ver = 71 }; // Default to V3D 7.1

    if (render_fd >= 0)
    {
        // Get generic identity... (skipped for brevity)
    }

    generate_qpu_matrix_mul(&devinfo);
    disassemble_qpu_program(&devinfo);

    if (render_fd >= 0)
        return execute_on_gpu();

    return 0;
}
