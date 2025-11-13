# sig_addr 필드 상세 설명

## 개요

`sig_addr`는 `v3d_qpu_instr` 구조체의 필드로, **시그널 비트가 데이터를 로드/저장할 때 사용할 주소**를 지정합니다.

```c
struct v3d_qpu_instr {
    enum v3d_qpu_instr_type type;

    struct v3d_qpu_sig sig;     // 시그널 비트
    uint8_t sig_addr;           // ← 시그널 주소 (0-255)
    bool sig_magic;             // magic 주소 여부
    uint8_t raddr_a;
    uint8_t raddr_b;
    struct v3d_qpu_flags flags;

    union {
        struct v3d_qpu_alu_instr alu;
        struct v3d_qpu_branch_instr branch;
    };
};
```

---

## sig_addr의 역할

### 기본 개념

`sig_addr`는 **시그널이 레지스터 주소를 필요로 할 때 사용**됩니다:

```
시그널 비트 설정 → sig_addr로 주소 지정 → 해당 주소로 데이터 로드/저장
```

### 언제 사용되는가?

`sig_addr`는 다음 시그널 비트들과 함께 사용됩니다:

| 시그널 비트 | sig_addr 사용 | 의미 |
|------------|--------------|------|
| `ldvary` | ✅ 사용 | Varying을 어느 레지스터로 로드할지 |
| `ldtmu` | ✅ 사용 | TMU 결과를 어느 레지스터로 로드할지 |
| `ldtlb` | ✅ 사용 | TLB 데이터를 어느 레지스터로 로드할지 |
| `ldtlbu` | ✅ 사용 | TLB 데이터(unsigned)를 어느 레지스터로 로드할지 |
| `ldunifrf` | ✅ 사용 | Uniform을 어느 레지스터 파일로 로드할지 |
| `ldunifarf` | ✅ 사용 | Uniform 주소를 어느 레지스터 파일로 로드할지 |
| `ldunif` | ❌ 사용 안 함 | 암묵적으로 r5로 로드 |
| `ldunifa` | ❌ 사용 안 함 | 암묵적 동작 |
| `ldvpm` | ❌ 사용 안 함 | VPM 설정으로 제어 |
| `thrsw` | ❌ 사용 안 함 | 주소 불필요 |

---

## sig_addr 사용 조건

### 조건 확인 함수

코드베이스에는 시그널이 주소를 사용하는지 확인하는 함수가 있습니다:

```c
bool v3d_qpu_sig_writes_address(const struct v3d_device_info *devinfo,
                                const struct v3d_qpu_sig *sig)
{
    if (devinfo->ver < 41)
        return false;

    return (sig->ldunifrf ||
            sig->ldunifarf ||
            sig->ldvary ||
            sig->ldtmu ||
            sig->ldtlb ||
            sig->ldtlbu);
}
```

**의미**:
- V3D 4.1+ 버전에서만 `sig_addr` 사용
- 위 6개 시그널 중 하나라도 설정되면 `sig_addr` 필요

---

## sig_magic 플래그

`sig_magic`는 `sig_addr`의 해석 방식을 결정합니다:

```c
bool sig_magic;  // If the signal writes to a magic address
```

### sig_magic = false (일반 레지스터 파일)

`sig_addr`를 **레지스터 파일 주소**로 해석합니다.

```c
// 예: TMU 결과를 rf32로 로드
instr.sig.ldtmu = true;
instr.sig_addr = 32;
instr.sig_magic = false;

// 디스어셈블리 출력:
// ; ldtmu.rf32
```

**범위**: 0 ~ 255 (레지스터 파일 주소)

---

### sig_magic = true (특수 레지스터)

`sig_addr`를 **magic 주소** (특수 레지스터)로 해석합니다.

```c
// 예: Varying을 특수 레지스터 r2로 로드
instr.sig.ldvary = true;
instr.sig_addr = V3D_QPU_WADDR_R2;  // = 2
instr.sig_magic = true;

// 디스어셈블리 출력:
// ; ldvary.r2
```

**가능한 값**: `enum v3d_qpu_waddr`에 정의된 magic 주소들

#### Magic 주소 예시

