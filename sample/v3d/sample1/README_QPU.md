# QPU 직접 프로그래밍 예제

이 디렉토리에는 Vulkan이나 OpenGL을 사용하지 않고 **QPU (Quad Processing Unit)**를 직접 프로그래밍하는 예제가 포함되어 있습니다.

## QPU란?

QPU는 V3D GPU의 **실행 유닛(Execution Unit)**입니다. 각 QPU는:
- **16-way SIMD** 프로세서 (한 번에 16개 데이터 처리)
- **Dual-issue**: ADD와 MUL 유닛을 동시에 실행 가능
- **64비트 명령어 인코딩**

### V3D 7.1 (Raspberry Pi 5) 아키텍처
```
┌─────────────────────────────────────┐
│         V3D GPU (2712 SoC)          │
├─────────────────────────────────────┤
│  QPU 0  │  QPU 1  │ ... │  QPU N   │  (다중 QPU)
├─────────────────────────────────────┤
│        각 QPU 구조:                  │
│  ┌─────────────────────────────┐   │
│  │  16개 레인 (SIMD)            │   │
│  │  ┌─────┬─────┬─────┬─────┐  │   │
│  │  │ L0  │ L1  │ ... │ L15 │  │   │
│  │  └─────┴─────┴─────┴─────┘  │   │
│  │                              │   │
│  │  ADD 유닛   MUL 유닛         │   │
│  │  (정수/FP)  (곱셈)           │   │
│  │                              │   │
│  │  레지스터 파일 (64 x 32bit)   │   │
│  │  - rf0 ~ rf63 (범용)         │   │
│  │  - r0 ~ r5 (누산기)          │   │
│  └─────────────────────────────┘   │
└─────────────────────────────────────┘
```

## 예제 파일

### 1. `qpu_minimal.c` - 최소 QPU 프로그램
**난이도**: ⭐ (가장 쉬움)

가장 간단한 QPU 프로그램 (3개 명령어):
```asm
1. r0 = 42          ; 레지스터에 값 로드
2. thrsw            ; 스레드 종료
3. nop              ; delay slot
```

**컴파일 및 실행:**
```bash
gcc -I. qpu_minimal.c -o qpu_minimal
./qpu_minimal
```

**출력 예:**
```
최소한의 QPU 프로그램 (3개 명령어)
====================================

1. r0 = 42
   인코딩: 0x...

2. thrsw (스레드 종료)
   인코딩: 0x...

3. nop (delay slot)
   인코딩: 0x...
```

### 2. `qpu_simple_add.c` - 벡터 덧셈
**난이도**: ⭐⭐⭐ (중급)

메모리에서 데이터를 읽어 벡터 덧셈을 수행:
```
input_a[] = {1, 2, 3, ..., 16}
input_b[] = {10, 20, 30, ..., 160}
output[] = input_a[] + input_b[]
```

**주요 기능:**
- Uniform 스트림에서 주소 읽기
- TMU (Texture Memory Unit)를 사용한 메모리 접근
- 16-way SIMD 벡터 연산
- 결과를 메모리에 쓰기

**컴파일:**
```bash
gcc -I. qpu_simple_add.c \
    broadcom/qpu/qpu_instr.c \
    broadcom/qpu/qpu_pack.c \
    broadcom/qpu/qpu_disasm.c \
    -o qpu_simple_add

./qpu_simple_add
```

## QPU 명령어 구조

### QPU 명령어 포맷 (64비트)

```
 63                                                              0
┌────────────────────────────────────────────────────────────────┐
│  신호  │  ADD 연산  │  MUL 연산  │  플래그  │  레지스터 주소  │
└────────────────────────────────────────────────────────────────┘
```

### 주요 구조체

```c
struct v3d_qpu_instr {
    enum v3d_qpu_instr_type type;  // ALU or BRANCH

    struct v3d_qpu_sig sig;        // 신호 비트들
    struct v3d_qpu_flags flags;    // 조건 플래그

    union {
        struct v3d_qpu_alu_instr alu;     // ALU 명령어
        struct v3d_qpu_branch_instr branch; // 분기 명령어
    };
};

struct v3d_qpu_alu_instr {
    struct {
        enum v3d_qpu_add_op op;    // ADD 연산 (FADD, ADD, SUB, ...)
        struct v3d_qpu_input a, b; // 입력 레지스터
        uint8_t waddr;             // 출력 레지스터
        bool magic_write;          // 특수 레지스터 쓰기 여부
    } add;

    struct {
        enum v3d_qpu_mul_op op;    // MUL 연산 (FMUL, MUL, ...)
        struct v3d_qpu_input a, b;
        uint8_t waddr;
        bool magic_write;
    } mul;
};
```

