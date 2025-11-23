# nir_to_vir.c - NIR에서 VIR로 변환

## 파일 정보
- **경로**: `medusa/broadcom/compiler/nir_to_vir.c`
- **역할**: NIR (공통 중간 표현)을 VIR (V3D IR, V3D 전용 중간 표현)로 변환
- **크기**: ~5000 라인의 핵심 백엔드 코드
- **중요도**: ★★★★★ (V3D 컴파일러의 핵심)

## 개요

`nir_to_vir.c`는 V3D 컴파일러의 가장 중요한 파일 중 하나입니다. 하드웨어 독립적인 NIR을 V3D GPU의 특성에 맞는 VIR로 변환합니다. 이 과정에서 compute shader의 모든 특수 기능이 V3D 하드웨어 명령어로 매핑됩니다.

---

## 주요 함수

### v3d_nir_to_vir()

```c
void
v3d_nir_to_vir(struct v3d_compile *c);
```

#### 역할
- NIR 함수를 VIR 명령어 시퀀스로 변환
- Compute shader 초기화 코드 생성
- System value 로드 구현
- Intrinsic 함수 처리

---

## Compute Shader 초기화

### Payload 레지스터 설정

**V3D 4.x** (from line 4779):
```c
if (c->s->info.stage == MESA_SHADER_COMPUTE) {
    if (c->devinfo->ver < 71) {
        c->cs_payload[0] = vir_MOV(c, vir_reg(QFILE_REG, 0));
        c->cs_payload[1] = vir_MOV(c, vir_reg(QFILE_REG, 2));
    } else {
        c->cs_payload[0] = vir_MOV(c, vir_reg(QFILE_REG, 3));
        c->cs_payload[1] = vir_MOV(c, vir_reg(QFILE_REG, 2));
    }
}
```

#### Payload 레지스터 구조

**cs_payload[0]** - Workgroup ID:
```
Bits [15:0]:  Workgroup ID X
Bits [23:16]: Workgroup ID Y
Bits [31:24]: (Reserved or other data)
```

**cs_payload[1]** - Workgroup Z and Local Invocation:
```
Bits [7:0]:   Workgroup ID Z
Bits [23:8]:  (Workgroup memory offset)
Bits [31:24]: Local Invocation Index (상위 8비트)
```

### Local Invocation Index 비트 수 계산

```c
int wg_size = (c->s->info.workgroup_size[0] *
               c->s->info.workgroup_size[1] *
               c->s->info.workgroup_size[2]);

c->local_invocation_index_bits =
    ffs(wg_size) == util_last_bit(wg_size) ? ffs(wg_size) - 1 : 8;

assert(c->local_invocation_index_bits <= 8);
```

#### 설명
- `ffs()`: Find First Set (첫 번째 1 비트의 위치)
- `util_last_bit()`: 최상위 1 비트의 위치
- 두 값이 같으면 wg_size가 2의 거듭제곱 → 정확한 비트 수 사용
- 다르면 최대 8비트 사용

#### 예시
```c
// local_size = {256, 1, 1}
// wg_size = 256 = 0b100000000
// ffs(256) = 9, util_last_bit(256) = 9
// → local_invocation_index_bits = 8

// local_size = {16, 16, 1}
// wg_size = 256
// → local_invocation_index_bits = 8

// local_size = {100, 1, 1}
// wg_size = 100 = 0b1100100
// ffs(100) = 3, util_last_bit(100) = 7
// → local_invocation_index_bits = 8 (최대값 사용)
```

---

## Shared Memory 초기화

```c
if (c->s->info.shared_size || c->s->info.cs.has_variable_shared_mem) {
    struct qreg wg_in_mem = vir_SHR(c, c->cs_payload[1],
                                    vir_uniform_ui(c, 8));

    if (c->s->info.workgroup_size[0] != 1 ||
        c->s->info.workgroup_size[1] != 1 ||
        c->s->info.workgroup_size[2] != 1) {
        wg_in_mem = vir_UMUL(c, wg_in_mem,
                            vir_uniform_ui(c, c->local_invocation_index_bits));
    }

    c->cs_shared_offset =
        vir_ADD(c,
                vir_uniform(c, QUNIFORM_SHARED_OFFSET, 0),
                wg_in_mem);

    if (c->s->info.cs.has_variable_shared_mem) {
        c->cs_shared_offset =
            vir_ADD(c, c->cs_shared_offset,
                    vir_uniform(c, QUNIFORM_SHARED_SIZE, 0));
    }
}
```

