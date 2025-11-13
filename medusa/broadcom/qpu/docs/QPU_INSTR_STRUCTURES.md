# QPU Instruction Structures Documentation

## 개요

이 문서는 `qpu_instr.h` 파일에 정의된 VideoCore V3D QPU (Quad Processing Unit) 명령어 관련 자료구조들을 상세히 설명합니다. 이 자료구조들은 64비트 QPU 명령어의 언팩(unpacked) 형태를 나타내며, 어셈블리와 디스어셈블리 작업에서 사용됩니다.

## 주요 자료구조

### 1. `struct v3d_qpu_sig` (Signal Bits)

QPU 명령어의 시그널 비트들을 나타내는 구조체입니다. 각 필드는 1비트 boolean 값입니다.

```c
struct v3d_qpu_sig {
    bool thrsw:1;        // Thread switch
    bool ldunif:1;       // Load uniform
    bool ldunifa:1;      // Load uniform address
    bool ldunifrf:1;     // Load uniform to register file
    bool ldunifarf:1;    // Load uniform address to register file
    bool ldtmu:1;        // Load from TMU (Texture Memory Unit)
    bool ldvary:1;       // Load varying
    bool ldvpm:1;        // Load from VPM (Vertex Pipe Memory)
    bool ldtlb:1;        // Load from TLB (Tile Buffer)
    bool ldtlbu:1;       // Load from TLB unsigned
    bool ucb:1;          // Uniform control bit
    bool rotate:1;       // Rotate operation
    bool wrtmuc:1;       // Write TMU cache
    bool small_imm_a:1;  // Small immediate for raddr_a (V3D 7.x)
    bool small_imm_b:1;  // Small immediate for raddr_b
    bool small_imm_c:1;  // Small immediate for raddr_c (V3D 7.x)
    bool small_imm_d:1;  // Small immediate for raddr_d (V3D 7.x)
};
```

**용도**:
- 메모리 로드/스토어 작업 제어
- 스레드 스위칭
- 즉시값(immediate) 사용 지정

---

### 2. `enum v3d_qpu_cond` (Condition Codes)

조건부 실행을 위한 조건 코드입니다.

```c
enum v3d_qpu_cond {
    V3D_QPU_COND_NONE,   // 무조건 실행
    V3D_QPU_COND_IFA,    // Flag A가 true일 때
    V3D_QPU_COND_IFB,    // Flag B가 true일 때
    V3D_QPU_COND_IFNA,   // Flag A가 false일 때
    V3D_QPU_COND_IFNB,   // Flag B가 false일 때
};
```

---

### 3. `enum v3d_qpu_pf` (Push Flags)

플래그 스택에 값을 푸시하는 조건입니다.

```c
enum v3d_qpu_pf {
    V3D_QPU_PF_NONE,     // 플래그 푸시 없음
    V3D_QPU_PF_PUSHZ,    // Zero 플래그 푸시
    V3D_QPU_PF_PUSHN,    // Negative 플래그 푸시
    V3D_QPU_PF_PUSHC,    // Carry 플래그 푸시
};
```

---

### 4. `enum v3d_qpu_uf` (Update Flags)

플래그 업데이트 모드를 지정합니다.

```c
enum v3d_qpu_uf {
    V3D_QPU_UF_NONE,     // 업데이트 없음
    V3D_QPU_UF_ANDZ,     // AND with zero flag
    V3D_QPU_UF_ANDNZ,    // AND with not-zero flag
    V3D_QPU_UF_NORNZ,    // NOR with not-zero flag
    V3D_QPU_UF_NORZ,     // NOR with zero flag
    V3D_QPU_UF_ANDN,     // AND with negative flag
    V3D_QPU_UF_ANDNN,    // AND with not-negative flag
    V3D_QPU_UF_NORNN,    // NOR with not-negative flag
    V3D_QPU_UF_NORN,     // NOR with negative flag
    V3D_QPU_UF_ANDC,     // AND with carry flag
    V3D_QPU_UF_ANDNC,    // AND with not-carry flag
    V3D_QPU_UF_NORNC,    // NOR with not-carry flag
    V3D_QPU_UF_NORC,     // NOR with carry flag
};
```

