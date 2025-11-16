# CLE (Control List Executor) - Vulkan 드라이버 가이드

## 개요

CLE는 Broadcom V3D GPU의 **Control List Executor**를 위한 하드웨어 패킷 정의 및 인코딩 레이어입니다. Vulkan 드라이버(`medusa/broadcom/vulkan`)는 CLE를 사용하여 `VkCommandBuffer`의 명령어를 V3D GPU가 이해할 수 있는 Control List로 변환합니다.

## V3D 7.1 (VideoCore VII - Raspberry Pi 5)

V3D 7.1은 Raspberry Pi 5의 **BCM2712 SoC**에 탑재된 GPU 버전입니다.

### 버전 정보
- **V3D 7.1.2**: 초기 버전
- **V3D 7.1.5**: RB swap 비트 추가
- **V3D 7.1.10**: 2712D0 전용 확장 기능

## Vulkan에서 CLE의 역할

### Vulkan Command Buffer → Control List 변환 과정

```
VkCommandBuffer (Vulkan API)
    ↓
v3dv_cmd_buffer (드라이버 내부 구조체)
    ↓
v3dv_job (렌더링 작업 단위)
    ↓
v3dv_cl (Control List 빌더)
    ↓
CLE Packets (v3d_packet_v71_pack.h)
    ↓
Control List (GPU 메모리의 바이트 스트림)
    ↓
V3D GPU 실행
```

### Control List의 두 가지 유형

#### 1. BCL (Binning Control List)
**목적**: 기하 처리 및 타일별 프리미티브 분류

```c
// v3dvx_cmd_buffer.c에서 BCL 생성 예제
void v3dX(job_emit_binning_prolog)(struct v3dv_job *job,
                                   const struct v3dv_frame_tiling *tiling,
                                   uint32_t layers)
{
    // 레이어 수 설정 (다층 렌더링)
    cl_emit(&job->bcl, NUMBER_OF_LAYERS, config) {
        config.number_of_layers = layers;
    }

    // 타일 비닝 모드 설정
    cl_emit(&job->bcl, TILE_BINNING_MODE_CFG, config) {
        config.width_in_pixels = tiling->width;
        config.height_in_pixels = tiling->height;
        config.log2_tile_width = log2_tile_size(tiling->tile_width);
        config.log2_tile_height = log2_tile_size(tiling->tile_height);
    }

    // VCD 캐시 플러시
    cl_emit(&job->bcl, FLUSH_VCD_CACHE, bin);

    // 타일 비닝 시작
    cl_emit(&job->bcl, START_TILE_BINNING, bin);
}
```

**BCL에 포함되는 주요 패킷:**
- `NUMBER_OF_LAYERS`: 렌더링 레이어 수
- `TILE_BINNING_MODE_CFG`: 타일 크기 및 렌더 타겟 설정
- `FLUSH_VCD_CACHE`: VCD(Vertex Cache Data) 플러시
- `START_TILE_BINNING`: 비닝 시작 명령
- `CLIP_WINDOW`: 클리핑 영역 설정
- `GEOMETRY_SHADER_STATE_RECORD`: 지오메트리/버텍스 셰이더 상태

#### 2. RCL (Rendering Control List)
**목적**: 타일별 픽셀 렌더링

```c
// RCL 생성 예제
cl_emit(rcl, TILE_RENDERING_MODE_CFG_COMMON, config) {
    config.early_z_disable = !job->early_z;
    config.image_width_pixels = tiling->width;
    config.image_height_pixels = tiling->height;
    config.number_of_render_targets = render_target_count;
    config.multisample_mode_4x = tiling->msaa;
    config.maximum_bpp_of_all_render_targets = tiling->internal_bpp;
}

// 렌더 타겟 설정 (컬러 첨부)
cl_emit(rcl, TILE_RENDERING_MODE_CFG_RENDER_TARGET_PART1, rt) {
    rt.render_target_number = i;
    rt.internal_type = fb->internal_type;
    rt.internal_bpp = fb->internal_bpp;
    rt.memory_format = v3d_memory_format(fb->vk_format);
    rt.output_image_format = v3d_output_image_format(fb->vk_format);
}

// 깊이/스텐실 클리어 값
cl_emit(rcl, TILE_RENDERING_MODE_CFG_ZS_CLEAR_VALUES, clear) {
    clear.z_clear_value = cmd_buffer->state.depth_clear_value;
    clear.stencil_clear_value = cmd_buffer->state.stencil_clear_value;
}
```

