# V3D TMU 캐시 아키텍처 및 관련 명령어

## 목차
1. [TMU 캐시 계층 구조](#tmu-캐시-계층-구조)
2. [캐시 동작 원리](#캐시-동작-원리)
3. [TMU 관련 명령어](#tmu-관련-명령어)
4. [캐시 제어 연산](#캐시-제어-연산)
5. [성능 최적화](#성능-최적화)
6. [실제 예제](#실제-예제)

---

## TMU 캐시 계층 구조

### 전체 메모리 계층

```
┌────────────────────────────────────────────────────────────────┐
│                         QPU Core                               │
│  ┌──────────────────────────────────────────────────────────┐  │
│  │  Register File (rf0-rf63)                                │  │
│  │  Each register: 16 × 32-bit SIMD vector                  │  │
│  └──────────────────────────────────────────────────────────┘  │
│                              │                                  │
│                              ▼                                  │
│  ┌──────────────────────────────────────────────────────────┐  │
│  │  TMU Interface Registers                                 │  │
│  │  - TMUA (Address): 메모리 주소 지정                      │  │
│  │  - TMUD (Data): 쓰기 데이터                              │  │
│  │  - TMUC (Config): 구성 파라미터                          │  │
│  │  - ldtmu: 읽기 데이터 수신                               │  │
│  └──────────────────────────────────────────────────────────┘  │
└────────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌────────────────────────────────────────────────────────────────┐
│               TMU (Texture Memory Unit)                        │
│               - Shared by 4 QPUs per Slice                     │
│                                                                │
│  ┌──────────────────────────────────────────────────────────┐  │
│  │  TMU Request Queue (16 slots across all threads)        │  │
│  │  - Queues memory requests from QPUs                      │  │
│  │  - FIFO ordering                                         │  │
│  └──────────────────────────────────────────────────────────┘  │
│                              │                                  │
│                              ▼                                  │
│  ┌──────────────────────────────────────────────────────────┐  │
│  │  L1 Texture Cache (per TMU)                              │  │
│  │  - Size: ~16 KB (추정)                                   │  │
│  │  - Cache line: 256 bytes                                 │  │
│  │  - Latency: ~5 cycles (hit)                              │  │
│  │  - Handles texture/memory reads and writes               │  │
│  └──────────────────────────────────────────────────────────┘  │
│                              │                                  │
│                    Cache Miss │                                │
│                              ▼                                  │
└────────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌────────────────────────────────────────────────────────────────┐
│                   L2 Cache (L2T)                               │
│                   - Shared across all slices                   │
│  ┌──────────────────────────────────────────────────────────┐  │
│  │  L2 Texture Cache                                        │  │
│  │  - Size: ~128 KB (추정)                                  │  │
│  │  - Cache line: 256 bytes                                 │  │
│  │  - Latency: ~20 cycles (hit)                             │  │
│  │  - Services: TMU, VCD, CLE, SLC                          │  │
│  └──────────────────────────────────────────────────────────┘  │
│                              │                                  │
│                    Cache Miss │                                │
│                              ▼                                  │
└────────────────────────────────────────────────────────────────┘
                              │
                              ▼
                      ┌───────────────┐
                      │  System DRAM  │
                      │  Latency:     │
                      │  ~100+ cycles │
                      └───────────────┘
```

### 캐시 사양

#### L1 Texture Cache
```
특성              │ 값
─────────────────┼─────────────────────────────
크기              │ ~16 KB (per TMU)
캐시 라인 크기     │ 256 bytes
연관성 (Way)      │ 구현 의존적 (추정: 4-way)
대체 정책         │ LRU (Least Recently Used)
접근 레이턴시     │ ~5 cycles (hit)
서비스 대상       │ 해당 TMU에 연결된 4개 QPU
읽기/쓰기         │ Read/Write-through
```

#### L2 Cache (L2T)
```
특성              │ 값
─────────────────┼─────────────────────────────
크기              │ ~128 KB (shared)
캐시 라인 크기     │ 256 bytes
연관성 (Way)      │ 구현 의존적 (추정: 8-way)
대체 정책         │ LRU
접근 레이턴시     │ ~20 cycles (hit)
서비스 대상       │ All TMUs, VCD, CLE, SLC
읽기/쓰기         │ Write-back with write buffer
DRAM 대역폭       │ AXI bus interface
```

---

## 캐시 동작 원리

### 1. 읽기 동작 (Cache Read)

```
QPU 요청:
  rf3 → TMUA (Address write)
    │
    ▼
TMU Request Queue:
  [addr1, addr2, ...]  ← FIFO order
    │
    ▼
L1 Cache Lookup:
  Tag match?
    │
    ├─ YES → Cache Hit (5 cycles)
    │         └─ Return data → ldtmu
    │
    └─ NO  → Cache Miss
              │
              ▼
           L2 Cache Lookup:
             Tag match?
               │
               ├─ YES → L2 Hit (20 cycles)
               │         ├─ Return data to L1
               │         └─ Return data → ldtmu
               │
               └─ NO  → L2 Miss
                         │
                         ▼
                      DRAM Access (100+ cycles)
                         ├─ Load cache line (256 bytes)
                         ├─ Fill L2 cache
                         ├─ Fill L1 cache
                         └─ Return data → ldtmu
```

### 2. 쓰기 동작 (Cache Write)

```
QPU 요청:
  rf12 → TMUD (Data write)
  rf5  → TMUA (Address write, triggers write)
    │
    ▼
TMU Request Queue:
  [write_addr, write_data]
    │
    ▼
L1 Cache:
  Write-Through or Write-Back?
    │
    ├─ Write Hit:
    │   ├─ Update L1 cache line
    │   └─ Propagate to L2
    │
    └─ Write Miss:
        └─ Allocate on write or Write-around
           (구현 의존적)
    │
    ▼
L2 Cache:
  Write-Back with Write Buffer
    │
    ├─ Update L2 cache line
    ├─ Mark dirty bit
    └─ Schedule writeback to DRAM
    │
    ▼
DRAM:
  Delayed writeback (when eviction or explicit flush)
```

### 3. 캐시 일관성 (Cache Coherency)

V3D TMU는 **일관성 있는 캐시(Coherent Cache)**를 제공하지 않습니다:

```
문제 시나리오:
┌─────────────────────────────────────────────────────────┐
│ 1. QPU A writes to address 0x1000 via TMU               │
│    → Data in L1 cache (dirty)                           │
├─────────────────────────────────────────────────────────┤
│ 2. QPU B reads from address 0x1000 via TMU              │
│    → Might read stale data!                             │
│    (if writeback hasn't occurred)                       │
└─────────────────────────────────────────────────────────┘

해결 방법:
  - Memory barrier (TMUWT + sync)
  - Cache flush operations (TMU atomic ops)
  - Proper synchronization primitives
```

---

## TMU 관련 명령어

### 1. 기본 메모리 접근 명령어

#### 읽기 명령어
```c
// 1. 주소 지정 (읽기 요청 트리거)
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 3;              // rf3 (address)
instr.alu.add.waddr = V3D_QPU_WADDR_TMUA;
instr.alu.add.magic_write = true;

// 2. NOP (TMU latency)
instr.alu.add.op = V3D_QPU_A_NOP;

// 3. 데이터 수신
instr.sig.ldtmu = true;                 // Load from TMU
instr.sig_addr = 10;                    // rf10 (destination)
instr.sig_magic = false;
```

**동작 흐름:**
```
Cycle 0: TMUA ← address       (L1 cache lookup starts)
Cycle 1-4: NOP               (Wait for cache)
Cycle 5: ldtmu → rf10        (Data arrives, if L1 hit)
```

#### 쓰기 명령어
```c
// 1. 데이터 준비
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 12;             // rf12 (data)
instr.alu.add.waddr = V3D_QPU_WADDR_TMUD;
instr.alu.add.magic_write = true;

// 2. 주소 지정 (쓰기 요청 트리거)
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 5;              // rf5 (address)
instr.alu.add.waddr = V3D_QPU_WADDR_TMUA;
instr.alu.add.magic_write = true;

// 3. 쓰기 완료 대기
instr.alu.add.op = V3D_QPU_A_TMUWT;
```

**동작 흐름:**
```
Cycle 0: TMUD ← data          (Data buffered in TMU)
Cycle 1: TMUA ← address       (Write triggered, L1 update)
Cycle 2-10: Processing        (L1 write, L2 propagation)
Cycle 11: TMUWT returns       (Write confirmed)
```

### 2. 텍스처 샘플링 명령어

#### TMUS (Texture Memory Unit Sample)
```c
// 일반 텍스처 샘플링
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 7;              // rf7 (S coordinate)
instr.alu.add.waddr = V3D_QPU_WADDR_TMUS;
instr.alu.add.magic_write = true;
```

**용도:** 2D 텍스처 샘플링 (S 좌표로 트리거)

#### TMUSF (Texture Memory Unit Sample, Fetch)
```c
// 텍셀 페치 (정수 좌표)
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 7;              // rf7 (X coordinate)
instr.alu.add.waddr = V3D_QPU_WADDR_TMUSF;
instr.alu.add.magic_write = true;
```

**용도:** 텍셀 페치 (필터링 없이 정수 좌표로 직접 접근)

#### TMUSLOD (Texture Memory Unit Sample, LOD)
```c
// LOD 지정 샘플링
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 7;              // rf7 (S coordinate)
instr.alu.add.waddr = V3D_QPU_WADDR_TMUSLOD;
instr.alu.add.magic_write = true;
```

**용도:** 명시적 LOD 레벨로 텍스처 샘플링

#### TMUSCM (Texture Memory Unit Sample, Cube Map)
```c
// 큐브맵 샘플링
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 7;              // rf7 (S coordinate)
instr.alu.add.waddr = V3D_QPU_WADDR_TMUSCM;
instr.alu.add.magic_write = true;
```

**용도:** 큐브맵 텍스처 샘플링

### 3. TMU 구성 명령어

#### TMUC (TMU Config)
```c
// TMU 구성 파라미터 설정
// P0, P1, P2 파라미터를 TMUC로 전송
instr.sig.wrtmuc = true;                // Write TMU config
instr.uniform = uniform_index;          // Config data from uniform
```

**구성 파라미터:**
- **P0 (Parameter 0)**: 반환 데이터 워드 수, 텍스처 주소
- **P1 (Parameter 1)**: 샘플러 주소, 출력 타입 (16-bit/32-bit)
- **P2 (Parameter 2)**: TMU 연산 타입, gather mode, LOD 설정

#### TMU Operation Types (P2에서 지정)
```c
enum v3d_tmu_op {
    V3D_TMU_OP_REGULAR = 15,                    // 일반 메모리/텍스처 접근

    // Atomic operations with cache behavior:
    V3D_TMU_OP_WRITE_ADD_READ_PREFETCH = 0,     // Add + Prefetch
    V3D_TMU_OP_WRITE_SUB_READ_CLEAR = 1,        // Sub + Cache clear
    V3D_TMU_OP_WRITE_XCHG_READ_FLUSH = 2,       // Exchange + Flush
    V3D_TMU_OP_WRITE_CMPXCHG_READ_FLUSH = 3,    // Compare-exchange + Flush
    V3D_TMU_OP_WRITE_UMIN_FULL_L1_CLEAR = 4,    // Unsigned min + L1 clear
    V3D_TMU_OP_WRITE_UMAX = 5,                  // Unsigned max
    V3D_TMU_OP_WRITE_SMIN = 6,                  // Signed min
    V3D_TMU_OP_WRITE_SMAX = 7,                  // Signed max
    V3D_TMU_OP_WRITE_AND_READ_INC = 8,          // AND + Increment
    V3D_TMU_OP_WRITE_OR_READ_DEC = 9,           // OR + Decrement
    V3D_TMU_OP_WRITE_XOR_READ_NOT = 10,         // XOR + NOT
};
```

---

## 캐시 제어 연산

### 1. 캐시 플러시 (Cache Flush)

일부 TMU atomic 연산은 **캐시 제어 동작**을 포함합니다:

#### V3D_TMU_OP_WRITE_XCHG_READ_FLUSH
```c
// Atomic exchange with cache flush
// 1. TMUD에 새 값 설정
// 2. TMUA로 atomic exchange 트리거
// 3. 이전 값 반환 + L1 캐시 라인 플러시
```

**동작:**
1. 원자적으로 메모리 값을 교환
2. 이전 값을 반환 (ldtmu로 수신)
3. **해당 캐시 라인을 L1에서 플러시** (dirty 데이터를 L2/DRAM에 기록)

**사용 사례:**
- Lock-free 알고리즘
- Spinlock 구현
- Producer-consumer 패턴

#### V3D_TMU_OP_WRITE_UMIN_FULL_L1_CLEAR
```c
// Atomic unsigned min with full L1 cache clear
// 1. TMUD에 비교할 값 설정
// 2. TMUA로 atomic umin 트리거
// 3. 최소값 기록 + L1 전체 캐시 클리어
```

**동작:**
1. 원자적으로 unsigned min 연산 수행
2. 이전 값을 반환
3. **L1 캐시 전체를 무효화** (매우 강력한 캐시 제어)

**사용 사례:**
- 메모리 배리어가 필요한 동기화
- 여러 QPU 간 데이터 일관성 보장
- Critical section 진입/탈출

### 2. 캐시 프리페치 (Cache Prefetch)

#### V3D_TMU_OP_WRITE_ADD_READ_PREFETCH
```c
// Atomic add with prefetch
// 1. TMUD에 더할 값 설정
// 2. TMUA로 atomic add 트리거
// 3. 이전 값 반환 + 인접 캐시 라인 프리페치
```

**동작:**
1. 원자적으로 값을 더함
2. 이전 값을 반환
3. **인접 메모리 영역을 캐시에 프리페치** (순차 접근 최적화)

**사용 사례:**
- 카운터 증가
- 순차 메모리 접근 패턴
- 배열 순회 최적화

### 3. 메모리 배리어 (Memory Barrier)

TMU 자체는 명시적인 memory barrier 명령어가 없지만, **TMUWT와 동기화를 조합**하여 구현:

```c
// Pattern 1: Write barrier
// 모든 TMU 쓰기가 완료될 때까지 대기
instr.alu.add.op = V3D_QPU_A_TMUWT;

// Pattern 2: SYNC와 결합
// 1. TMUWT (TMU 쓰기 완료 대기)
instr.alu.add.op = V3D_QPU_A_TMUWT;

// 2. SYNC (모든 QPU 동기화)
instr.alu.add.op = V3D_QPU_A_MOV;
instr.alu.add.a.raddr = 0;
instr.alu.add.waddr = V3D_QPU_WADDR_SYNC;
instr.alu.add.magic_write = true;

// Pattern 3: Cache flush를 포함한 atomic 사용
// V3D_TMU_OP_WRITE_XCHG_READ_FLUSH 등 사용
```

---

## 성능 최적화

### 1. 메모리 접근 패턴 최적화

#### 공간 지역성 (Spatial Locality)
```c
// ❌ 나쁜 예: 분산된 접근
for (int i = 0; i < 16; i++) {
    address = base + (i * 1024);  // 1KB 간격 → 캐시 라인 미스
}

// ✅ 좋은 예: 연속 접근
for (int i = 0; i < 16; i++) {
    address = base + (i * 4);     // 4 byte 간격 → 캐시 히트
}
```

**원리:**
- 캐시 라인 크기: 256 bytes
- 연속된 64개의 uint32_t (4 × 64 = 256 bytes)가 하나의 캐시 라인에 저장
- 순차 접근 시 cache hit rate 최대화

#### 시간 지역성 (Temporal Locality)
```c
// ❌ 나쁜 예: 동일 데이터를 반복 읽기
for (int iter = 0; iter < 100; iter++) {
    for (int i = 0; i < 1000; i++) {
        data = read_memory(base + i * 4);
        process(data);
    }
}

// ✅ 좋은 예: 데이터를 레지스터에 캐싱
for (int i = 0; i < 1000; i++) {
    data = read_memory(base + i * 4);  // 한 번만 읽기
    for (int iter = 0; iter < 100; iter++) {
        process(data);  // 레지스터에서 재사용
    }
}
```

### 2. 캐시 라인 정렬 (Cache Line Alignment)

```c
// 데이터 구조체를 256-byte aligned로 정렬
struct alignas(256) CacheAlignedData {
    float data[64];  // 256 bytes = 1 cache line
};

// 장점:
// 1. False sharing 방지
// 2. 캐시 라인 경계를 넘지 않음
// 3. 최적의 캐시 효율
```

### 3. SIMD 패턴과 캐시 코얼레싱 (Coalescing)

```c
// 16-way SIMD에서 연속 메모리 접근
// Thread 0: address = base + 0
// Thread 1: address = base + 4
// Thread 2: address = base + 8
// ...
// Thread 15: address = base + 60

// 모든 쓰레드가 같은 캐시 라인 내에서 접근
// → TMU가 여러 요청을 하나의 캐시 라인 읽기로 병합 (coalescing)
```

**Coalescing 효과:**
```
Uncoalesced (bad):
  Thread 0: address 0x1000    → L1 cache line 0 read
  Thread 1: address 0x2000    → L1 cache line 1 read
  Thread 2: address 0x3000    → L1 cache line 2 read
  ...
  → 16 cache line reads (worst case)

Coalesced (good):
  Thread 0: address 0x1000    ┐
  Thread 1: address 0x1004    │
  Thread 2: address 0x1008    ├→ L1 cache line 0 read (coalesced)
  ...                         │
  Thread 15: address 0x103C   ┘
  → 1 cache line read (best case)
```

### 4. TMU Request Queue 관리

```c
// TMU request queue는 16 슬롯 (모든 쓰레드 공유)
// 예: 2개 쓰레드, 각각 10개 요청
// → 2 × 10 = 20 slots needed → OVERFLOW!

// 해결: 쓰레드 수 줄이기 또는 요청 분할
if (tmu_writes > 16 / threads) {
    threads /= 2;  // Mesa 코드에서 사용하는 패턴
}
```

### 5. Prefetch 활용

```c
// 순차 접근 패턴에서 prefetch atomic 사용
for (int i = 0; i < N; i++) {
    // Atomic add with prefetch
    atomic_add_with_prefetch(counter, 1);

    // 다음 반복에서 사용할 데이터가 이미 L1에 있음
    process(data[i + 1]);  // Prefetched!
}
```

---

## 실제 예제

### 예제 1: 기본 메모리 읽기/쓰기 (캐시 동작 추적)

```c
uint32_t input[16] = {1, 2, 3, ..., 16};   // 64 bytes (1/4 cache line)
uint32_t output[16];

// Thread 0-15가 병렬 실행:
// Thread ID = EIDX (0-15)

// 1. 주소 계산
offset = thread_id * 4;                    // 0, 4, 8, ..., 60
read_addr = input_base + offset;

// 2. 읽기 요청 (TMUA)
rf3 = read_addr;
TMUA = rf3;                                // L1 cache lookup

// Cache 동작:
// Cycle 0: TMUA write (16 addresses)
//          → TMU checks L1 cache
//          → All 16 addresses in same cache line
//          → L1 MISS (first access)
// Cycle 1-10: L1 fetches from L2 or DRAM
// Cycle 11: ldtmu (all 16 threads get data from L1)

// 3. 데이터 수신
NOP;  // Wait
ldtmu → rf10;                              // Data arrives

// 4. 연산
rf12 = rf10 + 100;

// 5. 쓰기 요청
write_addr = output_base + offset;
rf5 = write_addr;
TMUD = rf12;                               // Prepare data
TMUA = rf5;                                // Trigger write

// Cache 동작:
// Cycle 0: TMUA write (16 addresses for write)
//          → TMU checks L1 cache
//          → L1 MISS (output buffer not cached yet)
// Cycle 1-5: Allocate L1 cache line
// Cycle 6: Write data to L1
// Cycle 7: Mark cache line dirty
//          → Will be written back to L2/DRAM later

// 6. 완료 대기
TMUWT;                                     // Wait for all writes
```

**캐시 상태 변화:**
```
초기:
L1: [empty]
L2: [empty]

After read (cycle 11):
L1: [input cache line: 1,2,3,...,16] (clean)
L2: [input cache line: 1,2,3,...,16] (clean)

After write (cycle 7):
L1: [output cache line: 101,102,...,116] (dirty)
L2: [not updated yet]

After TMUWT or eviction:
L1: [output cache line: 101,102,...,116] (clean)
L2: [output cache line: 101,102,...,116] (dirty)
DRAM: [will be written later]
```

### 예제 2: Atomic 연산으로 캐시 제어

```c
// QPU 간 동기화를 위한 spinlock 구현
volatile uint32_t lock = 0;

// Thread 0이 lock 획득 시도:
void acquire_lock() {
    uint32_t expected = 0;
    uint32_t desired = 1;
    uint32_t old_value;

    do {
        // Atomic compare-exchange with cache flush
        TMUD = desired;                    // New value: 1
        TMUA = &lock;                      // Compare & exchange
        // Operation: V3D_TMU_OP_WRITE_CMPXCHG_READ_FLUSH

        TMUWT;                             // Wait for completion
        ldtmu → old_value;                 // Get old value

        // Cache 동작:
        // 1. L1 cache line for 'lock' is flushed
        // 2. Dirty data written to L2/DRAM
        // 3. Other QPUs will see updated value

    } while (old_value != expected);

    // Lock acquired!
}

void release_lock() {
    // Atomic exchange with flush
    TMUD = 0;                              // New value: 0
    TMUA = &lock;                          // Exchange
    // Operation: V3D_TMU_OP_WRITE_XCHG_READ_FLUSH

    TMUWT;

    // Cache flush ensures other QPUs see the release
}
```

### 예제 3: 캐시 최적화된 벡터 합

```c
// 1024개 요소 합산 (16 threads)
uint32_t input[1024];
uint32_t partial_sum[16];

// Each thread processes 64 elements (256 bytes = 1 cache line)
int thread_id = EIDX;
int start_idx = thread_id * 64;

uint32_t sum = 0;

// 연속 메모리 접근 → 최적의 캐시 활용
for (int i = 0; i < 64; i++) {
    uint32_t addr = input_base + (start_idx + i) * 4;

    // 첫 16개 요소: L1 cache miss → 캐시 라인 로드
    // 나머지 48개 요소: L1 cache hit (이미 로드됨)
    TMUA = addr;
    NOP;
    ldtmu → value;

    sum += value;
}

// 각 쓰레드의 부분 합을 저장
partial_sum[thread_id] = sum;

// Cache efficiency:
// - 64 reads per thread
// - 64 * 4 bytes = 256 bytes = 1 cache line
// - Only 1 L1 cache miss per thread
// - 64 - 1 = 63 cache hits per thread
// - Hit rate: 63/64 = 98.4%!
```

### 예제 4: L1 전체 클리어로 동기화

```c
// 여러 QPU가 공유 버퍼에 데이터 기록 후 동기화
volatile uint32_t sync_counter = 0;

// Phase 1: 각 QPU가 데이터 기록
write_my_data_to_shared_buffer();

// Phase 2: 카운터 증가 (atomic)
TMUD = 1;
TMUA = &sync_counter;
// V3D_TMU_OP_WRITE_ADD_READ_PREFETCH
TMUWT;

// Phase 3: 모든 QPU가 완료될 때까지 대기
while (1) {
    TMUA = &sync_counter;
    NOP;
    ldtmu → current_count;

    if (current_count == NUM_QPUS) {
        // 모든 QPU 완료!
        break;
    }
}

// Phase 4: 최종 동기화 - L1 전체 클리어
TMUD = NUM_QPUS;  // Keep the final value
TMUA = &sync_counter;
// V3D_TMU_OP_WRITE_UMIN_FULL_L1_CLEAR
TMUWT;

// 이제 모든 QPU의 L1 캐시가 클리어되었음
// → 공유 버퍼의 최신 데이터가 보장됨
```

---

## 성능 카운터

V3D는 TMU 캐시 성능을 모니터링하는 여러 카운터를 제공합니다:

### V3D 7.1 성능 카운터
```
카운터 이름                              │ 설명
───────────────────────────────────────┼─────────────────────────────
TMU-total-text-quads-access            │ 총 텍스처 캐시 접근 횟수
TMU-active-cycles                      │ TMU 활성 사이클
TMU-stalled-cycles                     │ TMU 정지 사이클
L2T-total-cache-hit                    │ L2 캐시 히트 수
L2T-total-cache-miss                   │ L2 캐시 미스 수
L2T-TMU-read-hits                      │ TMU에서 L2 읽기 히트
L2T-TMU-read-miss                      │ TMU에서 L2 읽기 미스
QPU-stalls-TMU                         │ QPU가 TMU 대기로 정지
```

### V3D 4.2 성능 카운터
```
카운터 이름                              │ 설명
───────────────────────────────────────┼─────────────────────────────
TMU-total-text-quads-access            │ 총 텍스처 캐시 접근 횟수
TMU-total-text-cache-miss              │ 텍스처 캐시 미스 수
L2T-total-cache-hit                    │ L2 캐시 히트 수
L2T-total-cache-miss                   │ L2 캐시 미스 수
L2T-TMU-reads                          │ TMU에서 L2 읽기 수
L2T-TMU-writes                         │ TMU에서 L2 쓰기 수
L2T-TMU-read-miss                      │ TMU에서 L2 읽기 미스
L2T-TMU-write-miss                     │ TMU에서 L2 쓰기 미스
```

---

## 주요 포인트 요약

### 1. 캐시 계층
- **L1 Texture Cache**: ~16 KB, TMU당 1개, ~5 cycle latency
- **L2 Cache (L2T)**: ~128 KB, 전체 공유, ~20 cycle latency
- **Cache Line**: 256 bytes (64 × uint32_t)

### 2. TMU 명령어
- **기본 접근**: TMUA (read/write), TMUD (write data), ldtmu (read data)
- **텍스처 샘플링**: TMUS, TMUSF, TMUSLOD, TMUSCM
- **구성**: TMUC (wrtmuc signal로 P0/P1/P2 파라미터 설정)

### 3. 캐시 제어
- **Flush**: V3D_TMU_OP_WRITE_XCHG_READ_FLUSH (캐시 라인 플러시)
- **L1 Clear**: V3D_TMU_OP_WRITE_UMIN_FULL_L1_CLEAR (L1 전체 무효화)
- **Prefetch**: V3D_TMU_OP_WRITE_ADD_READ_PREFETCH (인접 데이터 프리페치)

### 4. 최적화 전략
- **공간 지역성**: 연속 메모리 접근으로 캐시 라인 재사용
- **시간 지역성**: 반복 사용 데이터를 레지스터에 유지
- **Coalescing**: SIMD 쓰레드들의 메모리 접근을 병합
- **정렬**: 256-byte aligned 데이터 구조 사용

### 5. 동기화
- **TMUWT**: 모든 TMU 쓰기 완료 대기
- **Atomic ops**: 캐시 플러시를 포함한 원자 연산으로 일관성 보장
- **SYNC**: QPU 간 배리어와 TMU 동기화 결합

---

## 참고 자료

- **V3D GPU Architecture**: Broadcom VideoCore VII
- **Driver**: Linux kernel v3d DRM driver
- **ISA**: V3D 7.1 Instruction Set Architecture
- **Hardware**: Raspberry Pi 5 (BCM2712)
- **Mesa Source**: `v3d_tex.c`, `nir_to_vir.c`, `v3d_compiler.h`
- **Performance Counters**: `v3d_performance_counters.h`

이 문서는 V3D TMU 캐시 아키텍처와 관련 명령어의 상세한 동작 원리를 설명합니다.