---

### 5. `enum v3d_qpu_waddr` (Write Address)

쓰기 주소를 지정하는 열거형입니다. 레지스터 파일과 특수 레지스터를 포함합니다.

```c
enum v3d_qpu_waddr {
    // 일반 레지스터 (V3D 4.x, V3D 7.x에서는 예약됨)
    V3D_QPU_WADDR_R0 = 0,
    V3D_QPU_WADDR_R1 = 1,
    V3D_QPU_WADDR_R2 = 2,
    V3D_QPU_WADDR_R3 = 3,
    V3D_QPU_WADDR_R4 = 4,
    V3D_QPU_WADDR_R5 = 5,        // V3D 4.x
    V3D_QPU_WADDR_QUAD = 5,      // V3D 7.x

    // 특수 레지스터
    V3D_QPU_WADDR_NOP = 6,       // No operation
    V3D_QPU_WADDR_TLB = 7,       // Tile buffer
    V3D_QPU_WADDR_TLBU = 8,      // Tile buffer unsigned
    V3D_QPU_WADDR_TMU = 9,       // Texture unit (V3D 3.x)
    V3D_QPU_WADDR_UNIFA = 9,     // Uniform address (V3D 4.x)
    V3D_QPU_WADDR_TMUL = 10,     // TMU lookup
    V3D_QPU_WADDR_TMUD = 11,     // TMU data
    V3D_QPU_WADDR_TMUA = 12,     // TMU address
    V3D_QPU_WADDR_TMUAU = 13,    // TMU address unsigned
    V3D_QPU_WADDR_VPM = 14,      // Vertex pipe memory
    V3D_QPU_WADDR_VPMU = 15,     // VPM unsigned
    V3D_QPU_WADDR_SYNC = 16,     // Synchronization
    V3D_QPU_WADDR_SYNCU = 17,
    V3D_QPU_WADDR_SYNCB = 18,

    // SFU (Special Function Unit) - V3D 7.x에서는 예약됨
    V3D_QPU_WADDR_RECIP = 19,    // Reciprocal
    V3D_QPU_WADDR_RSQRT = 20,    // Reciprocal square root
    V3D_QPU_WADDR_EXP = 21,      // Exponential
    V3D_QPU_WADDR_LOG = 22,      // Logarithm
    V3D_QPU_WADDR_SIN = 23,      // Sine
    V3D_QPU_WADDR_RSQRT2 = 24,   // Reciprocal sqrt (alternative)

    // TMU 구성 레지스터
    V3D_QPU_WADDR_TMUC = 32,     // TMU config
    V3D_QPU_WADDR_TMUS = 33,     // TMU stride
    V3D_QPU_WADDR_TMUT = 34,     // TMU type
    V3D_QPU_WADDR_TMUR = 35,     // TMU read
    V3D_QPU_WADDR_TMUI = 36,     // TMU image
    V3D_QPU_WADDR_TMUB = 37,     // TMU border
    V3D_QPU_WADDR_TMUDREF = 38,  // TMU depth reference
    V3D_QPU_WADDR_TMUOFF = 39,   // TMU offset
    V3D_QPU_WADDR_TMUSCM = 40,   // TMU S coordinate mode
    V3D_QPU_WADDR_TMUSF = 41,    // TMU S filter
    V3D_QPU_WADDR_TMUSLOD = 42,  // TMU S LOD
    // ... (더 많은 TMU 레지스터)

    V3D_QPU_WADDR_R5REP = 55,    // R5 replicate (V3D 4.x)
    V3D_QPU_WADDR_REP = 55,      // Replicate (V3D 7.x)
};
```

---

### 6. `struct v3d_qpu_flags`

ADD와 MUL 파이프라인의 플래그 조건을 저장합니다.

```c
struct v3d_qpu_flags {
    enum v3d_qpu_cond ac, mc;    // ADD/MUL 조건 코드
    enum v3d_qpu_pf apf, mpf;    // ADD/MUL 푸시 플래그
    enum v3d_qpu_uf auf, muf;    // ADD/MUL 업데이트 플래그
};
```

---

