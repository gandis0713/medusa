# shader_info.h - 셰이더 메타데이터 구조체

## 파일 정보
- **경로**: `medusa/compiler/shader_info.h`
- **역할**: 모든 셰이더 타입의 메타데이터를 정의하는 핵심 헤더 파일
- **타입**: 공용 인프라 (모든 셰이더 스테이지에서 사용)

## 개요

`shader_info.h`는 vertex, fragment, compute 등 모든 셰이더 타입의 메타정보를 담는 `shader_info` 구조체를 정의합니다. 이 구조체는 컴파일러가 셰이더의 특성을 이해하고 최적화하는 데 필수적입니다.

---

## 주요 구조체: `shader_info`

### 기본 필드

```c
typedef struct shader_info {
    const char *name;              // 셰이더 이름
    const char *label;             // 사용자 정의 라벨
    bool internal;                 // 내부 셰이더 여부
    blake3_hash source_blake3;     // 소스 해시
    mesa_shader_stage stage:8;     // 셰이더 스테이지 (MESA_SHADER_COMPUTE 등)

    // ... (다른 필드들)
} shader_info;
```

### Compute Shader 전용 필드

#### 1. Workgroup 정보

```c
/**
 * Local workgroup size used by compute/task/mesh shaders.
 */
uint16_t workgroup_size[3];
```

- **설명**: Compute shader의 local workgroup 크기 (X, Y, Z 차원)
- **예시**: `workgroup_size = {256, 1, 1}` → 256개의 thread를 1D로 배치
- **제약**: 플랫폼마다 최대값이 다름 (V3D의 경우 일반적으로 256 정도)

#### 2. Shared Memory

```c
/**
 * Size of shared variables accessed by compute/task/mesh shaders.
 */
unsigned shared_size;
```

- **설명**: Workgroup 내에서 공유되는 메모리 크기 (바이트 단위)
- **용도**: Thread 간 데이터 공유
- **예시**: `shared vec4 temp[64];` → `shared_size = 64 * 16 = 1024 bytes`

#### 3. Subgroup 정보

```c
/* The value reported in gl_SubgroupSize.
 * Must be a power of two between 1 and 128
 * or 0 if still unknown.
 */
uint8_t api_subgroup_size;

/* The maximum subgroup size dispatched by the hw. */
uint8_t max_subgroup_size;

/* The minimum subgroup size dispatched by the hw. */
uint8_t min_subgroup_size;
```

- **설명**: GPU의 SIMD 실행 단위 크기
- **V3D 예시**: 일반적으로 16
- **용도**: Subgroup 연산 최적화 (ballot, shuffle 등)

#### 4. Wide Subgroup Intrinsics

```c
/**
 * Uses subgroup intrinsics which can communicate across a quad.
 */
bool uses_wide_subgroup_intrinsics:1;
```

- **설명**: Quad 간 통신이 가능한 subgroup intrinsic 사용 여부
- **예시**: Fragment shader의 derivative 계산에 사용

### Compute Shader Union (cs)

```c
struct {
    uint16_t workgroup_size_hint[3];
    uint8_t user_data_components_amd:4;

    /* If the shader might run with shared mem on top of `shared_size`. */
    bool has_variable_shared_mem:1;

    /**
     * If the shader has any use of a cooperative matrix. From
     * SPV_KHR_cooperative_matrix.
     */
    bool has_cooperative_matrix:1;

    /**
     * pointer size is:
     *   AddressingModelLogical:    0    (default)
     *   AddressingModelPhysical32: 32
     *   AddressingModelPhysical64: 64
     */
    unsigned ptr_size;

    /** Index provided by VkPipelineShaderStageNodeCreateInfoAMDX or ShaderIndexAMDX */
    uint32_t shader_index;

    /** Maximum size required by any output node payload array */
    uint32_t node_payloads_size;

    /** Static workgroup count for overwriting the enqueued workgroup count. (0 if dynamic) */
    uint32_t workgroup_count[3];
} cs;
```