**RCL에 포함되는 주요 패킷:**
- `TILE_RENDERING_MODE_CFG_COMMON`: 공통 렌더링 설정
- `TILE_RENDERING_MODE_CFG_RENDER_TARGET_PART1/2/3`: 렌더 타겟 상세 설정
- `TILE_RENDERING_MODE_CFG_COLOR`: 컬러 버퍼 설정
- `TILE_RENDERING_MODE_CFG_ZS_CLEAR_VALUES`: 깊이/스텐실 클리어 값
- `TILE_RENDERING_MODE_CFG_CLEAR_COLORS_PART1/2/3`: 컬러 클리어 값
- `SUPERTILE_COORDINATES`: 슈퍼타일 좌표
- `CLEAR_RENDER_TARGETS`: 렌더 타겟 클리어

## 주요 파일 및 구조

### 1. `v3d_packet_v71_pack.h` (5,435 라인)
**자동 생성된 V3D 7.1 패킷 정의 헤더**

#### 주요 구조체 (Vulkan 렌더링 파이프라인 관점)

```c
// === Binning Pass 관련 ===

// 타일 비닝 모드 설정
struct V3D71_TILE_BINNING_MODE_CFG {
    uint32_t opcode;                        // 120
    uint32_t width_in_pixels;
    uint32_t height_in_pixels;
    uint32_t log2_tile_width;               // 타일 너비 (log2)
    uint32_t log2_tile_height;              // 타일 높이 (log2)
    // V3D 7.1: 가변 타일 크기 지원 (64x64, 128x64 등)
};

struct V3D71_START_TILE_BINNING {
    uint32_t opcode;                        // 6
};

struct V3D71_FLUSH_VCD_CACHE {
    uint32_t opcode;
};

// === Rendering Pass 관련 ===

// 타일 렌더링 공통 설정
struct V3D71_TILE_RENDERING_MODE_CFG_COMMON {
    uint32_t opcode;                        // 121
    uint32_t image_width_pixels;
    uint32_t image_height_pixels;
    uint32_t number_of_render_targets;
    uint32_t multisample_mode_4x;           // MSAA 4x 활성화
    uint32_t maximum_bpp_of_all_render_targets;
    bool early_z_disable;                   // Early-Z 테스트 비활성화
    bool early_z_update_direction;
    // ...
};

// 렌더 타겟 상세 설정 (VkFramebuffer의 각 attachment)
struct V3D71_TILE_RENDERING_MODE_CFG_RENDER_TARGET_PART1 {
    uint32_t render_target_number;          // 0-7
    uint32_t internal_type;                 // V3D71_Internal_Type
    uint32_t internal_bpp;                  // V3D71_Internal_BPP
    uint32_t memory_format;                 // UIF, Linear, etc.
    uint32_t output_image_format;           // RGBA8, RGBA16F, etc.
    // ...
};

// 컬러 클리어 값 (VkClearColorValue)
struct V3D71_TILE_RENDERING_MODE_CFG_CLEAR_COLORS_PART1 {
    uint32_t clear_color_low_32_bits;       // RGBA 클리어 값 (하위 32비트)
};

// 깊이/스텐실 클리어 값 (VkClearDepthStencilValue)
struct V3D71_TILE_RENDERING_MODE_CFG_ZS_CLEAR_VALUES {
    uint32_t z_clear_value;                 // 깊이 클리어 값
    uint32_t stencil_clear_value;           // 스텐실 클리어 값
};

// === 셰이더 관련 ===

struct V3D71_GEOMETRY_SHADER_STATE_RECORD {
    __gen_address_type shader_code_address; // 버텍스/지오메트리 셰이더 주소
    uint32_t shader_record_offset;
    // ...
};

// === 제어 명령 ===

struct V3D71_HALT { uint32_t opcode; };              // 0 - CL 종료
struct V3D71_NOP { uint32_t opcode; };               // 1
struct V3D71_FLUSH { uint32_t opcode; };             // 4 - 파이프라인 플러시
struct V3D71_FLUSH_ALL_STATE { uint32_t opcode; };   // 5
```

#### Vulkan 포맷 매핑 (VkFormat → V3D Format)

