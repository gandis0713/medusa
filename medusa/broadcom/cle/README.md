# CLE (Control List Executor)

## 개요

CLE는 Broadcom V3D GPU의 **Control List Executor** 관련 패킷 정의 및 인코딩/디코딩 기능을 제공하는 디렉토리입니다. V3D GPU는 명령어를 메모리에 있는 **Control List** 형태로 받아서 실행하며, CLE는 이러한 제어 목록을 생성하고 관리하는 역할을 담당합니다.

## V3D 7.1 (VideoCore VII)

V3D 7.1은 Raspberry Pi 5에 탑재된 **2712 SoC**의 GPU 버전입니다.

### 버전 히스토리
- **V3D 7.1.2**: 초기 버전
- **V3D 7.1.5**: RB swap 비트 추가 (bit 32)
- **V3D 7.1.10**: 2712D0 전용 기능 추가

### 주요 파일

#### 1. `v3d_packet_v71_pack.h` (5,435 라인)
V3D 7.1 하드웨어를 위한 **자동 생성된 패킷 정의 헤더 파일**입니다.

**내용:**
- **312개의 구조체**: Control List 패킷 정의
- **Enum 정의**: 하드웨어 상수 및 옵션
- **Pack/Unpack 함수**: 구조체 ↔ 바이너리 변환

**주요 패킷 구조체:**

```c
// 타일 비닝 모드 설정
struct V3D71_TILE_BINNING_MODE_CFG {
    uint32_t opcode;                    // 120
    uint32_t tile_allocation_memory_size;
    uint32_t tile_allocation_block_size;
    // ... 기타 비닝 관련 설정
};

// 타일 렌더링 모드 설정
struct V3D71_TILE_RENDERING_MODE_CFG_COMMON {
    uint32_t opcode;                    // 121
    uint32_t image_width_pixels;
    uint32_t image_height_pixels;
    // ... 기타 렌더링 설정
};

// GL 셰이더 상태
struct V3D71_GL_SHADER_STATE {
    uint32_t opcode;                    // 64
    __gen_address_type address;
    // ... 셰이더 주소 및 설정
};

// 기본 제어 명령
struct V3D71_HALT { uint32_t opcode; };              // 0
struct V3D71_NOP { uint32_t opcode; };               // 1
struct V3D71_FLUSH { uint32_t opcode; };             // 4
struct V3D71_START_TILE_BINNING { uint32_t opcode; }; // 6
```

**주요 Enum 타입:**

```c
// 비교 함수
enum V3D71_Compare_Function {
    V3D_COMPARE_FUNC_NEVER   = 0,
    V3D_COMPARE_FUNC_LESS    = 1,
    V3D_COMPARE_FUNC_EQUAL   = 2,
    // ...
};

// 블렌드 모드
enum V3D71_Blend_Mode {
    V3D_BLEND_MODE_ADD    = 0,
    V3D_BLEND_MODE_SUB    = 1,
    V3D_BLEND_MODE_MIN    = 3,
    V3D_BLEND_MODE_MAX    = 4,
    // ...
};

// 프리미티브 타입
enum V3D71_Primitive {
    V3D_PRIM_POINTS          = 0,
    V3D_PRIM_LINES           = 1,
    V3D_PRIM_TRIANGLES       = 4,
    V3D_PRIM_TRIANGLE_STRIP  = 5,
    // ...
};

// 출력 이미지 포맷
enum V3D71_Output_Image_Format {
    V3D_OUTPUT_IMAGE_FORMAT_SRGB8_ALPHA8  = 0,
    V3D_OUTPUT_IMAGE_FORMAT_RGBA32F       = 9,
    V3D_OUTPUT_IMAGE_FORMAT_RGBA16F       = 18,
    V3D_OUTPUT_IMAGE_FORMAT_RGBA8         = 27,
    V3D_OUTPUT_IMAGE_FORMAT_D32F          = 40,
    V3D_OUTPUT_IMAGE_FORMAT_D24S8         = 43,
    // BSTC (Broadcom Texture Compression)
    V3D_OUTPUT_IMAGE_FORMAT_BSTC8         = 39,
    V3D_OUTPUT_IMAGE_FORMAT_BSTC10        = 47,
    V3D_OUTPUT_IMAGE_FORMAT_BSTC10_PQ     = 49,
    V3D_OUTPUT_IMAGE_FORMAT_BSTC10_HLG    = 55,
    // ...
};

// TMU (Texture Memory Unit) 연산
enum V3D71_TMU_Op {
    V3D_TMU_OP_REGULAR                     = 15,
    V3D_TMU_OP_WRITE_ADD_READ_PREFETCH     = 0,
    V3D_TMU_OP_WRITE_XCHG_READ_FLUSH       = 2,
    V3D_TMU_OP_WRITE_UMIN_FULL_L1_CLEAR    = 4,
    // ...
};

// 메모리 포맷
enum V3D71_Memory_Format {
    V3D_MEMORY_FORMAT_RASTER              = 0,
    V3D_MEMORY_FORMAT_LINEARTILE          = 1,
    V3D_MEMORY_FORMAT_UIF_NO_XOR          = 4, // UIF: Universal Image Format
    V3D_MEMORY_FORMAT_UIF_XOR             = 5,
};
```