```c
enum v3d_qpu_waddr {
    V3D_QPU_WADDR_R0 = 0,    // Accumulator r0
    V3D_QPU_WADDR_R1 = 1,
    V3D_QPU_WADDR_R2 = 2,
    V3D_QPU_WADDR_R3 = 3,
    V3D_QPU_WADDR_R4 = 4,
    V3D_QPU_WADDR_R5 = 5,
    V3D_QPU_WADDR_NOP = 6,
    V3D_QPU_WADDR_TLB = 7,
    V3D_QPU_WADDR_UNIFA = 9,
    // ... 등등
};
```

---

## 디스어셈블리 출력

`sig_addr`는 디스어셈블리 시 다음과 같이 표시됩니다:

### 구현 코드

```c
static void v3d_qpu_disasm_sig_addr(struct disasm_state *disasm,
                                    const struct v3d_qpu_instr *instr)
{
    if (disasm->devinfo->ver < 41)
        return;

    if (!instr->sig_magic)
        append(disasm, ".rf%d", instr->sig_addr);
    else {
        const char *name =
            v3d_qpu_magic_waddr_name(disasm->devinfo,
                                     instr->sig_addr);
        if (name)
            append(disasm, ".%s", name);
        else
            append(disasm, ".UNKNOWN%d", instr->sig_addr);
    }
}
```

### 출력 예시

```assembly
; ldtmu.rf32       // sig_magic=false, sig_addr=32
; ldtmu.r2         // sig_magic=true, sig_addr=2 (V3D_QPU_WADDR_R2)
; ldvary.rf10      // sig_magic=false, sig_addr=10
; ldtlb.r3         // sig_magic=true, sig_addr=3
; ldunifrf.rf64    // sig_magic=false, sig_addr=64
```

---

## 사용 예시

### 예제 1: TMU 결과를 레지스터 파일로 로드

```c
struct v3d_qpu_instr instr = {
    .type = V3D_QPU_INSTR_TYPE_ALU,
    .sig = {
        .ldtmu = true,          // TMU 데이터 로드
    },
    .sig_addr = 42,             // rf42로 로드
    .sig_magic = false,         // 레지스터 파일 주소
    .alu = {
        .add.op = V3D_QPU_A_NOP,
        .mul.op = V3D_QPU_M_NOP,
    },
};

// 어셈블리: nop  ; ldtmu.rf42
```

### 예제 2: Varying을 Accumulator로 로드

```c
struct v3d_qpu_instr instr = {
    .type = V3D_QPU_INSTR_TYPE_ALU,
    .sig = {
        .ldvary = true,               // Varying 로드
    },
    .sig_addr = V3D_QPU_WADDR_R3,     // r3로 로드 (= 3)
    .sig_magic = true,                // Magic 주소 (accumulator)
    .alu = {
        .add.op = V3D_QPU_A_FMOV,
        // ... add 연산 설정
    },
};

// 어셈블리: fmov ...  ; ldvary.r3
```

### 예제 3: TLB 데이터를 레지스터 파일로 로드

```c
struct v3d_qpu_instr instr = {
    .type = V3D_QPU_INSTR_TYPE_ALU,
    .sig = {
        .ldtlb = true,          // TLB 로드
    },
    .sig_addr = 100,            // rf100으로 로드
    .sig_magic = false,         // 레지스터 파일
    .alu = {
        .add.op = V3D_QPU_A_NOP,
        .mul.op = V3D_QPU_M_NOP,
    },
};

// 어셈블리: nop  ; ldtlb.rf100
```

### 예제 4: Uniform을 레지스터 파일로 로드 (V3D 7.x)

```c
struct v3d_qpu_instr instr = {
    .type = V3D_QPU_INSTR_TYPE_ALU,
    .sig = {
        .ldunifrf = true,       // Uniform → 레지스터 파일
    },
    .sig_addr = 16,             // rf16으로 로드
    .sig_magic = false,         // 레지스터 파일
    .alu = {
        .add.op = V3D_QPU_A_NOP,
        .mul.op = V3D_QPU_M_NOP,
    },
};

// 어셈블리: nop  ; ldunifrf.rf16
```

---

## sig_addr 동작 방식 요약

### 데이터 흐름도

