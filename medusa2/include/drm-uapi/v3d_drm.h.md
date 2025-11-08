# V3D DRM UAPI 헤더 파일 상세 가이드

## 파일 개요

**파일 경로**: `include/drm-uapi/v3d_drm.h`
**역할**: Broadcom VideoCore V3D GPU와 Linux Kernel 간 사용자 공간 API (UAPI) 정의
**저작권**: © 2014-2018 Broadcom

### 핵심 역할

이 헤더 파일은 **Mesa V3D Vulkan 드라이버(사용자 공간)**와 **Linux Kernel V3D DRM 드라이버(커널 공간)** 간의 **인터페이스 계약**을 정의합니다.

```
┌─────────────────────────┐
│   Mesa V3D Driver       │  사용자 공간
│   (libvulkan_broadcom)  │
└───────────┬─────────────┘
            │ IOCTL 호출
            │ (v3d_drm.h 인터페이스)
┌───────────▼─────────────┐
│  Linux Kernel           │  커널 공간
│  V3D DRM Driver         │
└───────────┬─────────────┘
            │
┌───────────▼─────────────┐
│   V3D GPU Hardware      │  하드웨어
│   (Raspberry Pi 4/5)    │
└─────────────────────────┘
```

---

## 1. IOCTL 명령어 정의 (33-46번 줄)

### 1.1 핵심 GPU 작업 제출 명령어

| 명령어 | 값 | 설명 | 사용 시점 |
|--------|-----|------|----------|
| `DRM_V3D_SUBMIT_CL` | 0x00 | 3D 렌더링 작업 제출 (Binning + Rendering) | 삼각형 그리기, 모델 렌더링 |
| `DRM_V3D_SUBMIT_TFU` | 0x06 | Texture Formatting Unit 작업 제출 | 텍스처 포맷 변환, 밉맵 생성 |
| `DRM_V3D_SUBMIT_CSD` | 0x07 | Compute Shader 작업 제출 | 컴퓨트 쉐이더 실행 |
| `DRM_V3D_SUBMIT_CPU` | 0x0b | CPU 작업 제출 | 타임스탬프 쿼리, 간접 CSD |

### 1.2 메모리 관리 명령어

| 명령어 | 값 | 설명 | 구조체 |
|--------|-----|------|--------|
| `DRM_V3D_CREATE_BO` | 0x02 | GPU 메모리 버퍼 생성 | `drm_v3d_create_bo` |
| `DRM_V3D_MMAP_BO` | 0x03 | GPU 버퍼를 CPU 주소 공간으로 매핑 | `drm_v3d_mmap_bo` |
| `DRM_V3D_WAIT_BO` | 0x01 | 버퍼 작업 완료 대기 | `drm_v3d_wait_bo` |
| `DRM_V3D_GET_BO_OFFSET` | 0x05 | 버퍼의 GPU 주소 가져오기 | `drm_v3d_get_bo_offset` |

### 1.3 디버깅 및 프로파일링 명령어

| 명령어 | 값 | 설명 |
|--------|-----|------|
| `DRM_V3D_GET_PARAM` | 0x04 | GPU 파라미터 조회 (버전, 기능 지원 여부) |
| `DRM_V3D_PERFMON_CREATE` | 0x08 | 성능 모니터 생성 |
| `DRM_V3D_PERFMON_DESTROY` | 0x09 | 성능 모니터 제거 |
| `DRM_V3D_PERFMON_GET_VALUES` | 0x0a | 성능 카운터 값 읽기 |
| `DRM_V3D_PERFMON_GET_COUNTER` | 0x0c | 성능 카운터 정보 조회 |
| `DRM_V3D_PERFMON_SET_GLOBAL` | 0x0d | 전역 성능 모니터 설정 |

---

## 2. IOCTL 매크로 정의 (48-66번 줄)

각 명령어는 실제 IOCTL 시스템 콜로 매핑됩니다:

```c
#define DRM_IOCTL_V3D_SUBMIT_CL  DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_SUBMIT_CL, struct drm_v3d_submit_cl)
```

**매크로 의미:**
- `DRM_IOWR`: Read/Write IOCTL (양방향 데이터 전송)
- `DRM_IOW`: Write-only IOCTL (커널로 데이터만 전송)
- `DRM_COMMAND_BASE`: DRM 드라이버 전용 명령어 베이스 값

