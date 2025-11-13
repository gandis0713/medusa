# v3d_qpu_sig 구조체 상세 설명

## 개요

`v3d_qpu_sig`는 QPU 명령어의 **시그널 비트(Signal Bits)**를 나타내는 구조체입니다. 시그널 비트는 QPU 명령어가 실행될 때 발생하는 **부가적인 동작**들을 제어합니다. 주로 메모리 로드, 스레드 제어, 특수 레지스터 접근 등을 담당합니다.

## 구조체 정의

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

**특징**:
- 각 필드는 1비트 boolean 값 (`:1` 비트필드 문법)
- 총 17개의 시그널 비트
- 하나의 명령어에서 여러 시그널을 동시에 설정 가능 (하드웨어 제약 내에서)

---

## 시그널 비트 상세 설명

### 1. `thrsw` - Thread Switch

```c
bool thrsw:1;
```

**기능**: 스레드 스위칭을 수행합니다.

**설명**:
- QPU는 멀티스레딩을 지원하여 여러 스레드를 동시에 실행할 수 있습니다
- 한 스레드가 메모리 대기 등으로 지연될 때, 다른 스레드로 전환하여 파이프라인을 활용합니다
- TMU(텍스처 메모리), VPM 등의 지연 연산 후 결과를 기다릴 때 주로 사용됩니다

**사용 예시**:
```c
// 텍스처 요청 후 스레드 전환
instr.sig.thrsw = true;  // 다른 스레드 실행하며 텍스처 로드 대기
```

**주의사항**:
- V3D 4.2+ 버전에서는 스레드 전환 시에도 플래그가 보존됩니다
- 텍스처 연산 후 반드시 스레드 전환이 필요한 경우가 많습니다

**관련 코드**:
```c
// 디스어셈블리 출력
if (sig->thrsw)
    append(disasm, "; thrsw");
```

---

### 2. `ldunif` - Load Uniform

```c
bool ldunif:1;
```

**기능**: Uniform 값을 로드합니다.

**설명**:
- Uniform은 모든 쓰레드/버텍스/프래그먼트에 공통으로 적용되는 상수 값입니다
- 주로 변환 행렬, 색상 상수, 타이밍 값 등에 사용됩니다
- Uniform 스트림에서 다음 값을 읽어 특정 레지스터에 저장합니다

**사용 예시**:
```c
// Uniform 값을 r5 레지스터로 로드
instr.sig.ldunif = true;
```

**Uniform 데이터 흐름**:
```
Uniform Stream (메모리) → QPU → 레지스터
```

---

### 3. `ldunifa` - Load Uniform Address

```c
bool ldunifa:1;
```

**기능**: Uniform 주소를 로드합니다.

**설명**:
- Uniform 데이터의 메모리 주소를 설정합니다
- UNIFA (Uniform Address) 레지스터에 주소를 쓸 때 사용됩니다
- 이후 `ldunif`로 해당 주소의 데이터를 읽을 수 있습니다

**사용 시나리오**:
1. `ldunifa` - Uniform 메모리 주소 설정
2. `ldunif` - 설정된 주소에서 데이터 로드

---

### 4. `ldunifrf` - Load Uniform to Register File

```c
bool ldunifrf:1;
```

**기능**: Uniform 값을 레지스터 파일로 직접 로드합니다.

**설명**:
- Uniform 값을 특정 레지스터 파일 위치에 로드합니다
- 로드 대상 레지스터는 `sig_addr` 필드로 지정됩니다
- V3D 7.x에서 도입된 기능

**디스어셈블리 출력**:
```
; ldunifrf.rf32  (레지스터 파일 32번으로 로드)
```

---

### 5. `ldunifarf` - Load Uniform Address to Register File

```c
bool ldunifarf:1;
```

**기능**: Uniform 주소를 레지스터 파일로 로드합니다.

**설명**:
- `ldunifa`와 유사하지만 레지스터 파일에 직접 저장합니다
- 간접 주소 지정이나 동적 Uniform 접근에 사용됩니다

---

### 6. `ldtmu` - Load from TMU

```c
bool ldtmu:1;
```

**기능**: TMU(Texture Memory Unit)에서 데이터를 로드합니다.

