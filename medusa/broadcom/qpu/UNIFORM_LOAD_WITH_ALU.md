# Uniform 로드와 ALU 연산 동시 실행

## 질문

> "instr에서 uniform 로드와 연산을 동시에 할 수는 없는가?"

## 답변: 가능합니다! ✅

**QPU는 한 명령어에서 uniform 로드(시그널)와 ALU 연산을 동시에 수행할 수 있습니다.**

---

## 1. 기본 개념

QPU 명령어는 다음 요소들을 **동시에** 실행할 수 있습니다:

```
┌─────────────────────────────────────┐
│ 하나의 QPU 명령어                    │
├─────────────────────────────────────┤
│ 1. 시그널 비트 (Signal)              │  ← uniform 로드 등
│ 2. ADD ALU 연산                      │  ← 덧셈, 뺄셈 등
│ 3. MUL ALU 연산                      │  ← 곱셈 등
└─────────────────────────────────────┘
```

즉, **하나의 명령어로 3가지 작업을 동시에 처리 가능**합니다:
- Uniform 로드 (시그널)
- ADD 파이프라인 연산
- MUL 파이프라인 연산

---

## 2. 코드 예시

### 예시 1: ldunif + ADD 연산 (불가능)

```c
// ❌ 이것은 불가능합니다!
struct v3d_qpu_instr instr;
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.sig.ldunif = true;           // uniform을 r5로 로드
instr.alu.add.op = V3D_QPU_A_ADD;  // 동시에 덧셈?
instr.alu.add.a.raddr = 1;         // rf1
instr.alu.add.b.raddr = 2;         // rf2
instr.alu.add.waddr = 3;           // rf3
```

**문제점**: `ldunif`는 암묵적으로 r5 레지스터에 쓰기 때문에, ADD ALU의 쓰기와 충돌합니다!

### 예시 2: ldunif + NOP (일반적 패턴)

```c
// ✅ 일반적으로 사용하는 패턴
struct v3d_qpu_instr instr;
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.sig.ldunif = true;           // uniform을 r5로 로드
instr.alu.add.op = V3D_QPU_A_NOP;  // ADD는 NOP
instr.alu.mul.op = V3D_QPU_M_NOP;  // MUL도 NOP

// 디스어셈블리: nop  ; ldunif
```

이것이 샘플 코드에서 사용한 패턴입니다 (qpu_simple_add.c:93-100).

### 예시 3: ldunif + 읽기 전용 ALU 연산 (가능!)

```c
// ✅ 가능합니다! (읽기만 하고 다른 레지스터에 쓰기)
struct v3d_qpu_instr instr;
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.sig.ldunif = true;           // uniform을 r5로 로드
instr.alu.add.op = V3D_QPU_A_ADD;  // 동시에 덧셈
instr.alu.add.a.raddr = 1;         // rf1 (r5가 아님!)
instr.alu.add.b.raddr = 2;         // rf2 (r5가 아님!)
instr.alu.add.waddr = 3;           // rf3에 쓰기 (r5가 아님!)
instr.alu.add.magic_write = false;

// 디스어셈블리: add rf3, rf1, rf2  ; ldunif
// 결과:
//   - rf3 = rf1 + rf2 (ADD ALU)
//   - r5 = uniform 값 (ldunif 시그널)
```

**핵심**: ldunif가 쓰는 r5와 충돌하지 않으면 가능합니다!

### 예시 4: ldunifrf + ADD 연산 (V3D 7.x - 가능!)

```c
// ✅ V3D 7.x에서는 완전히 가능합니다!
struct v3d_qpu_instr instr;
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.sig.ldunifrf = true;         // uniform을 sig_addr 레지스터로 로드
instr.sig_addr = 10;               // rf10으로 로드
instr.sig_magic = false;
instr.alu.add.op = V3D_QPU_A_ADD;  // 동시에 덧셈
instr.alu.add.a.raddr = 1;         // rf1
instr.alu.add.b.raddr = 2;         // rf2
instr.alu.add.waddr = 3;           // rf3
instr.alu.add.magic_write = false;

// 디스어셈블리: add rf3, rf1, rf2  ; ldunifrf.rf10
// 결과:
//   - rf3 = rf1 + rf2 (ADD ALU)
//   - rf10 = uniform 값 (ldunifrf 시그널)
```