```c
enum V3D71_Output_Image_Format {
    // VK_FORMAT_R8G8B8A8_SRGB
    V3D_OUTPUT_IMAGE_FORMAT_SRGB8_ALPHA8  = 0,

    // VK_FORMAT_R8G8B8A8_UNORM
    V3D_OUTPUT_IMAGE_FORMAT_RGBA8         = 27,

    // VK_FORMAT_R16G16B16A16_SFLOAT
    V3D_OUTPUT_IMAGE_FORMAT_RGBA16F       = 18,

    // VK_FORMAT_R32G32B32A32_SFLOAT
    V3D_OUTPUT_IMAGE_FORMAT_RGBA32F       = 9,

    // VK_FORMAT_A2B10G10R10_UNORM_PACK32
    V3D_OUTPUT_IMAGE_FORMAT_RGB10_A2      = 3,

    // VK_FORMAT_D32_SFLOAT
    V3D_OUTPUT_IMAGE_FORMAT_D32F          = 40,

    // VK_FORMAT_D24_UNORM_S8_UINT
    V3D_OUTPUT_IMAGE_FORMAT_D24S8         = 43,

    // VK_FORMAT_D16_UNORM
    V3D_OUTPUT_IMAGE_FORMAT_D16           = 42,

    // Broadcom 텍스처 압축 (Vulkan 확장)
    V3D_OUTPUT_IMAGE_FORMAT_BSTC8         = 39,
    V3D_OUTPUT_IMAGE_FORMAT_BSTC10        = 47,

    // HDR 포맷
    V3D_OUTPUT_IMAGE_FORMAT_RGBA10X6_HLG  = 56,  // HLG HDR
    V3D_OUTPUT_IMAGE_FORMAT_RGBA10X6_PQ_BT1886 = 59,  // PQ HDR
};

enum V3D71_Memory_Format {
    V3D_MEMORY_FORMAT_RASTER              = 0,  // Linear
    V3D_MEMORY_FORMAT_LINEARTILE          = 1,  // Linear tiled
    V3D_MEMORY_FORMAT_UIF_NO_XOR          = 4,  // UIF (최적화된 타일 레이아웃)
    V3D_MEMORY_FORMAT_UIF_XOR             = 5,  // UIF + XOR 스크램블링
};
```

### 2. `v3dv_cl.h` - Vulkan CL 빌더 API

#### 핵심 구조체

```c
// Control List 빌더
struct v3dv_cl {
    void *base;                    // CL 버퍼 시작 주소
    struct v3dv_job *job;          // 소속 작업
    struct v3dv_cl_out *next;      // 현재 쓰기 위치
    struct v3dv_bo *bo;            // GPU 버퍼 오브젝트
    uint32_t size;                 // 버퍼 크기
    struct list_head bo_list;      // BO 참조 리스트
};

// BO 참조 (주소 재배치용)
struct v3dv_cl_reloc {
    struct v3dv_bo *bo;            // 버퍼 오브젝트
    uint32_t offset;               // 오프셋
};
```

#### Control List 빌드 매크로

```c
// 패킷 발행 매크로 (가장 많이 사용)
#define cl_emit(cl, packet, name)
```

**사용 예:**
```c
// VkCmdBeginRenderPass 구현 내부
cl_emit(&job->bcl, TILE_BINNING_MODE_CFG, config) {
    config.width_in_pixels = framebuffer->width;
    config.height_in_pixels = framebuffer->height;
    config.log2_tile_width = 6;  // 64픽셀 (2^6)
    config.log2_tile_height = 6;
}

// VkCmdClearAttachments 구현 내부
cl_emit(rcl, TILE_RENDERING_MODE_CFG_CLEAR_COLORS_PART1, clear) {
    clear.clear_color_low_32_bits = pack_color(clear_value);
}

// VkCmdPipelineBarrier에서 플러시
cl_emit(&job->bcl, FLUSH, flush);
```

### 3. Vulkan 드라이버의 CLE 사용 흐름

#### VkCommandBuffer 기록 → 실행