**Pack/Unpack 함수 패턴:**

```c
// 구조체를 바이트 배열로 직렬화
static inline void
V3D71_FLUSH_pack(__gen_user_data *data,
                 uint8_t * restrict cl,
                 const struct V3D71_FLUSH * restrict values)
{
    cl[0] = util_bitpack_uint(values->opcode, 0, 7);
}

// 바이트 배열을 구조체로 역직렬화
static inline void
V3D71_FLUSH_unpack(const uint8_t * restrict cl,
                   struct V3D71_FLUSH * restrict values)
{
    values->opcode = __gen_unpack_uint(cl, 0, 7);
}

// 각 패킷의 길이 정의 (바이트 단위)
#define V3D71_FLUSH_length  1
#define V3D71_GL_SHADER_STATE_length  5
#define V3D71_TILE_BINNING_MODE_CFG_length  9
```

#### 2. `v3d_packet.xml` (88,020 바이트)
모든 V3D 버전(4.2 ~ 7.1)의 **패킷 사양 XML 정의 파일**입니다.

```xml
<vcxml gen="3.3" min_ver="42" max_ver="71">
  <enum name="Compare Function" prefix="V3D_COMPARE_FUNC">
    <value name="NEVER" value="0"/>
    <value name="LESS" value="1"/>
    <!-- ... -->
  </enum>

  <struct name="TILE_BINNING_MODE_CFG" cl="B">
    <!-- 패킷 필드 정의 -->
  </struct>
</vcxml>
```

이 XML 파일을 `gen_pack_header.py` 스크립트로 처리하여 `v3d_packet_v71_pack.h`가 생성됩니다.

#### 3. `v3d_packet_helpers.h`
패킷 pack/unpack을 위한 **유틸리티 함수 모음**입니다.

**주요 기능:**
```c
// 비트 추출 함수
static inline uint64_t
__gen_unpack_uint(const uint8_t *restrict cl,
                  uint32_t start, uint32_t end);

static inline uint64_t
__gen_unpack_sint(const uint8_t *restrict cl,
                  uint32_t start, uint32_t end);

// 고정소수점 변환
static inline float
__gen_unpack_sfixed(const uint8_t *restrict cl,
                    uint32_t start, uint32_t end,
                    uint32_t fractional_size);

// 부동소수점 변환
static inline float
__gen_unpack_float(const uint8_t *restrict cl,
                   uint32_t start, uint32_t end);

// 주소 오프셋 계산
static inline uint64_t
__gen_offset(uint64_t v, uint32_t start, uint32_t end);
```

#### 4. `v3d_decoder.c/h`
Control List 바이너리를 **디코딩하여 사람이 읽을 수 있는 형태로 변환**하는 디버깅 도구입니다.

**용도:**
- 디버깅 시 Control List 덤프
- GPU 커맨드 분석
- 드라이버 개발 시 검증

#### 5. `v3dx_pack.h`
버전 독립적인 **매크로 레이어**로, 런타임에 V3D 버전을 선택할 수 있게 합니다.

```c
#if V3D_VERSION == 42
#  include "v3d_packet_v42_pack.h"
#elif V3D_VERSION == 71
#  include "v3d_packet_v71_pack.h"
#endif
```

## Control List의 역할

V3D GPU는 **명령어 버퍼(Command Buffer)**를 직접 실행하지 않고, 메모리에 저장된 **Control List**를 읽어서 실행합니다.

### Control List 구조

```
┌─────────────────────────────────────┐
│   Tile Binning Control List         │
├─────────────────────────────────────┤
│ TILE_BINNING_MODE_CFG               │ ← 비닝 모드 설정
│ START_TILE_BINNING                  │ ← 비닝 시작
│ GL_SHADER_STATE (vertex)            │ ← 버텍스 셰이더
│ ... (geometry commands)             │
│ FLUSH                               │
└─────────────────────────────────────┘

┌─────────────────────────────────────┐
│   Tile Rendering Control List       │
├─────────────────────────────────────┤
│ TILE_RENDERING_MODE_CFG_COMMON      │ ← 렌더링 모드 설정
│ SUPERTILE_COORDINATES               │ ← 타일 좌표
│ GL_SHADER_STATE (fragment)          │ ← 프래그먼트 셰이더
│ ... (rendering commands)            │
│ CLEAR_RENDER_TARGETS                │
│ HALT                                │ ← 종료
└─────────────────────────────────────┘
```

