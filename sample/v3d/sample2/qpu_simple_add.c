/*
 * QPU 간단한 벡터 덧셈 예제
 *
 * 이 예제는 V3D QPU를 직접 사용하여 두 벡터를 더하는 프로그램입니다.
 * Vulkan이나 OpenGL을 사용하지 않고 QPU 명령어를 직접 생성합니다.
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
 * 계산할 데이터:
 * input_a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}
 * input_b[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160}
 * output[] = input_a[] + input_b[] (각 요소별 덧셈)
 */

#define VECTOR_SIZE 16

int render_fd;
int primary_fd;

/*
 * debugfs에서 V3D ident 정보 읽기
 * 커널의 v3d_v3d_debugfs_ident 함수가 출력한 정보를 읽습니다.
 */
static void read_v3d_debugfs_ident(void)
{
    FILE* fp = NULL;
    char line[256];
    char debugfs_path[512];
    int card_num;

    printf("=== V3D debugfs ident 정보 ===\n");

    /* DRM 디바이스 번호 찾기 (renderD128 = card0, renderD129 = card1, ...) */
    if (render_fd >= 0)
    {
        struct stat st;
        if (fstat(render_fd, &st) == 0)
        {
            /* minor number에서 card 번호 계산: renderD128 = minor 128 = card 0 */
            card_num = minor(st.st_rdev) - 128;
        }
        else
        {
            card_num = 0;
        }
    }
    else
    {
        card_num = 0;
    }

    /* debugfs 경로: /sys/kernel/debug/dri/N/v3d_ident */
    snprintf(debugfs_path, sizeof(debugfs_path),
             "/sys/kernel/debug/dri/%d/v3d_ident", card_num);

    fp = fopen(debugfs_path, "r");
    if (!fp)
    {
        /* 권한 문제일 수 있으므로 sudo 힌트 제공 */
        printf("debugfs를 열 수 없습니다: %s\n", strerror(errno));
        printf("힌트: sudo를 사용하거나 debugfs 권한을 확인하세요.\n");
        printf("      sudo cat %s\n\n", debugfs_path);
        return;
    }

    /* 파일 내용 출력 */
    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }
    printf("\n");

    fclose(fp);
}

/* QPU 프로그램을 저장할 버퍼 */
static uint64_t qpu_code[256]; // 16번 반복 * 9명령어 + 여유분
static int qpu_code_size = 0;