### 7. `enum v3d_qpu_add_op` (ADD ALU Operations)

ADD ALU에서 수행할 수 있는 연산들입니다.

```c
enum v3d_qpu_add_op {
    // 산술 연산
    V3D_QPU_A_FADD,      // Floating-point add
    V3D_QPU_A_FSUB,      // Floating-point subtract
    V3D_QPU_A_ADD,       // Integer add
    V3D_QPU_A_SUB,       // Integer subtract
    V3D_QPU_A_MIN,       // Minimum
    V3D_QPU_A_MAX,       // Maximum
    V3D_QPU_A_UMIN,      // Unsigned minimum
    V3D_QPU_A_UMAX,      // Unsigned maximum
    V3D_QPU_A_FMIN,      // Floating-point minimum
    V3D_QPU_A_FMAX,      // Floating-point maximum

    // 비트 연산
    V3D_QPU_A_SHL,       // Shift left
    V3D_QPU_A_SHR,       // Shift right
    V3D_QPU_A_ASR,       // Arithmetic shift right
    V3D_QPU_A_ROR,       // Rotate right
    V3D_QPU_A_AND,       // Bitwise AND
    V3D_QPU_A_OR,        // Bitwise OR
    V3D_QPU_A_XOR,       // Bitwise XOR
    V3D_QPU_A_NOT,       // Bitwise NOT

    // 벡터 연산
    V3D_QPU_A_VADD,      // Vector add
    V3D_QPU_A_VSUB,      // Vector subtract
    V3D_QPU_A_VFPACK,    // Vector float pack
    V3D_QPU_A_VFMIN,     // Vector float minimum
    V3D_QPU_A_VFMAX,     // Vector float maximum (V3D 7.x)

    // 변환 연산
    V3D_QPU_A_FTOIN,     // Float to integer
    V3D_QPU_A_ITOF,      // Integer to float
    V3D_QPU_A_FTRUNC,    // Float truncate
    V3D_QPU_A_FTOIZ,     // Float to integer (zero)
    V3D_QPU_A_FFLOOR,    // Float floor
    V3D_QPU_A_FTOUZ,     // Float to unsigned (zero)
    V3D_QPU_A_FCEIL,     // Float ceiling
    V3D_QPU_A_FTOC,      // Float to clipped
    V3D_QPU_A_UTOF,      // Unsigned to float
    V3D_QPU_A_FROUND,    // Float round

    // 특수 함수
    V3D_QPU_A_RECIP,     // Reciprocal
    V3D_QPU_A_RSQRT,     // Reciprocal square root
    V3D_QPU_A_EXP,       // Exponential
    V3D_QPU_A_LOG,       // Logarithm
    V3D_QPU_A_SIN,       // Sine
    V3D_QPU_A_RSQRT2,    // Reciprocal square root (v2)

    // 플래그 연산
    V3D_QPU_A_FLAPUSH,   // Flag A push
    V3D_QPU_A_FLBPUSH,   // Flag B push
    V3D_QPU_A_FLPOP,     // Flag pop
    V3D_QPU_A_VFLA,      // Vector flag A
    V3D_QPU_A_VFLNA,     // Vector flag not A
    V3D_QPU_A_VFLB,      // Vector flag B
    V3D_QPU_A_VFLNB,     // Vector flag not B

    // 시스템/제어
    V3D_QPU_A_NOP,       // No operation
    V3D_QPU_A_TIDX,      // Thread index
    V3D_QPU_A_EIDX,      // Element index
    V3D_QPU_A_IID,       // Instance ID
    V3D_QPU_A_SAMPID,    // Sample ID
    V3D_QPU_A_BARRIERID, // Barrier ID

    // 좌표 연산
    V3D_QPU_A_FXCD,      // Fragment X coordinate (derivative)
    V3D_QPU_A_XCD,       // X coordinate
    V3D_QPU_A_FYCD,      // Fragment Y coordinate (derivative)
    V3D_QPU_A_YCD,       // Y coordinate
    V3D_QPU_A_FDX,       // Derivative X
    V3D_QPU_A_FDY,       // Derivative Y

    // VPM 연산
    V3D_QPU_A_VPMSETUP,  // VPM setup
    V3D_QPU_A_VPMWT,     // VPM wait
    V3D_QPU_A_LDVPMV_IN, // Load VPM vector input
    V3D_QPU_A_LDVPMV_OUT,// Load VPM vector output
    V3D_QPU_A_LDVPMD_IN, // Load VPM data input
    V3D_QPU_A_LDVPMD_OUT,// Load VPM data output
    V3D_QPU_A_LDVPMP,    // Load VPM pointer
    V3D_QPU_A_LDVPMG_IN, // Load VPM group input
    V3D_QPU_A_LDVPMG_OUT,// Load VPM group output
    V3D_QPU_A_STVPMV,    // Store VPM vector
    V3D_QPU_A_STVPMD,    // Store VPM data
    V3D_QPU_A_STVPMP,    // Store VPM pointer

    // 기타
    V3D_QPU_A_SETMSF,    // Set multisample flag
    V3D_QPU_A_SETREVF,   // Set reverse flag
    V3D_QPU_A_MSF,       // Multisample flag
    V3D_QPU_A_REVF,      // Reverse flag
    V3D_QPU_A_VDWWT,     // VDW wait
    V3D_QPU_A_TMUWT,     // TMU wait
    V3D_QPU_A_CLZ,       // Count leading zeros
    V3D_QPU_A_FCMP,      // Float compare
    V3D_QPU_A_LR,        // Link register
    V3D_QPU_A_FLAFIRST,  // First flag A
    V3D_QPU_A_FLNAFIRST, // First flag not A

    // V3D 7.x 전용 연산
    V3D_QPU_A_FMOV,      // Float move
    V3D_QPU_A_MOV,       // Move
    V3D_QPU_A_VPACK,     // Vector pack
    V3D_QPU_A_V8PACK,    // 8-bit vector pack
    V3D_QPU_A_V10PACK,   // 10-bit vector pack
    V3D_QPU_A_V11FPACK,  // 11-bit float vector pack
    V3D_QPU_A_BALLOT,    // Ballot (vote)
    V3D_QPU_A_BCASTF,    // Broadcast float
    V3D_QPU_A_ALLEQ,     // All equal
    V3D_QPU_A_ALLFEQ,    // All float equal
    V3D_QPU_A_ROTQ,      // Rotate quad
    V3D_QPU_A_ROT,       // Rotate
    V3D_QPU_A_SHUFFLE,   // Shuffle
};
```