### 단계별 설명

#### 1. Workgroup의 메모리 내 위치 추출
```c
struct qreg wg_in_mem = vir_SHR(c, c->cs_payload[1], vir_uniform_ui(c, 8));
```
- `cs_payload[1]`의 bits [23:8]에 workgroup 메모리 오프셋이 저장됨
- 8비트 right shift로 추출

#### 2. Workgroup 크기 고려
```c
if (workgroup_size > 1) {
    wg_in_mem = vir_UMUL(c, wg_in_mem,
                        vir_uniform_ui(c, c->local_invocation_index_bits));
}
```
- Workgroup이 여러 thread를 가지면 local invocation index 비트 수로 곱함
- 이유: 각 workgroup의 shared memory 영역 크기를 반영

#### 3. 베이스 주소와 합산
```c
c->cs_shared_offset = vir_ADD(c,
    vir_uniform(c, QUNIFORM_SHARED_OFFSET, 0),
    wg_in_mem);
```
- `QUNIFORM_SHARED_OFFSET`: L2T 캐시의 베이스 주소
- `wg_in_mem`: 이 workgroup의 오프셋
- 결과: 이 workgroup의 shared memory 시작 주소

#### 4. Variable Shared Memory 처리
```c
if (c->s->info.cs.has_variable_shared_mem) {
    c->cs_shared_offset = vir_ADD(c, c->cs_shared_offset,
                                  vir_uniform(c, QUNIFORM_SHARED_SIZE, 0));
}
```
- OpenCL의 동적 shared memory 지원
- Vulkan에서는 일반적으로 사용하지 않음

---

## System Value Intrinsic 처리

### emit_load_local_invocation_index()

```c
static struct qreg
emit_load_local_invocation_index(struct v3d_compile *c)
{
    return vir_SHR(c, c->cs_payload[1],
                   vir_uniform_ui(c, 32 - c->local_invocation_index_bits));
}
```

#### 설명
- `cs_payload[1]`의 상위 비트에서 local invocation index 추출
- `32 - local_invocation_index_bits` 만큼 right shift

#### 예시
```c
// local_invocation_index_bits = 8
// cs_payload[1] = 0xAB??????   (AB = local invocation index in hex)
// shift = 32 - 8 = 24
// result = 0x000000AB
```

### load_workgroup_id

**NIR Intrinsic**:
```c
case nir_intrinsic_load_workgroup_id:
```

**VIR 구현** (from line 3714):
```c
struct qreg x = vir_AND(c, c->cs_payload[0],
                       vir_uniform_ui(c, 0xffff));

struct qreg y = vir_SHR(c, c->cs_payload[0],
                       vir_uniform_ui(c, 16));
y = vir_AND(c, y, vir_uniform_ui(c, 0xff));

struct qreg z = vir_AND(c, c->cs_payload[1],
                       vir_uniform_ui(c, 0xff));

ntq_store_def(c, &instr->def, 0, x);
ntq_store_def(c, &instr->def, 1, y);
ntq_store_def(c, &instr->def, 2, z);
```

#### 비트 마스킹 과정

**X (bits [15:0])**:
```
cs_payload[0] = 0x??YYYXXX
AND 0xFFFF    = 0x0000XXXX
→ Workgroup ID X
```

**Y (bits [23:16])**:
```
cs_payload[0] = 0x??YYYXXX
SHR 16        = 0x0000??YY
AND 0xFF      = 0x000000YY
→ Workgroup ID Y
```

**Z (bits [7:0])**:
```
cs_payload[1] = 0x??????ZZ
AND 0xFF      = 0x000000ZZ
→ Workgroup ID Z
```

### load_num_workgroups

```c
case nir_intrinsic_load_num_workgroups:
    for (int i = 0; i < 3; i++) {
        ntq_store_def(c, &instr->def, i,
                      vir_uniform(c, QUNIFORM_NUM_WORK_GROUPS, i));
    }
    break;
```

#### 설명
- Dispatch 시 지정된 workgroup 개수를 uniform으로 전달
- 각 차원(X, Y, Z)마다 별도의 uniform

#### GLSL 사용 예시
```glsl
uvec3 num_wg = gl_NumWorkGroups;
uint total_threads = num_wg.x * num_wg.y * num_wg.z *
                     gl_WorkGroupSize.x * gl_WorkGroupSize.y * gl_WorkGroupSize.z;
```

### load_base_workgroup_id