/* QPU 명령어를 버퍼에 추가하는 헬퍼 함수 */
static void emit_qpu_instr(const struct v3d_device_info* devinfo,
                           struct v3d_qpu_instr* instr)
{
    if (qpu_code_size >= 256)
    {
        fprintf(stderr, "QPU code buffer overflow (max 256 instructions)\n");
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

/*
 * QPU 벡터 덧셈 프로그램 생성
 *
 * 이 함수는 다음 작업을 수행하는 QPU 명령어를 생성합니다:
 * 1. uniform으로부터 입력 벡터 A의 주소 로드
 * 2. uniform으로부터 입력 벡터 B의 주소 로드
 * 3. uniform으로부터 출력 벡터의 주소 로드
 * 4. TMU를 사용하여 메모리에서 A 벡터 읽기
 * 5. TMU를 사용하여 메모리에서 B 벡터 읽기
 * 6. A + B 계산
 * 7. TMU를 사용하여 결과를 메모리에 쓰기
 * 8. 프로그램 종료
 */
void generate_qpu_vector_add(const struct v3d_device_info* devinfo)
{
    struct v3d_qpu_instr instr;

    printf("QPU 간단한 쓰기 테스트 프로그램 생성 중...\n");
    printf("V3D 버전: %d.%d\n", devinfo->ver / 10, devinfo->ver % 10);

    /*
     * 벡터 덧셈: output[i] = input_a[i] + input_b[i], i = 0..15
     *
     * Uniform layout:
     * [0] = input_a 주소
     * [1] = input_b 주소
     * [2] = output 주소
     */

    /*
     * 명령어 0-2: uniform에서 주소 3개 로드
     */
    // rf0 = input_a 주소 (uniform[0])
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.sig.ldunifrf = true;
    instr.sig_addr = 0;
    instr.sig_magic = false;
    instr.alu.add.op = V3D_QPU_A_NOP;
    instr.alu.mul.op = V3D_QPU_M_NOP;
    emit_qpu_instr(devinfo, &instr);

    // rf1 = input_b 주소 (uniform[1])
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.sig.ldunifrf = true;
    instr.sig_addr = 1;
    instr.sig_magic = false;
    instr.alu.add.op = V3D_QPU_A_NOP;
    instr.alu.mul.op = V3D_QPU_M_NOP;
    emit_qpu_instr(devinfo, &instr);

    // rf2 = output 주소 (uniform[2])
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.sig.ldunifrf = true;
    instr.sig_addr = 2;
    instr.sig_magic = false;
    instr.alu.add.op = V3D_QPU_A_NOP;
    instr.alu.mul.op = V3D_QPU_M_NOP;
    emit_qpu_instr(devinfo, &instr);

    /*
     * 16개의 ALU가 병렬로 각각 하나의 요소를 처리
     * Element 0: output[0] = input_a[0] + input_b[0]
     * Element 1: output[1] = input_a[1] + input_b[1]
     * ...
     * Element 15: output[15] = input_a[15] + input_b[15]
     */

    // rf7 = EIDX (thread ID: 0~15)
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.alu.add.op = V3D_QPU_A_EIDX; // Element Index (thread ID을 얻는 특수 op)
    instr.alu.add.waddr = 7;           // 얻어낸 Element ID값을 rf7에 저장.
    instr.alu.add.magic_write = false;
    instr.alu.mul.op = V3D_QPU_M_NOP;
    emit_qpu_instr(devinfo, &instr);

    /*
     * Element ID를 2배로 변환하여 offset 계산
     * Element 0: offset = 0
     * Element 1: offset = 2
     * ...
     * Element 15: offset = 30
     */
    // rf8 = rf7 * 2 (thread_id * 2)
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.alu.add.op = V3D_QPU_A_ADD;
    instr.alu.add.a.raddr = 7; // rf7
    instr.alu.add.b.raddr = 7; // rf7
    instr.alu.add.waddr = 8;   // rf8에 저장
    instr.alu.add.magic_write = false;
    instr.alu.mul.op = V3D_QPU_M_NOP;
    emit_qpu_instr(devinfo, &instr);

    /*
     * offset을 4배로 변환하여 input_a의 주소 계산
     * Element 0: offset = 0, input_a[0]의 offset
     * Element 1: offset = 2, input_a[1]의 offset 주소
     * ...
     * Element 15: offset = 30, input_a[15]의 offset 주소
     */
    // rf9 = rf8 * 2 = rf7 * 4 (offset in bytes)
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.alu.add.op = V3D_QPU_A_ADD;
    instr.alu.add.a.raddr = 8; // rf8
    instr.alu.add.b.raddr = 8; // rf8
    instr.alu.add.waddr = 9;   // rf9에 저장
    instr.alu.add.magic_write = false;
    instr.alu.mul.op = V3D_QPU_M_NOP;
    emit_qpu_instr(devinfo, &instr);

    /*
     * rf9에 저장된 offset으로 input_a 배열의 각 요소들의 주소를 저장
     */
    // rf3 = rf0 + rf9 (input_a 배열의 시작 주소 + input_a[0...15 Element]의 offset)
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.alu.add.op = V3D_QPU_A_ADD;
    instr.alu.add.a.raddr = 0; // rf0 (input_a 배열의 시작 주소)
    instr.alu.add.b.raddr = 9; // rf9 (input_a[0...15 Element]의 offset)
    instr.alu.add.waddr = 3;   // rf3에 저장
    instr.alu.add.magic_write = false;
    instr.alu.mul.op = V3D_QPU_M_NOP;
    emit_qpu_instr(devinfo, &instr);

    /*
     * rf9에 저장된 offset으로 input_b 배열의 각 요소들의 주소를 저장
     */
    // rf4 = rf1 + rf9 (input_b 배열의 시작 주소 + input_b[0...15 Element]의 offset)
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.alu.add.op = V3D_QPU_A_ADD;
    instr.alu.add.a.raddr = 1; // rf1 (input_b 배열의 시작 주소)
    instr.alu.add.b.raddr = 9; // rf9 (input_b[0...15 Element]의 offset)
    instr.alu.add.waddr = 4;   // rf4에 저장
    instr.alu.add.magic_write = false;
    instr.alu.mul.op = V3D_QPU_M_NOP;
    emit_qpu_instr(devinfo, &instr);

    /*
     * rf9에 저장된 offset으로 output 배열의 각 요소들의 주소를 저장
     */
    // rf5 = rf2 + rf9 (output 배열의 시작 주소 + output[0...15 Element]의 offset)
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.alu.add.op = V3D_QPU_A_ADD;
    instr.alu.add.a.raddr = 2; // rf2 (output 배열의 시작 주소)
    instr.alu.add.b.raddr = 9; // rf9 (output[0...15 Element]의 offset)
    instr.alu.add.waddr = 5;   // rf5에 저장
    instr.alu.add.magic_write = false;
    instr.alu.mul.op = V3D_QPU_M_NOP;
    emit_qpu_instr(devinfo, &instr);

    // 메모리에서 레지스터 파일로 데이터 읽어 오기
    {
        // TMU 읽기: input_a[0..15]를 TMU로 읽어 온다.
        // TMU는 데이터를 QPU - TMU 사이의 FIFO Buffer에 임시 저장한다.
        // FIFO 버퍼는 레지스터 파일처럼 직접 주소를 지정해서 사용할 수 있는 공간이 아니다.
        memset(&instr, 0, sizeof(instr));
        instr.type = V3D_QPU_INSTR_TYPE_ALU;
        instr.alu.add.op = V3D_QPU_A_MOV;
        instr.alu.add.a.raddr = 3; // rf3 (input_a[element_id] 주소)
        instr.alu.add.waddr = V3D_QPU_WADDR_TMUA;
        instr.alu.add.magic_write = true;
        instr.alu.mul.op = V3D_QPU_M_NOP;
        emit_qpu_instr(devinfo, &instr);

        // TMU 읽기: input_b[0..15]를 TMU로 읽어 온다.
        // 마찬가지로, TMU는 데이터를 QPU - TMU 사이의 FIFO Buffer에 임시 저장한다.
        memset(&instr, 0, sizeof(instr));
        instr.type = V3D_QPU_INSTR_TYPE_ALU;
        instr.alu.add.op = V3D_QPU_A_MOV;
        instr.alu.add.a.raddr = 4; // rf4 (input_b[element_id] 주소)
        instr.alu.add.waddr = V3D_QPU_WADDR_TMUA;
        instr.alu.add.magic_write = true;
        instr.alu.mul.op = V3D_QPU_M_NOP;
        emit_qpu_instr(devinfo, &instr);

        // NOP (TMU 레이턴시, 다른 연산을 이부분에서 진행하면 효율을 높일 수 있다.)
        // 너무 적은 시간 이후에, ldtmu를 진행하면, stall에 빠지게 된다.
        memset(&instr, 0, sizeof(instr));
        instr.type = V3D_QPU_INSTR_TYPE_ALU;
        instr.alu.add.op = V3D_QPU_A_NOP;
        instr.alu.mul.op = V3D_QPU_M_NOP;
        emit_qpu_instr(devinfo, &instr);

        // TMU로 input a,b를 읽어 오므로, FIF에 2개가 저장된다.
        // 먼저 실행한 명령어 부터 순차적으로 들어오므로, a데이터가 먼저 들어온다.
        // 따라서, ldtmu를 실행하면 먼저 input_a 데이터를 읽어온다.
        // ldtmu: rf10 = input_a[element_id], TMU로 읽어온 데이터를 rf10에 저장
        memset(&instr, 0, sizeof(instr));
        instr.type = V3D_QPU_INSTR_TYPE_ALU;
        instr.sig.ldtmu = true; // TMU로 읽어온 데이터를 저장
        instr.sig_addr = 10;    // rf10에 저장
        instr.sig_magic = false;
        instr.alu.add.op = V3D_QPU_A_NOP;
        instr.alu.mul.op = V3D_QPU_M_NOP;
        emit_qpu_instr(devinfo, &instr);

        // 위에서 input_a 데이터를 FIFO에서 읽어왔으므로,
        // ldtmu를 실행하면 먼저 input_b 데이터를 읽어온다.
        // ldtmu: rf11 = input_b[element_id], TMU로 읽어온 데이터를 rf11에 저장
        memset(&instr, 0, sizeof(instr));
        instr.type = V3D_QPU_INSTR_TYPE_ALU;
        instr.sig.ldtmu = true; // TMU로 읽어온 데이터를 저장
        instr.sig_addr = 11;    // rf11에 저장
        instr.sig_magic = false;
        instr.alu.add.op = V3D_QPU_A_NOP;
        instr.alu.mul.op = V3D_QPU_M_NOP;
        emit_qpu_instr(devinfo, &instr);
    }

    // 덧셈 수행
    // rf12 = rf10 + rf11(input_a + input_b)
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.alu.add.op = V3D_QPU_A_ADD;
    instr.alu.add.a.raddr = 10; // rf10 (input_a)
    instr.alu.add.b.raddr = 11; // rf11 (input_b)
    instr.alu.add.waddr = 12;   // rf12 (덧셈 결과)
    instr.alu.add.magic_write = false;
    instr.alu.mul.op = V3D_QPU_M_NOP;
    emit_qpu_instr(devinfo, &instr);

    // 덧셈 결과를 메모리에 저장하기
    {
        // TMU 쓰기 준비: tmud = rf12 (덧셈 결과)
        // 읽기 때 사용했던 QPU - TMU 사이의 FIFO Buffer와는 다르다.
        // 쓰기는 QPU내부의 특수 목적 레지스터에 보관된다.
        // 읽기(Read)와 달리 쓰기(Write) 데이터는 큐에 쌓이지 않는다.
        // 따라서, 반드시 TMUD 쓰기 직후에 TMUA 쓰기가 짝을 이뤄야 한다.
        memset(&instr, 0, sizeof(instr));
        instr.type = V3D_QPU_INSTR_TYPE_ALU;
        instr.alu.add.op = V3D_QPU_A_MOV;
        instr.alu.add.a.raddr = 12;               // rf12 (덧셈 결과)
        instr.alu.add.waddr = V3D_QPU_WADDR_TMUD; // QPU 특수 목적 레지스터에 보관
        instr.alu.add.magic_write = true;
        instr.alu.mul.op = V3D_QPU_M_NOP;
        emit_qpu_instr(devinfo, &instr);

        // TMU 쓰기 시작: tmua = rf5 (output[thread_id] 주소)
        // QPU 특수 목적 레지스터에 저장된 데이터를 rf5에 저장된 output 주소에 write한다.
        memset(&instr, 0, sizeof(instr));
        instr.type = V3D_QPU_INSTR_TYPE_ALU;
        instr.alu.add.op = V3D_QPU_A_MOV;
        instr.alu.add.a.raddr = 5; // rf5 (output[thread_id] 주소)
        instr.alu.add.waddr = V3D_QPU_WADDR_TMUA;
        instr.alu.add.magic_write = true;
        instr.alu.mul.op = V3D_QPU_M_NOP;
        emit_qpu_instr(devinfo, &instr);

        // TMUWT - 모든 TMU 쓰기 완료 대기
        memset(&instr, 0, sizeof(instr));
        instr.type = V3D_QPU_INSTR_TYPE_ALU;
        instr.alu.add.op = V3D_QPU_A_TMUWT;
        instr.alu.mul.op = V3D_QPU_M_NOP;
        emit_qpu_instr(devinfo, &instr);

        // NOP (tmuwt 이후)
        for (int i = 0; i < 2; i++)
        {
            memset(&instr, 0, sizeof(instr));
            instr.type = V3D_QPU_INSTR_TYPE_ALU;
            instr.alu.add.op = V3D_QPU_A_NOP;
            instr.alu.mul.op = V3D_QPU_M_NOP;
            emit_qpu_instr(devinfo, &instr);
        }
    }

    // 프로그램 종료
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.sig.thrsw = true;
    instr.alu.add.op = V3D_QPU_A_NOP;
    instr.alu.mul.op = V3D_QPU_M_NOP;
    emit_qpu_instr(devinfo, &instr);

    // NOP (thrsw delay slots)
    for (int i = 0; i < 2; i++)
    {
        memset(&instr, 0, sizeof(instr));
        instr.type = V3D_QPU_INSTR_TYPE_ALU;
        instr.alu.add.op = V3D_QPU_A_NOP;
        instr.alu.mul.op = V3D_QPU_M_NOP;
        emit_qpu_instr(devinfo, &instr);
    }

    printf("QPU 프로그램 생성 완료: %d 명령어\n\n", qpu_code_size);
    printf("벡터 덧셈: output[i] = input_a[i] + input_b[i] (i=0..15)\n\n");
}

/*
 * 생성된 QPU 명령어를 디스어셈블하여 출력
 */
void disassemble_qpu_program(const struct v3d_device_info* devinfo)
{
    printf("=== QPU 프로그램 디스어셈블 ===\n");

    for (int i = 0; i < qpu_code_size; i++)
    {
        printf("%2d: 0x%016lx  ", i, qpu_code[i]);

        struct v3d_qpu_instr instr;
        bool ok = v3d_qpu_instr_unpack(devinfo, qpu_code[i], &instr);

        if (ok)
        {
            const char* disasm = v3d_qpu_disasm(devinfo, qpu_code[i]);
            printf("%s", disasm);
        }
        else
        {
            printf("(invalid instruction)");
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * 프로그램 설명 출력
 */
void print_program_explanation(void)
{
    printf("=== 프로그램 동작 설명 ===\n");
    printf("이 QPU 프로그램은 16-way SIMD 벡터 덧셈을 수행합니다:\n\n");

    printf("1. Uniform에서 3개의 주소를 로드:\n");
    printf("   - rf0 = input_a 베이스 주소\n");
    printf("   - rf1 = input_b 베이스 주소\n");
    printf("   - rf2 = output 베이스 주소\n\n");

    printf("2. 각 쓰레드의 오프셋 계산 (16개 쓰레드 병렬 실행):\n");
    printf("   - rf7 = EIDX (thread ID: 0~15)\n");
    printf("   - rf8 = rf7 * 2\n");
    printf("   - rf9 = rf8 * 2 = thread_id * 4 (바이트 오프셋)\n\n");

    printf("3. 각 쓰레드의 메모리 주소 계산:\n");
    printf("   - rf3 = rf0 + rf9 → input_a[thread_id] 주소\n");
    printf("   - rf4 = rf1 + rf9 → input_b[thread_id] 주소\n");
    printf("   - rf5 = rf2 + rf9 → output[thread_id] 주소\n\n");

    printf("4. 각 쓰레드가 자신의 요소 처리:\n");
    printf("   a) TMU 읽기:\n");
    printf("      - tmua = rf3 → input_a[thread_id] 읽기\n");
    printf("      - tmua = rf4 → input_b[thread_id] 읽기\n");
    printf("   b) 데이터 로드 및 덧셈:\n");
    printf("      - ldtmu rf10 ← input_a[thread_id]\n");
    printf("      - ldtmu rf11 ← input_b[thread_id]\n");
    printf("      - rf12 = rf10 + rf11\n");
    printf("   c) TMU 쓰기:\n");
    printf("      - tmud = rf12\n");
    printf("      - tmua = rf5 → output[thread_id] 쓰기\n\n");

    printf("5. 완료:\n");
    printf("   - tmuwt: 모든 TMU 쓰기 완료 대기\n");
    printf("   - thrsw: 스레드 종료\n\n");

    printf("핵심 개념:\n");
    printf("  • V3D는 16-way SIMD: 16개 쓰레드가 병렬로 같은 명령어 실행\n");
    printf("  • EIDX로 각 쓰레드의 ID를 얻어 서로 다른 데이터 처리\n");
    printf("  • TMUD와 TMUA는 반드시 별도 명령어로 분리!\n\n");
}

/*
 * GPU 메모리 할당 및 관리 구조체
 */
struct gpu_buffer
{
    int fd;          // DRM 파일 디스크립터
    uint32_t handle; // BO 핸들
    uint32_t size;   // 버퍼 크기
    void* map;       // CPU 맵핑 주소
    uint64_t offset; // GPU 주소 오프셋
};

/*
 * GPU 버퍼 할당
 */
static struct gpu_buffer* create_gpu_buffer(int drm_fd, uint32_t size)
{
    struct gpu_buffer* buf = calloc(1, sizeof(struct gpu_buffer));
    if (!buf)
        return NULL;

    buf->fd = drm_fd;
    buf->size = size;

    /* BO (Buffer Object) 생성 */
    struct drm_v3d_create_bo create = {
        .size = size,
    };

    if (ioctl(drm_fd, DRM_IOCTL_V3D_CREATE_BO, &create) < 0)
    {
        fprintf(stderr, "Failed to create BO: %s\n", strerror(errno));
        free(buf);
        return NULL;
    }

    buf->handle = create.handle;
    buf->offset = create.offset;

    /* CPU에서 접근 가능하도록 메모리 맵핑 */
    struct drm_v3d_mmap_bo mmap_bo = {
        .handle = buf->handle,
    };

    if (ioctl(drm_fd, DRM_IOCTL_V3D_MMAP_BO, &mmap_bo) < 0)
    {
        fprintf(stderr, "Failed to mmap BO: %s\n", strerror(errno));
        struct drm_gem_close close = { .handle = buf->handle };
        ioctl(drm_fd, DRM_IOCTL_GEM_CLOSE, &close);
        free(buf);
        return NULL;
    }

    buf->map = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED,
                    drm_fd, mmap_bo.offset);
    if (buf->map == MAP_FAILED)
    {
        fprintf(stderr, "Failed to mmap buffer: %s\n", strerror(errno));
        struct drm_gem_close close = { .handle = buf->handle };
        ioctl(drm_fd, DRM_IOCTL_GEM_CLOSE, &close);
        free(buf);
        return NULL;
    }

    return buf;
}

/*
 * GPU 버퍼 해제
 */
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
 * 실제 GPU에서 QPU 프로그램 실행
 */
int execute_on_gpu(void)
{
    struct gpu_buffer* code_bo = NULL;
    struct gpu_buffer* input_a_bo = NULL;
    struct gpu_buffer* input_b_bo = NULL;
    struct gpu_buffer* output_bo = NULL;
    struct gpu_buffer* uniforms_bo = NULL;
    int ret = -1;

    printf("\n=== 실제 GPU 실행 ===\n");

    if (render_fd < 0)
    {
        fprintf(stderr, "Note: V3D DRM 커널 드라이버가 필요합니다.\n");
        return -1;
    }

    printf("V3D DRM 디바이스 열기 성공\n");

    /* 2. GPU 메모리 할당 */
    printf("GPU 메모리 할당 중...\n");

    /* QPU 코드 버퍼 (64 bytes aligned) */
    code_bo = create_gpu_buffer(render_fd, qpu_code_size * sizeof(uint64_t));
    if (!code_bo)
        goto cleanup;

    /* 입력/출력 데이터 버퍼 */
    input_a_bo = create_gpu_buffer(render_fd, VECTOR_SIZE * sizeof(uint32_t));
    if (!input_a_bo)
        goto cleanup;

    input_b_bo = create_gpu_buffer(render_fd, VECTOR_SIZE * sizeof(uint32_t));
    if (!input_b_bo)
        goto cleanup;

    output_bo = create_gpu_buffer(render_fd, VECTOR_SIZE * sizeof(uint32_t));
    if (!output_bo)
        goto cleanup;

    /* Uniform 버퍼 (3개 주소 - V3D는 32비트 주소 사용) */
    uniforms_bo = create_gpu_buffer(render_fd, 3 * sizeof(uint32_t));
    if (!uniforms_bo)
        goto cleanup;

    printf("GPU 메모리 할당 완료\n");

    /* 3. 데이터 준비 */
    printf("데이터 초기화 중...\n");

    /* QPU 코드 복사 */
    memcpy(code_bo->map, qpu_code, qpu_code_size * sizeof(uint64_t));

    /* 입력 데이터 초기화 */
    uint32_t* input_a = (uint32_t*)input_a_bo->map;
    uint32_t* input_b = (uint32_t*)input_b_bo->map;
    uint32_t* output = (uint32_t*)output_bo->map;

    printf("입력 벡터 A: ");
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        input_a[i] = i + 1;
        printf("%u ", input_a[i]);
    }
    printf("\n");

    printf("입력 벡터 B: ");
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        input_b[i] = (i + 1) * 10;
        printf("%u ", input_b[i]);
    }
    printf("\n");

    /* Uniform 데이터: [0-2]=주소들 */
    uint32_t* uniforms = (uint32_t*)uniforms_bo->map;
    uniforms[0] = (uint32_t)input_a_bo->offset; // input_a 주소
    uniforms[1] = (uint32_t)input_b_bo->offset; // input_b 주소
    uniforms[2] = (uint32_t)output_bo->offset;  // output 주소

    printf("Uniform 설정:\n");
    printf("  input_a: 0x%08x\n", uniforms[0]);
    printf("  input_b: 0x%08x\n", uniforms[1]);
    printf("  output:  0x%08x\n", uniforms[2]);

    /* 4. Compute Shader Dispatch 구성 */
    printf("GPU 작업 제출 중...\n");

    uint32_t bo_handles[5] = {
        code_bo->handle,
        input_a_bo->handle,
        input_b_bo->handle,
        output_bo->handle,
        uniforms_bo->handle,
    };

    struct drm_v3d_submit_csd submit = { 0 };

    /* CSD cfg[7] 레지스터 설정 (V3D 7.1 실제 하드웨어 포맷):
     * cfg[0]: (num_wgs_x << 16) | wg_offset_x
     * cfg[1]: (num_wgs_y << 16) | wg_offset_y
     * cfg[2]: (num_wgs_z << 16) | wg_offset_z
     * cfg[3]: wg_size | (wgs_per_sg << 8) | (batches_per_sg-1 << 12) | (max_sg_id << 20)
     * cfg[4]: num_batches (V3D 7.1.6+에서는 -1 하지 않음)
     * cfg[5]: shader_offset | SINGLE_SEG | THREADING 플래그
     * cfg[6]: uniforms_offset
     */

    /* Workgroup 설정: 1x1x1 workgroup */
    const uint32_t wg_count_x = 1;
    const uint32_t wg_count_y = 1;
    const uint32_t wg_count_z = 1;
    const uint32_t num_wgs = wg_count_x * wg_count_y * wg_count_z;

    /* Workgroup 크기: 16 (QPU의 16-way SIMD에 맞춤) */
    const uint32_t wg_size = 16;

    /* Supergroup 설정 */
    const uint32_t wgs_per_sg = 1;                                          // 1 workgroup per supergroup
    const uint32_t batches_per_sg = (wgs_per_sg * wg_size + 15) / 16;       // = 1
    const uint32_t num_batches = batches_per_sg * num_wgs;                  // = 1
    const uint32_t max_sg_id = (num_wgs + wgs_per_sg - 1) / wgs_per_sg - 1; // = 0

    /* cfg[0-2]: Workgroup count와 offset */
    submit.cfg[0] = (wg_count_x << 16) | 0; // WG count X=1, offset X=0
    submit.cfg[1] = (wg_count_y << 16) | 0; // WG count Y=1, offset Y=0
    submit.cfg[2] = (wg_count_z << 16) | 0; // WG count Z=1, offset Z=0

    /* cfg[3]: Workgroup와 Supergroup 설정 */
    submit.cfg[3] = (wg_size & 0xff) |             // WG_SIZE (8 bits)
                    ((wgs_per_sg & 0xf) << 8) |    // WGS_PER_SG (4 bits)
                    ((batches_per_sg - 1) << 12) | // BATCHES_PER_SG_M1 (8 bits)
                    ((max_sg_id & 0x3f) << 20);    // MAX_SG_ID (6 bits)

    /* cfg[4]: 총 batch 개수 (V3D 7.1.6+에서는 -1 하지 않음) */
    submit.cfg[4] = num_batches;

    /* cfg[5]: Shader 주소 + 플래그 */
    submit.cfg[5] = (uint32_t)code_bo->offset;
    submit.cfg[5] |= (1 << 1); // V3D_CSD_CFG5_SINGLE_SEG - 단일 세그먼트
    // THREADING 비트는 쓰레드가 4개일 때만 설정 (우리는 1개 사용)

    /* cfg[6]: Uniform 주소 */
    submit.cfg[6] = (uint32_t)uniforms_bo->offset;

    printf("CSD cfg 설정:\n");
    printf("  cfg[0] = 0x%08x (wg_count_x=%u)\n", submit.cfg[0], wg_count_x);
    printf("  cfg[1] = 0x%08x (wg_count_y=%u)\n", submit.cfg[1], wg_count_y);
    printf("  cfg[2] = 0x%08x (wg_count_z=%u)\n", submit.cfg[2], wg_count_z);
    printf("  cfg[3] = 0x%08x (wg_size=%u, wgs_per_sg=%u, batches_per_sg=%u)\n",
           submit.cfg[3], wg_size, wgs_per_sg, batches_per_sg);
    printf("  cfg[4] = 0x%08x (num_batches=%u)\n", submit.cfg[4], num_batches);
    printf("  cfg[5] = 0x%08x (shader=0x%x)\n", submit.cfg[5], (uint32_t)code_bo->offset);
    printf("  cfg[6] = 0x%08x (uniforms=0x%x)\n", submit.cfg[6], (uint32_t)uniforms_bo->offset);

    submit.bo_handles = (uintptr_t)bo_handles;
    submit.bo_handle_count = 5;
    submit.in_sync = 0;
    submit.out_sync = 0;
    submit.flags = 0;
    submit.perfmon_id = 0;

    /* 5. GPU에 작업 제출 */
    if (ioctl(render_fd, DRM_IOCTL_V3D_SUBMIT_CSD, &submit) < 0)
    {
        fprintf(stderr, "Failed to submit CSD: %s\n", strerror(errno));
        goto cleanup;
    }

    printf("GPU 작업 제출 완료 (seqno: %llu)\n", submit.out_sync);

    /* 6. GPU 완료 대기 */
    printf("GPU 실행 완료 대기 중...\n");

    struct drm_v3d_wait_bo wait = {
        .handle = output_bo->handle,
        .timeout_ns = 1000000000, // 1초 타임아웃
    };

    if (ioctl(render_fd, DRM_IOCTL_V3D_WAIT_BO, &wait) < 0)
    {
        fprintf(stderr, "Failed to wait for BO: %s\n", strerror(errno));
        goto cleanup;
    }

    printf("GPU 실행 완료!\n\n");

    /* 7. 결과 확인 */
    // output is already declared and initialized at line ~498

    printf("출력 벡터:   ");
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        printf("%u ", output[i]);
    }
    printf("\n");

    /* 8. 결과 검증 (벡터 덧셈: output[i] = input_a[i] + input_b[i]) */
    printf("\n결과 검증: ");
    bool success = true;
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        uint32_t expected = input_a[i] + input_b[i];
        if (output[i] != expected)
        {
            printf("FAILED (index %d: expected %u, got %u)\n", i, expected, output[i]);
            success = false;
            break;
        }
    }

