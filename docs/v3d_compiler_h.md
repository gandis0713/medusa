# v3d_compiler.h - V3D 컴파일러 핵심 구조체

## 파일 정보
- **경로**: `medusa/broadcom/compiler/v3d_compiler.h`
- **역할**: Broadcom V3D GPU 컴파일러의 핵심 데이터 구조 및 API 정의
- **타겟 하드웨어**: Raspberry Pi 4 (V3D 4.2), Raspberry Pi 5 (V3D 7.x)

## 개요

`v3d_compiler.h`는 V3D GPU용 컴파일러의 모든 핵심 구조체, 열거형, 함수를 정의합니다. NIR (중간 표현)을 VIR (V3D IR)로 변환하고, 최종적으로 QPU (V3D의 처리 유닛) 기계어로 컴파일하는 전 과정을 관리합니다.

---

## Compute Shader 관련 핵심 구조체

### 1. v3d_compute_prog_data

Compute shader의 최종 컴파일 결과를 담는 구조체입니다.

```c
struct v3d_compute_prog_data {
    struct v3d_prog_data base;

    /* Size in bytes of the workgroup's shared space. */
    uint32_t shared_size;

    uint16_t local_size[3];

    /* If the shader uses subgroup functionality */
    bool has_subgroups;
};
```

#### 필드 설명

##### shared_size
- **타입**: `uint32_t`
- **용도**: Workgroup shared memory 크기 (바이트 단위)
- **예시**: `shared vec4 data[64];` → `shared_size = 256 * 4 = 1024`
- **V3D 제약**: L2T 캐시 크기에 의해 제한됨

##### local_size[3]
- **타입**: `uint16_t[3]`
- **용도**: Local workgroup 크기 (X, Y, Z)
- **예시**: `layout(local_size_x = 256) in;` → `local_size = {256, 1, 1}`
- **V3D 제약**: 총 invocation 수는 일반적으로 256 이하

##### has_subgroups
- **타입**: `bool`
- **용도**: Subgroup intrinsic 사용 여부
- **예시**: `subgroupBallot()`, `subgroupShuffle()` 등 사용 시 `true`
- **V3D**: Subgroup 크기는 일반적으로 16

---

### 2. v3d_compile

컴파일 컨텍스트를 담는 구조체로, 컴파일 과정의 모든 상태를 관리합니다.

```c
struct v3d_compile {
    const struct v3d_device_info *devinfo;
    nir_shader *s;
    nir_function_impl *impl;

    // ... (많은 필드들)

    /* Compute shader 전용 필드들 */
    struct qreg cs_payload[2];
    struct qreg cs_shared_offset;
    int local_invocation_index_bits;

    // ... (더 많은 필드들)
};
```

#### Compute Shader 관련 핵심 필드

##### cs_payload[2]
```c
struct qreg cs_payload[2];
```

- **용도**: Compute shader의 페이로드 레지스터
- **내용**:
  - `cs_payload[0]`: Workgroup ID 정보
    - Bits [15:0]: Workgroup ID X
    - Bits [23:16]: Workgroup ID Y
  - `cs_payload[1]`: Local invocation 및 Workgroup ID Z 정보
    - Bits [7:0]: Workgroup ID Z
    - Bits [31:24]: Local invocation index (상위 8비트)

**V3D 4.x 코드 예시** (from nir_to_vir.c:4779):
```c
c->cs_payload[0] = vir_MOV(c, vir_reg(QFILE_REG, 0));  // 레지스터 0에서 로드
c->cs_payload[1] = vir_MOV(c, vir_reg(QFILE_REG, 2));  // 레지스터 2에서 로드
```

**V3D 7.x 코드 예시** (from nir_to_vir.c:4782):
```c
c->cs_payload[0] = vir_MOV(c, vir_reg(QFILE_REG, 3));  // 레지스터 3에서 로드
c->cs_payload[1] = vir_MOV(c, vir_reg(QFILE_REG, 2));  // 레지스터 2에서 로드
```

##### cs_shared_offset
```c
struct qreg cs_shared_offset;
```

