# V3D QPU ADD ALU 연산 상세 설명

이 문서는 V3D GPU QPU의 ADD ALU가 지원하는 모든 연산을 상세히 설명합니다.

**출처**: `medusa/broadcom/qpu/qpu_instr.h` (line 146-245)

---

## 목차

1. [산술 연산 (Arithmetic Operations)](#산술-연산)
2. [부동소수점 연산 (Floating Point Operations)](#부동소수점-연산)
3. [비트 연산 (Bitwise Operations)](#비트-연산)
4. [시프트/회전 연산 (Shift/Rotate Operations)](#시프트회전-연산)
5. [비교/최소/최대 연산 (Compare/Min/Max Operations)](#비교최소최대-연산)
6. [벡터 연산 (Vector Operations)](#벡터-연산)
7. [변환 연산 (Conversion Operations)](#변환-연산)
8. [쓰레드/ID 연산 (Thread/ID Operations)](#쓰레드id-연산)
9. [메모리/VPM 연산 (Memory/VPM Operations)](#메모리vpm-연산)
10. [특수 연산 (Special Operations)](#특수-연산)
11. [플래그 연산 (Flag Operations)](#플래그-연산)
12. [V3D 7.x 전용 연산](#v3d-7x-전용-연산)

---

## 산술 연산

### `V3D_QPU_A_ADD` - 정수 덧셈
```c
결과 = a + b  (32비트 정수)
```
**설명**: 두 32비트 정수를 더합니다. 16-way SIMD로 동작하므로 한 명령어로 16개 요소를 동시에 처리합니다.

**예제**:
```c
// rf3 = rf1 + rf2
instr.alu.add.op = V3D_QPU_A_ADD;
instr.alu.add.a.raddr = 1;  // rf1
instr.alu.add.b.raddr = 2;  // rf2
instr.alu.add.waddr = 3;    // rf3
```

**사용 사례**:
- 오프셋 계산: `address = base + offset`
- 카운터 증가: `i = i + 1`
- 좌표 변환: `x_new = x + delta_x`

---

### `V3D_QPU_A_SUB` - 정수 뺄셈
```c
결과 = a - b  (32비트 정수)
```
**설명**: 두 32비트 정수를 뺍니다.

**예제**:
```c
// rf5 = rf10 - rf11
instr.alu.add.op = V3D_QPU_A_SUB;
instr.alu.add.a.raddr = 10;
instr.alu.add.b.raddr = 11;
instr.alu.add.waddr = 5;
```

---

### `V3D_QPU_A_NEG` - 부호 반전
```c
결과 = -a  (2의 보수)
```
**설명**: 피연산자의 부호를 반전합니다 (단항 연산).

---

## 부동소수점 연산

### `V3D_QPU_A_FADD` - 부동소수점 덧셈
```c
결과 = a + b  (32비트 float, IEEE 754)
```
**설명**: IEEE 754 표준에 따른 32비트 부동소수점 덧셈입니다.

**예제**:
```c
// rf_result = vec_a + vec_b
instr.alu.add.op = V3D_QPU_A_FADD;
instr.alu.add.a.raddr = vec_a_reg;
instr.alu.add.b.raddr = vec_b_reg;
instr.alu.add.waddr = result_reg;
```

**사용 사례**:
- 그래픽스: 정점 변환, 조명 계산
- 물리 시뮬레이션: 힘/가속도 누적
- 신호 처리: 샘플 합산

---

### `V3D_QPU_A_FADDNF` - 부동소수점 덧셈 (플래그 없음)
```c
결과 = a + b  (플래그 업데이트 없음)
```
**설명**: `FADD`와 동일하지만 조건 플래그를 업데이트하지 않습니다. 성능 최적화에 유용합니다.

---

### `V3D_QPU_A_FSUB` - 부동소수점 뺄셈
```c
결과 = a - b  (32비트 float)
```
**설명**: IEEE 754 표준 부동소수점 뺄셈입니다.

---

### `V3D_QPU_A_FMUL` (MUL ALU에도 존재)
**참고**: 부동소수점 곱셈은 주로 MUL ALU에서 수행됩니다.

---

## 비트 연산

### `V3D_QPU_A_AND` - 비트 AND
```c
결과 = a & b  (비트별 AND)
```
**설명**: 두 값의 비트별 논리곱을 계산합니다.

**예제**:
```c
// 마스크 적용: result = value & 0xFF
instr.alu.add.op = V3D_QPU_A_AND;
instr.alu.add.a.raddr = value_reg;
instr.alu.add.b.raddr = mask_reg;  // 0xFF
instr.alu.add.waddr = result_reg;
```

**사용 사례**:
- 비트 마스킹: `flags & MASK`
- 비트 추출: `(value & 0xFF00) >> 8`
- 짝수 판별: `if (n & 1 == 0)`

---

### `V3D_QPU_A_OR` - 비트 OR
```c
결과 = a | b  (비트별 OR)
```
**설명**: 두 값의 비트별 논리합을 계산합니다.

**사용 사례**:
- 플래그 설정: `flags |= FLAG_ENABLE`
- 비트 병합: `rgba = (r << 24) | (g << 16) | (b << 8) | a`

---

### `V3D_QPU_A_XOR` - 비트 XOR
```c
결과 = a ^ b  (비트별 XOR)
```
**설명**: 두 값의 비트별 배타적 논리합을 계산합니다.

**사용 사례**:
- 비트 토글: `flags ^= FLAG_BIT`
- 빠른 비교: `if (a ^ b == 0)` → a == b
- 암호화: XOR 암호

---

### `V3D_QPU_A_NOT` - 비트 NOT
```c
결과 = ~a  (비트 반전)
```
**설명**: 모든 비트를 반전합니다 (1의 보수).

---

## 시프트/회전 연산

### `V3D_QPU_A_SHL` - 논리 왼쪽 시프트
```c
결과 = a << b  (Shift Left)
```
**설명**: 값을 왼쪽으로 시프트하고 오른쪽에 0을 채웁니다.

**예제**:
```c
// 4배 증가: result = value * 4 = value << 2
instr.alu.add.op = V3D_QPU_A_SHL;
instr.alu.add.a.raddr = value_reg;
instr.alu.add.b.raddr = shift_2_reg;  // 2
instr.alu.add.waddr = result_reg;
```

**사용 사례**:
- 2의 거듭제곱 곱셈: `x * 8 = x << 3`
- 비트 배치: `(r << 16) | (g << 8) | b`
- 주소 계산: `offset = index << 2`  (배열 인덱싱)

---

### `V3D_QPU_A_SHR` - 논리 오른쪽 시프트
```c
결과 = a >> b  (Unsigned Shift Right)
```
**설명**: 값을 오른쪽으로 시프트하고 왼쪽에 0을 채웁니다 (부호 없는).

**사용 사례**:
- 2의 거듭제곱 나눗셈: `x / 4 = x >> 2`
- 비트 추출: `(rgba >> 8) & 0xFF`  (green 추출)

---

### `V3D_QPU_A_ASR` - 산술 오른쪽 시프트
```c
결과 = a >> b  (Signed Shift Right, 부호 확장)
```
**설명**: 값을 오른쪽으로 시프트하고 왼쪽에 부호 비트를 채웁니다 (부호 있는 정수).

**차이점**:
```c
int32_t x = -8;  // 0xFFFFFFF8
SHR:  x >> 2 = 0x3FFFFFFE  (양수가 됨, 잘못됨!)
ASR:  x >> 2 = 0xFFFFFFFE  (-2, 올바름!)
```

---

### `V3D_QPU_A_ROR` - 오른쪽 회전
```c
결과 = rotate_right(a, b)
```
**설명**: 비트를 오른쪽으로 회전합니다. 오른쪽에서 나간 비트가 왼쪽으로 들어옵니다.

**예제**:
```c
// 0x12345678을 8비트 회전
// Before: 0x12345678
// After:  0x78123456
```

**사용 사례**:
- 암호화 알고리즘
- 해시 함수
- PRNG (의사 난수 생성기)

---

## 비교/최소/최대 연산

### `V3D_QPU_A_MIN` - 정수 최소값 (부호 있음)
```c
결과 = min(a, b)  (signed)
```
**설명**: 두 부호 있는 정수 중 작은 값을 선택합니다.

**예제**:
```c
// 범위 제한: value = min(value, MAX)
instr.alu.add.op = V3D_QPU_A_MIN;
instr.alu.add.a.raddr = value_reg;
instr.alu.add.b.raddr = max_reg;
instr.alu.add.waddr = value_reg;
```

---

### `V3D_QPU_A_MAX` - 정수 최대값 (부호 있음)
```c
결과 = max(a, b)  (signed)
```
**사용 사례**:
- 클램핑: `value = max(0, min(value, 255))`
- 임계값: `if (x > threshold)` → `x = max(x, threshold)`

---

### `V3D_QPU_A_UMIN` - 정수 최소값 (부호 없음)
```c
결과 = min(a, b)  (unsigned)
```

---

### `V3D_QPU_A_UMAX` - 정수 최대값 (부호 없음)
```c
결과 = max(a, b)  (unsigned)
```

---

### `V3D_QPU_A_FMIN` - 부동소수점 최소값
```c
결과 = fmin(a, b)  (IEEE 754)
```
**설명**: NaN 처리를 포함한 IEEE 754 표준 최소값입니다.

---

### `V3D_QPU_A_FMAX` - 부동소수점 최대값
```c
결과 = fmax(a, b)  (IEEE 754)
```

---

### `V3D_QPU_A_FCMP` - 부동소수점 비교
```c
플래그 설정: a <=> b
```
**설명**: 두 부동소수점 값을 비교하고 조건 플래그만 설정합니다.

---

## 벡터 연산

### `V3D_QPU_A_VADD` - 벡터 덧셈 (16비트 SIMD)
```c
결과 = vadd(a, b)  // 16비트 요소별 덧셈
```
**설명**: 32비트 레지스터를 2개의 16비트 값으로 취급하여 병렬 덧셈합니다.

**구조**:
```
a = [a_hi:16bit | a_lo:16bit]
b = [b_hi:16bit | b_lo:16bit]
결과 = [a_hi+b_hi | a_lo+b_lo]
```

**사용 사례**:
- 픽셀 연산: RGB565 포맷 처리
- 오디오: 스테레오 샘플 (L/R) 동시 처리

---

### `V3D_QPU_A_VSUB` - 벡터 뺄셈 (16비트 SIMD)
```c
결과 = vsub(a, b)
```

---

### `V3D_QPU_A_VFPACK` - 벡터 부동소수점 팩
```c
결과 = pack(float32_a, float32_b) → [float16, float16]
```
**설명**: 두 32비트 float를 16비트 half-float로 변환하여 하나의 레지스터에 팩합니다.

---

### `V3D_QPU_A_VFMIN` - 벡터 부동소수점 최소값
```c
결과 = [fmin(a_hi, b_hi), fmin(a_lo, b_lo)]
```

---

### `V3D_QPU_A_VFMAX` - 벡터 부동소수점 최대값
```c
결과 = [fmax(a_hi, b_hi), fmax(a_lo, b_lo)]
```

---

## 변환 연산

### `V3D_QPU_A_ITOF` - 정수 → 부동소수점
```c
결과 = (float)a  (int32 → float32)
```
**설명**: 부호 있는 32비트 정수를 32비트 float로 변환합니다.

**예제**:
```c
// int pixel_count = 1024;
// float normalized = (float)pixel_count / 2048.0f;
instr.alu.add.op = V3D_QPU_A_ITOF;
instr.alu.add.a.raddr = count_reg;
instr.alu.add.waddr = float_reg;
```

---

### `V3D_QPU_A_UTOF` - 부호 없는 정수 → 부동소수점
```c
결과 = (float)a  (uint32 → float32)
```

---

### `V3D_QPU_A_FTOIN` - 부동소수점 → 정수 (반올림)
```c
결과 = round(a)  (float → int, 가장 가까운 정수)
```

---

### `V3D_QPU_A_FTRUNC` - 부동소수점 → 정수 (버림)
```c
결과 = trunc(a)  (소수점 버림, 0 방향)
```
**예제**:
```
3.9 → 3
-3.9 → -3
```

---

### `V3D_QPU_A_FFLOOR` - 부동소수점 내림
```c
결과 = floor(a)  (음의 무한대 방향)
```
**예제**:
```
3.9 → 3
-3.1 → -4
```

---

### `V3D_QPU_A_FCEIL` - 부동소수점 올림
```c
결과 = ceil(a)  (양의 무한대 방향)
```
**예제**:
```
3.1 → 4
-3.9 → -3
```

---

### `V3D_QPU_A_FROUND` - 부동소수점 반올림
```c
결과 = round(a)  (가장 가까운 정수)
```

---

### `V3D_QPU_A_FTOIZ` - Float → Int (0으로 반올림)
```c
결과 = (int)a  with rounding toward zero
```

---

### `V3D_QPU_A_FTOUZ` - Float → Unsigned Int (0으로 반올림)
```c
결과 = (uint)a
```

---

### `V3D_QPU_A_FTOC` - Float → Int (clamped)
```c
결과 = clamp((int)a, INT_MIN, INT_MAX)
```

---

## 쓰레드/ID 연산

### `V3D_QPU_A_EIDX` - Element Index (쓰레드 ID)
```c
결과 = [0, 1, 2, 3, ..., 15]  (16-way SIMD)
```
**설명**: 각 SIMD 레인의 인덱스를 반환합니다. **피연산자가 필요 없습니다** (단항 연산).

**예제**:
```c
// rf7 = EIDX
instr.alu.add.op = V3D_QPU_A_EIDX;
instr.alu.add.waddr = 7;
instr.alu.add.magic_write = false;

// 결과: rf7[0]=0, rf7[1]=1, ..., rf7[15]=15
```

**사용 사례**:
```c
// 각 쓰레드가 서로 다른 데이터 처리
offset = thread_id * 4;  // EIDX * 4
address = base + offset;
data[thread_id] = input[thread_id];
```

**실제 사용 예** (`qpu_simple_add.c`):
```c
// rf7 = EIDX (thread ID: 0~15)
// rf9 = rf7 * 4  (바이트 오프셋)
// rf3 = input_base + rf9  → 각 쓰레드가 서로 다른 주소 접근
```

---

### `V3D_QPU_A_TIDX` - Thread Index
```c
결과 = thread_index
```
**설명**: 현재 하드웨어 쓰레드 번호를 반환합니다 (QPU에서 실행 중인 쓰레드 ID).

**EIDX vs TIDX 차이**:
- **EIDX**: SIMD 레인 인덱스 (0~15, 항상 고정)
- **TIDX**: 하드웨어 쓰레드 번호 (QPU가 멀티쓰레딩 시 변경 가능)

---

### `V3D_QPU_A_IID` - Invocation ID
```c
결과 = workgroup 내 invocation ID
```
**설명**: Compute shader에서 현재 invocation의 ID를 반환합니다.

---

### `V3D_QPU_A_SAMPID` - Sample ID
```c
결과 = MSAA sample ID
```
**설명**: Multi-Sample Anti-Aliasing 사용 시 현재 샘플 번호를 반환합니다.

---

### `V3D_QPU_A_BARRIERID` - Barrier ID
```c
결과 = barrier ID
```
**설명**: 동기화 barrier의 ID를 반환합니다.

---

## 메모리/VPM 연산

### `V3D_QPU_A_TMUWT` - TMU Wait
```c
동작: TMU 작업 완료 대기
```
**설명**: TMU (Texture Memory Unit)의 모든 쓰기 작업이 완료될 때까지 대기합니다.

**예제**:
```c
// TMU 쓰기 후 반드시 대기
instr.alu.add.waddr = V3D_QPU_WADDR_TMUD;  // 데이터
instr.alu.add.waddr = V3D_QPU_WADDR_TMUA;  // 주소 (쓰기 트리거)

// 대기
instr.alu.add.op = V3D_QPU_A_TMUWT;
```

**중요**: TMU 쓰기 후 프로그램 종료 전 반드시 호출해야 합니다!

---

### `V3D_QPU_A_VPMSETUP` - VPM Setup
```c
동작: VPM (Vertex Pipe Memory) 설정
```
**설명**: VPM 접근을 위한 DMA/스트라이드 설정을 구성합니다.

---

### `V3D_QPU_A_VPMWT` - VPM Wait
```c
동작: VPM DMA 완료 대기
```

---

### `V3D_QPU_A_LDVPMV_IN` - VPM에서 정점 데이터 로드
```c
동작: VPM → 레지스터 (vertex input)
```

---

### `V3D_QPU_A_LDVPMV_OUT` - VPM에 정점 데이터 저장
```c
동작: 레지스터 → VPM (vertex output)
```

---

### `V3D_QPU_A_LDVPMD_IN` - VPM에서 일반 데이터 로드
```c
동작: VPM → 레지스터 (generic data)
```

---

### `V3D_QPU_A_LDVPMD_OUT` - VPM에 일반 데이터 저장
```c
동작: 레지스터 → VPM (generic data)
```

---

### `V3D_QPU_A_LDVPMP` - VPM 포인터 로드
```c
동작: VPM 포인터 레지스터 로드
```

---

### `V3D_QPU_A_LDVPMG_IN` - VPM 일반 로드 (geom shader)
```c
동작: Geometry shader VPM 입력
```

---

### `V3D_QPU_A_LDVPMG_OUT` - VPM 일반 저장 (geom shader)
```c
동작: Geometry shader VPM 출력
```

---

### `V3D_QPU_A_STVPMV` - VPM 정점 저장
```c
동작: VPM에 정점 데이터 저장 (레거시)
```

---

### `V3D_QPU_A_STVPMD` - VPM 데이터 저장
```c
동작: VPM에 일반 데이터 저장 (레거시)
```

---

### `V3D_QPU_A_STVPMP` - VPM 팩 데이터 저장
```c
동작: VPM에 팩된 데이터 저장
```

---

## 특수 연산

### `V3D_QPU_A_NOP` - No Operation
```c
동작: 아무것도 하지 않음
```
**설명**: 명령어 슬롯을 채우거나 파이프라인 지연(delay slot)을 처리하는 데 사용됩니다.

**예제**:
```c
// thrsw 이후 2 사이클 지연 필요
instr.sig.thrsw = true;
emit_qpu_instr(&instr);

// NOP 2개
instr.alu.add.op = V3D_QPU_A_NOP;
instr.alu.mul.op = V3D_QPU_M_NOP;
emit_qpu_instr(&instr);
emit_qpu_instr(&instr);
```

---

### `V3D_QPU_A_MOV` - 정수 이동
```c
결과 = a  (레지스터 복사)
```
**설명**: 값을 다른 레지스터로 복사합니다.

**예제**:
```c
// rf5 = rf3
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 3;
instr.alu.add.waddr = 5;
```

---

### `V3D_QPU_A_FMOV` - 부동소수점 이동
```c
결과 = a  (float 복사)
```

---

### `V3D_QPU_A_CLZ` - Count Leading Zeros
```c
결과 = clz(a)  (최상위 0 비트 개수)
```
**설명**: 최상위 비트부터 첫 번째 1이 나올 때까지의 0 개수를 셉니다.

**예제**:
```
0x00000001 → 31  (31개의 leading zeros)
0x00000100 → 23
0x80000000 → 0
0x00000000 → 32
```

**사용 사례**:
- 정수 log2 계산: `log2(x) ≈ 31 - clz(x)`
- 정규화 (normalization)
- 비트 스캔

---

### `V3D_QPU_A_RECIP` - 역수 (1/x)
```c
결과 ≈ 1.0 / a  (근사값)
```
**설명**: 부동소수점 역수의 근사값을 계산합니다.

**중요**: 하드웨어 근사값이므로 정확하지 않을 수 있습니다. 정밀도가 필요하면 Newton-Raphson 반복으로 개선해야 합니다.

---

### `V3D_QPU_A_RSQRT` - 역 제곱근 (1/√x)
```c
결과 ≈ 1.0 / sqrt(a)
```
**설명**: 1/√x의 근사값을 빠르게 계산합니다.

**사용 사례**:
- 벡터 정규화: `normalized = v * rsqrt(dot(v,v))`
- 조명 계산: 거리 감쇠

---

### `V3D_QPU_A_RSQRT2` - 역 제곱근 (개선된 정밀도)
```c
결과 ≈ 1.0 / sqrt(a)  (더 정확함)
```

---

### `V3D_QPU_A_EXP` - 지수 함수 (2^x)
```c
결과 ≈ 2^a
```
**설명**: 2의 거듭제곱을 계산합니다. `e^x = 2^(x * log2(e))`로 자연 지수도 계산 가능합니다.

---

### `V3D_QPU_A_LOG` - 로그 함수 (log₂)
```c
결과 ≈ log₂(a)
```
**설명**: 밑이 2인 로그를 계산합니다.

---

### `V3D_QPU_A_SIN` - 사인 함수
```c
결과 ≈ sin(a * 2π)
```
**중요**: 입력 범위는 [0, 1]이며 [0, 2π]에 매핑됩니다.

---

## 플래그 연산

### `V3D_QPU_A_SETMSF` - MSF 설정
```c
동작: Multisample Fragment 플래그 설정
```

---

### `V3D_QPU_A_SETREVF` - REVF 설정
```c
동작: Reverse Fragment 플래그 설정
```

---

### `V3D_QPU_A_MSF` - MSF 읽기
```c
결과 = MSF flag
```

---

### `V3D_QPU_A_REVF` - REVF 읽기
```c
결과 = Reverse flag
```

---

### `V3D_QPU_A_FLAPUSH` - Flag A Push
```c
동작: Flag A 스택에 푸시
```
**설명**: 조건부 실행을 위한 플래그 스택 관리입니다.

---

### `V3D_QPU_A_FLBPUSH` - Flag B Push
```c
동작: Flag B 스택에 푸시
```

---

### `V3D_QPU_A_FLPOP` - Flag Pop
```c
동작: 플래그 스택에서 팝
```

---

### `V3D_QPU_A_FLAFIRST` - Flag A First Active
```c
결과 = first active lane in flag A
```

---

### `V3D_QPU_A_FLNAFIRST` - Flag A First Inactive
```c
결과 = first inactive lane in flag A
```

---

### `V3D_QPU_A_VFLA` - Vector Flag A
```c
결과 = vector of flag A values
```

---

### `V3D_QPU_A_VFLNA` - Vector Flag A Negated
```c
결과 = vector of negated flag A
```

---

### `V3D_QPU_A_VFLB` - Vector Flag B
```c
결과 = vector of flag B values
```

---

### `V3D_QPU_A_VFLNB` - Vector Flag B Negated
```c
결과 = vector of negated flag B
```

---

## 좌표/Fragment 연산

### `V3D_QPU_A_FXCD` - Fragment X Coordinate (Float)
```c
결과 = fragment_x  (float)
```
**설명**: 현재 프래그먼트의 X 좌표를 부동소수점으로 반환합니다.

---

### `V3D_QPU_A_FYCD` - Fragment Y Coordinate (Float)
```c
결과 = fragment_y  (float)
```

---

### `V3D_QPU_A_XCD` - Fragment X Coordinate (Int)
```c
결과 = fragment_x  (int)
```

---

### `V3D_QPU_A_YCD` - Fragment Y Coordinate (Int)
```c
결과 = fragment_y  (int)
```

---

### `V3D_QPU_A_FDX` - Fragment X 편미분
```c
결과 = d(value)/dx
```
**설명**: 프래그먼트 간 X 방향 변화율을 계산합니다.

**사용 사례**:
- MIP 레벨 계산
- 텍스처 필터링

---

### `V3D_QPU_A_FDY` - Fragment Y 편미분
```c
결과 = d(value)/dy
```

---

### `V3D_QPU_A_VDWWT` - Varying Data Wait
```c
동작: Varying 데이터 로드 완료 대기
```

---

### `V3D_QPU_A_LR` - Link Register
```c
결과 = return address
```
**설명**: 함수 호출 시 리턴 주소를 저장/로드합니다.

---

## V3D 7.x 전용 연산

다음 연산들은 **V3D 7.x (Raspberry Pi 5)** 에서만 사용 가능합니다.

### `V3D_QPU_A_VPACK` - 벡터 팩
```c
결과 = pack vector elements
```
**설명**: 여러 요소를 하나의 레지스터로 팩합니다.

---

### `V3D_QPU_A_V8PACK` - 8비트 벡터 팩
```c
결과 = pack 4 × 8-bit values
```
**설명**: 4개의 8비트 값을 32비트 레지스터에 팩합니다.

**사용 사례**:
- RGBA 픽셀 팩킹: `[R:8 | G:8 | B:8 | A:8]`

---

### `V3D_QPU_A_V10PACK` - 10비트 벡터 팩
```c
결과 = pack 10-bit values
```

---

### `V3D_QPU_A_V11FPACK` - 11비트 Float 벡터 팩
```c
결과 = pack 11-bit float values
```

---

### `V3D_QPU_A_BALLOT` - Ballot (투표)
```c
결과 = bitmask of active lanes
```
**설명**: 활성화된 SIMD 레인의 비트마스크를 반환합니다.

**예제**:
```c
// 조건을 만족하는 레인 찾기
// if (value > threshold)
//   active_mask = ballot(true)
```

---

### `V3D_QPU_A_BCASTF` - Broadcast Float
```c
결과 = broadcast value to all lanes
```
**설명**: 하나의 값을 모든 SIMD 레인에 방송합니다.

---

### `V3D_QPU_A_ALLEQ` - All Equal (정수)
```c
결과 = all lanes have same value?
```
**설명**: 모든 SIMD 레인이 같은 값을 가지는지 확인합니다.

---

### `V3D_QPU_A_ALLFEQ` - All Equal (Float)
```c
결과 = all lanes have same float value?
```

---

### `V3D_QPU_A_ROTQ` - Rotate Quad
```c
결과 = rotate within quad (4 lanes)
```
**설명**: 4개 레인(quad) 내에서 값을 회전합니다.

---

### `V3D_QPU_A_ROT` - Rotate
```c
결과 = rotate lanes
```
**설명**: SIMD 레인 전체에서 값을 회전합니다.

---

### `V3D_QPU_A_SHUFFLE` - Shuffle
```c
결과 = shuffle lanes according to mask
```
**설명**: 레인 순서를 재배열합니다.

**사용 사례**:
- SIMD 레인 간 데이터 교환
- Warp shuffle (CUDA와 유사)

---

## 연산 분류 요약

| 분류 | 연산 개수 | 주요 연산 |
|------|-----------|-----------|
| **산술** | 3 | ADD, SUB, NEG |
| **부동소수점** | 3 | FADD, FSUB, FMOV |
| **비트 연산** | 4 | AND, OR, XOR, NOT |
| **시프트/회전** | 4 | SHL, SHR, ASR, ROR |
| **비교/최소/최대** | 7 | MIN, MAX, UMIN, UMAX, FMIN, FMAX, FCMP |
| **벡터 연산** | 5 | VADD, VSUB, VFPACK, VFMIN, VFMAX |
| **변환** | 11 | ITOF, UTOF, FTOIN, FTRUNC, FFLOOR, FCEIL, ... |
| **쓰레드/ID** | 5 | **EIDX**, TIDX, IID, SAMPID, BARRIERID |
| **메모리/VPM** | 13 | TMUWT, VPMSETUP, LDVPMV_IN, LDVPMV_OUT, ... |
| **특수 연산** | 9 | NOP, MOV, CLZ, RECIP, RSQRT, EXP, LOG, SIN |
| **플래그** | 10 | FLAPUSH, FLBPUSH, FLPOP, MSF, REVF, ... |
| **좌표/Fragment** | 7 | FXCD, FYCD, XCD, YCD, FDX, FDY |
| **V3D 7.x 전용** | 13 | VPACK, V8PACK, BALLOT, BCASTF, ALLEQ, SHUFFLE |
| **총계** | **96개** | |

---

## 자주 사용되는 연산 패턴

### 1. 벡터 덧셈
```c
// output[i] = a[i] + b[i]
ldtmu rf10        // a[i]
ldtmu rf11        // b[i]
add rf12, rf10, rf11
```

### 2. 오프셋 계산
```c
// address = base + (thread_id * 4)
eidx rf7          // thread_id
add rf8, rf7, rf7 // * 2
add rf9, rf8, rf8 // * 4
add rf3, rf0, rf9 // base + offset
```

### 3. 조건부 클램핑
```c
// value = clamp(value, 0, 255)
max rf5, rf5, rf0_zero    // max(value, 0)
min rf5, rf5, rf1_255     // min(value, 255)
```

### 4. 벡터 정규화
```c
// normalized = v / length(v)
// length = sqrt(v.x² + v.y² + v.z²)
fmul rf10, rf0, rf0       // x²
fmul rf11, rf1, rf1       // y²
fmul rf12, rf2, rf2       // z²
fadd rf13, rf10, rf11     // x² + y²
fadd rf13, rf13, rf12     // + z²
rsqrt rf14, rf13          // 1/sqrt(length²)
fmul rf0, rf0, rf14       // x * (1/length)
fmul rf1, rf1, rf14       // y * (1/length)
fmul rf2, rf2, rf14       // z * (1/length)
```

---

## 버전별 차이점

### V3D 4.x vs V3D 7.x

| 기능 | V3D 4.x | V3D 7.x |
|------|---------|---------|
| Accumulator 레지스터 | r0-r5 있음 | 없음 (제거됨) |
| V8PACK, V10PACK | ❌ | ✅ |
| BALLOT, SHUFFLE | ❌ | ✅ |
| ALLEQ, ALLFEQ | ❌ | ✅ |
| ROT, ROTQ | ❌ | ✅ |

---

## 참고 자료

- **소스 파일**: `medusa/broadcom/qpu/qpu_instr.h` (line 146-245)
- **디스어셈블러**: `medusa/broadcom/qpu/qpu_instr.c` (line 96-193)
- **사용 예제**: `sample/v3d/sample2/qpu_simple_add.c`
- **관련 문서**:
  - [QPU_INSTR_STRUCTURES.md](QPU_INSTR_STRUCTURES.md) - 명령어 구조
  - [V3D_QPU_SIG_DETAILED.md](V3D_QPU_SIG_DETAILED.md) - 시그널 비트
  - [WHY_16_THREADS_PER_QPU.md](WHY_16_THREADS_PER_QPU.md) - SIMD 아키텍처

---

## 주의사항

1. **SIMD 동작**: 모든 연산은 16-way SIMD로 동작합니다.
2. **플래그 오염**: 일부 연산은 조건 플래그를 변경합니다.
3. **근사값**: RECIP, RSQRT, EXP, LOG, SIN은 근사값을 반환합니다.
4. **레이턴시**: TMU/VPM 연산은 여러 사이클이 걸립니다.
5. **버전 확인**: V3D 7.x 전용 연산은 이전 버전에서 사용 불가합니다.

---

**문서 작성일**: 2025-11-13
**V3D 버전**: 4.x ~ 7.1 (Raspberry Pi 4/5)