### Tile-Based Rendering

V3D는 **Tile-Based Deferred Rendering (TBDR)** 아키텍처를 사용합니다:

1. **Binning Pass**: 기하 처리 및 타일별 정렬
   - 화면을 타일(64x64 픽셀)로 분할
   - 각 타일에 영향을 주는 프리미티브 분류

2. **Rendering Pass**: 타일별 래스터화
   - 타일 단위로 on-chip 메모리에서 렌더링
   - 대역폭 최적화

## V3D 7.1 특화 기능

### 1. BSTC (Broadcom Texture Compression)
```c
V3D_OUTPUT_IMAGE_FORMAT_BSTC8         // 8-bit BSTC
V3D_OUTPUT_IMAGE_FORMAT_BSTC10        // 10-bit BSTC
V3D_OUTPUT_IMAGE_FORMAT_BSTC10_PQ     // PQ 색공간
V3D_OUTPUT_IMAGE_FORMAT_BSTC10_HLG    // HLG 색공간
```

### 2. HDR 지원
```c
V3D_OUTPUT_IMAGE_FORMAT_RGBA10X6_HLG        // HLG HDR
V3D_OUTPUT_IMAGE_FORMAT_RGBA10X6_PQ_BT1886  // PQ HDR (BT.1886)
```

### 3. UIF (Universal Image Format)
```c
V3D_MEMORY_FORMAT_UIF_NO_XOR  // XOR 없는 UIF
V3D_MEMORY_FORMAT_UIF_XOR     // XOR 스크램블링 포함
```

### 4. Supertile 지원
타일을 그룹화한 **Supertile** 단위 렌더링 지원으로 효율성 향상

## 사용 예제

### Control List 생성 예제

```c
#include "cle/v3d_packet_v71_pack.h"

void build_control_list(void *cl_buffer)
{
    uint8_t *cl = (uint8_t *)cl_buffer;

    // 타일 비닝 모드 설정
    struct V3D71_TILE_BINNING_MODE_CFG binning_cfg = {
        .opcode = V3D71_TILE_BINNING_MODE_CFG_opcode,
        .tile_allocation_memory_size = 1024 * 1024,
        .width_in_pixels = 1920,
        .height_in_pixels = 1080,
        // ...
    };
    V3D71_TILE_BINNING_MODE_CFG_pack(NULL, cl, &binning_cfg);
    cl += V3D71_TILE_BINNING_MODE_CFG_length;

    // 비닝 시작
    struct V3D71_START_TILE_BINNING start = {
        .opcode = V3D71_START_TILE_BINNING_opcode
    };
    V3D71_START_TILE_BINNING_pack(NULL, cl, &start);
    cl += V3D71_START_TILE_BINNING_length;

    // GL 셰이더 상태
    struct V3D71_GL_SHADER_STATE shader = {
        .opcode = V3D71_GL_SHADER_STATE_opcode,
        .address = shader_code_address,
    };
    V3D71_GL_SHADER_STATE_pack(NULL, cl, &shader);
    cl += V3D71_GL_SHADER_STATE_length;

    // ... 추가 명령어

    // 플러시
    struct V3D71_FLUSH flush = {
        .opcode = V3D71_FLUSH_opcode
    };
    V3D71_FLUSH_pack(NULL, cl, &flush);
}
```

## 참고사항

### 생성 파일
`v3d_packet_v71_pack.h`는 자동 생성 파일이므로 **직접 수정하지 마십시오**. 수정이 필요한 경우:
1. `v3d_packet.xml`을 수정
2. `gen_pack_header.py` 재실행

### 디버깅
Control List 디버깅 시 `v3d_decoder`를 사용하여 바이너리를 디코딩할 수 있습니다.

### 관련 디렉토리
- `medusa/broadcom/qpu/`: QPU 명령어 인코딩/디코딩
- `medusa/broadcom/compiler/`: V3D 컴파일러 (NIR → VIR → QPU)
- `medusa/vulkan/`: Vulkan 드라이버 (CLE를 사용하여 명령어 버퍼 생성)

## 요약

**CLE (Control List Executor)**는 V3D GPU에게 전달할 하드웨어 명령어를 생성하는 핵심 레이어입니다. V3D 7.1 패킷 정의를 통해 Raspberry Pi 5의 GPU를 제어하며, 타일 기반 렌더링, HDR, 텍스처 압축 등 현대 GPU 기능을 지원합니다.