```c
case nir_intrinsic_load_base_workgroup_id:
    for (int i = 0; i < 3; i++) {
        ntq_store_def(c, &instr->def, i,
                      vir_uniform(c, QUNIFORM_WORK_GROUP_BASE, i));
    }
    break;
```

#### Vulkan 사용 예시
```c
// vkCmdDispatchBase()
vkCmdDispatchBase(
    commandBuffer,
    10, 20, 0,     // base group X, Y, Z
    100, 50, 1,    // group count X, Y, Z
    // ...
);

// Shader 내에서:
// gl_WorkGroupID는 자동으로 baseGroup이 더해진 값
```

### load_workgroup_size

```c
case nir_intrinsic_load_workgroup_size:
    if (c->s->info.workgroup_size_variable) {
        for (int i = 0; i < 3; i++) {
            ntq_store_def(c, &instr->def, i,
                          vir_uniform(c, QUNIFORM_WORK_GROUP_SIZE, i));
        }
    } else {
        for (int i = 0; i < 3; i++) {
            ntq_store_def(c, &instr->def, i,
                          vir_uniform_ui(c, c->s->info.workgroup_size[i]));
        }
    }
    break;
```

#### 설명
- **Variable mode**: Uniform으로 전달 (런타임 결정)
- **Fixed mode**: Immediate 값 사용 (컴파일 타임 상수)

#### GLSL 예시
```glsl
layout(local_size_x = 256) in;

void main() {
    // 컴파일 타임 상수:
    uint size = gl_WorkGroupSize.x;  // = 256 (immediate)
}
```

---

## Barrier 구현

### Control Barrier

**NIR Intrinsic**:
```c
case nir_intrinsic_barrier:
```

**VIR 구현** (추정, 실제 코드는 더 복잡할 수 있음):
```c
// TSY (Thread Synchronization) 명령어 생성
emit_tsy_op(c, V3D_TSY_WAIT);

// 또는
struct qinst *barrier = vir_NOP(c);
barrier->qpu.sig.thrsw = true;  // Thread switch
```

**주석** (from line 3408):
```c
/* Emit a TSY op to get all invocations in the workgroup
 * (actually supergroup) to block until the last invocation
 * reaches this point.
 */
```

#### V3D의 Barrier 구현 방식
1. **TSY 명령어 사용**: Thread synchronization unit 활용
2. **Supergroup 단위**: V3D는 workgroup보다 큰 "supergroup" 단위로 동기화
3. **Hardware barrier**: 소프트웨어 루프 없이 하드웨어가 직접 처리

### GLSL 예시
```glsl
shared float data[256];

void main() {
    uint tid = gl_LocalInvocationIndex;

    data[tid] = compute_value();

    barrier();  // ← TSY 명령어로 변환

    float neighbor = data[(tid + 1) % 256];
}
```

---

## Shared Memory 접근

### Shared Load

**NIR**:
```c
nir_intrinsic_load_shared
```

**VIR 구현 개념**:
```c
// 1. 주소 계산
qreg base = c->cs_shared_offset;
qreg offset = ... (from intrinsic);
qreg addr = vir_ADD(c, base, offset);

// 2. TMU (Texture Memory Unit) load
qreg result = emit_tmu_general_load(c, addr, ...);
```

### Shared Store

**NIR**:
```c
nir_intrinsic_store_shared
```

**VIR 구현 개념**:
```c
// 1. 주소 계산
qreg addr = vir_ADD(c, c->cs_shared_offset, offset);

// 2. TMU store
emit_tmu_general_store(c, addr, value, ...);
```

### GLSL 예시
```glsl
shared vec4 temp[64];

void main() {
    uint lid = gl_LocalInvocationIndex;

    // Store: temp[lid] = vec4(1.0);
    // VIR:
    // addr = cs_shared_offset + lid * 16
    // TMU_STORE(addr, vec4(1.0))

    temp[lid] = vec4(1.0);

    barrier();

    // Load: vec4 value = temp[(lid + 1) % 64];
    // VIR:
    // offset = ((lid + 1) % 64) * 16
    // addr = cs_shared_offset + offset
    // result = TMU_LOAD(addr)

    vec4 value = temp[(lid + 1) % 64];
}
```

---

## TMU (Texture Memory Unit) 활용

### TMU Operation Types

```c
enum v3d_tmu_op_type {
    V3D_TMU_OP_TYPE_REGULAR,   // 일반 load/store
    V3D_TMU_OP_TYPE_ATOMIC,    // Atomic 연산
    V3D_TMU_OP_TYPE_CACHE      // Cache control
};
```

### Atomic 연산