    if (success)
    {
        printf("PASSED! GPU 벡터 덧셈 성공!\n");
        printf("         모든 16개 요소가 정확하게 계산되었습니다.\n");
        ret = 0;
    }

cleanup:
    /* 9. 정리 */
    destroy_gpu_buffer(code_bo);
    destroy_gpu_buffer(input_a_bo);
    destroy_gpu_buffer(input_b_bo);
    destroy_gpu_buffer(output_bo);
    destroy_gpu_buffer(uniforms_bo);

    return ret;
}

/*
 * CPU 시뮬레이션 실행
 */
void simulate_execution(void)
{
    uint32_t input_a[VECTOR_SIZE];
    uint32_t input_b[VECTOR_SIZE];
    uint32_t output[VECTOR_SIZE];

    /* 입력 데이터 초기화 */
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        input_a[i] = i + 1;
        input_b[i] = (i + 1) * 10;
    }

    printf("=== CPU 시뮬레이션 실행 ===\n");
    printf("입력 벡터 A: ");
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        printf("%u ", input_a[i]);
    }
    printf("\n");

    printf("입력 벡터 B: ");
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        printf("%u ", input_b[i]);
    }
    printf("\n");

    /* CPU에서 시뮬레이션 */
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        output[i] = input_a[i] + input_b[i];
    }

    printf("출력 벡터:   ");
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        printf("%u ", output[i]);
    }
    printf("\n\n");
}