**사용 예시 (`src/broadcom/vulkan/v3dv_queue.c:1040`):**
```c
int ret = v3d_ioctl(device->render_fd,
                    DRM_IOCTL_V3D_SUBMIT_CL,
                    &submit);
```

---

## 3. 핵심 데이터 구조체

### 3.1 `struct drm_v3d_submit_cl` (153-224번 줄)

**가장 중요한 구조체** - 3D 렌더링 작업을 GPU에 제출합니다.

#### 구조체 멤버 상세

**Command List 포인터:**
```c
__u32 bcl_start;  // Binning Command List 시작 주소
__u32 bcl_end;    // BCL 끝 주소 (exclusive)
__u32 rcl_start;  // Rendering Command List 시작 주소
__u32 rcl_end;    // RCL 끝 주소 (exclusive)
```

- **BCL (Binning Command List)**:
  - 역할: 버텍스 처리, 프리미티브가 어느 타일에 속하는지 계산
  - 실행 단계: 첫 번째 (Binning Phase)
  - 출력: Tile Allocation Memory에 타일별 렌더링 명령 생성

- **RCL (Rendering Command List)**:
  - 역할: 각 타일을 실제로 렌더링 (픽셀 쉐이더 실행)
  - 실행 단계: 두 번째 (Rendering Phase)
  - 출력: 프레임버퍼에 최종 이미지

**Tile Memory 관리:**
```c
__u32 qma;  // Tile Allocation Memory Address
__u32 qms;  // Tile Allocation Memory Size
__u32 qts;  // Tile State Data Array Address
```

- **qma/qms**: BCL이 타일별 렌더링 명령을 저장할 메모리
- **qts**: 각 타일의 상태 정보 (Clear 값, Z/Stencil 버퍼 등)

**Buffer Object 참조:**
```c
__u64 bo_handles;        // BO 핸들 배열 포인터
__u32 bo_handle_count;   // BO 개수
```

모든 렌더링에 사용되는 GPU 버퍼들의 핸들 리스트 (버텍스 버퍼, 텍스처, 프레임버퍼 등)

**동기화:**
```c
__u32 in_sync_bcl;  // BCL 시작 전 대기할 syncobj
__u32 in_sync_rcl;  // RCL 시작 전 대기할 syncobj
__u32 out_sync;     // 렌더링 완료 시 신호할 syncobj
```

**플래그 및 확장:**
```c
__u32 flags;        // DRM_V3D_SUBMIT_CL_FLUSH_CACHE 등
__u32 perfmon_id;   // 성능 모니터 ID (0 = 사용 안 함)
__u64 extensions;   // 확장 기능 포인터 (drm_v3d_multi_sync 등)
```

#### 사용 흐름 예시

```
1. Mesa 드라이버가 Vulkan vkCmdDraw() 호출 받음
   ↓
2. BCL/RCL 생성 (v3dvx_cmd_buffer.c)
   - cl_emit() 매크로로 GPU 명령어 인코딩
   ↓
3. drm_v3d_submit_cl 구조체 채우기
   - bcl_start/end, rcl_start/end 설정
   - bo_handles에 사용할 모든 버퍼 추가
   - qma/qms/qts 설정
   ↓
4. ioctl(DRM_IOCTL_V3D_SUBMIT_CL) 호출
   ↓
5. Kernel 드라이버가 GPU에 작업 전달
   ↓
6. GPU 실행
   - Binning Phase: BCL 실행 → 타일별 렌더링 명령 생성
   - Rendering Phase: RCL 실행 → 각 타일 렌더링
   ↓
7. 완료 시 out_sync 신호
```

---

### 3.2 `struct drm_v3d_create_bo` (246-260번 줄)

GPU 메모리 버퍼 객체 생성

```c
struct drm_v3d_create_bo {
    __u32 size;     // 요청 크기 (bytes)
    __u32 flags;    // 예약 (현재 사용 안 함)
    __u32 handle;   // [출력] GEM 핸들
    __u32 offset;   // [출력] GPU 주소 공간 오프셋
};
```

**중요:** `offset`은 항상 0이 아닌 값입니다 (하드웨어가 0을 특별하게 처리하므로).

**사용 예시 (`src/broadcom/vulkan/v3dv_bo.c:249`):**
```c
struct drm_v3d_create_bo create = {
    .size = size,
};
int ret = v3d_ioctl(device->render_fd, DRM_IOCTL_V3D_CREATE_BO, &create);
if (ret == 0) {
    bo->handle = create.handle;
    bo->offset = create.offset;
}
```

---