```
┌─────────────────────────────────────────────────────────┐
│ 시그널 비트 설정                                          │
│ (ldtmu, ldvary, ldtlb, ldunifrf, etc.)                  │
└────────────────┬────────────────────────────────────────┘
                 │
                 v
┌─────────────────────────────────────────────────────────┐
│ sig_addr 값 확인                                         │
│ - sig_magic = false → 레지스터 파일 주소 (rf0~rf255)      │
│ - sig_magic = true  → Magic 주소 (r0~r5, 특수 레지스터)   │
└────────────────┬────────────────────────────────────────┘
                 │
                 v
┌─────────────────────────────────────────────────────────┐
│ 데이터 로드                                               │
│ 소스 → sig_addr가 가리키는 레지스터로 데이터 복사          │
│ - TMU: 텍스처 메모리 → 레지스터                           │
│ - Varying: 보간된 값 → 레지스터                           │
│ - TLB: 타일 버퍼 → 레지스터                               │
│ - Uniform: Uniform 스트림 → 레지스터                      │
└─────────────────────────────────────────────────────────┘
```

---

## 주요 사용 패턴

### 패턴 1: TMU 로드 (텍스처 샘플링)

```c
// 1단계: TMU 주소 쓰기
struct v3d_qpu_instr write_tmu = {
    .alu.add.waddr = V3D_QPU_WADDR_TMUA,
    .alu.add.magic_write = true,
    // ... 텍스처 좌표 설정
};

// 2단계: 스레드 전환
struct v3d_qpu_instr thrsw = {
    .sig.thrsw = true,
    // ...
};

// 3단계: TMU 결과 로드
struct v3d_qpu_instr load_tmu = {
    .sig.ldtmu = true,
    .sig_addr = 10,         // rf10으로 로드
    .sig_magic = false,
    // ...
};
```

### 패턴 2: Varying 로드 (프래그먼트 셰이더)

```c
struct v3d_qpu_instr load_varying = {
    .sig.ldvary = true,
    .sig_addr = V3D_QPU_WADDR_R2,  // r2로 로드
    .sig_magic = true,              // Accumulator 사용
    // ...
};
```

### 패턴 3: TLB 로드 (블렌딩)

```c
// 기존 픽셀 값을 읽어와서 블렌딩
struct v3d_qpu_instr load_pixel = {
    .sig.ldtlb = true,
    .sig_addr = 5,          // rf5로 로드
    .sig_magic = false,
    // ...
};
```

---

## V3D 버전별 차이

### V3D 4.0 이하
- `sig_addr` 지원 안 함
- 시그널은 암묵적 레지스터를 사용
- 예: `ldunif`는 항상 r5로 로드

### V3D 4.1+
- `sig_addr` 도입
- 명시적 주소 지정 가능
- 더 유연한 레지스터 할당

### V3D 7.x
- `ldunifrf`, `ldunifarf` 추가
- 더 많은 시그널이 `sig_addr` 사용

---

## 레지스터 파일 vs Accumulator

### 레지스터 파일 (RF)

```c
sig_magic = false;
sig_addr = 0~255;
```

**특징**:
- 256개의 레지스터 (rf0 ~ rf255)
- 큰 저장 공간
- 일반적인 데이터 저장에 사용

**사용 예**:
```c
// TMU 결과를 rf32에 저장
instr.sig.ldtmu = true;
instr.sig_addr = 32;
instr.sig_magic = false;
```

### Accumulator (r0 ~ r5)

```c
sig_magic = true;
sig_addr = V3D_QPU_WADDR_R0 ~ V3D_QPU_WADDR_R5;
```

**특징**:
- 6개의 특수 레지스터 (r0 ~ r5)
- ALU 출력으로도 사용됨
- 빠른 접근

**사용 예**:
```c
// Varying을 r3에 저장
instr.sig.ldvary = true;
instr.sig_addr = V3D_QPU_WADDR_R3;  // = 3
instr.sig_magic = true;
```

---

## 실제 사용 예시 (컴파일러에서)

### UNIFA 쓰기 확인

```c
// qpu_instr.c:862
if (v3d_qpu_sig_writes_address(devinfo, &inst->sig) &&
    inst->sig_magic &&
    inst->sig_addr == V3D_QPU_WADDR_UNIFA) {
    // Uniform 주소를 UNIFA에 쓰는 경우
    return true;
}
```