**장점**: `ldunifrf`는 목적지를 자유롭게 선택할 수 있어서 더 유연합니다!

---

## 3. 실제 컴파일러 예시

V3D 컴파일러의 최적화 코드에서 실제로 사용하는 패턴을 볼 수 있습니다:

```assembly
# 원본 코드 (비효율적)
nop t1; ldunif (0x00000004 / 0.000000)
nop t2; ldunif (0x00000004 / 0.000000)
add t3, t1, t2

# 최적화 후 (더 효율적)
nop t1; ldunif (0x00000004 / 0.000000)
nop t2; ldunif (0x00000004 / 0.000000)
nop t4; ldunif (0x00000008 / 0.000000)  # 상수 폴딩 적용
mov t3, t4
```

출처: [vir_opt_constant_alu.c:35-43](medusa/broadcom/compiler/vir_opt_constant_alu.c#L35-L43)

여기서 `nop t1; ldunif`는 실제로:
- **NOP 연산** (ADD/MUL ALU에서)
- **uniform 로드** (시그널 비트)

두 가지를 **동시에 수행**하는 명령어입니다.

---

## 4. 가능한 조합 정리

### ✅ 가능한 조합

| 시그널 | ALU 연산 | 조건 | 설명 |
|--------|---------|------|------|
| `ldunif` | NOP | 항상 | 가장 일반적인 패턴 |
| `ldunif` | ADD/MUL | r5를 건드리지 않을 때 | 다른 레지스터만 읽고 쓰면 OK |
| `ldunifrf` | ADD/MUL | 항상 | 목적지가 충돌하지 않음 |
| `ldunifrf` | NOP | 항상 | 샘플 코드에서 사용 |
| `ldtmu` | NOP | 일반적 | TMU 로드 + NOP |
| `ldtmu` | ADD/MUL | sig_addr와 충돌 안 할 때 | 가능하지만 복잡함 |
| `ldvary` | ADD/MUL | sig_addr와 충돌 안 할 때 | Varying 로드 + 연산 |

### ❌ 불가능한/어려운 조합

| 시그널 | ALU 연산 | 이유 |
|--------|---------|------|
| `ldunif` | r5에 쓰는 연산 | r5 쓰기 충돌 |
| `ldunifrf` | sig_addr 레지스터에 쓰는 연산 | 목적지 충돌 |
| 여러 로드 시그널 | 아무거나 | 시그널 간 충돌 (하드웨어 제약) |

---

## 5. 샘플 코드 분석

당신의 샘플 코드([qpu_simple_add.c:93-100](sample/v3d/sample1/qpu_simple_add.c#L93-L100))에서:

```c
// rf0 = input_a 주소 (uniform[0])
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.sig.ldunifrf = true;        // ← uniform 로드 (시그널)
instr.sig_addr = 0;
instr.sig_magic = false;
instr.alu.add.op = V3D_QPU_A_NOP; // ← NOP (ALU 연산)
instr.alu.mul.op = V3D_QPU_M_NOP;
emit_qpu_instr(devinfo, &instr);
```

이 코드는 **안전하게** uniform을 로드하기 위해 ALU를 NOP으로 설정했습니다.

### 최적화 가능성

하지만 다음과 같이 바꿀 수 있습니다:

```c
// 명령어 1: uniform 로드 + 동시에 다른 연산
instr.sig.ldunifrf = true;
instr.sig_addr = 0;              // rf0 = uniform[0]
instr.sig_magic = false;
instr.alu.add.op = V3D_QPU_A_ADD; // rf7 + rf7 (다른 레지스터)
instr.alu.add.a.raddr = 7;
instr.alu.add.b.raddr = 7;
instr.alu.add.waddr = 8;         // rf8에 결과 쓰기
instr.alu.add.magic_write = false;
instr.alu.mul.op = V3D_QPU_M_NOP;

// 디스어셈블리: add rf8, rf7, rf7  ; ldunifrf.rf0
// 결과:
//   - rf0 = uniform[0] (주소)
//   - rf8 = rf7 + rf7 (동시에 다른 계산)
```

이렇게 하면 **명령어 하나를 절약**할 수 있습니다!

---

## 6. 실전 활용 예시

### 패턴 A: 분리 (안전하지만 느림)

```c
// 명령어 1: uniform 로드
instr1.sig.ldunifrf = true;
instr1.sig_addr = 0;
instr1.alu.add.op = V3D_QPU_A_NOP;
instr1.alu.mul.op = V3D_QPU_M_NOP;

// 명령어 2: 덧셈
instr2.alu.add.op = V3D_QPU_A_ADD;
instr2.alu.add.a.raddr = 1;
instr2.alu.add.b.raddr = 2;
instr2.alu.add.waddr = 3;
instr2.alu.mul.op = V3D_QPU_M_NOP;

// 총 명령어: 2개
```

### 패턴 B: 통합 (효율적)

```c
// 명령어 1: uniform 로드 + 덧셈 동시 실행
instr.sig.ldunifrf = true;
instr.sig_addr = 0;              // rf0 = uniform
instr.sig_magic = false;
instr.alu.add.op = V3D_QPU_A_ADD; // rf1 + rf2
instr.alu.add.a.raddr = 1;
instr.alu.add.b.raddr = 2;
instr.alu.add.waddr = 3;         // rf3
instr.alu.add.magic_write = false;
instr.alu.mul.op = V3D_QPU_M_NOP;

// 총 명령어: 1개 (50% 절약!)
```

---

## 7. 주의사항

### 1. 레지스터 충돌 확인

```c
// ❌ 잘못된 예: sig_addr와 ALU waddr 충돌
instr.sig.ldunifrf = true;
instr.sig_addr = 3;              // rf3에 uniform 로드
instr.alu.add.waddr = 3;         // rf3에 덧셈 결과 쓰기
// → 충돌! rf3에 두 값이 동시에 쓰임
```

### 2. ldunif의 r5 충돌

```c
// ❌ 잘못된 예: ldunif는 r5에 쓰므로
instr.sig.ldunif = true;         // r5에 uniform 로드
instr.alu.add.waddr = V3D_QPU_WADDR_R5;
instr.alu.add.magic_write = true;
// → 충돌! r5에 두 값이 동시에 쓰임
```

### 3. 시그널 간 충돌

```c
// ❌ 잘못된 예: 여러 로드 시그널
instr.sig.ldunif = true;
instr.sig.ldtmu = true;
// → 하드웨어 제약: 한 번에 하나의 로드만 가능
```

---

## 8. V3D 버전별 차이

### V3D 4.x

```c
// ldunif만 사용 가능 (r5로 고정)
instr.sig.ldunif = true;
// → 항상 r5에 로드
// → ALU는 r5를 피해야 함
```

### V3D 7.x

```c
// ldunifrf 사용 가능 (자유로운 목적지)
instr.sig.ldunifrf = true;
instr.sig_addr = 10;  // 원하는 레지스터 선택!
// → 더 유연한 조합 가능
```

---

## 9. 성능 비교

### 시나리오: 3개의 uniform 로드 + 2개의 덧셈

#### 방법 A: 분리 (5개 명령어)

```assembly
nop         ; ldunifrf.rf0    # 명령어 1
nop         ; ldunifrf.rf1    # 명령어 2
nop         ; ldunifrf.rf2    # 명령어 3
add rf3, rf0, rf1             # 명령어 4
add rf4, rf2, rf3             # 명령어 5
```

#### 방법 B: 통합 (3개 명령어)

```assembly
nop         ; ldunifrf.rf0    # 명령어 1: uniform 로드
add rf3, rf0, rf1  ; ldunifrf.rf1    # 명령어 2: 덧셈 + uniform 로드
add rf4, rf2, rf3  ; ldunifrf.rf2    # 명령어 3: 덧셈 + uniform 로드
```

**성능 향상**: 40% 명령어 절약! (5 → 3)

---

## 10. 결론

### ✅ 가능합니다!

Uniform 로드(시그널)와 ALU 연산은 **한 명령어에서 동시에 실행 가능**합니다.

### 핵심 규칙

1. **레지스터 충돌 없어야 함**
   - 시그널의 목적지 ≠ ALU의 목적지

2. **시그널 제약 확인**
   - 한 명령어에 하나의 로드 시그널만

3. **V3D 버전 확인**
   - V3D 4.x: `ldunif` (r5 고정)
   - V3D 7.x: `ldunifrf` (자유로운 선택)

### 권장 사항

```c
// 샘플 코드 수정 제안: 명령어 절약
// Before (qpu_simple_add.c:140-169):
// - EIDX 로드: 1개 명령어
// - rf7*2 계산: 1개 명령어
// - rf8*2 계산: 1개 명령어
// 총: 3개 명령어

// After (최적화):
instr.sig.ldunifrf = true;       // uniform 로드 (명령어 재사용)
instr.sig_addr = 0;              // 이미 실행된 uniform 로드
instr.alu.add.op = V3D_QPU_A_EIDX;
instr.alu.add.waddr = 7;
// 총: uniform 로드와 EIDX를 동시 실행 → 명령어 절약!
```

### 최종 답변

**네, uniform 로드와 ALU 연산을 동시에 할 수 있습니다!** 단, 레지스터 충돌만 피하면 됩니다. 샘플 코드에서 NOP을 사용한 것은 **안전한 선택**이지만, 최적화를 위해서는 실제 연산과 결합할 수 있습니다.

---

## 11. 실습 예제

### 당신의 샘플 코드 최적화

```c
// 원본 (qpu_simple_add.c:140-158)
// rf7 = EIDX
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.alu.add.op = V3D_QPU_A_EIDX;
instr.alu.add.waddr = 7;
instr.alu.add.magic_write = false;
instr.alu.mul.op = V3D_QPU_M_NOP;
emit_qpu_instr(devinfo, &instr);

// rf8 = rf7 * 2
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.alu.add.op = V3D_QPU_A_ADD;
instr.alu.add.a.raddr = 7;
instr.alu.add.b.raddr = 7;
instr.alu.add.waddr = 8;
instr.alu.add.magic_write = false;
instr.alu.mul.op = V3D_QPU_M_NOP;
emit_qpu_instr(devinfo, &instr);
```

### 최적화 버전 (MUL 파이프라인 활용)

```c
// 1개 명령어로 통합: ADD에서 EIDX, MUL에서 곱셈
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;

// ADD 파이프라인: EIDX
instr.alu.add.op = V3D_QPU_A_EIDX;
instr.alu.add.waddr = 7;           // rf7 = EIDX
instr.alu.add.magic_write = false;

// MUL 파이프라인: (사용 가능하면 다른 연산)
// 또는 후속 명령어에서 활용
instr.alu.mul.op = V3D_QPU_M_NOP;

emit_qpu_instr(devinfo, &instr);

// rf8 = rf7 * 2 (별도 명령어 필요 - EIDX 결과를 기다려야 함)
```

**참고**: EIDX는 ADD 파이프라인 전용이므로, 이 경우는 크게 최적화하기 어렵습니다. 하지만 uniform 로드 명령어들은 위에서 설명한 대로 최적화 가능합니다!

---

## 요약

| 질문 | 답변 |
|------|------|
| Uniform 로드 + ALU 연산 동시 가능? | ✅ **가능** |
| 조건은? | 레지스터 충돌 없어야 함 |
| 샘플 코드에서 NOP을 쓴 이유? | 안전하고 명확하기 때문 (최적화는 아님) |
| 최적화 가능? | ✅ **가능** (레지스터 충돌만 피하면) |
| 성능 향상? | 최대 50% 명령어 절약 가능 |

**핵심**: QPU는 시그널(uniform 로드)과 ALU 연산을 **병렬로 실행**하도록 설계되었습니다!