## QPU 레지스터

### 범용 레지스터 파일
- **rf0 ~ rf63**: 64개의 32비트 범용 레지스터
- V3D 7.x에서 `raddr` 필드로 접근

### 누산기 레지스터 (V3D 4.x)
- **r0 ~ r5**: 6개의 누산기 레지스터
- V3D 7.x에서는 예약됨 (rf0 ~ rf63 사용)

### 특수 레지스터 (Magic Registers)
```c
V3D_QPU_WADDR_UNIFA   // Uniform FIFO 주소
V3D_QPU_WADDR_TMUA    // TMU 주소 (메모리 읽기 시작)
V3D_QPU_WADDR_TMUD    // TMU 데이터 (메모리 쓰기 데이터)
V3D_QPU_WADDR_TMUC    // TMU config
V3D_QPU_WADDR_VPM     // VPM (Vertex Pipe Memory) 접근
V3D_QPU_WADDR_TLB     // Tile Buffer (렌더링용)
```

## 신호 비트 (Signals)

QPU 명령어는 다양한 신호를 포함할 수 있습니다:

```c
struct v3d_qpu_sig {
    bool thrsw;        // 스레드 전환/종료
    bool ldunif;       // Uniform 로드
    bool ldtmu;        // TMU 데이터 읽기
    bool ldvary;       // Varying 로드 (셰이더용)
    bool small_imm_a;  // 작은 즉시값 (add a)
    bool small_imm_b;  // 작은 즉시값 (add b)
    bool small_imm_c;  // 작은 즉시값 (mul a)
    bool small_imm_d;  // 작은 즉시값 (mul b)
    // ...
};
```

## QPU 명령어 예제

### 1. 레지스터 간 덧셈
```c
// r2 = r0 + r1
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.alu.add.op = V3D_QPU_A_ADD;
instr.alu.add.a.raddr = 0;  // r0
instr.alu.add.b.raddr = 1;  // r1
instr.alu.add.waddr = 2;    // r2
instr.alu.mul.op = V3D_QPU_M_NOP;
```

### 2. 즉시값 로드 (Small Immediate)
```c
// r0 = 15
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.sig.small_imm_b = true;
instr.raddr_b = 15;  // 즉시값 15
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.b.raddr = 32;  // small_imm 사용 시 특수 값
instr.alu.add.waddr = 0;     // r0
```

### 3. Uniform 로드
```c
// r3 = uniform
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.sig.ldunif = true;  // uniform 스트림에서 읽기
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.waddr = 3;  // r3에 저장
```

### 4. 메모리 읽기 (TMU)
```c
// Step 1: TMU에 읽기 주소 설정
instr.sig.ldunif = true;
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.waddr = V3D_QPU_WADDR_TMUA;  // TMU 주소
instr.alu.add.magic_write = true;

// Step 2: 읽기 완료 대기 (결과는 r4에 저장됨)
instr.sig.ldtmu = true;
instr.alu.add.op = V3D_QPU_A_NOP;
```

### 5. 메모리 쓰기 (TMU)
```c
// Step 1: 쓸 데이터 설정
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 0;  // r0의 값을
instr.alu.add.waddr = V3D_QPU_WADDR_TMUD;  // TMU data에 설정
instr.alu.add.magic_write = true;

// Step 2: 쓰기 주소 설정 (쓰기 시작)
instr.alu.mul.op = V3D_QPU_A_MOV;
instr.alu.mul.waddr = V3D_QPU_WADDR_TMUA;  // TMU 주소
instr.alu.mul.magic_write = true;

// Step 3: 쓰기 완료 대기
instr.alu.add.op = V3D_QPU_A_TMUWT;
```

### 6. 조건부 실행
```c
// if (flags.z) r0 = r1
instr.flags.ac = V3D_QPU_COND_IFA;  // A 플래그가 set이면 실행
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 1;
instr.alu.add.waddr = 0;
```