#### 주요 필드 설명

##### workgroup_size_hint
- **용도**: 컴파일러 힌트 (실제 크기는 `workgroup_size` 사용)
- **예시**: OpenCL의 `reqd_work_group_size` 속성

##### has_variable_shared_mem
- **설명**: 동적으로 shared memory 크기가 결정되는 경우
- **OpenCL 예시**: `__local void *ptr` 파라미터
- **Vulkan 예시**: `VkSpecializationInfo`로 크기 지정

##### has_cooperative_matrix
- **설명**: Cooperative matrix 사용 여부
- **용도**: 행렬 곱셈 가속 (Tensor Core 같은 기능)
- **확장**: `SPV_KHR_cooperative_matrix`

##### ptr_size
- **설명**: 포인터 크기 (바이트 단위)
- **값**:
  - `0`: 논리적 주소 (기본값)
  - `32`: 32비트 물리 주소
  - `64`: 64비트 물리 주소

##### workgroup_count
- **설명**: 정적 workgroup 개수
- **용도**: 컴파일 타임에 dispatch 크기를 알 수 있는 경우
- **값**: `{0, 0, 0}`이면 동적 (런타임에 결정)

---

## Barrier 및 동기화

```c
/* Whether explicit barriers are used */
bool uses_control_barrier : 1;
bool uses_memory_barrier : 1;
```

### uses_control_barrier
- **설명**: `barrier()` 사용 여부
- **용도**: Workgroup 내 모든 thread 동기화
- **예시**:
  ```glsl
  shared vec4 temp[256];

  void main() {
      temp[gl_LocalInvocationIndex] = compute_value();
      barrier();  // ← uses_control_barrier = true
      vec4 result = temp[(gl_LocalInvocationIndex + 1) % 256];
  }
  ```

### uses_memory_barrier
- **설명**: 메모리 배리어 사용 여부
- **종류**:
  - `memoryBarrier()` - 일반 메모리 배리어
  - `memoryBarrierShared()` - Shared memory만
  - `memoryBarrierBuffer()` - SSBO만
  - `memoryBarrierImage()` - Image만

---

## 메모리 및 리소스 정보

```c
/* Number of uniform buffers used by this shader */
uint8_t num_ubos;

/* Number of shader storage buffers (max .driver_location + 1) used by this
 * shader.  In the case of nir_lower_atomics_to_ssbo being used, this will
 * be the number of actual SSBOs in gl_program->info, and the lowered SSBOs
 * and atomic counters in nir_shader->info.
 */
uint8_t num_ssbos;

/* Number of images used by this shader */
uint8_t num_images;
```

### Compute Shader에서의 사용 예시

```glsl
// UBO
layout(std140, binding = 0) uniform Parameters {
    vec4 data;
};  // num_ubos = 1

// SSBO
layout(std430, binding = 1) buffer OutputBuffer {
    vec4 results[];
};  // num_ssbos = 1

// Image
layout(rgba32f, binding = 2) uniform image2D img;  // num_images = 1
```

---

## System Values

```c
/* Which system values are actually read */
BITSET_DECLARE(system_values_read, SYSTEM_VALUE_MAX);
```

### Compute Shader 관련 System Values

| System Value | 설명 | GLSL |
|-------------|------|------|
| `SYSTEM_VALUE_WORKGROUP_ID` | Workgroup ID (X, Y, Z) | `gl_WorkGroupID` |
| `SYSTEM_VALUE_LOCAL_INVOCATION_ID` | Local invocation ID | `gl_LocalInvocationID` |
| `SYSTEM_VALUE_GLOBAL_INVOCATION_ID` | Global invocation ID | `gl_GlobalInvocationID` |
| `SYSTEM_VALUE_LOCAL_INVOCATION_INDEX` | 1D local invocation index | `gl_LocalInvocationIndex` |
| `SYSTEM_VALUE_NUM_WORKGROUPS` | Workgroup 개수 | `gl_NumWorkGroups` |
| `SYSTEM_VALUE_WORKGROUP_SIZE` | Workgroup 크기 | `gl_WorkGroupSize` |
| `SYSTEM_VALUE_SUBGROUP_SIZE` | Subgroup 크기 | `gl_SubgroupSize` |
| `SYSTEM_VALUE_SUBGROUP_INVOCATION` | Subgroup 내 invocation ID | `gl_SubgroupInvocationID` |