- **용도**: Shared memory의 베이스 주소
- **계산**: Workgroup 메모리 위치 + Local invocation index 기반 오프셋
- **사용 예시**:
  ```c
  // shared vec4 data[256];
  // data[gl_LocalInvocationIndex] = ...;

  // 생성되는 코드:
  qreg addr = vir_ADD(c, c->cs_shared_offset,
                      vir_uniform(c, QUNIFORM_SHARED_OFFSET, 0));
  ```

##### local_invocation_index_bits
```c
int local_invocation_index_bits;
```

- **용도**: Local invocation index를 표현하는 데 필요한 비트 수
- **계산**: `ceil(log2(workgroup_size[0] * workgroup_size[1] * workgroup_size[2]))`
- **제약**: V3D에서는 최대 8비트 (256 invocations)
- **예시**:
  - `local_size = {256, 1, 1}` → `local_invocation_index_bits = 8`
  - `local_size = {16, 16, 1}` → `local_invocation_index_bits = 8`
  - `local_size = {8, 8, 4}` → `local_invocation_index_bits = 9` (오류!)

**코드 예시** (from nir_to_vir.c:4789):
```c
int wg_size = (c->s->info.workgroup_size[0] *
               c->s->info.workgroup_size[1] *
               c->s->info.workgroup_size[2]);
c->local_invocation_index_bits =
    ffs(wg_size) == util_last_bit(wg_size) ? ffs(wg_size) - 1 : 8;
assert(c->local_invocation_index_bits <= 8);
```

---

## Uniform 관련 열거형: quniform_contents

Compute shader에서 사용하는 uniform 타입들입니다.

### Compute Shader 전용 Uniforms

```c
enum quniform_contents {
    // ... (다른 uniform 타입들)

    /* Number of workgroups passed to glDispatchCompute in the dimension
     * selected by the data value.
     */
    QUNIFORM_NUM_WORK_GROUPS,

    /* Base workgroup offset passed to vkCmdDispatchBase in the dimension
     * selected by the data value.
     */
    QUNIFORM_WORK_GROUP_BASE,

    /* Workgroup size for variable workgroup support */
    QUNIFORM_WORK_GROUP_SIZE,

    /**
     * Returns the offset of the shared memory for compute shaders.
     *
     * This will be accessed using TMU general memory operations, so the
     * L2T cache will effectively be the shared memory area.
     */
    QUNIFORM_SHARED_OFFSET,

    /**
     * OpenCL variable shared memory
     *
     * This will only be used when the shader declares variable_shared_memory.
     */
    QUNIFORM_SHARED_SIZE,

    // ... (다른 uniform 타입들)
};
```

#### QUNIFORM_NUM_WORK_GROUPS
- **용도**: `glDispatchCompute()` 또는 `vkCmdDispatch()`로 전달된 workgroup 개수
- **GLSL**: `gl_NumWorkGroups.xyz`
- **데이터**: Dimension index (0=X, 1=Y, 2=Z)
- **사용 예시**:
  ```c
  // GLSL:
  // uint num_x = gl_NumWorkGroups.x;

  // 생성되는 VIR:
  vir_uniform(c, QUNIFORM_NUM_WORK_GROUPS, 0);  // X dimension
  ```

#### QUNIFORM_WORK_GROUP_BASE
- **용도**: `vkCmdDispatchBase()`의 base offset
- **Vulkan 전용**: `VK_KHR_device_group` 확장
- **GLSL**: 없음 (내부적으로 `gl_WorkGroupID`에 더해짐)
- **데이터**: Dimension index (0=X, 1=Y, 2=Z)

#### QUNIFORM_WORK_GROUP_SIZE
- **용도**: Variable workgroup size 지원
- **GLSL**: `gl_WorkGroupSize.xyz` (variable 모드에서)
- **일반적으로**: Compile time constant로 처리됨

#### QUNIFORM_SHARED_OFFSET
- **용도**: Shared memory의 베이스 주소
- **V3D 구현**: TMU (Texture Memory Unit)의 L2T 캐시 사용
- **계산**: Workgroup ID와 shared memory 크기로부터 계산
- **사용 예시**:
  ```c
  // shared float data[256];
  // data[tid] = value;

  // 주소 계산:
  qreg shared_base = vir_uniform(c, QUNIFORM_SHARED_OFFSET, 0);
  qreg offset = vir_MUL(c, tid, vir_uniform_ui(c, 4));  // sizeof(float)
  qreg addr = vir_ADD(c, shared_base, offset);
  ```

