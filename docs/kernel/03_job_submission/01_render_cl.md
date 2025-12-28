# 렌더링 작업 제출 (CL Submission)

`DRM_V3D_SUBMIT_CL` IOCTL은 3D 엔진에 빈닝(Binning) 및 렌더링(Renderer) 커맨드 리스트(Command List, CL)를 제출하여 실행을 요청합니다.

## IOCTL 정보

- **매크로**: `DRM_IOCTL_V3D_SUBMIT_CL`
- **명령 코드**: `DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_SUBMIT_CL, struct drm_v3d_submit_cl)`

## 데이터 구조체

### `struct drm_v3d_submit_cl`

```c
struct drm_v3d_submit_cl {
    // [Binning CL]
    // 첫 번째로 실행되는 명령어 집합. 좌표 셰이더를 실행하여 프리미티브의 위치를 결정하고,
    // 타일별로 필요한 상태 업데이트와 그리기 호출을 타일 할당 BO에 기록합니다.
    // 같은 FD 내의 이전 BCL은 자동으로 대기(block)하지만, 다른 클라이언트의 작업과는
    // 명시적인 동기화(in_sync_bcl)가 필요할 수 있습니다.
    __u32 bcl_start; // BCL 시작 오프셋
    __u32 bcl_end;   // BCL 끝 오프셋 (마지막 바이트의 다음 주소)

    // [Render CL]
    // 두 번째로 실행되는 명령어 집합. BCL에 의해 설정된 타일이나 고정된 타일 집합을 실행합니다.
    // 이 RCL은 해당 제출의 BCL 및 같은 FD의 이전 RCL을 자동으로 대기합니다.
    __u32 rcl_start; // RCL 시작 오프셋
    __u32 rcl_end;   // RCL 끝 오프셋

    // [Synchronization]
    __u32 in_sync_bcl; // BCL 시작 전 대기할 선택적 sync object (0이면 없음)
    __u32 in_sync_rcl; // RCL 시작 전 대기할 선택적 sync object
    __u32 out_sync;    // 작업 완료 시 시그널을 보낼 선택적 sync object

    // [Tile Allocation Memory]
    // V3D 3.3에서는 CL 내부에서 설정 가능하여 선택적이지만, V3D 4.1 이상에서는 필수입니다.
    __u32 qma; // 타일 할당 메모리의 오프셋
    __u32 qms; // 타일 할당 메모리의 크기
    __u32 qts; // 타일 상태 데이터 배열(Tile State Data Array)의 오프셋

    // [Buffer Objects]
    __u64 bo_handles;      // 작업에서 참조하는 BO 핸들들의 배열 포인터 (__u32 배열)
    __u32 bo_handle_count; // BO 핸들 개수

    // [Flags]
    __u32 flags; // 제출 플래그 (아래 참조)

    // [Performance Monitor]
    __u32 perfmon_id; // 이 작업에 연결할 PerfMon ID (0이면 없음)

    __u32 pad; // 패딩

    // [Extensions]
    __u64 extensions; // 확장 기능 링크드 리스트 포인터
};
```

## 제약 사항 (Constraints)

- **주소 정렬 (Alignments)**:
    - `bcl_start`, `bcl_end`, `rcl_start`, `rcl_end` 등 모든 주소 오프셋은 적절한 정렬을 따라야 합니다 (보통 명령어 단위 정렬 필요).
    - `qma`(Tile Allocation Memory)는 V3D 하드웨어 요구사항에 따라 4096 바이트(페이지) 정렬되어야 하는 경우가 많습니다.
- **`pad`**: 반드시 0이어야 합니다.
- **`bo_handle_count`**: `bo_handles` 배열의 크기와 일치해야 합니다. 이 배열에 포함되지 않은 BO를 CL에서 참조하면 GPU Fault가 발생할 수 있습니다.
- **`flags`**: 유효하지 않은 비트가 설정되면 `EINVAL` 에러가 발생할 수 있습니다.
- **메모리 오버플로우**: `qms`(Tile Allocation Memory Size)가 부족하면 렌더링 중 오버플로우가 발생할 수 있습니다.

## 사용 케이스 (Use Cases)

### 1. 기본 렌더링 제출 (Standard Rendering)
가장 일반적인 3D 렌더링 작업입니다. BCL(Binning)과 RCL(Rendering)을 쌍으로 제출합니다.
- **구성**: BCL의 시작/끝 주소, RCL의 시작/끝 주소, 타일 할당/상태 BO 정보 포함.
- **동작**: BCL이 먼저 실행되어 화면을 타일로 나누고 프리미티브를 빈닝한 뒤, RCL이 각 타일을 렌더링합니다.

### 2. RCL 전용 제출 (RCL-only Blit)
BCL 없이 렌더링만 수행하는 경우입니다(예: 화면 클리어, 전체 화면 블릿).
- **구성**: `bcl_start`, `bcl_end`는 0 또는 무시됨. RCL 정보만 유효.
- **주의**: V3D 하드웨어 버전에 따라 지원 방식이 다를 수 있음(일부 버전은 BCL 필수일 수 있음).

### 3. 멀티 싱크 동기화 제출 (With Multi-Sync)
`DRM_V3D_EXT_ID_MULTI_SYNC` 확장을 사용하여 복잡한 입출력 의존성을 처리합니다.
- **상황**: Vulkan의 세마포어(Semaphore) 대기/시그널이나 타임라인 세마포어 동작을 구현할 때.
- **구성**: `extensions` 필드에 `struct drm_v3d_multi_sync` 구조체를 연결하고, `in_sync_bcl` 등의 레거시 필드는 0으로 설정.

### 4. 캐시 플러시 (Cache Flush)
TMU(Texture Memory Unit) 등을 통한 메모리 쓰기(예: Image Store)가 발생한 직후, 해당 데이터를 BCL/RCL에서 읽어야 할 때.
- **구성**: `DRM_V3D_SUBMIT_CL_FLUSH_CACHE` 플래그 설정.
- **효과**: 작업 시작 전 L1/L2 캐시를 플러시하여 데이터 일관성 보장.

### 5. PerfMon 연결
성능 분석을 위해 특정 렌더링 패스의 성능 카운터를 수집할 때.
- **구성**: `perfmon_id` 필드에 생성된 PerfMon ID 설정.
- **효과**: 해당 CL 실행 동안 카운터가 누적됨.

## 플래그 (`flags`)

| 플래그 이름 | 값 | 설명 |
| :--- | :--- | :--- |
| `DRM_V3D_SUBMIT_CL_FLUSH_CACHE` | 0x01 | 작업 제출 시 캐시를 플러시합니다. TMU(Texture Memory Unit) 쓰기로 인해 캐시 라인이 더럽혀진 경우 호출자가 이 플래그를 사용하여 플러시해야 합니다. L1T, slice, L2C, L2T, GCA 캐시는 각 CL 실행 전에 플러시됩니다. |
| `DRM_V3D_SUBMIT_EXTENSION` | 0x02 | `extensions` 필드가 유효함을 나타냅니다. 확장 구조체를 사용할 때 설정해야 합니다. |

## 큐 (Queues)

이 IOCTL과 관련된 큐는 다음과 같습니다 (`enum v3d_queue`):
- `V3D_BIN`: Binning 작업 큐
- `V3D_RENDER`: Rendering 작업 큐