### 7. 부동소수점 연산
```c
// r0 = r1 + r2 (float)
instr.alu.add.op = V3D_QPU_A_FADD;  // 부동소수점 덧셈
instr.alu.add.a.raddr = 1;
instr.alu.add.b.raddr = 2;
instr.alu.add.waddr = 0;

// r3 = r4 * r5 (float) - MUL 유닛 동시 실행
instr.alu.mul.op = V3D_QPU_M_FMUL;
instr.alu.mul.a.raddr = 4;
instr.alu.mul.b.raddr = 5;
instr.alu.mul.waddr = 3;
```

## QPU 프로그램 실행 흐름

### 1. 명령어 생성
```c
struct v3d_qpu_instr instr;
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.alu.add.op = V3D_QPU_A_ADD;
// ... 필드 설정
```

### 2. 명령어 인코딩 (패킹)
```c
uint64_t packed;
bool ok = v3d_qpu_instr_pack(&devinfo, &instr, &packed);
```

### 3. 명령어 버퍼에 저장
```c
uint64_t qpu_code[256];
qpu_code[0] = packed_instr_0;
qpu_code[1] = packed_instr_1;
// ...
```

### 4. GPU에 제출 (실제 실행 - 커널 필요)
```c
// DRM ioctl을 통해 QPU 코드를 GPU에 제출
// 이 부분은 커널 드라이버(/dev/dri/renderD128)가 필요합니다
struct drm_v3d_submit_csd submit = {
    .cfg = {
        .num_batches = 1,
        .wg_size = 16,  // 16-way SIMD
    },
    .bo_handles = ...,  // GPU 메모리 핸들
    .perfmon_id = 0,
};
ioctl(fd, DRM_IOCTL_V3D_SUBMIT_CSD, &submit);
```

## QPU vs VIR vs NIR

medusa 프로젝트의 컴파일 계층:

```
SPIR-V (Vulkan Shader)
    ↓
NIR (하드웨어 독립적 중간 표현)
    ↓
VIR (V3D 중간 표현 - 가상 레지스터)
    ↓
QPU (실제 하드웨어 명령어)
```

- **NIR**: 범용 최적화, 하드웨어 독립적
- **VIR**: V3D 전용, 가상 레지스터 무제한 사용
- **QPU**: 실제 하드웨어 명령어, 제한된 레지스터 (64개)

## 주의사항

### 1. Delay Slots
QPU는 파이프라인 아키텍처이므로 특정 명령어 이후 delay slot이 필요:
```c
thrsw   // 스레드 종료
nop     // delay slot 1
nop     // delay slot 2
```

### 2. TMU Latency
TMU 읽기/쓰기는 비동기적:
```c
tmua = address  // 읽기 시작
// ... 다른 명령어 실행 가능
ldtmu           // 읽기 완료 대기
```

### 3. 16-way SIMD
모든 연산은 16개 레인에서 동시 실행:
```c
r0 = r1 + r2  // 실제로는 16개의 덧셈이 동시 발생
// r0[0] = r1[0] + r2[0]
// r0[1] = r1[1] + r2[1]
// ...
// r0[15] = r1[15] + r2[15]
```

## 참고 자료

### medusa 소스 코드
- `medusa/broadcom/qpu/qpu_instr.h`: QPU 명령어 정의
- `medusa/broadcom/qpu/qpu_pack.c`: 명령어 인코딩
- `medusa/broadcom/qpu/qpu_disasm.c`: 디스어셈블러
- `medusa/broadcom/compiler/vir_to_qpu.c`: VIR → QPU 변환

### V3D 문서
- Broadcom VideoCore VI/VII Architecture Manual
- Raspberry Pi 5 Datasheet (BCM2712)

## 빌드 및 실행

```bash
# 최소 예제 실행
gcc -I.. qpu_minimal.c -o qpu_minimal
./qpu_minimal

# 벡터 덧셈 예제 (전체 빌드)
cd medusa
mkdir build && cd build
cmake ..
make

# 예제 실행
./examples/qpu_simple_add
```

## 다음 단계

실제 QPU 실행을 위해서는:
1. **V3D DRM 커널 드라이버** 설치 (Raspberry Pi OS에 포함)
2. **GPU 메모리 할당** (DRM BO API 사용)
3. **CSD (Compute Shader Dispatch)** ioctl 호출
4. **결과 읽기 및 검증**

더 복잡한 예제는 `medusa/broadcom/vulkan/v3dv_cmd_buffer.c`의 컴퓨트 셰이더 구현을 참고하세요.