---

### 8. `enum v3d_qpu_mul_op` (MUL ALU Operations)

MUL ALU에서 수행할 수 있는 연산들입니다.

```c
enum v3d_qpu_mul_op {
    V3D_QPU_M_ADD,       // Integer add
    V3D_QPU_M_SUB,       // Integer subtract
    V3D_QPU_M_UMUL24,    // Unsigned 24-bit multiply
    V3D_QPU_M_SMUL24,    // Signed 24-bit multiply
    V3D_QPU_M_FMUL,      // Floating-point multiply
    V3D_QPU_M_VFMUL,     // Vector float multiply
    V3D_QPU_M_MULTOP,    // Multiple operations
    V3D_QPU_M_FMOV,      // Float move
    V3D_QPU_M_MOV,       // Move
    V3D_QPU_M_NOP,       // No operation

    // V3D 7.x 전용 연산
    V3D_QPU_M_FTOUNORM16,    // Float to unsigned normalized 16-bit
    V3D_QPU_M_FTOSNORM16,    // Float to signed normalized 16-bit
    V3D_QPU_M_VFTOUNORM8,    // Vector float to unsigned norm 8-bit
    V3D_QPU_M_VFTOSNORM8,    // Vector float to signed norm 8-bit
    V3D_QPU_M_VFTOUNORM10LO, // Vector float to unorm 10-bit low
    V3D_QPU_M_VFTOUNORM10HI, // Vector float to unorm 10-bit high
};
```

---

### 9. `enum v3d_qpu_output_pack` (Output Packing)

출력 결과를 패킹하는 방식을 지정합니다.