**NIR**:
```c
nir_intrinsic_shared_atomic_add
```

**VIR 구현**:
```c
qreg addr = compute_shared_address(...);
qreg value = ...;

// TMU atomic add
uint32_t tmu_op = V3D_TMU_OP_WRITE_ADD_READ_PREFETCH;
qreg result = emit_tmu_atomic(c, addr, value, tmu_op);
```

**GLSL 예시**:
```glsl
shared uint counter;

void main() {
    // counter += 1;
    atomicAdd(counter, 1u);
}
```

**생성되는 VIR (개념)**:
```
addr = cs_shared_offset + offsetof(counter)
result = TMU_ATOMIC_ADD(addr, 1)
```

---

## Subgroup 연산

### Ballot

**NIR**:
```c
nir_intrinsic_ballot
```

**VIR 구현** (V3D 4.x):
```c
case nir_intrinsic_ballot: {
    nir_def *src = instr->src[0].ssa;

    // V3D의 BALLOT SFU (Special Function Unit) 사용
    struct qreg ballot_result = vir_BALLOT(c, ntq_get_src(c, src, 0));

    // uvec4로 확장 (subgroup size가 16이므로 하위 16비트만 사용)
    for (int i = 0; i < 4; i++) {
        if (i == 0) {
            ntq_store_def(c, &instr->def, i, ballot_result);
        } else {
            ntq_store_def(c, &instr->def, i, vir_uniform_ui(c, 0));
        }
    }
    break;
}
```

**GLSL 예시**:
```glsl
bool condition = (gl_LocalInvocationIndex % 2) == 0;
uvec4 mask = subgroupBallot(condition);
// mask.x의 하위 16비트에 각 lane의 condition 결과가 비트로 저장됨
```

### Shuffle

**NIR**:
```c
nir_intrinsic_shuffle
```

**VIR 구현**:
```c
case nir_intrinsic_shuffle: {
    struct qreg value = ntq_get_src(c, instr->src[0].ssa, 0);
    struct qreg lane_id = ntq_get_src(c, instr->src[1].ssa, 0);

    // V3D의 SHUFFLE SFU 사용
    struct qreg result = vir_SHUFFLE(c, value, lane_id);

    ntq_store_def(c, &instr->def, 0, result);
    break;
}
```

**GLSL 예시**:
```glsl
float value = input_data[gl_LocalInvocationIndex];
float neighbor = subgroupShuffle(value, (gl_SubgroupInvocationID + 1) % gl_SubgroupSize);
```

---

## 실제 코드 예시

### Example 1: 간단한 Add Shader

**GLSL**:
```glsl
#version 450
layout(local_size_x = 256) in;

layout(std430, binding = 0) buffer A { float a[]; };
layout(std430, binding = 1) buffer B { float b[]; };
layout(std430, binding = 2) buffer C { float c[]; };

void main() {
    uint gid = gl_GlobalInvocationID.x;
    c[gid] = a[gid] + b[gid];
}
```

**생성되는 VIR (의사 코드)**:
```
// Compute shader 초기화
cs_payload[0] = REG[0]
cs_payload[1] = REG[2]

// gl_GlobalInvocationID.x 계산
wg_id_x = cs_payload[0] & 0xFFFF
local_id_x = cs_payload[1] >> 24
gid = wg_id_x * 256 + local_id_x

// a[gid] 로드
a_base = UNIFORM(SSBO_0_BASE)
a_offset = gid * 4
a_addr = a_base + a_offset
a_value = TMU_LOAD(a_addr)

// b[gid] 로드
b_base = UNIFORM(SSBO_1_BASE)
b_offset = gid * 4
b_addr = b_base + b_offset
b_value = TMU_LOAD(b_addr)

// c[gid] = a[gid] + b[gid]
result = FADD(a_value, b_value)
c_base = UNIFORM(SSBO_2_BASE)
c_offset = gid * 4
c_addr = c_base + c_offset
TMU_STORE(c_addr, result)
```

### Example 2: Reduction with Shared Memory

**GLSL**:
```glsl
#version 450
layout(local_size_x = 256) in;

shared float sdata[256];

layout(std430, binding = 0) buffer Input { float data[]; };
layout(std430, binding = 1) buffer Output { float result; };

void main() {
    uint tid = gl_LocalInvocationIndex;
    uint gid = gl_GlobalInvocationID.x;

    sdata[tid] = data[gid];
    barrier();

    for (uint s = 128; s > 0; s >>= 1) {
        if (tid < s) {
            sdata[tid] += sdata[tid + s];
        }
        barrier();
    }

    if (tid == 0) {
        atomicAdd(result, sdata[0]);
    }
}
```

