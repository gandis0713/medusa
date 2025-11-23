# spirv_to_nir.c - SPIR-V에서 NIR로 변환

## 파일 정보
- **경로**: `medusa/compiler/spirv/spirv_to_nir.c`
- **역할**: SPIR-V 바이너리를 NIR (NIR Intermediate Representation)로 변환
- **입력**: Vulkan/OpenCL의 SPIR-V 바이너리
- **출력**: NIR 셰이더

## 개요

`spirv_to_nir.c`는 Vulkan compute shader의 진입점입니다. SPIR-V 바이너리 포맷을 파싱하고, OpCode를 NIR 명령어로 변환합니다. 이 과정은 모든 SPIR-V 기반 셰이더 컴파일의 첫 단계입니다.

---

## SPIR-V란?

### SPIR-V (Standard Portable Intermediate Representation - V)
- **목적**: 크로스 플랫폼 셰이더 중간 표현
- **포맷**: 바이너리 형식 (텍스트 아님)
- **장점**:
  - 컴파일 타임 단축
  - 소스 코드 노출 방지
  - 벤더 독립적

### SPIR-V 생성 과정

```
GLSL Shader
    ↓
[glslangValidator 또는 shaderc]
    ↓
SPIR-V Binary (.spv 파일)
    ↓
[spirv_to_nir.c] ← 이 파일의 역할
    ↓
NIR
```

---

## 주요 함수

### spirv_to_nir()

```c
nir_shader *
spirv_to_nir(const uint32_t *words, size_t word_count,
             struct nir_spirv_specialization *spec, unsigned num_spec,
             gl_shader_stage stage, const char *entry_point_name,
             const struct spirv_to_nir_options *options,
             const nir_shader_compiler_options *nir_options);
```

#### 파라미터 설명

##### words, word_count
- **타입**: `const uint32_t *`, `size_t`
- **설명**: SPIR-V 바이너리 데이터
- **포맷**: SPIR-V는 32비트 word의 배열
- **예시**:
  ```c
  // .spv 파일 로드
  FILE *f = fopen("shader.comp.spv", "rb");
  fseek(f, 0, SEEK_END);
  size_t size = ftell(f);
  fseek(f, 0, SEEK_SET);

  size_t word_count = size / 4;
  uint32_t *words = malloc(size);
  fread(words, 1, size, f);
  fclose(f);

  // spirv_to_nir() 호출
  nir_shader *nir = spirv_to_nir(words, word_count, ...);
  ```

##### spec, num_spec
- **타입**: `struct nir_spirv_specialization *`, `unsigned`
- **용도**: Specialization constants 설정
- **Vulkan**: `VkSpecializationInfo`에 대응

**Specialization Constants 예시**:

```glsl
// Compute shader
#version 450
layout(local_size_x_id = 0) in;  // spec constant ID 0
layout(local_size_y_id = 1) in;  // spec constant ID 1
layout(local_size_z_id = 2) in;  // spec constant ID 2

layout(constant_id = 3) const int BUFFER_SIZE = 256;

void main() {
    // workgroup 크기와 BUFFER_SIZE는 런타임에 결정됨
}
```

```c
// C 코드
nir_spirv_specialization specs[] = {
    { .id = 0, .value.u32 = 128 },  // local_size_x = 128
    { .id = 1, .value.u32 = 1 },    // local_size_y = 1
    { .id = 2, .value.u32 = 1 },    // local_size_z = 1
    { .id = 3, .value.u32 = 512 },  // BUFFER_SIZE = 512
};

nir_shader *nir = spirv_to_nir(words, word_count,
                               specs, 4,  // 4개의 specialization
                               MESA_SHADER_COMPUTE, "main", ...);
```

##### stage
- **타입**: `gl_shader_stage`
- **값**: Compute shader의 경우 `MESA_SHADER_COMPUTE`
- **다른 값들**:
  - `MESA_SHADER_VERTEX`
  - `MESA_SHADER_FRAGMENT`
  - `MESA_SHADER_GEOMETRY`
  - 등등

##### entry_point_name
- **타입**: `const char *`
- **설명**: SPIR-V의 entry point 함수 이름
- **일반적으로**: `"main"`
- **다중 entry point**:
  ```glsl
  // GLSL (VK_KHR_shader_non_semantic_info)
  void computeMain() { ... }  // entry_point_name = "computeMain"
  void processData() { ... }   // entry_point_name = "processData"
  ```