```c
enum v3d_qpu_output_pack {
    V3D_QPU_PACK_NONE,   // 패킹 없음
    V3D_QPU_PACK_L,      // 16비트 float로 변환, 하위 16비트에 저장
    V3D_QPU_PACK_H,      // 16비트 float로 변환, 상위 16비트에 저장
};
```

---

### 10. `enum v3d_qpu_input_unpack` (Input Unpacking)

입력 데이터를 언팩하는 방식을 지정합니다.

```c
enum v3d_qpu_input_unpack {
    V3D_QPU_UNPACK_NONE,           // 언팩 없음
    V3D_QPU_UNPACK_ABS,            // 절댓값
    V3D_QPU_UNPACK_L,              // 하위 16비트를 32비트 float로 변환
    V3D_QPU_UNPACK_H,              // 상위 16비트를 32비트 float로 변환

    // V3D 7.1 포화 연산
    V3D71_QPU_UNPACK_SAT,          // [0.0, 1.0]로 포화
    V3D71_QPU_UNPACK_NSAT,         // [-1.0, 1.0]로 포화
    V3D71_QPU_UNPACK_MAX0,         // [0.0, +inf]로 포화

    // 복제 연산
    V3D_QPU_UNPACK_REPLICATE_32F_16, // 16f로 변환 후 상위 비트에 복제
    V3D_QPU_UNPACK_REPLICATE_L_16,   // 하위 16비트를 상위로 복제
    V3D_QPU_UNPACK_REPLICATE_H_16,   // 상위 16비트를 하위로 복제
    V3D_QPU_UNPACK_SWAP_16,          // 상위/하위 16비트 교환

    // 정수 변환
    V3D_QPU_UNPACK_UL,             // 하위 16비트를 unsigned 32비트로
    V3D_QPU_UNPACK_UH,             // 상위 16비트를 unsigned 32비트로
    V3D_QPU_UNPACK_IL,             // 하위 16비트를 signed 32비트로
    V3D_QPU_UNPACK_IH,             // 상위 16비트를 signed 32비트로
};
```

---

### 11. `enum v3d_qpu_mux` (Multiplexer Selection)

레지스터 파일 멀티플렉서를 선택합니다 (V3D 4.x).

```c
enum v3d_qpu_mux {
    V3D_QPU_MUX_R0,   // Register file 0
    V3D_QPU_MUX_R1,   // Register file 1
    V3D_QPU_MUX_R2,   // Register file 2
    V3D_QPU_MUX_R3,   // Register file 3
    V3D_QPU_MUX_R4,   // Register file 4
    V3D_QPU_MUX_R5,   // Register file 5
    V3D_QPU_MUX_A,    // ADD ALU 출력
    V3D_QPU_MUX_B,    // MUL ALU 출력
};
```

---

### 12. `struct v3d_qpu_input`

ALU 입력을 나타냅니다.

```c
struct v3d_qpu_input {
    union {
        enum v3d_qpu_mux mux;   // V3D 4.x: 멀티플렉서 선택
        uint8_t raddr;          // V3D 7.x: 레지스터 주소
    };
    enum v3d_qpu_input_unpack unpack; // 입력 언팩 모드
};
```

**특징**:
- V3D 4.x와 7.x에서 다른 방식으로 레지스터를 참조
- 언팩 모드를 통해 입력 데이터 변환 가능

---

### 13. `struct v3d_qpu_alu_instr` (ALU Instruction)

ALU 명령어를 나타내는 구조체입니다. ADD와 MUL 파이프라인을 모두 포함합니다.

```c
struct v3d_qpu_alu_instr {
    struct {
        enum v3d_qpu_add_op op;          // ADD 연산
        struct v3d_qpu_input a, b;       // 입력 operand A, B
        uint8_t waddr;                   // 쓰기 주소
        bool magic_write;                // 특수 레지스터 쓰기 여부
        enum v3d_qpu_output_pack output_pack; // 출력 패킹
    } add;

    struct {
        enum v3d_qpu_mul_op op;          // MUL 연산
        struct v3d_qpu_input a, b;       // 입력 operand A, B
        uint8_t waddr;                   // 쓰기 주소
        bool magic_write;                // 특수 레지스터 쓰기 여부
        enum v3d_qpu_output_pack output_pack; // 출력 패킹
    } mul;
};
```