```c
// 1. Command Buffer 기록 시작 (vkBeginCommandBuffer)
v3dv_cmd_buffer_begin()
    └─> 내부 상태 초기화

// 2. Render Pass 시작 (vkCmdBeginRenderPass)
v3dv_CmdBeginRenderPass()
    └─> v3dv_job_start()
        └─> v3dv_cl_init(&job->bcl)  // BCL 초기화
        └─> v3dv_cl_init(&job->rcl)  // RCL 초기화

// 3. Binning Prolog 발행
v3dX(job_emit_binning_prolog)(job, tiling, layers)
    └─> cl_emit(&job->bcl, NUMBER_OF_LAYERS, ...)
    └─> cl_emit(&job->bcl, TILE_BINNING_MODE_CFG, ...)
    └─> cl_emit(&job->bcl, FLUSH_VCD_CACHE, ...)
    └─> cl_emit(&job->bcl, START_TILE_BINNING, ...)

// 4. 드로우 커맨드 (vkCmdDraw)
v3dv_CmdDraw()
    └─> BCL에 기하 데이터 패킷 추가

// 5. Render Pass 종료 (vkCmdEndRenderPass)
v3dv_CmdEndRenderPass()
    └─> Rendering Prolog 발행
        └─> cl_emit(rcl, TILE_RENDERING_MODE_CFG_COMMON, ...)
        └─> cl_emit(rcl, TILE_RENDERING_MODE_CFG_RENDER_TARGET_*, ...)

// 6. Command Buffer 제출 (vkQueueSubmit)
v3dv_QueueSubmit()
    └─> v3dv_queue_driver_submit()
        └─> DRM_IOCTL_V3D_SUBMIT_CL (BCL + RCL을 GPU에 전달)
```

## Tile-Based Deferred Rendering (TBDR) in Vulkan

V3D는 TBDR 아키텍처를 사용하며, 이는 Vulkan 렌더 패스와 자연스럽게 매핑됩니다.

### Vulkan Render Pass → V3D TBDR 매핑

```
VkRenderPass
    ↓
VkFramebuffer (1920x1080)
    ↓
타일 분할 (64x64 픽셀 타일)
    ↓
┌─────────────────────────────────────┐
│  Binning Pass (BCL)                 │
├─────────────────────────────────────┤
│ • VkCmdDraw → 기하 처리             │
│ • 각 타일에 영향 주는 삼각형 분류   │
│ • Tile Lists 생성                   │
└─────────────────────────────────────┘
    ↓
┌─────────────────────────────────────┐
│  Rendering Pass (RCL)               │
├─────────────────────────────────────┤
│ For each tile (30x17 = 510 tiles):  │
│   • Tile 메모리(TSDA)에 로드         │
│   • Fragment Shader 실행             │
│   • Early-Z, Blending                │
│   • Framebuffer에 쓰기               │
└─────────────────────────────────────┘
```

### Vulkan Subpass → Tile 최적화

```c
// Subpass dependencies를 통한 타일 메모리 최적화
VkSubpassDependency dependency = {
    .srcSubpass = 0,
    .dstSubpass = 1,
    .srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
    .dstStageMask = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
    .srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
    .dstAccessMask = VK_ACCESS_INPUT_ATTACHMENT_READ_BIT,
    .dependencyFlags = VK_DEPENDENCY_BY_REGION_BIT,  // 타일 단위 종속성
};
```

**VK_DEPENDENCY_BY_REGION_BIT의 의미:**
- 타일 단위로 종속성 해결
- 서브패스 간 타일 메모리 재사용
- 메모리 대역폭 절약

## V3D 7.1 특화 기능 (Vulkan 관점)

### 1. 가변 타일 크기
```c
// V3D 7.1에서 타일 크기 선택 가능
config.log2_tile_width = 6;   // 64 픽셀
config.log2_tile_height = 6;  // 64 픽셀

// 또는 비정방형 타일
config.log2_tile_width = 7;   // 128 픽셀
config.log2_tile_height = 6;  // 64 픽셀
```

### 2. Double Buffer 모드
```c
// 작은 렌더 타겟에서 성능 향상
config.double_buffer_in_non_ms_mode = true;
```

### 3. BSTC 텍스처 압축
Broadcom 전용 텍스처 압축 (Vulkan 확장으로 노출 가능)

### 4. HDR 렌더링
```c
// HLG/PQ HDR 포맷 지원
V3D_OUTPUT_IMAGE_FORMAT_RGBA10X6_HLG
V3D_OUTPUT_IMAGE_FORMAT_RGB10_A2_PQ_BT1886
```

## 실전 예제: Vulkan 삼각형 렌더링