##### options
- **타입**: `const struct spirv_to_nir_options *`
- **용도**: SPIR-V → NIR 변환 옵션
- **주요 필드**:
  ```c
  struct spirv_to_nir_options {
      bool environment;          // Vulkan vs OpenCL
      bool caps_*;               // 지원 capability
      bool lower_workgroup_access_to_offsets;  // Compute shader 관련
      // ... 더 많은 옵션
  };
  ```

##### nir_options
- **타입**: `const nir_shader_compiler_options *`
- **용도**: NIR 컴파일러 옵션 (하드웨어 특성)
- **예시**: V3D의 경우 지원하는 명령어, 제약사항 등

---

## SPIR-V OpCode → NIR 변환

### Compute Shader 관련 주요 OpCode

#### 1. OpExecutionMode

SPIR-V:
```
OpExecutionMode %main LocalSize 256 1 1
```

NIR:
```c
shader->info.workgroup_size[0] = 256;
shader->info.workgroup_size[1] = 1;
shader->info.workgroup_size[2] = 1;
```

#### 2. OpVariable (Workgroup storage class)

SPIR-V:
```
%shared_data = OpVariable %ptr_workgroup %float_array_256 Workgroup
```

NIR:
```c
nir_variable *var = nir_variable_create(
    shader,
    nir_var_mem_shared,
    glsl_array_type(glsl_float_type(), 256, 0),
    "shared_data"
);
shader->info.shared_size += 256 * 4;  // 1024 bytes
```

#### 3. OpLoad / OpStore (shared memory)

SPIR-V:
```
%value = OpLoad %float %shared_data[%index]
OpStore %shared_data[%index] %new_value
```

NIR:
```c
// Load
nir_intrinsic_instr *load = nir_intrinsic_instr_create(
    shader, nir_intrinsic_load_shared);
// ... setup

// Store
nir_intrinsic_instr *store = nir_intrinsic_instr_create(
    shader, nir_intrinsic_store_shared);
// ... setup
```

#### 4. OpControlBarrier

SPIR-V:
```
OpControlBarrier %workgroup %workgroup %acquire_release_semantics
```

NIR:
```c
nir_intrinsic_instr *barrier = nir_intrinsic_instr_create(
    shader, nir_intrinsic_barrier);

nir_intrinsic_set_memory_scope(barrier, NIR_SCOPE_WORKGROUP);
nir_intrinsic_set_memory_semantics(barrier,
    NIR_MEMORY_ACQ_REL | NIR_MEMORY_RELEASE);

shader->info.uses_control_barrier = true;
```

GLSL:
```glsl
barrier();
```

#### 5. OpAtomicIAdd

SPIR-V:
```
%result = OpAtomicIAdd %uint %ptr %scope %semantics %value
```

NIR:
```c
nir_intrinsic_instr *atomic = nir_intrinsic_instr_create(
    shader, nir_intrinsic_atomic_add);
// ... setup
```

GLSL:
```glsl
atomicAdd(counter, 1);
```

---

## System Value 처리

### gl_GlobalInvocationID

SPIR-V:
```
%gid = OpLoad %v3uint %gl_GlobalInvocationID
```

NIR:
```c
nir_intrinsic_instr *load_gid = nir_intrinsic_instr_create(
    shader, nir_intrinsic_load_global_invocation_id);

// 또는 계산:
// global_id = workgroup_id * workgroup_size + local_id
nir_def *wg_id = nir_load_workgroup_id(b);
nir_def *wg_size = nir_load_workgroup_size(b);
nir_def *local_id = nir_load_local_invocation_id(b);
nir_def *global_id = nir_iadd(b,
    nir_imul(b, wg_id, wg_size),
    local_id);
```

### gl_LocalInvocationIndex

SPIR-V:
```
%lid_idx = OpLoad %uint %gl_LocalInvocationIndex
```

NIR:
```c
nir_intrinsic_instr *load_lid_idx = nir_intrinsic_instr_create(
    shader, nir_intrinsic_load_local_invocation_index);

BITSET_SET(shader->info.system_values_read,
           SYSTEM_VALUE_LOCAL_INVOCATION_INDEX);
```

### gl_WorkGroupID

SPIR-V:
```
%wg_id = OpLoad %v3uint %gl_WorkGroupID
```

NIR:
```c
nir_intrinsic_instr *load_wg_id = nir_intrinsic_instr_create(
    shader, nir_intrinsic_load_workgroup_id);

BITSET_SET(shader->info.system_values_read,
           SYSTEM_VALUE_WORKGROUP_ID);
```