### 3.3 `struct drm_v3d_mmap_bo` (273-279번 줄)

GPU 버퍼를 CPU가 접근 가능한 가상 메모리로 매핑

```c
struct drm_v3d_mmap_bo {
    __u32 handle;   // BO 핸들
    __u32 flags;    // 예약
    __u64 offset;   // [출력] mmap()에 사용할 오프셋
};
```

**2단계 매핑 과정:**

1. `ioctl(DRM_IOCTL_V3D_MMAP_BO)` 호출 → `offset` 받음
2. `mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, offset)` 호출

**사용 예시 (`src/broadcom/vulkan/v3dv_bo.c:292`):**
```c
struct drm_v3d_mmap_bo mmap_bo = { .handle = bo->handle };
v3d_ioctl(device->render_fd, DRM_IOCTL_V3D_MMAP_BO, &mmap_bo);

bo->map = mmap(NULL, bo->size, PROT_READ | PROT_WRITE,
               MAP_SHARED, device->render_fd, mmap_bo.offset);
```

---

### 3.4 `struct drm_v3d_wait_bo` (234-238번 줄)

버퍼 작업 완료 대기 (블로킹 동기화)

```c
struct drm_v3d_wait_bo {
    __u32 handle;       // 대기할 BO 핸들
    __u32 pad;
    __u64 timeout_ns;   // 타임아웃 (나노초, 0 = 무한 대기)
};
```

**사용 시나리오:**
- CPU가 GPU 렌더링 결과를 읽기 전에 완료 대기
- 여러 프로세스가 동일 BO를 사용할 때 동기화

---

### 3.5 `struct drm_v3d_submit_tfu` (317-347번 줄)

**TFU (Texture Formatting Unit)** 작업 제출

TFU는 다음 작업을 하드웨어 가속으로 수행:
- 텍스처 포맷 변환 (RGBA → DXT, ETC 등)
- 밉맵 생성
- 타일 메모리 레이아웃 변환

```c
struct drm_v3d_submit_tfu {
    __u32 icfg;        // Image Configuration
    __u32 iia;         // Input Image Address
    __u32 iis;         // Input Image Stride
    __u32 ica;         // Input Chroma Address
    __u32 iua;         // Input U/V Address
    __u32 ioa;         // Input/Output Address
    __u32 ios;         // Input/Output Stride
    __u32 coef[4];     // Coefficient for format conversion
    __u32 bo_handles[4]; // 0: output, 1-3: inputs
    __u32 in_sync;     // 시작 전 대기할 syncobj
    __u32 out_sync;    // 완료 시 신호할 syncobj
    __u32 flags;
    __u64 extensions;
    struct {
        __u32 ioc;     // V3D 7.1 전용 필드
        __u32 pad;
    } v71;
};
```

---

### 3.6 `struct drm_v3d_submit_csd` (353-382번 줄)

**Compute Shader** 디스패치

```c
struct drm_v3d_submit_csd {
    __u32 cfg[7];           // Compute 설정 레지스터
    __u32 coef[4];          // TMU 설정
    __u64 bo_handles;       // 사용할 BO 배열 포인터
    __u32 bo_handle_count;
    __u32 in_sync;
    __u32 out_sync;
    __u32 perfmon_id;
    __u64 extensions;
    __u32 flags;
    __u32 pad;
};
```

**cfg[7] 레지스터:**
- `cfg[0-2]`: Workgroup 개수 (X, Y, Z)
- `cfg[3-5]`: Workgroup 크기 (X, Y, Z)
- `cfg[6]`: Batch 설정

---

## 4. GPU 큐 타입 (104-111번 줄)

```c
enum v3d_queue {
    V3D_BIN,         // Binning 작업 (BCL 실행)
    V3D_RENDER,      // Rendering 작업 (RCL 실행)
    V3D_TFU,         // Texture Formatting Unit
    V3D_CSD,         // Compute Shader Dispatch
    V3D_CACHE_CLEAN, // 캐시 플러시
    V3D_CPU,         // CPU 작업 (타임스탬프 쿼리 등)
};
```

**큐 간 의존성:**
```
V3D_BIN → V3D_RENDER (BCL이 먼저 실행되어야 RCL 실행 가능)
V3D_TFU, V3D_CSD: 독립 실행 가능
```

---

## 5. GPU 파라미터 조회 (281-299번 줄)

