# Vulkan Compute Shader 관련 파일 목록

이 문서는 medusa 프로젝트의 Vulkan compute shader 컴파일과 관련된 파일들을 정리한 것입니다.

## 목차
- [medusa/compiler - 공통 컴파일러 인프라](#medusacompiler---공통-컴파일러-인프라)
- [medusa/broadcom/compiler - V3D 하드웨어 백엔드](#medusabroadcomcompiler---v3d-하드웨어-백엔드)

---

## medusa/compiler - 공통 컴파일러 인프라

### 핵심 헤더 파일

#### 1. shader_info.h
- **경로**: `medusa/compiler/shader_info.h`
- **역할**: 모든 셰이더 타입(compute, fragment, vertex 등)의 메타데이터 정의
- **Compute Shader 관련 주요 구조체**:
  - `shader_info.cs` - Compute shader 전용 정보
  - `workgroup_size[3]` - Local workgroup 크기 (X, Y, Z)
  - `shared_size` - Shared memory 크기
  - `workgroup_size_variable` - 가변 workgroup 크기 지원
  - `has_variable_shared_mem` - 가변 shared memory 사용 여부

#### 2. shader_enums.h
- **경로**: `medusa/compiler/shader_enums.h`
- **역할**: 셰이더 관련 열거형 및 상수 정의
- **주요 내용**: MESA_SHADER_COMPUTE 등 셰이더 스테이지 정의

#### 3. glsl_types.h / glsl_types.c
- **경로**:
  - `medusa/compiler/glsl_types.h`
  - `medusa/compiler/glsl_types.c`
- **역할**: GLSL/SPIR-V 타입 시스템 정의
- **주요 기능**: 벡터, 행렬, 구조체 등의 타입 표현

---

### NIR (NIR Intermediate Representation)

NIR은 Mesa의 중간 표현 형식으로, SPIR-V를 하드웨어 명령어로 변환하는 과정에서 사용됩니다.

#### 핵심 NIR 파일들

##### 1. nir/nir.h
- **경로**: `medusa/compiler/nir/nir.h`
- **역할**: NIR의 핵심 데이터 구조 및 API
- **주요 구조체**:
  - `nir_shader` - NIR 셰이더 표현
  - `nir_function` - 함수 표현
  - `nir_intrinsic_instr` - 내장 명령어

##### 2. nir/nir_builder.h / nir_builder.c
- **경로**:
  - `medusa/compiler/nir/nir_builder.h`
  - `medusa/compiler/nir/nir_builder.c`
- **역할**: NIR 명령어 생성 유틸리티

##### 3. nir/nir_intrinsics.h / nir_intrinsics.c
- **경로**:
  - `medusa/compiler/nir/nir_intrinsics.h`
  - `medusa/compiler/nir/nir_intrinsics.c`
- **역할**: NIR 내장 함수(intrinsic) 정의
- **Compute 관련 Intrinsics**:
  - `load_workgroup_id` - Workgroup ID 로드
  - `load_local_invocation_id` - Local invocation ID 로드
  - `load_global_invocation_id` - Global invocation ID 로드
  - `load_num_workgroups` - Workgroup 개수 로드
  - `control_barrier` - Control barrier 동기화
  - `memory_barrier` - Memory barrier

##### 4. nir/nir_lower_subgroups.c
- **경로**: `medusa/compiler/nir/nir_lower_subgroups.c`
- **역할**: Subgroup 연산 lowering
- **주요 기능**: ballot, broadcast, shuffle 등의 subgroup 연산 변환

##### 5. nir/nir_lower_system_values.c
- **경로**: `medusa/compiler/nir/nir_lower_system_values.c`
- **역할**: System value 변수 lowering
- **Compute 관련**: workgroup ID, local invocation ID 등을 실제 로드 명령어로 변환

##### 6. nir/nir_lower_explicit_io.c
- **경로**: `medusa/compiler/nir/nir_lower_explicit_io.c`
- **역할**: SSBO, UBO, shared memory 등의 명시적 I/O lowering
- **주요 기능**: 메모리 접근을 실제 주소 계산 및 로드/스토어 명령어로 변환

##### 7. nir/nir_lower_atomics.c
- **경로**: `medusa/compiler/nir/nir_lower_atomics.c`
- **역할**: Atomic 연산 lowering
- **주요 기능**: atomic_add, atomic_min 등을 하드웨어 명령어로 변환

##### 8. nir/nir_opt_barriers.c
- **경로**: `medusa/compiler/nir/nir_opt_barriers.c`
- **역할**: Barrier 최적화
- **주요 기능**: 불필요한 barrier 제거 및 병합

---

### SPIR-V 프론트엔드

#### 1. spirv/spirv_to_nir.c
- **경로**: `medusa/compiler/spirv/spirv_to_nir.c`
- **역할**: SPIR-V 바이너리를 NIR로 변환
- **주요 기능**:
  - SPIR-V 파싱
  - OpCode를 NIR 명령어로 변환
  - Compute shader entry point 처리

#### 2. spirv/vtn_variables.c
- **경로**: `medusa/compiler/spirv/vtn_variables.c`
- **역할**: SPIR-V 변수 처리
- **Compute 관련**:
  - Workgroup 변수 (shared memory)
  - SSBO (Storage Buffer)
  - UBO (Uniform Buffer)

#### 3. spirv/vtn_cfg.c
- **경로**: `medusa/compiler/spirv/vtn_cfg.c`
- **역할**: SPIR-V Control Flow Graph 처리
- **주요 기능**: 제어 흐름 구조 변환

#### 4. spirv/spirv.h
- **경로**: `medusa/compiler/spirv/spirv.h`
- **역할**: SPIR-V 명세 정의
- **주요 내용**: SPIR-V OpCode, 열거형, 상수

#### 5. spirv/vtn_private.h
- **경로**: `medusa/compiler/spirv/vtn_private.h`
- **역할**: SPIR-V to NIR 변환 내부 구조체 및 유틸리티

---

## medusa/broadcom/compiler - V3D 하드웨어 백엔드

Broadcom V3D GPU (Raspberry Pi 4/5에 사용)용 컴파일러 백엔드입니다.

### 핵심 파일들

#### 1. v3d_compiler.h
- **경로**: `medusa/broadcom/compiler/v3d_compiler.h`
- **역할**: V3D 컴파일러 핵심 구조체 및 API 정의
- **Compute Shader 관련 주요 구조체**:
  - `v3d_compute_prog_data` - Compute shader 프로그램 데이터
    - `shared_size` - Shared memory 크기
    - `local_size[3]` - Local workgroup 크기
    - `has_subgroups` - Subgroup 사용 여부
  - `v3d_compile` - 컴파일 컨텍스트
    - `cs_payload[2]` - Compute shader 페이로드 레지스터
    - `cs_shared_offset` - Shared memory 오프셋
    - `local_invocation_index_bits` - Local invocation index 비트 수
  - `quniform_contents` - Uniform 타입
    - `QUNIFORM_NUM_WORK_GROUPS` - Workgroup 개수
    - `QUNIFORM_WORK_GROUP_BASE` - Workgroup base offset
    - `QUNIFORM_SHARED_OFFSET` - Shared memory 오프셋
    - `QUNIFORM_SHARED_SIZE` - Shared memory 크기

#### 2. nir_to_vir.c
- **경로**: `medusa/broadcom/compiler/nir_to_vir.c`
- **역할**: NIR을 VIR (V3D IR)로 변환
- **Compute 관련 주요 함수**:
  - `emit_load_local_invocation_index()` - Local invocation index 로드
  - Intrinsic 처리:
    - `nir_intrinsic_load_num_workgroups`
    - `nir_intrinsic_load_workgroup_id`
    - `nir_intrinsic_load_base_workgroup_id`
    - `nir_intrinsic_load_workgroup_size`
    - `nir_intrinsic_load_local_invocation_index`
  - Compute shader 초기화 (cs_payload 설정)
  - Shared memory 주소 계산

#### 3. vir.c
- **경로**: `medusa/broadcom/compiler/vir.c`
- **역할**: VIR 명령어 생성 및 관리
- **Compute 관련**:
  - Workgroup size 설정
  - Subgroup 지원 처리
  - 프로그램 데이터 생성

#### 4. qpu_schedule.c
- **경로**: `medusa/broadcom/compiler/qpu_schedule.c`
- **역할**: QPU (V3D의 처리 유닛) 명령어 스케줄링
- **주요 기능**:
  - 명령어 의존성 분석
  - 레이턴시 숨김 최적화
  - Thread switching 최적화 (compute shader의 경우 중요)

#### 5. vir_register_allocate.c
- **경로**: `medusa/broadcom/compiler/vir_register_allocate.c`
- **역할**: 레지스터 할당
- **Compute 관련**:
  - Workgroup 내 레지스터 압력 관리
  - Spilling 처리

#### 6. vir_to_qpu.c
- **경로**: `medusa/broadcom/compiler/vir_to_qpu.c`
- **역할**: VIR을 QPU 기계어로 변환
- **주요 기능**: 최종 바이너리 생성

---

### V3D NIR Lowering 패스

#### 1. v3d_nir_lower_image_load_store.c
- **경로**: `medusa/broadcom/compiler/v3d_nir_lower_image_load_store.c`
- **역할**: Image load/store 연산을 V3D TMU 명령어로 lowering
- **Compute 관련**: Image buffer, storage image 접근

#### 2. v3d_nir_lower_io.c
- **경로**: `medusa/broadcom/compiler/v3d_nir_lower_io.c`
- **역할**: I/O 연산 lowering
- **주요 기능**: Compute shader의 경우 최소한의 I/O 처리

#### 3. v3d_nir_lower_scratch.c
- **경로**: `medusa/broadcom/compiler/v3d_nir_lower_scratch.c`
- **역할**: Scratch memory (레지스터 spill) 처리
- **Compute 관련**: Workgroup 크기가 클 때 레지스터 압력 관리

#### 4. v3d_nir_lower_load_store_bitsize.c
- **경로**: `medusa/broadcom/compiler/v3d_nir_lower_load_store_bitsize.c`
- **역할**: 메모리 접근의 비트 크기 조정
- **Compute 관련**: SSBO, shared memory 접근 최적화

---

## 컴파일 파이프라인 흐름

Vulkan compute shader가 실행 가능한 바이너리로 변환되는 과정:

```
SPIR-V Binary
    ↓
[spirv_to_nir.c] SPIR-V → NIR 변환
    ↓
NIR (Generic IR)
    ↓
[NIR Optimization Passes]
  - nir_lower_subgroups
  - nir_lower_system_values
  - nir_lower_explicit_io
  - nir_lower_atomics
  - nir_opt_barriers
    ↓
[V3D NIR Lowering]
  - v3d_nir_lower_image_load_store
  - v3d_nir_lower_io
  - v3d_nir_lower_load_store_bitsize
    ↓
[nir_to_vir.c] NIR → VIR 변환
    ↓
VIR (V3D IR)
    ↓
[VIR Optimization]
  - vir_opt_*
    ↓
[vir_register_allocate.c] 레지스터 할당
    ↓
[qpu_schedule.c] 명령어 스케줄링
    ↓
[vir_to_qpu.c] VIR → QPU 기계어 변환
    ↓
QPU Binary (실행 가능한 코드)
```

---

## 주요 개념 정리

### Workgroup
- **Local Workgroup**: Compute shader의 작업 단위 (X × Y × Z 크기)
- **Workgroup ID**: 각 workgroup의 고유 식별자
- **Local Invocation ID**: Workgroup 내에서의 thread ID
- **Global Invocation ID**: `Workgroup ID × Workgroup Size + Local Invocation ID`

### Shared Memory
- Workgroup 내의 thread들이 공유하는 고속 메모리
- V3D에서는 TMU (Texture Memory Unit)의 L2T 캐시를 사용
- `QUNIFORM_SHARED_OFFSET`으로 접근

### Subgroup
- GPU의 SIMD 실행 단위 (V3D의 경우 일반적으로 16)
- Subgroup 연산: ballot, broadcast, shuffle 등

### Barriers
- **Control Barrier**: 모든 thread가 동기화될 때까지 대기
- **Memory Barrier**: 메모리 접근 순서 보장

### TMU (Texture Memory Unit)
- V3D의 메모리 접근 유닛
- Image, SSBO, Atomic, Shared memory 접근 처리

---

## 참고 사항

이 코드베이스는 Mesa 프로젝트에서 파생되었으며, Broadcom V3D GPU를 위한 Vulkan compute shader 지원을 제공합니다.

주요 타겟 하드웨어:
- Raspberry Pi 4 (V3D 4.2)
- Raspberry Pi 5 (V3D 7.x)

자세한 문서는 개별 파일의 역할 및 사용 예시 문서를 참고하세요.