#### QUNIFORM_SHARED_SIZE
- **용도**: 동적 shared memory 크기 (OpenCL)
- **OpenCL**: `__local void *ptr` 파라미터
- **Vulkan**: 일반적으로 사용하지 않음 (컴파일 타임에 결정)

---

## System Value Intrinsics 구현

### load_workgroup_id 처리

**코드** (from nir_to_vir.c:3714):
```c
case nir_intrinsic_load_workgroup_id: {
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
    break;
}
```

**설명**:
- `cs_payload[0]`에서 X (하위 16비트), Y (상위 8비트) 추출
- `cs_payload[1]`에서 Z (하위 8비트) 추출

**GLSL 예시**:
```glsl
uvec3 wgid = gl_WorkGroupID;  // X, Y, Z
```

### load_local_invocation_index 처리

**함수** (from nir_to_vir.c:3346):
```c
static struct qreg
emit_load_local_invocation_index(struct v3d_compile *c)
{
    return vir_SHR(c, c->cs_payload[1],
                   vir_uniform_ui(c, 32 - c->local_invocation_index_bits));
}
```

**설명**:
- `cs_payload[1]`의 상위 비트에 local invocation index가 저장됨
- Right shift로 추출

**GLSL 예시**:
```glsl
uint lid = gl_LocalInvocationIndex;
```

### load_base_workgroup_id 처리

**코드** (from nir_to_vir.c:3729):
```c
case nir_intrinsic_load_base_workgroup_id: {
    ntq_store_def(c, &instr->def, 0,
                  vir_uniform(c, QUNIFORM_WORK_GROUP_BASE, 0));
    ntq_store_def(c, &instr->def, 1,
                  vir_uniform(c, QUNIFORM_WORK_GROUP_BASE, 1));
    ntq_store_def(c, &instr->def, 2,
                  vir_uniform(c, QUNIFORM_WORK_GROUP_BASE, 2));
    break;
}
```

**Vulkan 사용 예시**:
```c
// vkCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, ...)
// GLSL에서는 gl_WorkGroupID에 자동으로 더해짐
```

---

## Shared Memory 초기화

**코드** (from nir_to_vir.c:4796):
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
}
```

**설명**:
1. `cs_payload[1]`에서 workgroup의 메모리 내 위치 추출
2. Workgroup 크기가 1보다 크면 local invocation index 비트 수로 곱함
3. 베이스 오프셋과 더하여 최종 shared memory 주소 계산

---

## Barrier 구현

### Control Barrier

Compute shader에서 `barrier()`를 만나면 V3D의 TSY (Thread Synchronization) 명령어를 생성합니다.

**관련 상수** (from nir_to_vir.c:54):
```c
#define V3D_TSY_SET_QUORUM          0
#define V3D_TSY_INC_WAITERS         1
#define V3D_TSY_DEC_WAITERS         2
// ... (더 많은 TSY 명령어)
#define V3D_TSY_WAIT                8
#define V3D_TSY_WAIT_INC            9
// ...
```

**GLSL 예시**:
```glsl
shared float data[256];

void main() {
    uint tid = gl_LocalInvocationIndex;
    data[tid] = compute_value();

    barrier();  // ← V3D_TSY_WAIT 명령어 생성

    float result = data[(tid + 1) % 256];
}
```

**컴파일러 주석** (from nir_to_vir.c:3408):
```c
/* Emit a TSY op to get all invocations in the workgroup
 * (actually supergroup) to block until the last invocation
 * reaches this point.
 */
```

---

## 최적화 관련 플래그

### Compute Shader 특화 최적화

```c
struct v3d_compile {
    // ...

    /* Disable TMU pipelining. This may increase the chances of being able
     * to compile shaders with high register pressure that require to emit
     * TMU spills.
     */
    bool disable_tmu_pipelining;

    /* Disable sorting of UBO loads with constant offset. This may
     * increase the chances of being able to compile shaders with high
     * register pressure.
     */
    bool disable_constant_ubo_load_sorting;

    /* Moves UBO/SSBO loads right before their first user (nir_opt_move).
     * This can reduce register pressure.
     */
    bool move_buffer_loads;