```c
enum drm_v3d_param {
    DRM_V3D_PARAM_V3D_UIFCFG,              // UIF 설정
    DRM_V3D_PARAM_V3D_HUB_IDENT1,          // Hub 식별자 1
    DRM_V3D_PARAM_V3D_HUB_IDENT2,          // Hub 식별자 2
    DRM_V3D_PARAM_V3D_HUB_IDENT3,          // Hub 식별자 3
    DRM_V3D_PARAM_V3D_CORE0_IDENT0,        // Core 0 식별자 0
    DRM_V3D_PARAM_V3D_CORE0_IDENT1,        // Core 0 식별자 1
    DRM_V3D_PARAM_V3D_CORE0_IDENT2,        // Core 0 식별자 2
    DRM_V3D_PARAM_SUPPORTS_TFU,            // TFU 지원 여부
    DRM_V3D_PARAM_SUPPORTS_CSD,            // Compute Shader 지원
    DRM_V3D_PARAM_SUPPORTS_CACHE_FLUSH,    // 캐시 플러시 지원
    DRM_V3D_PARAM_SUPPORTS_PERFMON,        // 성능 모니터 지원
    DRM_V3D_PARAM_SUPPORTS_MULTISYNC_EXT,  // Multi-sync 확장 지원
    DRM_V3D_PARAM_SUPPORTS_CPU_QUEUE,      // CPU 큐 지원
    DRM_V3D_PARAM_MAX_PERF_COUNTERS,       // 최대 성능 카운터 개수
    DRM_V3D_PARAM_SUPPORTS_SUPER_PAGES,    // Super Page 지원
    DRM_V3D_PARAM_GLOBAL_RESET_COUNTER,    // 전역 리셋 카운터
    DRM_V3D_PARAM_CONTEXT_RESET_COUNTER,   // 컨텍스트 리셋 카운터
};
```

**사용 예시 (`src/broadcom/vulkan/v3dv_device.c`):**
```c
struct drm_v3d_get_param param = {
    .param = DRM_V3D_PARAM_SUPPORTS_TFU,
};
v3d_ioctl(fd, DRM_IOCTL_V3D_GET_PARAM, &param);
if (param.value) {
    // TFU 지원됨
}
```

---

## 6. 확장 시스템 (71-88번 줄)

확장 가능한 IOCTL 인터페이스를 위한 링크드 리스트 구조

```c
struct drm_v3d_extension {
    __u64 next;   // 다음 확장 포인터 (NULL이면 끝)
    __u32 id;     // 확장 ID
    __u32 flags;  // Must be zero
};
```

**확장 타입:**
```c
#define DRM_V3D_EXT_ID_MULTI_SYNC                    0x01  // 다중 동기화
#define DRM_V3D_EXT_ID_CPU_INDIRECT_CSD              0x02  // 간접 Compute
#define DRM_V3D_EXT_ID_CPU_TIMESTAMP_QUERY           0x03  // 타임스탬프 쿼리
#define DRM_V3D_EXT_ID_CPU_RESET_TIMESTAMP_QUERY     0x04  // 타임스탬프 리셋
#define DRM_V3D_EXT_ID_CPU_COPY_TIMESTAMP_QUERY      0x05  // 타임스탬프 복사
#define DRM_V3D_EXT_ID_CPU_RESET_PERFORMANCE_QUERY   0x06  // 성능 쿼리 리셋
#define DRM_V3D_EXT_ID_CPU_COPY_PERFORMANCE_QUERY    0x07  // 성능 쿼리 복사
```

### 6.1 Multi-Sync 확장 (122-136번 줄)

여러 동기화 객체를 동시에 처리

```c
struct drm_v3d_multi_sync {
    struct drm_v3d_extension base;
    __u64 in_syncs;         // 입력 세마포어 배열 포인터
    __u64 out_syncs;        // 출력 세마포어 배열 포인터
    __u32 in_sync_count;    // 입력 세마포어 개수
    __u32 out_sync_count;   // 출력 세마포어 개수
    __u32 wait_stage;       // 대기할 큐 단계 (v3d_queue)
    __u32 pad;
};
```

**사용 시나리오:**
- Vulkan의 여러 세마포어를 단일 작업에 연결
- 복잡한 GPU 파이프라인 동기화

---

## 7. 성능 모니터링

### 7.1 성능 카운터 (622-711번 줄)

V3D 4.2용으로 87개의 하드웨어 성능 카운터 정의 (deprecated, `DRM_V3D_PERFMON_GET_COUNTER` 사용 권장)

**주요 카운터 카테고리:**