**특징**:
- QPU는 ADD와 MUL 두 개의 ALU를 병렬로 실행 가능
- 각 파이프라인은 독립적인 입력, 연산, 출력을 가짐

---

### 14. Branch 관련 열거형

#### `enum v3d_qpu_branch_cond` (Branch Condition)

```c
enum v3d_qpu_branch_cond {
    V3D_QPU_BRANCH_COND_ALWAYS,   // 무조건 분기
    V3D_QPU_BRANCH_COND_A0,       // Flag A[0]이 true
    V3D_QPU_BRANCH_COND_NA0,      // Flag A[0]이 false
    V3D_QPU_BRANCH_COND_ALLA,     // 모든 Flag A가 true
    V3D_QPU_BRANCH_COND_ANYNA,    // 하나라도 Flag A가 false
    V3D_QPU_BRANCH_COND_ANYA,     // 하나라도 Flag A가 true
    V3D_QPU_BRANCH_COND_ALLNA,    // 모든 Flag A가 false
};
```

#### `enum v3d_qpu_msfign` (Multisample Flag Ignore)

```c
enum v3d_qpu_msfign {
    V3D_QPU_MSFIGN_NONE,  // 멀티샘플 플래그 무시 안 함
    V3D_QPU_MSFIGN_P,     // 레인에 플래그가 없으면 무시 (FS: pixel, VS: vertex)
    V3D_QPU_MSFIGN_Q,     // 2x2 쿼드에 플래그가 없으면 무시 (FS only)
};
```

#### `enum v3d_qpu_branch_dest` (Branch Destination)

```c
enum v3d_qpu_branch_dest {
    V3D_QPU_BRANCH_DEST_ABS,      // 절대 주소
    V3D_QPU_BRANCH_DEST_REL,      // 상대 주소
    V3D_QPU_BRANCH_DEST_LINK_REG, // 링크 레지스터
    V3D_QPU_BRANCH_DEST_REGFILE,  // 레지스터 파일
};
```

---

### 15. `struct v3d_qpu_branch_instr` (Branch Instruction)

분기 명령어를 나타냅니다.

```c
struct v3d_qpu_branch_instr {
    enum v3d_qpu_branch_cond cond;   // 분기 조건
    enum v3d_qpu_msfign msfign;      // 멀티샘플 플래그 무시 모드

    enum v3d_qpu_branch_dest bdi;    // 명령어 포인터 분기 방식
    enum v3d_qpu_branch_dest bdu;    // Uniform 포인터 분기 방식

    bool ub;                         // Uniform 분기 활성화
    uint8_t raddr_a;                 // 읽기 주소 A
    uint32_t offset;                 // 분기 오프셋
};
```

**용도**:
- 조건부/무조건 분기
- 루프 구현
- 함수 호출/리턴

---

### 16. `enum v3d_qpu_instr_type` (Instruction Type)

```c
enum v3d_qpu_instr_type {
    V3D_QPU_INSTR_TYPE_ALU,    // ALU 명령어
    V3D_QPU_INSTR_TYPE_BRANCH, // 분기 명령어
};
```

---

### 17. `struct v3d_qpu_instr` (QPU Instruction - 최상위 구조체)

완전한 QPU 명령어를 나타내는 최상위 구조체입니다.

```c
struct v3d_qpu_instr {
    enum v3d_qpu_instr_type type;    // 명령어 타입 (ALU/Branch)

    struct v3d_qpu_sig sig;          // 시그널 비트
    uint8_t sig_addr;                // 시그널 주소
    bool sig_magic;                  // 시그널의 magic 주소 쓰기 여부
    uint8_t raddr_a;                 // 읽기 주소 A (V3D 4.x)
    uint8_t raddr_b;                 // 읽기 주소 B (V3D 4.x, 7.x에서는 small imm)
    struct v3d_qpu_flags flags;      // 플래그 조건

    union {
        struct v3d_qpu_alu_instr alu;      // ALU 명령어
        struct v3d_qpu_branch_instr branch; // 분기 명령어
    };
};
```

