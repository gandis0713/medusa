# V3D QPU 특수 쓰기 주소(WADDR) 상세 설명

이 문서는 V3D GPU QPU의 특수 쓰기 주소(`v3d_qpu_waddr`)를 상세히 설명합니다.

**출처**: `medusa/broadcom/qpu/qpu_instr.h` (line 93-138)

---

## 목차

1. [개요](#개요)
2. [Accumulator 레지스터 (V3D 4.x 전용)](#accumulator-레지스터)
3. [TMU (Texture Memory Unit)](#tmu-texture-memory-unit)
4. [VPM (Vertex Pipe Memory)](#vpm-vertex-pipe-memory)
5. [TLB (Tile Buffer)](#tlb-tile-buffer)
6. [동기화 레지스터](#동기화-레지스터)
7. [수학 함수 레지스터 (V3D 4.x)](#수학-함수-레지스터)
8. [기타 특수 레지스터](#기타-특수-레지스터)
9. [버전별 차이점](#버전별-차이점)
10. [사용 예제](#사용-예제)

---

## 개요

### magic_write 플래그

QPU 명령어에서 쓰기 주소는 두 가지 모드로 해석됩니다:

```c
instr.alu.add.waddr = 주소값;
instr.alu.add.magic_write = true/false;
```

| `magic_write` | 주소 범위 | 의미 |
|---------------|-----------|------|
| `false` | 0-63 | **일반 레지스터 파일** (rf0 ~ rf63) |
| `true` | 0-55 | **특수 레지스터** (WADDR enum) |

**중요**: 같은 주소 값이라도 `magic_write` 플래그에 따라 다른 레지스터를 가리킵니다!

```c
// 예시
instr.alu.add.waddr = 12;
instr.alu.add.magic_write = false;  // → rf12 (일반 레지스터)

instr.alu.add.waddr = 12;
instr.alu.add.magic_write = true;   // → TMUA (TMU Address)
```

---

## Accumulator 레지스터

**버전**: V3D 4.x 전용 (V3D 7.x에서는 제거됨)

### `V3D_QPU_WADDR_R0` ~ `V3D_QPU_WADDR_R5` (0-5)

```c
V3D_QPU_WADDR_R0 = 0,    /* Reserved on V3D 7.x */
V3D_QPU_WADDR_R1 = 1,    /* Reserved on V3D 7.x */
V3D_QPU_WADDR_R2 = 2,    /* Reserved on V3D 7.x */
V3D_QPU_WADDR_R3 = 3,    /* Reserved on V3D 7.x */
V3D_QPU_WADDR_R4 = 4,    /* Reserved on V3D 7.x */
V3D_QPU_WADDR_R5 = 5,    /* V3D 4.x */
```

**설명**: 6개의 임시 accumulator 레지스터입니다.

**특징**:
- V3D 4.x에서 ALU 연산의 임시 저장소
- V3D 7.x에서는 **완전히 제거됨** (일반 레지스터 파일 사용)

**V3D 4.x 예제**:
```c
// r5에 uniform 로드 (V3D 4.x ldunif 동작)
instr.sig.ldunif = true;
// 결과는 자동으로 r5에 저장됨
```

---

### `V3D_QPU_WADDR_QUAD` (5)

```c
V3D_QPU_WADDR_QUAD = 5,  /* V3D 7.x */
```

**버전**: V3D 7.x 전용

**설명**: Quad 연산 관련 레지스터 (r5와 같은 주소 값)

**용도**: Fragment shader에서 2×2 pixel quad 처리

---

## TMU (Texture Memory Unit)

TMU는 **메모리 및 텍스처 접근**을 담당하는 하드웨어 유닛입니다.

### 핵심 TMU 레지스터

#### `V3D_QPU_WADDR_TMUD` (11) - TMU Data

```c
V3D_QPU_WADDR_TMUD = 11,
```

**용도**: TMU **쓰기**에 사용할 데이터 설정

**사용 시점**: 메모리에 데이터를 쓰기 전에 먼저 설정

**예제** (메모리 쓰기):
```c
// 1단계: 쓸 데이터 설정
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 12;              // rf12 (쓸 데이터)
instr.alu.add.waddr = V3D_QPU_WADDR_TMUD; // tmud에 저장
instr.alu.add.magic_write = true;
emit_qpu_instr(&instr);

// 2단계: 쓸 주소 설정 (쓰기 트리거)
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 5;               // rf5 (쓸 주소)
instr.alu.add.waddr = V3D_QPU_WADDR_TMUA; // tmua에 쓰기 → 쓰기 시작!
instr.alu.add.magic_write = true;
emit_qpu_instr(&instr);

// 3단계: 완료 대기
instr.alu.add.op = V3D_QPU_A_TMUWT;
emit_qpu_instr(&instr);
```

**중요**: `TMUD`는 반드시 `TMUA` 쓰기 **전에** 설정해야 합니다!

---

#### `V3D_QPU_WADDR_TMUA` (12) - TMU Address

```c
V3D_QPU_WADDR_TMUA = 12,
```

**용도**: TMU 작업의 **주소** 설정 및 **작업 트리거**

**읽기 모드**: TMUA에 주소 쓰기 → 메모리 읽기 시작
**쓰기 모드**: TMUD 설정 후 TMUA에 주소 쓰기 → 메모리 쓰기 시작

**예제** (메모리 읽기):
```c
// TMU 읽기 요청
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 3;               // rf3 (읽을 주소)
instr.alu.add.waddr = V3D_QPU_WADDR_TMUA; // tmua ← 주소
instr.alu.add.magic_write = true;
emit_qpu_instr(&instr);
// → TMU가 백그라운드에서 메모리 읽기 시작

// NOP (레이턴시 대기)
instr.alu.add.op = V3D_QPU_A_NOP;
emit_qpu_instr(&instr);

// 데이터 수신
instr.sig.ldtmu = true;  // TMU에서 데이터 로드
instr.sig_addr = 10;     // 목적지: rf10
instr.sig_magic = false;
emit_qpu_instr(&instr);
// → rf10 = 메모리[rf3]
```

**실제 사용** (`qpu_simple_add.c:192-199`):
```c
// TMU 읽기: input_a[thread_id]
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 3; // rf3 (input_a[thread_id] 주소)
instr.alu.add.waddr = V3D_QPU_WADDR_TMUA;
instr.alu.add.magic_write = true;
instr.alu.mul.op = V3D_QPU_M_NOP;
emit_qpu_instr(devinfo, &instr);
```

---

#### `V3D_QPU_WADDR_TMUAU` (13) - TMU Address (Unsigned)

```c
V3D_QPU_WADDR_TMUAU = 13,
```

**용도**: TMUA와 동일하지만 **부호 없는(unsigned)** 주소 처리

---

#### `V3D_QPU_WADDR_TMUL` (10) - TMU Lock/Load Type

```c
V3D_QPU_WADDR_TMUL = 10,
```

**용도**: TMU 로드 타입 및 캐시 정책 설정

---

### 텍스처 샘플링 관련 레지스터

#### `V3D_QPU_WADDR_TMUC` (32) - TMU Coordinate

```c
V3D_QPU_WADDR_TMUC = 32,
```

**용도**: 텍스처 좌표 설정 (S/T/R)

**사용 사례**:
- 2D 텍스처: (S, T) 좌표
- 3D 텍스처: (S, T, R) 좌표
- Cubemap: 방향 벡터

---

#### `V3D_QPU_WADDR_TMUS` (33) - TMU S Coordinate

```c
V3D_QPU_WADDR_TMUS = 33,
```

**용도**: 텍스처 S 좌표 (가로, U)

---

#### `V3D_QPU_WADDR_TMUT` (34) - TMU T Coordinate

```c
V3D_QPU_WADDR_TMUT = 34,
```

**용도**: 텍스처 T 좌표 (세로, V)

---

#### `V3D_QPU_WADDR_TMUR` (35) - TMU R Coordinate

```c
V3D_QPU_WADDR_TMUR = 35,
```

**용도**: 텍스처 R 좌표 (3D 깊이)

---

#### `V3D_QPU_WADDR_TMUI` (36) - TMU Array Index

```c
V3D_QPU_WADDR_TMUI = 36,
```

**용도**: 텍스처 배열 인덱스

---

#### `V3D_QPU_WADDR_TMUB` (37) - TMU Bias/LOD Bias

```c
V3D_QPU_WADDR_TMUB = 37,
```

**용도**: MIP level bias 설정

**사용 사례**: 텍스처 샤프니스/블러 조절

---

#### `V3D_QPU_WADDR_TMUDREF` (38) - TMU Depth Reference

```c
V3D_QPU_WADDR_TMUDREF = 38,
```

**용도**: 그림자 맵 비교를 위한 깊이 참조 값

---

#### `V3D_QPU_WADDR_TMUOFF` (39) - TMU Offset

```c
V3D_QPU_WADDR_TMUOFF = 39,
```

**용도**: 텍스처 샘플링 오프셋

---

#### `V3D_QPU_WADDR_TMUSCM` (40) - TMU S Coordinate (Manual Clamp)

```c
V3D_QPU_WADDR_TMUSCM = 40,
```

**용도**: 수동 클램핑이 적용된 S 좌표

---

#### `V3D_QPU_WADDR_TMUSF` (41) - TMU S Coordinate (Full Precision)

```c
V3D_QPU_WADDR_TMUSF = 41,
```

**용도**: 전체 정밀도 S 좌표

---

#### `V3D_QPU_WADDR_TMUSLOD` (42) - TMU S + LOD

```c
V3D_QPU_WADDR_TMUSLOD = 42,
```

**용도**: S 좌표 + 명시적 LOD 레벨

---

#### `V3D_QPU_WADDR_TMUHS` ~ `V3D_QPU_WADDR_TMUHSLOD` (43-46)

```c
V3D_QPU_WADDR_TMUHS = 43,
V3D_QPU_WADDR_TMUHSCM = 44,
V3D_QPU_WADDR_TMUHSF = 45,
V3D_QPU_WADDR_TMUHSLOD = 46,
```

**용도**: Half-precision (16비트) 버전의 텍스처 좌표 레지스터

**장점**: 메모리 및 대역폭 절약

---

## VPM (Vertex Pipe Memory)

VPM은 **CPU-GPU 간 데이터 전송** 및 **버텍스/지오메트리 데이터 저장**에 사용되는 공유 메모리입니다.

### `V3D_QPU_WADDR_VPM` (14) - VPM Write

```c
V3D_QPU_WADDR_VPM = 14,
```

**용도**: VPM에 데이터 쓰기

**사용 사례**:
- 버텍스 셰이더 출력
- 지오메트리 셰이더 데이터
- 쓰레드 간 공유 데이터

**예제**:
```c
// VPM에 데이터 쓰기
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 10;           // rf10 (쓸 데이터)
instr.alu.add.waddr = V3D_QPU_WADDR_VPM;
instr.alu.add.magic_write = true;
emit_qpu_instr(&instr);
```

---

### `V3D_QPU_WADDR_VPMU` (15) - VPM Setup

```c
V3D_QPU_WADDR_VPMU = 15,
```

**용도**: VPM 접근 설정 (DMA, 스트라이드 등)

**설정 내용**:
- 읽기/쓰기 주소
- 스트라이드 (행/열 간격)
- DMA 모드

---

## TLB (Tile Buffer)

TLB는 **렌더링 출력** (프래그먼트 색상, 깊이)을 저장하는 타일 기반 버퍼입니다.

### `V3D_QPU_WADDR_TLB` (7) - Tile Buffer Write

```c
V3D_QPU_WADDR_TLB = 7,
```

**용도**: 프래그먼트 셰이더에서 픽셀 색상을 TLB에 쓰기

**사용 사례**: Fragment shader 출력

**예제**:
```c
// 최종 색상을 TLB에 쓰기
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 20;           // rf20 (RGBA 색상)
instr.alu.add.waddr = V3D_QPU_WADDR_TLB;
instr.alu.add.magic_write = true;
emit_qpu_instr(&instr);
```

---

### `V3D_QPU_WADDR_TLBU` (8) - Tile Buffer (Unsigned)

```c
V3D_QPU_WADDR_TLBU = 8,
```

**용도**: TLB와 동일하지만 부호 없는 정수 포맷

---

## 동기화 레지스터

### `V3D_QPU_WADDR_SYNC` (16) - Sync

```c
V3D_QPU_WADDR_SYNC = 16,
```

**용도**: 쓰레드 동기화 및 세마포어

---

### `V3D_QPU_WADDR_SYNCU` (17) - Sync (Unsigned)

```c
V3D_QPU_WADDR_SYNCU = 17,
```

---

### `V3D_QPU_WADDR_SYNCB` (18) - Sync Barrier

```c
V3D_QPU_WADDR_SYNCB = 18,
```

**용도**: 배리어 동기화 (모든 쓰레드 대기)

---

## 수학 함수 레지스터

**버전**: V3D 4.x 전용 (V3D 7.x에서는 Reserved)

이 레지스터들에 쓰기를 하면 **하드웨어가 자동으로 함수를 계산**합니다.

### `V3D_QPU_WADDR_RECIP` (19) - Reciprocal (1/x)

```c
V3D_QPU_WADDR_RECIP = 19,  /* Reserved on V3D 7.x */
```

**V3D 4.x 동작**:
```c
// RECIP에 값 쓰기
instr.alu.add.waddr = V3D_QPU_WADDR_RECIP;
// → 하드웨어가 1/x 계산
// → 결과는 나중에 레지스터로 읽음
```

---

### `V3D_QPU_WADDR_RSQRT` (20) - Reciprocal Square Root (1/√x)

```c
V3D_QPU_WADDR_RSQRT = 20,  /* Reserved on V3D 7.x */
```

---

### `V3D_QPU_WADDR_EXP` (21) - Exponential (2^x)

```c
V3D_QPU_WADDR_EXP = 21,    /* Reserved on V3D 7.x */
```

---

### `V3D_QPU_WADDR_LOG` (22) - Logarithm (log₂)

```c
V3D_QPU_WADDR_LOG = 22,    /* Reserved on V3D 7.x */
```

---

### `V3D_QPU_WADDR_SIN` (23) - Sine

```c
V3D_QPU_WADDR_SIN = 23,    /* Reserved on V3D 7.x */
```

---

### `V3D_QPU_WADDR_RSQRT2` (24) - RSQRT (Improved)

```c
V3D_QPU_WADDR_RSQRT2 = 24, /* Reserved on V3D 7.x */
```

**설명**: 더 정밀한 1/√x 계산

**V3D 7.x**: 이 기능들은 대신 **ADD ALU 명령어**로 제공됩니다 (`V3D_QPU_A_RECIP`, `V3D_QPU_A_RSQRT` 등).

---

## 기타 특수 레지스터

### `V3D_QPU_WADDR_NOP` (6) - No Operation

```c
V3D_QPU_WADDR_NOP = 6,
```

**용도**: 쓰기를 버림 (결과 무시)

**사용 사례**:
- 플래그만 설정하고 결과는 필요 없을 때
- 명령어 슬롯 채우기

**예제**:
```c
// 비교만 하고 결과는 버림
instr.alu.add.op = V3D_QPU_A_FCMP;
instr.alu.add.a.raddr = 10;
instr.alu.add.b.raddr = 11;
instr.alu.add.waddr = V3D_QPU_WADDR_NOP;  // 결과 무시
instr.alu.add.magic_write = true;
// → 플래그만 설정됨
```

---

### `V3D_QPU_WADDR_UNIFA` (9) - Uniform Address

```c
V3D_QPU_WADDR_UNIFA = 9, /* V3D 4.x */
V3D_QPU_WADDR_TMU = 9,   /* V3D 3.x */
```

**버전별 차이**:
- **V3D 3.x**: TMU 레지스터
- **V3D 4.x+**: Uniform 주소 레지스터

**V3D 4.x+ 용도**: Uniform 버퍼의 주소를 설정합니다.

**예제**:
```c
// Uniform 주소 설정
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 5;  // uniform 버퍼 주소
instr.alu.add.waddr = V3D_QPU_WADDR_UNIFA;
instr.alu.add.magic_write = true;
emit_qpu_instr(&instr);
```

---

### `V3D_QPU_WADDR_R5REP` / `V3D_QPU_WADDR_REP` (55)

```c
V3D_QPU_WADDR_R5REP = 55, /* V3D 4.x */
V3D_QPU_WADDR_REP = 55,   /* V3D 7.x */
```

**용도**: 값을 모든 SIMD 레인에 복제 (broadcast)

**예제**:
```c
// 하나의 값을 16개 레인에 모두 복사
instr.alu.add.waddr = V3D_QPU_WADDR_REP;
instr.alu.add.magic_write = true;
// → 모든 레인이 같은 값을 가짐
```

---

## 버전별 차이점

### V3D 4.x vs V3D 7.x

| 레지스터 | V3D 4.x | V3D 7.x |
|----------|---------|---------|
| **R0-R5** | ✅ Accumulator | ❌ Reserved |
| **QUAD** | ❌ | ✅ Quad 연산 |
| **RECIP/RSQRT/EXP/LOG/SIN** | ✅ 하드웨어 함수 | ❌ Reserved (ALU 명령어 사용) |
| **TMU/VPM/TLB** | ✅ | ✅ |
| **R5REP/REP** | R5REP | REP |

---

## 사용 예제

### 예제 1: 메모리 읽기 (TMU)

```c
// 1. 주소를 TMUA에 쓰기 (읽기 트리거)
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 3;              // rf3 = 메모리 주소
instr.alu.add.waddr = V3D_QPU_WADDR_TMUA;
instr.alu.add.magic_write = true;       // 특수 레지스터!
instr.alu.mul.op = V3D_QPU_M_NOP;
emit_qpu_instr(&instr);

// 2. NOP (TMU 레이턴시 대기)
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.alu.add.op = V3D_QPU_A_NOP;
instr.alu.mul.op = V3D_QPU_M_NOP;
emit_qpu_instr(&instr);

// 3. ldtmu로 데이터 수신
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.sig.ldtmu = true;
instr.sig_addr = 10;                    // rf10 = 결과
instr.sig_magic = false;                // 일반 레지스터!
instr.alu.add.op = V3D_QPU_A_NOP;
instr.alu.mul.op = V3D_QPU_M_NOP;
emit_qpu_instr(&instr);

// 결과: rf10 = 메모리[rf3]
```

---

### 예제 2: 메모리 쓰기 (TMU)

```c
// 1. 데이터를 TMUD에 설정
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 12;             // rf12 = 쓸 데이터
instr.alu.add.waddr = V3D_QPU_WADDR_TMUD;
instr.alu.add.magic_write = true;
instr.alu.mul.op = V3D_QPU_M_NOP;
emit_qpu_instr(&instr);

// 2. 주소를 TMUA에 쓰기 (쓰기 트리거)
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 5;              // rf5 = 메모리 주소
instr.alu.add.waddr = V3D_QPU_WADDR_TMUA;
instr.alu.add.magic_write = true;
instr.alu.mul.op = V3D_QPU_M_NOP;
emit_qpu_instr(&instr);

// 3. TMUWT (완료 대기)
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.alu.add.op = V3D_QPU_A_TMUWT;
instr.alu.mul.op = V3D_QPU_M_NOP;
emit_qpu_instr(&instr);

// 결과: 메모리[rf5] = rf12
```

**실제 사용** (`qpu_simple_add.c:260-280`):
```c
// TMU 쓰기: tmud = rf12 (덧셈 결과)
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 12; // rf12 (덧셈 결과)
instr.alu.add.waddr = V3D_QPU_WADDR_TMUD;
instr.alu.add.magic_write = true;
instr.alu.mul.op = V3D_QPU_M_NOP;
emit_qpu_instr(devinfo, &instr);

// TMU 쓰기 시작: tmua = rf5 (output[thread_id] 주소)
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
```

---

### 예제 3: VPM 쓰기

```c
// VPM에 데이터 쓰기
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 10;             // rf10 = 쓸 데이터
instr.alu.add.waddr = V3D_QPU_WADDR_VPM;
instr.alu.add.magic_write = true;
instr.alu.mul.op = V3D_QPU_M_NOP;
emit_qpu_instr(&instr);
```

---

### 예제 4: TLB 쓰기 (Fragment Shader)

```c
// 픽셀 색상을 TLB에 출력
memset(&instr, 0, sizeof(instr));
instr.type = V3D_QPU_INSTR_TYPE_ALU;
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 20;             // rf20 = RGBA 색상
instr.alu.add.waddr = V3D_QPU_WADDR_TLB;
instr.alu.add.magic_write = true;
instr.alu.mul.op = V3D_QPU_M_NOP;
emit_qpu_instr(&instr);
```

---

## TMU 메모리 액세스 플로우

### 읽기 플로우
```
┌─────────────────────────────────────────────┐
│          TMU 메모리 읽기 과정                 │
└─────────────────────────────────────────────┘

1. 요청:
   rf3 → TMUA (waddr=12, magic_write=true)
   → TMU: "이 주소에서 읽어줘!"
   → 백그라운드 메모리 읽기 시작

2. 대기:
   NOP (TMU가 메모리에서 데이터 가져오는 중...)

3. 수신:
   ldtmu (sig.ldtmu=true, sig_addr=10, sig_magic=false)
   → rf10 ← TMU FIFO
   → rf10 = 메모리[rf3]
```

### 쓰기 플로우
```
┌─────────────────────────────────────────────┐
│          TMU 메모리 쓰기 과정                 │
└─────────────────────────────────────────────┘

1. 데이터 설정:
   rf12 → TMUD (waddr=11, magic_write=true)
   → TMU 버퍼: "이 데이터를 쓸 거야"

2. 주소 설정 (쓰기 트리거):
   rf5 → TMUA (waddr=12, magic_write=true)
   → TMU: "이 주소에 쓰기 시작!"
   → 백그라운드 메모리 쓰기 시작

3. 완료 대기:
   TMUWT (alu.add.op = V3D_QPU_A_TMUWT)
   → 모든 TMU 쓰기 완료될 때까지 대기
   → 메모리[rf5] = rf12
```

---

## 특수 레지스터 분류 요약

| 분류 | 레지스터 | 개수 |
|------|----------|------|
| **Accumulator** | R0-R5 | 6 (V3D 4.x) |
| **TMU 핵심** | TMUD, TMUA, TMUAU, TMUL | 4 |
| **TMU 텍스처** | TMUC, TMUS, TMUT, TMUR, TMUI, TMUB, ... | 15 |
| **VPM** | VPM, VPMU | 2 |
| **TLB** | TLB, TLBU | 2 |
| **동기화** | SYNC, SYNCU, SYNCB | 3 |
| **수학 함수** | RECIP, RSQRT, EXP, LOG, SIN, RSQRT2 | 6 (V3D 4.x) |
| **기타** | NOP, UNIFA, QUAD, REP | 4 |
| **총계** | | **42개** |

---

## 핵심 개념 요약

### 1. **magic_write 플래그**
- `false`: 일반 레지스터 (rf0-rf63)
- `true`: 특수 레지스터 (WADDR enum)

### 2. **TMU 사용 패턴**
- **읽기**: `TMUA` → `NOP` → `ldtmu`
- **쓰기**: `TMUD` → `TMUA` → `TMUWT`

### 3. **버전 차이**
- V3D 4.x: Accumulator(r0-r5), 하드웨어 수학 함수
- V3D 7.x: Accumulator 제거, ALU 명령어로 대체

### 4. **비동기 하드웨어**
- TMU, VPM은 비동기로 동작
- 요청 후 지연 시간 필요
- 완료 대기 명령어 필수 (TMUWT, VPMWT)

---

## 주의사항

1. **magic_write 확인**: 항상 올바른 값으로 설정해야 합니다!
2. **TMU 순서**: `TMUD` → `TMUA` 순서 필수 (쓰기 시)
3. **레이턴시**: TMU/VPM 작업 후 NOP 필요
4. **완료 대기**: TMUWT, VPMWT로 완료 보장
5. **버전 체크**: V3D 4.x vs 7.x 차이점 주의

---

## 참고 자료

- **소스 파일**: `medusa/broadcom/qpu/qpu_instr.h` (line 93-138)
- **디스어셈블러**: `medusa/broadcom/qpu/qpu_instr.c`
- **사용 예제**: `sample/v3d/sample2/qpu_simple_add.c` (line 192-287)
- **관련 문서**:
  - [V3D_QPU_ADD_ALU_OPS.md](V3D_QPU_ADD_ALU_OPS.md) - ADD ALU 연산
  - [V3D_QPU_SIG_DETAILED.md](V3D_QPU_SIG_DETAILED.md) - 시그널 비트
  - [QPU_INSTR_STRUCTURES.md](QPU_INSTR_STRUCTURES.md) - 명령어 구조

---

**문서 작성일**: 2025-11-13
**V3D 버전**: 4.x ~ 7.1 (Raspberry Pi 4/5)