**렌더링 파이프라인:**
- `V3D_PERFCNT_FEP_VALID_PRIMS`: 유효한 프리미티브 수
- `V3D_PERFCNT_FEP_VALID_QUADS`: 유효한 쿼드 수
- `V3D_PERFCNT_TLB_QUADS_WRITTEN`: 프레임버퍼에 쓰인 쿼드

**QPU (쉐이더 실행):**
- `V3D_PERFCNT_QPU_IDLE_CYCLES`: QPU 유휴 사이클
- `V3D_PERFCNT_QPU_ACTIVE_CYCLES_FRAG`: 프래그먼트 쉐이더 실행 사이클
- `V3D_PERFCNT_QPU_CYCLES_TMU_STALL`: TMU 대기로 인한 스톨

**캐시:**
- `V3D_PERFCNT_QPU_IC_HIT/MISS`: Instruction Cache Hit/Miss
- `V3D_PERFCNT_L2T_HITS/MISSES`: L2 Cache Hit/Miss
- `V3D_PERFCNT_TMU_TCACHE_ACCESS/MISS`: Texture Cache

**메모리 대역폭:**
- `V3D_PERFCNT_AXI_WRITE_BYTES_WATCH_0`: AXI 쓰기 바이트 수
- `V3D_PERFCNT_AXI_READ_BYTES_WATCH_0`: AXI 읽기 바이트 수

### 7.2 성능 모니터 생성 (715-719번 줄)

```c
struct drm_v3d_perfmon_create {
    __u32 id;                                      // [출력] 생성된 perfmon ID
    __u32 ncounters;                               // 모니터링할 카운터 개수
    __u8 counters[DRM_V3D_MAX_PERF_COUNTERS];     // 카운터 ID 배열 (최대 32개)
};
```

### 7.3 성능 카운터 값 읽기 (734-738번 줄)

```c
struct drm_v3d_perfmon_get_values {
    __u32 id;            // perfmon ID
    __u32 pad;
    __u64 values_ptr;    // u64 배열 포인터 (ncounters 크기)
};
```

---

## 8. 실제 사용 예시

### 8.1 삼각형 렌더링 전체 흐름

```c
// 1. Vertex Buffer 생성
struct drm_v3d_create_bo vb_create = { .size = vertex_size };
ioctl(fd, DRM_IOCTL_V3D_CREATE_BO, &vb_create);

// 2. Framebuffer 생성
struct drm_v3d_create_bo fb_create = { .size = fb_size };
ioctl(fd, DRM_IOCTL_V3D_CREATE_BO, &fb_create);

// 3. Vertex Buffer에 데이터 복사
struct drm_v3d_mmap_bo vb_mmap = { .handle = vb_create.handle };
ioctl(fd, DRM_IOCTL_V3D_MMAP_BO, &vb_mmap);
void *vb_map = mmap(NULL, vertex_size, PROT_WRITE, MAP_SHARED, fd, vb_mmap.offset);
memcpy(vb_map, vertices, vertex_size);
munmap(vb_map, vertex_size);

// 4. BCL/RCL 생성 (Command List)
uint8_t *bcl = allocate_cl_buffer();
uint8_t *rcl = allocate_cl_buffer();
generate_bcl(bcl, vb_create.offset, vertex_count);
generate_rcl(rcl, fb_create.offset, width, height);

// 5. 렌더링 작업 제출
struct drm_v3d_submit_cl submit = {
    .bcl_start = bcl_bo_offset,
    .bcl_end = bcl_bo_offset + bcl_size,
    .rcl_start = rcl_bo_offset,
    .rcl_end = rcl_bo_offset + rcl_size,
    .qma = tile_alloc_offset,
    .qms = tile_alloc_size,
    .qts = tile_state_offset,
    .bo_handles = (uint64_t)&bo_array,  // {vb_handle, fb_handle, ...}
    .bo_handle_count = 2,
    .flags = 0,
};
ioctl(fd, DRM_IOCTL_V3D_SUBMIT_CL, &submit);

// 6. 완료 대기
struct drm_v3d_wait_bo wait = {
    .handle = fb_create.handle,
    .timeout_ns = 1000000000,  // 1초
};
ioctl(fd, DRM_IOCTL_V3D_WAIT_BO, &wait);

// 7. 결과 읽기
struct drm_v3d_mmap_bo fb_mmap = { .handle = fb_create.handle };
ioctl(fd, DRM_IOCTL_V3D_MMAP_BO, &fb_mmap);
void *fb_map = mmap(NULL, fb_size, PROT_READ, MAP_SHARED, fd, fb_mmap.offset);
save_image(fb_map, width, height);
```