**특징**:
- 64비트 명령어의 언팩된 형태
- ALU 또는 Branch 명령어를 union으로 포함
- 시그널, 플래그, 레지스터 주소 등 모든 제어 정보 포함

---

## 주요 함수 프로토타입

파일에는 다음과 같은 유틸리티 함수들도 선언되어 있습니다:

### 이름 변환 함수
- `v3d_qpu_magic_waddr_name()` - 특수 쓰기 주소의 이름 반환
- `v3d_qpu_add_op_name()` - ADD 연산 이름 반환
- `v3d_qpu_mul_op_name()` - MUL 연산 이름 반환
- `v3d_qpu_cond_name()` - 조건 이름 반환
- `v3d_qpu_pf_name()` - Push flag 이름 반환
- `v3d_qpu_uf_name()` - Update flag 이름 반환
- `v3d_qpu_pack_name()` - 출력 팩 이름 반환
- `v3d_qpu_unpack_name()` - 입력 언팩 이름 반환
- `v3d_qpu_branch_cond_name()` - 분기 조건 이름 반환
- `v3d_qpu_msfign_name()` - 멀티샘플 플래그 무시 모드 이름 반환

### 인코딩/디코딩 함수
- `v3d_qpu_sig_pack()` / `v3d_qpu_sig_unpack()` - 시그널 패킹/언팩
- `v3d_qpu_flags_pack()` / `v3d_qpu_flags_unpack()` - 플래그 패킹/언팩
- `v3d_qpu_small_imm_pack()` / `v3d_qpu_small_imm_unpack()` - 즉시값 패킹/언팩
- `v3d_qpu_instr_pack()` / `v3d_qpu_instr_unpack()` - 명령어 패킹/언팩

### 명령어 분석 함수
- `v3d_qpu_add_op_has_dst()` - ADD 연산이 목적지를 가지는지 확인
- `v3d_qpu_mul_op_has_dst()` - MUL 연산이 목적지를 가지는지 확인
- `v3d_qpu_add_op_num_src()` - ADD 연산의 소스 operand 개수
- `v3d_qpu_mul_op_num_src()` - MUL 연산의 소스 operand 개수
- `v3d_qpu_cond_invert()` - 조건 반전

### 특수 레지스터 확인 함수
- `v3d_qpu_magic_waddr_is_sfu()` - SFU 레지스터 여부
- `v3d_qpu_magic_waddr_is_tmu()` - TMU 레지스터 여부
- `v3d_qpu_magic_waddr_is_tlb()` - TLB 레지스터 여부
- `v3d_qpu_magic_waddr_is_vpm()` - VPM 레지스터 여부
- `v3d_qpu_magic_waddr_is_tsy()` - TSY 레지스터 여부
- `v3d_qpu_magic_waddr_loads_unif()` - Uniform 로드 여부

### 명령어 특성 확인 함수
- `v3d_qpu_reads_tlb()` - TLB 읽기 여부
- `v3d_qpu_writes_tlb()` - TLB 쓰기 여부
- `v3d_qpu_uses_tlb()` - TLB 사용 여부
- `v3d_qpu_instr_is_sfu()` - SFU 명령어 여부
- `v3d_qpu_instr_is_legacy_sfu()` - 레거시 SFU 명령어 여부
- `v3d_qpu_uses_sfu()` - SFU 사용 여부
- `v3d_qpu_writes_tmu()` - TMU 쓰기 여부
- `v3d_qpu_writes_r3()` / `v3d_qpu_writes_r4()` / `v3d_qpu_writes_r5()` - 레지스터 쓰기 여부
- `v3d_qpu_writes_rf0_implicitly()` - RF0 암시적 쓰기 여부
- `v3d_qpu_writes_accum()` - Accumulator 쓰기 여부
- `v3d_qpu_waits_on_tmu()` - TMU 대기 여부
- `v3d_qpu_uses_mux()` - 특정 MUX 사용 여부
- `v3d_qpu_uses_vpm()` - VPM 사용 여부
- `v3d_qpu_waits_vpm()` - VPM 대기 여부
- `v3d_qpu_reads_vpm()` - VPM 읽기 여부
- `v3d_qpu_writes_vpm()` - VPM 쓰기 여부
- `v3d_qpu_reads_or_writes_vpm()` - VPM 읽기/쓰기 여부
- `v3d_qpu_reads_flags()` - 플래그 읽기 여부
- `v3d_qpu_writes_flags()` - 플래그 쓰기 여부
- `v3d_qpu_writes_unifa()` - UNIFA 쓰기 여부
- `v3d_qpu_sig_writes_address()` - 시그널이 주소를 쓰는지 여부
- `v3d_qpu_unpacks_f32()` - 32비트 float 언팩 여부
- `v3d_qpu_unpacks_f16()` - 16비트 float 언팩 여부
- `v3d_qpu_is_nop()` - NOP 명령어 여부