**설명**:
- TMU는 텍스처 샘플링과 메모리 접근을 담당하는 하드웨어 유닛입니다
- 텍스처 좌표를 TMU에 보낸 후, 이 시그널로 결과를 읽어옵니다
- 일반적으로 `thrsw`와 함께 사용됩니다 (텍스처 로드는 지연이 큽니다)

**사용 패턴**:
```c
// 1. TMU에 텍스처 주소 쓰기
write_to_tmu(texture_address);

// 2. 스레드 전환하여 로드 대기
instr1.sig.thrsw = true;

// 3. TMU 결과 읽기
instr2.sig.ldtmu = true;
```

**디스어셈블리 출력**:
```
; ldtmu.r2  (TMU 결과를 r2로 로드)
```

---

### 7. `ldvary` - Load Varying

```c
bool ldvary:1;
```

**기능**: Varying 값을 로드합니다.

**설명**:
- Varying은 버텍스 셰이더에서 프래그먼트 셰이더로 전달되는 보간된 값입니다
- 주로 색상, 텍스처 좌표, 법선 벡터 등이 varying으로 전달됩니다
- 프래그먼트 셰이더에서 픽셀 위치에 따라 보간된 값을 받습니다

**Varying 데이터 흐름**:
```
Vertex Shader → (보간) → Fragment Shader (ldvary)
```

**사용 예시**:
```c
// 텍스처 좌표 varying 로드
instr.sig.ldvary = true;
instr.sig_addr = texture_coord_varying_index;
```

---

### 8. `ldvpm` - Load from VPM

```c
bool ldvpm:1;
```

**기능**: VPM(Vertex Pipe Memory)에서 데이터를 로드합니다.

**설명**:
- VPM은 버텍스 데이터와 어트리뷰트를 저장하는 온칩 메모리입니다
- 버텍스 셰이더에서 입력 데이터를 읽을 때 사용합니다
- VPM은 매우 빠른 로컬 메모리입니다

**VPM 사용 단계**:
1. VPM 설정 (VPMSETUP)
2. VPM에서 데이터 로드 (`ldvpm`)
3. 데이터 처리

**디스어셈블리 출력**:
```
; ldvpm
```

---

### 9. `ldtlb` - Load from TLB

```c
bool ldtlb:1;
```

**기능**: TLB(Tile Buffer)에서 데이터를 로드합니다.

**설명**:
- TLB는 렌더링 타겟(프레임버퍼)의 타일을 캐싱하는 메모리입니다
- 블렌딩이나 depth test를 위해 기존 픽셀 값을 읽을 때 사용합니다
- 주로 프래그먼트 셰이더에서 사용됩니다

**사용 시나리오**:
- Alpha blending: 기존 색상 값 읽기
- Depth testing: 기존 depth 값 비교
- Read-modify-write 연산

---

### 10. `ldtlbu` - Load from TLB Unsigned

```c
bool ldtlbu:1;
```

**기능**: TLB에서 부호 없는(unsigned) 데이터를 로드합니다.

**설명**:
- `ldtlb`와 유사하지만 부호 없는 정수 형식으로 해석합니다
- 8비트/16비트 부호 없는 색상 값 등을 읽을 때 사용합니다

---

### 11. `ucb` - Uniform Control Bit

```c
bool ucb:1;
```

**기능**: Uniform 제어 비트입니다.

**설명**:
- Uniform 스트림의 동작을 제어합니다
- 정확한 동작은 하드웨어 버전에 따라 다를 수 있습니다
- 일반적으로 Uniform 주소 자동 증가 등을 제어합니다

**사용 빈도**: 비교적 드물게 사용됩니다.

---

### 12. `rotate` - Rotate Operation

```c
bool rotate:1;
```

**기능**: 레지스터 값 회전(rotate) 연산을 수행합니다.

**설명**:
- 입력 레지스터의 요소들을 회전시킵니다
- SIMD 벡터 연산에서 레인(lane) 간 데이터 교환에 사용됩니다
- 쿼드(quad) 내 픽셀 간 데이터 공유에 유용합니다

**사용 예시**:
```c
// 벡터 요소를 1칸씩 회전
instr.sig.rotate = true;
```