---

## Memory Model 처리

### SPIR-V Memory Model

```
OpMemoryModel Logical GLSL450
```

또는

```
OpMemoryModel Physical64 Vulkan
```

- **Logical**: 논리적 주소 공간 (일반적)
- **Physical32/64**: 물리적 주소 공간 (고급 용도)

### Vulkan Memory Model (VK_KHR_vulkan_memory_model)

SPIR-V:
```
OpCapability VulkanMemoryModel
OpMemoryModel Logical Vulkan
```

NIR:
- 더 정밀한 메모리 순서 보장
- `OpMemoryBarrier`의 scope와 semantics 정보 보존

---

## Subgroup 연산 처리

### OpGroupNonUniformBallot

SPIR-V:
```
%result = OpGroupNonUniformBallot %v4uint %subgroup %predicate
```

NIR:
```c
nir_intrinsic_instr *ballot = nir_intrinsic_instr_create(
    shader, nir_intrinsic_ballot);

shader->info.uses_wide_subgroup_intrinsics = true;
```

GLSL:
```glsl
uvec4 mask = subgroupBallot(condition);
```

### OpGroupNonUniformShuffle

SPIR-V:
```
%result = OpGroupNonUniformShuffle %float %subgroup %value %id
```

NIR:
```c
nir_intrinsic_instr *shuffle = nir_intrinsic_instr_create(
    shader, nir_intrinsic_shuffle);
```

GLSL:
```glsl
float value = subgroupShuffle(data, lane_id);
```

---

## 실제 사용 예시

### 1. Vulkan에서 SPIR-V 로드 및 변환

```c
// SPIR-V 파일 로드
VkShaderModuleCreateInfo createInfo = {
    .sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,
    .codeSize = spirv_size,
    .pCode = spirv_data,
};
VkShaderModule shaderModule;
vkCreateShaderModule(device, &createInfo, NULL, &shaderModule);

// 내부적으로 spirv_to_nir() 호출
struct spirv_to_nir_options spirv_options = {
    .environment = NIR_SPIRV_VULKAN,
    .lower_workgroup_access_to_offsets = true,
    // V3D capabilities
    .caps = {
        .subgroup_basic = true,
        .subgroup_ballot = true,
        .subgroup_shuffle = true,
        // ...
    },
};

nir_shader *nir = spirv_to_nir(
    spirv_data,
    spirv_size / 4,
    NULL, 0,  // no specialization
    MESA_SHADER_COMPUTE,
    "main",
    &spirv_options,
    &v3d_nir_options
);
```

### 2. GLSL → SPIR-V → NIR 전체 흐름

**GLSL Compute Shader** (add.comp):
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

**SPIR-V 생성**:
```bash
glslangValidator -V add.comp -o add.comp.spv
# 또는
glslc add.comp -o add.comp.spv
```

**SPIR-V 바이너리** (일부):
```
; Magic: 0x07230203
; Version: 1.0
; Generator: Khronos Glslang
; Bound: 50
; Schema: 0

OpCapability Shader
OpMemoryModel Logical GLSL450
OpEntryPoint GLCompute %main "main" %gl_GlobalInvocationID
OpExecutionMode %main LocalSize 256 1 1

; Annotations
OpDecorate %gl_GlobalInvocationID BuiltIn GlobalInvocationId
OpDecorate %_arr_float_uint_0 ArrayStride 4
OpMemberDecorate %InputA 0 Offset 0
OpDecorate %InputA BufferBlock
OpDecorate %a DescriptorSet 0
OpDecorate %a Binding 0
; ... (더 많은 decoration)

; Types
%void = OpTypeVoid
%3 = OpTypeFunction %void
%uint = OpTypeInt 32 0
%float = OpTypeFloat 32
; ... (더 많은 타입)

; Entry point
%main = OpFunction %void None %3
%5 = OpLabel
%gid = OpLoad %v3uint %gl_GlobalInvocationID
%gid_x = OpCompositeExtract %uint %gid 0
; ... (나머지 명령어)
OpReturn
OpFunctionEnd
```