### 사용 예시

```glsl
#version 450
layout(local_size_x = 256) in;

void main() {
    // system_values_read에 다음이 설정됨:
    // - SYSTEM_VALUE_GLOBAL_INVOCATION_ID
    // - SYSTEM_VALUE_LOCAL_INVOCATION_INDEX

    uint gid = gl_GlobalInvocationID.x;
    uint lid = gl_LocalInvocationIndex;
}
```

---

## Shared Memory 명시적 레이아웃

```c
/**
 * Shared memory types have explicit layout set.  Used for
 * SPV_KHR_workgroup_storage_explicit_layout.
 */
bool shared_memory_explicit_layout:1;
```

### 사용 예시 (GLSL + 확장)

```glsl
#version 450
#extension GL_EXT_shared_memory_block : enable

layout(local_size_x = 256) in;

layout(std430) shared SharedData {
    vec4 values[64];
    uint counter;
} sharedBlock;  // ← shared_memory_explicit_layout = true

void main() {
    sharedBlock.values[gl_LocalInvocationIndex / 4] = vec4(0.0);
}
```

---

## Zero-Initialize Workgroup Memory

```c
/**
 * Used for VK_KHR_zero_initialize_workgroup_memory.
 */
bool zero_initialize_shared_memory:1;
```

### 설명
- **기본 동작**: Shared memory는 초기화되지 않음 (쓰레기 값)
- **이 플래그 설정 시**: 모든 shared memory가 0으로 초기화됨
- **성능 영향**: 초기화 오버헤드 발생
- **Vulkan 기능**: `VK_KHR_zero_initialize_workgroup_memory` 확장

### 사용 예시

```c
// Vulkan에서 활성화
VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures zeroInitFeature = {
    .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES,
    .shaderZeroInitializeWorkgroupMemory = VK_TRUE
};

// 이 경우 shader_info.zero_initialize_shared_memory = true
```

---

## Variable Workgroup Size

```c
/**
 * Used for ARB_compute_variable_group_size.
 */
bool workgroup_size_variable:1;
```

### 설명
- **일반 Compute Shader**: Workgroup 크기가 컴파일 타임에 결정 (`local_size_x` 등)
- **Variable Group Size**: 런타임에 workgroup 크기 결정 가능
- **OpenGL 확장**: `ARB_compute_variable_group_size`
- **Vulkan**: 일반적으로 고정 크기 사용

### 사용 예시 (OpenGL)

```glsl
#version 450
#extension GL_ARB_compute_variable_group_size : enable

layout(local_size_variable) in;  // ← workgroup_size_variable = true

void main() {
    // 크기는 glDispatchComputeGroupSizeARB()로 지정
    uint size = gl_WorkGroupSize.x;  // 런타임에 결정됨
}
```

---

## VK_KHR_shader_maximal_reconvergence

```c
/**
 * VK_KHR_shader_maximal_reconvergence
 */
bool maximally_reconverges:1;
```

### 설명
- **용도**: Divergent control flow 후 reconvergence 보장
- **예시**: `if (gl_LocalInvocationIndex < 128)` 후 다시 합류
- **성능**: Reconvergence 지점을 명확히 하여 SIMD 효율 향상

---

## 실제 사용 예시

### 1. 간단한 Compute Shader

```glsl
#version 450

layout(local_size_x = 256) in;

layout(std430, binding = 0) buffer Input {
    float data[];
} inputBuffer;

layout(std430, binding = 1) buffer Output {
    float results[];
} outputBuffer;

void main() {
    uint gid = gl_GlobalInvocationID.x;
    outputBuffer.results[gid] = inputBuffer.data[gid] * 2.0;
}
```