### 1. Render Pass 설정
```c
VkRenderPassCreateInfo renderPassInfo = {
    .sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO,
    .attachmentCount = 1,
    .pAttachments = &colorAttachment,  // VK_FORMAT_R8G8B8A8_UNORM
    .subpassCount = 1,
    .pSubpasses = &subpass,
};
vkCreateRenderPass(device, &renderPassInfo, NULL, &renderPass);
```

**내부 CLE 변환:**
```c
// v3dvx_cmd_buffer.c
cl_emit(rcl, TILE_RENDERING_MODE_CFG_RENDER_TARGET_PART1, rt) {
    rt.internal_type = V3D_INTERNAL_TYPE_8;
    rt.internal_bpp = V3D_INTERNAL_BPP_32;
    rt.output_image_format = V3D_OUTPUT_IMAGE_FORMAT_RGBA8;  // ← VkFormat 매핑
}
```

### 2. Clear 값 설정
```c
VkClearValue clearColor = {.color = {{0.0f, 0.0f, 0.0f, 1.0f}}};
VkRenderPassBeginInfo beginInfo = {
    .renderPass = renderPass,
    .framebuffer = framebuffer,
    .clearValueCount = 1,
    .pClearValues = &clearColor,
};
vkCmdBeginRenderPass(cmdBuffer, &beginInfo, VK_SUBPASS_CONTENTS_INLINE);
```

**내부 CLE 변환:**
```c
cl_emit(rcl, TILE_RENDERING_MODE_CFG_CLEAR_COLORS_PART1, clear) {
    clear.clear_color_low_32_bits = 0xFF000000;  // RGBA(0, 0, 0, 1)
}
```

### 3. Draw 호출
```c
vkCmdDraw(cmdBuffer, 3, 1, 0, 0);  // 삼각형 (3 정점)
```

**내부 CLE 변환:**
```c
// BCL에 기하 데이터 추가
cl_emit(&job->bcl, VERTEX_ARRAY_PRIMITIVES, prim) {
    prim.mode = V3D_PRIM_TRIANGLES;
    prim.length = 3;
    prim.index_of_first_vertex = 0;
}
```

## 디버깅 및 검증

### Control List 덤프
```c
// v3d_decoder 사용 (환경 변수)
export V3D_DEBUG=cl

// 실행 시 BCL/RCL 덤프 출력
vkQueueSubmit(...);
```

**출력 예:**
```
BCL: 0x00001000
  0: TILE_BINNING_MODE_CFG (120)
     width: 1920
     height: 1080
  9: START_TILE_BINNING (6)
 10: VERTEX_ARRAY_PRIMITIVES (36)
     mode: TRIANGLES
```

### Vulkan Validation Layers
CLE 생성 오류는 일반적으로 Vulkan Validation에서 먼저 감지됩니다.

## 참고 파일

### Vulkan 드라이버 핵심 파일
- `v3dv_cmd_buffer.c`: Command buffer 기록
- `v3dvx_cmd_buffer.c`: CLE 발행 (버전별)
- `v3dv_queue.c`: GPU 제출
- `v3dv_cl.h`: CL 빌더 API
- `v3dv_private.h`: 드라이버 내부 구조체

### CLE 정의 파일
- `v3d_packet_v71_pack.h`: V3D 7.1 패킷 정의 (자동 생성)
- `v3d_packet.xml`: 패킷 사양 (소스)
- `v3d_packet_helpers.h`: Pack/Unpack 유틸리티

## 요약

**Vulkan → CLE 매핑:**

| Vulkan API | CLE 패킷 |
|-----------|---------|
| `vkCmdBeginRenderPass` | `TILE_BINNING_MODE_CFG`, `TILE_RENDERING_MODE_CFG_*` |
| `vkCmdDraw` | `VERTEX_ARRAY_PRIMITIVES` (BCL) |
| `VkClearValue` | `TILE_RENDERING_MODE_CFG_CLEAR_COLORS_*` |
| `VkFramebuffer` | `TILE_RENDERING_MODE_CFG_RENDER_TARGET_*` |
| `vkCmdPipelineBarrier` | `FLUSH`, `FLUSH_ALL_STATE` |
| Subpass dependencies | Tile memory 최적화 |

CLE는 Vulkan의 고수준 그래픽 명령어를 V3D GPU의 타일 기반 렌더링 파이프라인으로 효율적으로 변환하는 핵심 레이어입니다.