**NIR 출력** (의사 코드):
```
shader: MESA_SHADER_COMPUTE
name: main
workgroup_size: (256, 1, 1)
shared_size: 0
num_ssbos: 3

decl_var ssbo INTERP_MODE_NONE float[] a (0, 0, 0)
decl_var ssbo INTERP_MODE_NONE float[] b (1, 0, 0)
decl_var ssbo INTERP_MODE_NONE float[] c (2, 0, 0)

impl main {
    block block_0:
    /* preds: */
    vec3 32 ssa_0 = load_global_invocation_id
    vec1 32 ssa_1 = mov ssa_0.x

    // a[gid]
    vec1 32 ssa_2 = deref_var &a (ssbo float[])
    vec1 32 ssa_3 = deref_array &(*ssa_2)[ssa_1] (ssbo float)
    vec1 32 ssa_4 = intrinsic load_deref (ssa_3) ()

    // b[gid]
    vec1 32 ssa_5 = deref_var &b (ssbo float[])
    vec1 32 ssa_6 = deref_array &(*ssa_5)[ssa_1] (ssbo float)
    vec1 32 ssa_7 = intrinsic load_deref (ssa_6) ()

    // a[gid] + b[gid]
    vec1 32 ssa_8 = fadd ssa_4, ssa_7

    // c[gid] = result
    vec1 32 ssa_9 = deref_var &c (ssbo float[])
    vec1 32 ssa_10 = deref_array &(*ssa_9)[ssa_1] (ssbo float)
    intrinsic store_deref (ssa_10, ssa_8) (1)

    /* succs: block_1 */
    block block_1:
}
```

---

## SPIR-V Validation

### spirv-val 도구

SPIR-V 바이너리가 유효한지 검증:
```bash
spirv-val add.comp.spv
```

### 일반적인 오류

1. **잘못된 capability**:
   ```
   ERROR: Capability not declared: OpGroupNonUniformBallot requires VulkanMemoryModel
   ```

2. **잘못된 decoration**:
   ```
   ERROR: OpDecorate DescriptorSet must be used with StorageBuffer or Uniform
   ```

3. **타입 불일치**:
   ```
   ERROR: OpLoad result type does not match pointer operand type
   ```

---

## 디버깅 팁

### 1. SPIR-V 디스어셈블

```bash
spirv-dis add.comp.spv -o add.comp.spvasm
```

### 2. NIR 출력

```c
nir_shader *nir = spirv_to_nir(...);

// NIR 출력
nir_print_shader(nir, stdout);
```

### 3. NIR_DEBUG 환경 변수

```bash
NIR_DEBUG=print ./my_vulkan_app
```

출력:
```
MESA: debug: NIR shader: main
MESA: debug:   stage: compute
MESA: debug:   workgroup_size: (256, 1, 1)
MESA: debug:   ... (전체 NIR)
```

---

## Compute Shader 특화 처리

### 1. Workgroup Size 추출

```c
// SPIR-V: OpExecutionMode %main LocalSize 256 1 1
// NIR:
shader->info.workgroup_size[0] = 256;
shader->info.workgroup_size[1] = 1;
shader->info.workgroup_size[2] = 1;
```

### 2. Shared Memory 계산

```c
// SPIR-V의 모든 Workgroup 변수를 순회
for (각 OpVariable with Workgroup storage class) {
    size_t var_size = calculate_type_size(variable->type);
    shader->info.shared_size += var_size;
}
```

### 3. Barrier 감지

```c
// SPIR-V: OpControlBarrier
shader->info.uses_control_barrier = true;

// SPIR-V: OpMemoryBarrier
shader->info.uses_memory_barrier = true;
```

---

## 정리

### spirv_to_nir.c의 역할

1. **SPIR-V 파싱**: 바이너리 포맷 해석
2. **OpCode 변환**: SPIR-V 명령어 → NIR 명령어
3. **메타데이터 추출**: shader_info 구조체 채우기
4. **타입 시스템 변환**: SPIR-V 타입 → GLSL 타입
5. **Decoration 처리**: Binding, location, layout 등

### Compute Shader 특화 기능

- Workgroup size 추출
- Shared memory 크기 계산
- System value (gl_GlobalInvocationID 등) 처리
- Barrier 감지
- Subgroup 연산 변환
- Atomic 연산 처리

### 다음 단계

SPIR-V → NIR 변환 후:
1. NIR 최적화 패스 실행
2. V3D 특화 NIR lowering
3. NIR → VIR 변환 (nir_to_vir.c)
4. VIR 최적화
5. 레지스터 할당
6. VIR → QPU 변환

`spirv_to_nir.c`는 이 파이프라인의 시작점으로, 모든 후속 단계의 기반이 됩니다.