**생성되는 shader_info**:
```c
shader_info info = {
    .stage = MESA_SHADER_COMPUTE,
    .workgroup_size = {256, 1, 1},
    .shared_size = 0,
    .num_ssbos = 2,
    .uses_control_barrier = false,
    .uses_memory_barrier = false,
    .system_values_read = {SYSTEM_VALUE_GLOBAL_INVOCATION_ID},
    .cs = {
        .has_variable_shared_mem = false,
        .workgroup_count = {0, 0, 0}  // 동적
    }
};
```

### 2. Shared Memory를 사용하는 Reduction

```glsl
#version 450

layout(local_size_x = 256) in;

shared float sharedData[256];

layout(std430, binding = 0) buffer Input {
    float data[];
} inputBuffer;

layout(std430, binding = 1) buffer Output {
    float result;
} outputBuffer;

void main() {
    uint tid = gl_LocalInvocationIndex;
    uint gid = gl_GlobalInvocationID.x;

    // Load to shared memory
    sharedData[tid] = inputBuffer.data[gid];
    barrier();

    // Reduction
    for (uint stride = 128; stride > 0; stride >>= 1) {
        if (tid < stride) {
            sharedData[tid] += sharedData[tid + stride];
        }
        barrier();
    }

    // Write result
    if (tid == 0) {
        atomicAdd(outputBuffer.result, sharedData[0]);
    }
}
```

**생성되는 shader_info**:
```c
shader_info info = {
    .stage = MESA_SHADER_COMPUTE,
    .workgroup_size = {256, 1, 1},
    .shared_size = 256 * 4,  // 256 floats = 1024 bytes
    .num_ssbos = 2,
    .uses_control_barrier = true,  // barrier() 사용
    .uses_memory_barrier = true,   // barrier()는 memory barrier 포함
    .system_values_read = {
        SYSTEM_VALUE_GLOBAL_INVOCATION_ID,
        SYSTEM_VALUE_LOCAL_INVOCATION_INDEX
    },
    .cs = {
        .has_variable_shared_mem = false,
        .workgroup_count = {0, 0, 0}
    }
};
```

---

## 컴파일러에서의 활용

### 1. 최적화 결정

```c
// 예: Shared memory 크기에 따른 최적화
if (shader->info.shared_size > MAX_SHARED_SIZE) {
    // Spill to global memory
} else {
    // Use fast shared memory path
}
```

### 2. Workgroup 크기 검증

```c
// 예: V3D의 제약 확인
uint32_t total_invocations =
    shader->info.workgroup_size[0] *
    shader->info.workgroup_size[1] *
    shader->info.workgroup_size[2];

if (total_invocations > V3D_MAX_INVOCATIONS_PER_WORKGROUP) {
    return VK_ERROR_INITIALIZATION_FAILED;
}
```

### 3. Barrier 처리

```c
// 예: Barrier가 있으면 특별한 처리 필요
if (shader->info.uses_control_barrier) {
    // V3D의 경우 TSY (Thread Synchronization) 명령어 생성
    emit_tsy_op(V3D_TSY_WAIT);
}
```

---

## 정리

`shader_info.h`는 컴파일러가 셰이더를 이해하고 최적화하는 데 필요한 모든 메타정보를 담는 핵심 구조체입니다.

### Compute Shader 관련 핵심 요소
1. **Workgroup**: `workgroup_size`, `workgroup_count`
2. **Shared Memory**: `shared_size`, `has_variable_shared_mem`
3. **Subgroup**: `api_subgroup_size`, `uses_wide_subgroup_intrinsics`
4. **Barriers**: `uses_control_barrier`, `uses_memory_barrier`
5. **System Values**: `system_values_read` 비트셋
6. **Resources**: `num_ubos`, `num_ssbos`, `num_images`

이 정보들은 SPIR-V → NIR 변환 과정에서 채워지고, 이후 최적화 및 코드 생성 단계에서 활용됩니다.