**응용**:
- 수평/수직 블러링
- 이웃 픽셀 접근
- SIMD reduction 연산

---

### 13. `wrtmuc` - Write TMU Cache

```c
bool wrtmuc:1;
```

**기능**: TMU 캐시에 데이터를 씁니다.

**설명**:
- TMU를 통해 메모리에 쓰기 연산을 수행합니다
- 이미지 스토어, 버퍼 쓰기 등에 사용됩니다
- Compute Shader에서 출력 버퍼에 쓸 때 주로 사용됩니다

**TMU 쓰기 과정**:
1. TMU 주소 레지스터에 쓰기 주소 설정
2. TMU 데이터 레지스터에 쓸 데이터 저장
3. `wrtmuc` 시그널로 쓰기 실행

**디스어셈블리 출력**:
```
; wrtmuc
```

---

### 14. `small_imm_b` - Small Immediate B

```c
bool small_imm_b:1;
```

**기능**: `raddr_b` 필드를 작은 즉시값(small immediate)으로 해석합니다.

**설명**:
- 일반적으로 `raddr_b`는 레지스터 주소를 나타냅니다
- 이 비트가 설정되면 `raddr_b`를 즉시값으로 해석합니다
- 작은 상수 값(-16~15, 0, 1, 2, 특수 값 등)을 인코딩할 수 있습니다

**사용 예시**:
```c
// r0 = r1 + 5 (즉시값 5 사용)
instr.sig.small_imm_b = true;
instr.raddr_b = encode_small_imm(5);
instr.alu.add.op = V3D_QPU_A_ADD;
```

**장점**:
- 별도의 uniform 로드 없이 상수 사용 가능
- 코드 크기와 메모리 접근 감소

**디스어셈블리 출력**:
```
add r0, r1, 5          // small immediate로 5 사용
add r2, r3, 0x3f800000 // 1.0f (float)
```

---

### 15. `small_imm_a` - Small Immediate A (V3D 7.x)

```c
bool small_imm_a:1;  /* raddr_a (add a), since V3D 7.x */
```

**기능**: `raddr_a`를 작은 즉시값으로 해석합니다.

**설명**:
- V3D 7.x에서 추가된 기능
- ADD ALU의 A 입력에 즉시값 사용 가능
- `small_imm_b`와 동일한 방식으로 동작합니다

**V3D 4.x vs 7.x**:
- V3D 4.x: `small_imm_b`만 지원
- V3D 7.x: `small_imm_a`, `small_imm_b`, `small_imm_c`, `small_imm_d` 모두 지원

---

### 16. `small_imm_c` - Small Immediate C (V3D 7.x)

```c
bool small_imm_c:1;  /* raddr_c (mul a), since V3D 7.x */
```

**기능**: `raddr_c`를 작은 즉시값으로 해석합니다.

**설명**:
- V3D 7.x에서 추가
- MUL ALU의 A 입력에 즉시값 사용 가능
- 곱셈 연산에서도 즉시값을 직접 사용할 수 있습니다

**사용 예시**:
```c
// r0 = r1 * 2 (즉시값 2 사용)
instr.sig.small_imm_c = true;
instr.alu.mul.a.raddr = encode_small_imm(2);
instr.alu.mul.op = V3D_QPU_M_FMUL;
```

---

### 17. `small_imm_d` - Small Immediate D (V3D 7.x)

```c
bool small_imm_d:1;  /* raddr_d (mul b), since V3D 7.x */
```

**기능**: `raddr_d`를 작은 즉시값으로 해석합니다.

**설명**:
- V3D 7.x에서 추가
- MUL ALU의 B 입력에 즉시값 사용 가능
- 더욱 유연한 즉시값 사용이 가능합니다

---

## 시그널 비트 조합 규칙

### 상호 배타적 시그널

일부 시그널들은 **동시에 설정할 수 없습니다** (하드웨어 제약):

```c
// ❌ 잘못된 예: 여러 로드 시그널 동시 사용
instr.sig.ldunif = true;
instr.sig.ldtmu = true;   // 오류: 동시 사용 불가

// ✅ 올바른 예: 하나씩 사용
instr1.sig.ldunif = true;
instr2.sig.ldtmu = true;
```

### 일반적인 조합