**생성되는 VIR (주요 부분)**:
```
// 초기화
cs_payload[0] = REG[0]
cs_payload[1] = REG[2]
local_invocation_index_bits = 8

// Shared memory 베이스 계산
wg_in_mem = cs_payload[1] >> 8
wg_in_mem = wg_in_mem * 8  // local_invocation_index_bits
cs_shared_offset = UNIFORM(QUNIFORM_SHARED_OFFSET) + wg_in_mem

// tid, gid 계산
tid = cs_payload[1] >> 24
wg_id_x = cs_payload[0] & 0xFFFF
gid = wg_id_x * 256 + tid

// sdata[tid] = data[gid];
data_addr = SSBO_BASE + gid * 4
value = TMU_LOAD(data_addr)
shared_addr = cs_shared_offset + tid * 4
TMU_STORE(shared_addr, value)

// barrier();
TSY V3D_TSY_WAIT

// Reduction loop
s = 128
LOOP:
    cond = tid < s
    IF (cond) {
        addr1 = cs_shared_offset + tid * 4
        val1 = TMU_LOAD(addr1)

        addr2 = cs_shared_offset + (tid + s) * 4
        val2 = TMU_LOAD(addr2)

        sum = FADD(val1, val2)
        TMU_STORE(addr1, sum)
    }
    TSY V3D_TSY_WAIT

    s = s >> 1
    IF (s > 0) GOTO LOOP

// if (tid == 0) atomicAdd(result, sdata[0]);
IF (tid == 0) {
    shared_addr = cs_shared_offset
    final_val = TMU_LOAD(shared_addr)
    result_addr = SSBO_RESULT_BASE
    TMU_ATOMIC_ADD(result_addr, final_val)
}
```

---

## 최적화 기법

### 1. TMU Pipelining

```c
// 여러 TMU load를 연속으로 발행하여 latency 숨김
qreg addr1 = ...;
qreg addr2 = ...;

// 두 load를 연속 발행
emit_tmu_load(c, addr1);
emit_tmu_load(c, addr2);

// 나중에 결과 수집
qreg result1 = vir_LDTMU(c);
qreg result2 = vir_LDTMU(c);
```

### 2. Uniform Load 최적화

```c
// 같은 UBO에서 연속된 오프셋의 데이터 로드 시
// unifa 레지스터 업데이트 최소화
if (c->current_unifa_block == block &&
    c->current_unifa_index == ubo_index &&
    offset == c->current_unifa_offset) {
    // Skip unifa write, just emit ldunifa
} else {
    // Update unifa
}
```

---

## 디버깅

### VIR 출력

```c
// 컴파일 중
v3d_nir_to_vir(c);

// VIR 출력
vir_dump(c);
```

**출력 예시**:
```
t0 = mov r0
t1 = mov r2
t2 = and t0, 0xffff
t3 = shr t0, 16
t4 = and t3, 0xff
t5 = uniform(QUNIFORM_SSBO_OFFSET, 0)
...
```

### 환경 변수

```bash
V3D_DEBUG=vir ./my_app
```

---

## 정리

### nir_to_vir.c의 핵심 역할

1. **Compute Shader 초기화**
   - Payload 레지스터 설정
   - Shared memory 베이스 주소 계산
   - Local invocation index 비트 수 결정

2. **System Value 구현**
   - `gl_GlobalInvocationID`: Workgroup ID와 Local ID 조합
   - `gl_LocalInvocationIndex`: Payload에서 추출
   - `gl_NumWorkGroups`: Uniform 로드

3. **Barrier 처리**
   - `barrier()` → TSY 명령어

4. **Shared Memory**
   - 주소 계산: `cs_shared_offset + offset`
   - TMU 사용: General memory operations

5. **Subgroup 연산**
   - V3D SFU (Special Function Unit) 활용
   - BALLOT, SHUFFLE 등

### 다음 단계

NIR → VIR 변환 후:
1. VIR 최적화 (`vir_opt_*`)
2. 레지스터 할당 (`vir_register_allocate.c`)
3. QPU 스케줄링 (`qpu_schedule.c`)
4. VIR → QPU 변환 (`vir_to_qpu.c`)

`nir_to_vir.c`는 하드웨어 독립적인 NIR을 V3D 특화 VIR로 변환하여, 이후 단계에서 효율적인 기계어를 생성할 수 있도록 합니다.