### V3D 7.x 전용 함수
- `v3d71_qpu_reads_raddr()` - 특정 raddr 읽기 여부
- `v3d71_qpu_writes_waddr_explicitly()` - 특정 waddr 명시적 쓰기 여부

---

## 사용 예시

### ALU 명령어 생성

```c
struct v3d_qpu_instr instr = {
    .type = V3D_QPU_INSTR_TYPE_ALU,
    .sig = {0},  // 모든 시그널 비트 0
    .flags = {
        .ac = V3D_QPU_COND_NONE,
        .mc = V3D_QPU_COND_NONE,
        .apf = V3D_QPU_PF_NONE,
        .mpf = V3D_QPU_PF_NONE,
        .auf = V3D_QPU_UF_NONE,
        .muf = V3D_QPU_UF_NONE,
    },
    .alu = {
        .add = {
            .op = V3D_QPU_A_FADD,
            .a = { .mux = V3D_QPU_MUX_R0, .unpack = V3D_QPU_UNPACK_NONE },
            .b = { .mux = V3D_QPU_MUX_R1, .unpack = V3D_QPU_UNPACK_NONE },
            .waddr = V3D_QPU_WADDR_R2,
            .magic_write = false,
            .output_pack = V3D_QPU_PACK_NONE,
        },
        .mul = {
            .op = V3D_QPU_M_NOP,
        },
    },
};
```

### 분기 명령어 생성

```c
struct v3d_qpu_instr branch_instr = {
    .type = V3D_QPU_INSTR_TYPE_BRANCH,
    .sig = {0},
    .branch = {
        .cond = V3D_QPU_BRANCH_COND_ALWAYS,
        .msfign = V3D_QPU_MSFIGN_NONE,
        .bdi = V3D_QPU_BRANCH_DEST_REL,
        .bdu = V3D_QPU_BRANCH_DEST_ABS,
        .ub = false,
        .raddr_a = 0,
        .offset = 0x100,
    },
};
```

---

## V3D 버전별 차이점

### V3D 4.x vs V3D 7.x

| 기능 | V3D 4.x | V3D 7.x |
|------|---------|---------|
| 레지스터 참조 | MUX 사용 | raddr 직접 사용 |
| Small immediate | `small_imm_b`만 지원 | `small_imm_a/b/c/d` 모두 지원 |
| R0-R4 레지스터 | 사용 가능 | 예약됨 (Reserved) |
| SFU 명령어 | WADDR로 트리거 | ADD ALU 명령어로 실행 |
| QUAD 레지스터 | 없음 | V3D_QPU_WADDR_QUAD (=5) |

---

## 요약

이 헤더 파일은 Broadcom VideoCore V3D GPU의 QPU 명령어 셋 아키텍처를 C 구조체로 표현합니다. 주요 특징:

1. **이중 ALU 파이프라인**: ADD와 MUL을 병렬 실행 가능
2. **풍부한 연산 세트**: 산술, 논리, 벡터, 변환, 특수 함수 등
3. **유연한 I/O**: 입력 언팩, 출력 팩킹 지원
4. **조건부 실행**: 플래그 기반 조건부 실행
5. **시그널 비트**: 메모리 로드/스토어, 스레드 제어
6. **버전 호환성**: V3D 4.x와 7.x 모두 지원

이 구조체들은 QPU 어셈블러/디스어셈블러, 컴파일러, 디버거 등에서 사용됩니다.