```c
// 스레드 전환 + TMU 로드
instr.sig.thrsw = true;
instr.sig.ldtmu = true;

// Small immediate 사용
instr.sig.small_imm_b = true;

// V3D 7.x: 복수 즉시값
instr.sig.small_imm_a = true;
instr.sig.small_imm_c = true;
```

---

## 디스어셈블리 출력 예시

시그널 비트가 설정된 명령어는 디스어셈블리 시 세미콜론(`;`) 뒤에 표시됩니다:

```assembly
add r0, r1, r2                    ; No signal
fadd r3, r4, r5  ; thrsw          ; Thread switch
nop              ; ldtmu.r2       ; Load from TMU to r2
mov r1, r2       ; ldvary.r0      ; Load varying to r0
add r0, r1, 5    ; (small_imm_b)  ; Using immediate value 5
```

---

## 시그널 비트 카테고리 정리

### 📥 메모리 로드 시그널 (8개)
| 시그널 | 설명 | 주 사용처 |
|--------|------|-----------|
| `ldunif` | Uniform 로드 | 상수 값 |
| `ldunifa` | Uniform 주소 로드 | Uniform 주소 설정 |
| `ldunifrf` | Uniform → 레지스터 파일 | V3D 7.x |
| `ldunifarf` | Uniform 주소 → 레지스터 파일 | V3D 7.x |
| `ldtmu` | TMU 데이터 로드 | 텍스처/메모리 읽기 |
| `ldvary` | Varying 로드 | 보간된 값 |
| `ldvpm` | VPM 로드 | 버텍스 데이터 |
| `ldtlb` / `ldtlbu` | TLB 로드 | 프레임버퍼 읽기 |

### 🔄 제어 시그널 (2개)
| 시그널 | 설명 |
|--------|------|
| `thrsw` | 스레드 전환 |
| `ucb` | Uniform 제어 비트 |

### ✍️ 쓰기 시그널 (1개)
| 시그널 | 설명 |
|--------|------|
| `wrtmuc` | TMU 캐시 쓰기 |

### 🔢 즉시값 시그널 (4개)
| 시그널 | 설명 | 버전 |
|--------|------|------|
| `small_imm_b` | raddr_b 즉시값 | All |
| `small_imm_a` | raddr_a 즉시값 | V3D 7.x |
| `small_imm_c` | raddr_c 즉시값 | V3D 7.x |
| `small_imm_d` | raddr_d 즉시값 | V3D 7.x |

### 🔧 기타 시그널 (1개)
| 시그널 | 설명 |
|--------|------|
| `rotate` | 레지스터 회전 |

---

## 코드 사용 예시

### 예제 1: Uniform 로드
```c
struct v3d_qpu_instr instr = {
    .type = V3D_QPU_INSTR_TYPE_ALU,
    .sig = {
        .ldunif = true,  // Uniform 값 로드
    },
    .alu = {
        .add = {
            .op = V3D_QPU_A_NOP,
        },
        .mul = {
            .op = V3D_QPU_M_NOP,
        },
    },
};
```

### 예제 2: 텍스처 샘플링
```c
// 1단계: TMU에 텍스처 좌표 쓰기
struct v3d_qpu_instr write_tmu = {
    .alu.add.waddr = V3D_QPU_WADDR_TMUA,
    // ... 좌표 설정
};

// 2단계: 스레드 전환
struct v3d_qpu_instr thread_sw = {
    .sig.thrsw = true,
    .alu.add.op = V3D_QPU_A_NOP,
    .alu.mul.op = V3D_QPU_M_NOP,
};

// 3단계: TMU 결과 로드
struct v3d_qpu_instr load_tmu = {
    .sig.ldtmu = true,
    .sig_addr = 2,  // r2로 로드
    // ... 나머지 설정
};
```

### 예제 3: Small Immediate 사용
```c
// r0 = r1 + 10
struct v3d_qpu_instr add_imm = {
    .type = V3D_QPU_INSTR_TYPE_ALU,
    .sig = {
        .small_imm_b = true,  // raddr_b를 즉시값으로
    },
    .raddr_b = encode_small_imm(10),
    .alu = {
        .add = {
            .op = V3D_QPU_A_ADD,
            .a = { .mux = V3D_QPU_MUX_A },  // rf[raddr_a]
            .b = { .mux = V3D_QPU_MUX_B },  // small immediate 10
            .waddr = 0,
            .magic_write = false,
        },
    },
};
```