### 특정 Magic 주소 쓰기 확인

```c
// qpu_instr.c:907
if (v3d_qpu_sig_writes_address(devinfo, &inst->sig) &&
    inst->sig_magic && inst->sig_addr == waddr) {
    // 특정 magic 주소(waddr)에 쓰는 경우
    return true;
}
```

---

## 디버깅 체크리스트

`sig_addr` 관련 문제를 디버깅할 때:

- [ ] **V3D 버전 확인**: 4.1+ 버전인가?
- [ ] **시그널 비트 확인**: `v3d_qpu_sig_writes_address()`가 true를 반환하는 시그널인가?
- [ ] **sig_magic 설정**: 레지스터 파일 vs Accumulator 의도가 맞는가?
- [ ] **주소 범위 확인**:
  - `sig_magic = false`: 0 ~ 255 범위인가?
  - `sig_magic = true`: 유효한 `v3d_qpu_waddr` 값인가?
- [ ] **시그널 조합**: 한 명령어에 여러 주소 쓰기 시그널이 없는가?
- [ ] **디스어셈블리 확인**: 출력이 의도한 대로인가?

---

## 요약 테이블

| 항목 | 설명 |
|------|------|
| **타입** | `uint8_t` (0-255) |
| **용도** | 시그널이 데이터를 로드할 레지스터 주소 지정 |
| **사용 시그널** | `ldvary`, `ldtmu`, `ldtlb`, `ldtlbu`, `ldunifrf`, `ldunifarf` |
| **sig_magic=false** | 레지스터 파일 주소 (rf0~rf255) |
| **sig_magic=true** | Magic 주소 (r0~r5, 특수 레지스터) |
| **버전** | V3D 4.1+ |
| **디스어셈블리** | `.rf<N>` 또는 `.r<N>` 또는 `.특수이름` |

---

## 핵심 포인트

### ✅ sig_addr의 3가지 핵심 역할

1. **목적지 지정**: 시그널이 로드한 데이터를 어디에 저장할지
2. **주소 해석**: `sig_magic` 플래그와 함께 주소 타입 결정
3. **유연성 제공**: 프로그래머가 원하는 레지스터에 데이터 배치 가능

### ✅ 사용 조건

- V3D 4.1 이상 버전
- 주소가 필요한 시그널 (`ldvary`, `ldtmu`, `ldtlb`, `ldtlbu`, `ldunifrf`, `ldunifarf`)
- `sig_magic` 플래그와 함께 사용

### ✅ 대표적 사용 사례

```c
// TMU 샘플링 결과를 원하는 레지스터로
instr.sig.ldtmu = true;
instr.sig_addr = 42;
instr.sig_magic = false;  // rf42

// Varying을 Accumulator로
instr.sig.ldvary = true;
instr.sig_addr = V3D_QPU_WADDR_R3;
instr.sig_magic = true;   // r3
```

---

## 참고: 관련 함수

```c
// 시그널이 주소를 사용하는지 확인
bool v3d_qpu_sig_writes_address(
    const struct v3d_device_info *devinfo,
    const struct v3d_qpu_sig *sig
);

// Magic 주소 이름 얻기
const char *v3d_qpu_magic_waddr_name(
    const struct v3d_device_info *devinfo,
    enum v3d_qpu_waddr waddr
);

// 명령어 패킹/언패킹 시 sig_addr 처리
bool v3d_qpu_instr_pack(...);
bool v3d_qpu_instr_unpack(...);
```

---

## 결론

`sig_addr`는 QPU 명령어에서 **시그널이 데이터를 저장할 레지스터를 지정하는 핵심 필드**입니다. `sig_magic` 플래그와 함께 사용하여 레지스터 파일 또는 특수 레지스터(Accumulator)를 선택할 수 있으며, V3D 4.1 이상에서 더 유연한 레지스터 할당을 가능하게 합니다.

**핵심 기억 사항**:
- 모든 시그널이 `sig_addr`를 사용하는 것은 아님
- `sig_magic`이 주소 해석 방식을 결정함
- V3D 버전에 따라 동작이 다를 수 있음