int main(int argc, char* argv[])
{
    /* V3D 7.1 디바이스 정보 설정 (Raspberry Pi 5) */
    struct v3d_device_info devinfo;
    memset(&devinfo, 0, sizeof(devinfo));

    printf("========================================\n");
    printf("   QPU 벡터 덧셈 예제 (V3D 7.1)\n");
    printf("========================================\n\n");

    /* GPU 디바이스 열어서 실제 QPU 개수 확인 시도 */
    render_fd = open("/dev/dri/renderD128", O_RDWR);
    if (render_fd < 0)
    {
        printf("V3D DRM 디바이스 열기 실패: %s\n", strerror(errno));
        return 1;
    }

    if (!v3d_get_device_info(render_fd, &devinfo, (v3d_ioctl_fun)ioctl))
    {
        printf("V3D 디바이스 정보 가져오기 실패\n");
        close(render_fd);
        return 1;
    }

    /* debugfs에서 상세 정보 읽기 */
    read_v3d_debugfs_ident();

    /* QPU 프로그램 생성 */
    generate_qpu_vector_add(&devinfo);

    /* 디스어셈블 출력 */
    disassemble_qpu_program(&devinfo);

    /* 프로그램 설명 */
    print_program_explanation();

    /* CPU 시뮬레이션 */
    simulate_execution();

    /* 실제 GPU 실행 시도 */
    bool run_on_gpu = true;
    if (argc > 1 && strcmp(argv[1], "--no-gpu") == 0)
    {
        run_on_gpu = false;
        printf("GPU 실행 건너뛰기 (--no-gpu 옵션)\n");
    }

    if (run_on_gpu)
    {
        printf("\n");
        int result = execute_on_gpu();
        if (result != 0)
        {
            printf("\nGPU 실행 실패 - CPU 시뮬레이션 결과만 유효합니다.\n");
            printf("Raspberry Pi 5에서 실행하거나 --no-gpu 옵션을 사용하세요.\n");
        }
    }

    /* IDENT1 레지스터 다시 읽어서 상세 정보 출력 */
    struct drm_v3d_get_param ident1_req = {
        .param = DRM_V3D_PARAM_V3D_CORE0_IDENT1,
    };
    uint32_t ident1_value = 0;
    if (ioctl(render_fd, DRM_IOCTL_V3D_GET_PARAM, &ident1_req) == 0)
    {
        ident1_value = ident1_req.value;
    }

    int nslc = (ident1_value >> 4) & 0xf;
    int qups = (ident1_value >> 8) & 0xf;
    int ntmu = (ident1_value >> 12) & 0xf;
    int vpm_size_kb = ((ident1_value >> 28) & 0xf);
    // devinfo.vpm_size = vpm_size_kb * 1024;

    printf("=== 실제 GPU 하드웨어 정보 ===\n");
    printf("V3D 버전: %d.%d\n", devinfo.ver / 10, devinfo.ver % 10);
    printf("QPU 개수: %d\n", devinfo.qpu_count);
    printf("Slice 갯수: %d\n", devinfo.slice_count);
    printf("TMU 개수: %d\n", devinfo.tmu_count);
    printf("Semaphore 갯수: %d\n", devinfo.sem_count);
    printf("VPM 크기: %d bytes\n", devinfo.vpm_size);
    printf("최대 동시 쓰레드: %d (QPU × 16)\n", devinfo.qpu_count * 16);
    printf("Accumulator 레지스터: %s\n",
           devinfo.has_accumulators ? "있음 (V3D 4.x)" : "없음 (V3D 7.x)");
    printf("\n");

    if (render_fd >= 0)
        close(render_fd);

    printf("\n========================================\n");
    printf("프로그램 종료\n");
    printf("========================================\n");

    return 0;
}