### 예제 4: Varying 로드 (프래그먼트 셰이더)
```c
// 텍스처 좌표 varying 로드
struct v3d_qpu_instr load_vary = {
    .type = V3D_QPU_INSTR_TYPE_ALU,
    .sig = {
        .ldvary = true,
    },
    .sig_addr = TEXCOORD_VARYING_INDEX,
    .sig_magic = true,
    .alu = {
        .add = {
            .op = V3D_QPU_A_NOP,
        },
    },
};
```

---

## 시그널 확인 함수

코드베이스에는 시그널 관련 유틸리티 함수들이 있습니다:

```c
// 시그널 패킹/언패킹
bool v3d_qpu_sig_pack(const struct v3d_device_info *devinfo,
                      const struct v3d_qpu_sig *sig,
                      uint32_t *packed_sig);

bool v3d_qpu_sig_unpack(const struct v3d_device_info *devinfo,
                        uint32_t packed_sig,
                        struct v3d_qpu_sig *sig);

// 시그널이 주소를 쓰는지 확인
bool v3d_qpu_sig_writes_address(const struct v3d_device_info *devinfo,
                                const struct v3d_qpu_sig *sig);
```

---

## V3D 버전별 차이점

### V3D 4.x
- `small_imm_b`만 지원
- Uniform/TMU/Varying/VPM/TLB 로드 기본 지원

### V3D 7.x
- **4개의 small immediate 모두 지원** (`a`, `b`, `c`, `d`)
- `ldunifrf`, `ldunifarf` 추가
- 더 유연한 레지스터 참조 방식

---

## 성능 최적화 팁

### 1. 스레드 전환 활용
```c
// ❌ 비효율적: TMU 결과를 즉시 기다림 (파이프라인 정지)
write_to_tmu();
read_from_tmu();  // 긴 대기 시간

// ✅ 효율적: 스레드 전환으로 다른 작업 수행
write_to_tmu();
thread_switch();   // 다른 스레드 실행
read_from_tmu();   // 결과 준비됨
```

### 2. Small Immediate 사용
```c
// ❌ 비효율적: Uniform으로 상수 전달
load_uniform(1);
add(r0, r1, uniform);

// ✅ 효율적: Small immediate 사용
add(r0, r1, 1);  // small_imm_b
```

### 3. 시그널 조합 최적화
```c
// 하나의 명령어에 ALU 연산 + 시그널 포함
add r0, r1, r2  ; ldunif  // 덧셈과 동시에 uniform 로드
```

---

## 디버깅 체크리스트

시그널 비트 관련 문제 디버깅 시 확인 사항:

- [ ] 상호 배타적 시그널을 동시에 사용하지 않았는가?
- [ ] TMU 쓰기 후 적절한 스레드 전환이 있는가?
- [ ] Small immediate 범위가 올바른가? (-16~15 등)
- [ ] `sig_addr`이 올바르게 설정되었는가?
- [ ] V3D 버전에 맞는 시그널을 사용하는가? (7.x 전용 등)
- [ ] TLB/VPM 접근 전 적절한 설정이 되었는가?

---

## 요약

`v3d_qpu_sig`는 QPU 명령어의 **부가 기능**을 제어하는 핵심 구조체입니다:

| 카테고리 | 시그널 수 | 주요 용도 |
|---------|----------|----------|
| 메모리 로드 | 8 | Uniform, TMU, Varying, VPM, TLB |
| 제어 | 2 | 스레드 전환, Uniform 제어 |
| 쓰기 | 1 | TMU 캐시 쓰기 |
| 즉시값 | 4 | Small immediate 사용 |
| 기타 | 1 | 레지스터 회전 |

**핵심 포인트**:
- ✅ 하나의 명령어에 ALU 연산과 시그널을 동시 수행 가능
- ✅ 메모리 지연을 스레드 전환으로 숨김
- ✅ Small immediate로 상수 로드 최적화
- ✅ V3D 7.x는 더 많은 즉시값 옵션 제공