### 8.2 Compute Shader 실행

```c
// 1. Input/Output 버퍼 생성
struct drm_v3d_create_bo input_bo = { .size = input_size };
struct drm_v3d_create_bo output_bo = { .size = output_size };
ioctl(fd, DRM_IOCTL_V3D_CREATE_BO, &input_bo);
ioctl(fd, DRM_IOCTL_V3D_CREATE_BO, &output_bo);

// 2. Compute Shader 제출
uint32_t bo_handles[] = { input_bo.handle, output_bo.handle };
struct drm_v3d_submit_csd csd = {
    .cfg = {
        workgroup_x,    // cfg[0]
        workgroup_y,    // cfg[1]
        workgroup_z,    // cfg[2]
        wg_size_x,      // cfg[3]
        wg_size_y,      // cfg[4]
        wg_size_z,      // cfg[5]
        batch_cfg,      // cfg[6]
    },
    .bo_handles = (uint64_t)bo_handles,
    .bo_handle_count = 2,
};
ioctl(fd, DRM_IOCTL_V3D_SUBMIT_CSD, &csd);
```

---

## 9. 디버깅 팁

### 9.1 IOCTL 호출 추적

```bash
# strace로 IOCTL 호출 확인
strace -e ioctl -v ./my_vulkan_app 2>&1 | grep V3D

# 출력 예시:
ioctl(5, DRM_IOCTL_V3D_CREATE_BO, {size=4096, flags=0}) = 0
ioctl(5, DRM_IOCTL_V3D_SUBMIT_CL, {bcl_start=0x1000, ...}) = 0
```

### 9.2 커널 로그 확인

```bash
# V3D 드라이버 디버그 메시지
sudo dmesg | grep v3d

# 예시 출력:
[   10.123] v3d fef00000.v3d: bin job submitted
[   10.125] v3d fef00000.v3d: render job completed
```

### 9.3 GPU 리셋 감지

```c
struct drm_v3d_get_param reset_check = {
    .param = DRM_V3D_PARAM_CONTEXT_RESET_COUNTER,
};
uint64_t last_reset = 0;

while (rendering) {
    ioctl(fd, DRM_IOCTL_V3D_GET_PARAM, &reset_check);
    if (reset_check.value != last_reset) {
        printf("GPU reset detected!\n");
        last_reset = reset_check.value;
        // 복구 로직...
    }
}
```

---

## 10. 참고 파일

| 파일 경로 | 역할 |
|-----------|------|
| `src/broadcom/vulkan/v3dv_queue.c` | SUBMIT_CL 호출 구현 |
| `src/broadcom/vulkan/v3dv_bo.c` | BO 생성/매핑 구현 |
| `src/broadcom/vulkan/v3dv_device.c` | GET_PARAM 호출로 GPU 정보 조회 |
| `src/broadcom/vulkan/v3dvx_cmd_buffer.c` | BCL/RCL 생성 |
| `src/broadcom/cle/v3d_packet.xml` | GPU 명령어 패킷 정의 |
| `drivers/gpu/drm/v3d/` (Linux Kernel) | 커널 드라이버 구현 |

---

## 11. 요약

**v3d_drm.h의 핵심 역할:**

1. **인터페이스 계약**: Mesa 드라이버와 Kernel 드라이버 간 통신 규약
2. **IOCTL 정의**: 14개의 GPU 작업 제출/관리 명령어
3. **데이터 구조**: 렌더링, 컴퓨트, 메모리 관리를 위한 구조체
4. **동기화**: syncobj 기반 GPU-CPU, GPU-GPU 동기화
5. **확장성**: 링크드 리스트 기반 확장 시스템
6. **성능 프로파일링**: 87개 하드웨어 카운터 접근

**가장 중요한 구조체:**
- `drm_v3d_submit_cl`: 3D 렌더링 작업 제출 (BCL + RCL)
- `drm_v3d_create_bo`: GPU 메모리 할당
- `drm_v3d_submit_csd`: Compute Shader 실행

**사용 흐름:**
```
Application → Mesa V3D Driver → v3d_drm.h (IOCTL) → Kernel V3D Driver → GPU
```

이 파일은 **Raspberry Pi 5의 Vulkan 지원의 핵심**이며, 모든 GPU 작업은 이 인터페이스를 통해 제출됩니다.