    // ...
};
```

#### Compute Shader에서의 중요성
- **높은 레지스터 압력**: Workgroup 크기가 클수록 더 많은 레지스터 필요
- **TMU 사용 많음**: SSBO, shared memory 접근이 빈번
- **최적화 전략**: 레지스터 압력을 줄이기 위해 일부 최적화 비활성화

---

## 실제 사용 예시

### 1. 간단한 Vector Add

```glsl
#version 450
layout(local_size_x = 256) in;

layout(std430, binding = 0) buffer InputA {
    float a[];
};

layout(std430, binding = 1) buffer InputB {
    float b[];
};

layout(std430, binding = 2) buffer Output {
    float c[];
};

void main() {
    uint gid = gl_GlobalInvocationID.x;
    c[gid] = a[gid] + b[gid];
}
```

**생성되는 v3d_compute_prog_data**:
```c
v3d_compute_prog_data prog_data = {
    .shared_size = 0,
    .local_size = {256, 1, 1},
    .has_subgroups = false,
    .base = {
        .threads = 2,  // V3D는 일반적으로 2-way threading
        .has_control_barrier = false,
        // ...
    }
};
```

### 2. Shared Memory Reduction

```glsl
#version 450
layout(local_size_x = 256) in;

shared float sdata[256];

layout(std430, binding = 0) buffer Input {
    float data[];
};

layout(std430, binding = 1) buffer Output {
    float result;
};

void main() {
    uint tid = gl_LocalInvocationIndex;
    uint gid = gl_GlobalInvocationID.x;

    // Load to shared memory
    sdata[tid] = data[gid];
    barrier();

    // Parallel reduction
    for (uint s = 128; s > 0; s >>= 1) {
        if (tid < s) {
            sdata[tid] += sdata[tid + s];
        }
        barrier();
    }

    // Write final result
    if (tid == 0) {
        atomicAdd(result, sdata[0]);
    }
}
```

**생성되는 v3d_compute_prog_data**:
```c
v3d_compute_prog_data prog_data = {
    .shared_size = 256 * 4,  // 1024 bytes
    .local_size = {256, 1, 1},
    .has_subgroups = false,
    .base = {
        .threads = 2,
        .has_control_barrier = true,  // barrier() 사용
        .tmu_spills = 0,  // 최적화되면 0
        .tmu_fills = 0,
        // ...
    }
};
```

**생성되는 VIR 코드 (의사 코드)**:
```
// Shared memory 베이스 주소 계산
wg_in_mem = cs_payload[1] >> 8
shared_base = UNIFORM(QUNIFORM_SHARED_OFFSET) + (wg_in_mem * 8)

// sdata[tid] = data[gid];
gid = calc_global_invocation_id()
data_addr = SSBO_base + gid * 4
data_value = TMU_LOAD(data_addr)
shared_addr = shared_base + tid * 4
TMU_STORE(shared_addr, data_value)

// barrier();
TSY V3D_TSY_WAIT

// Reduction loop
// ...

// barrier();
TSY V3D_TSY_WAIT

// atomicAdd
if (tid == 0) {
    TMU_ATOMIC_ADD(result_addr, sdata[0])
}
```

---

## 정리

### v3d_compiler.h의 Compute Shader 핵심 요소

1. **v3d_compute_prog_data**: 최종 컴파일 결과
   - `shared_size`: Shared memory 크기
   - `local_size[3]`: Workgroup 크기
   - `has_subgroups`: Subgroup 사용 여부

2. **v3d_compile**: 컴파일 컨텍스트
   - `cs_payload[2]`: Workgroup/Local ID 정보
   - `cs_shared_offset`: Shared memory 베이스 주소
   - `local_invocation_index_bits`: Index 비트 수

3. **quniform_contents**: Uniform 타입
   - `QUNIFORM_NUM_WORK_GROUPS`: Dispatch 크기
   - `QUNIFORM_SHARED_OFFSET`: Shared memory 위치
   - `QUNIFORM_WORK_GROUP_BASE`: Base offset

4. **System Value 구현**:
   - `load_workgroup_id`: cs_payload에서 비트 마스킹
   - `load_local_invocation_index`: cs_payload에서 shift
   - `barrier()`: TSY 명령어 생성

이 구조체들은 NIR → VIR → QPU 변환 과정을 관통하며 compute shader의 의미를 하드웨어 명령어로 정확히 변환하는 데 사용됩니다.
