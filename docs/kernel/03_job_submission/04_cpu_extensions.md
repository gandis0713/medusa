# CPU 작업 및 확장 (CPU Submission & Extensions)

`DRM_V3D_SUBMIT_CPU` IOCTL은 CPU에서 처리하거나 CPU가 관여하는 작업을 제출하는 데 사용됩니다. 주로 확장(Extension) 기능을 통해 다양한 작업을 정의합니다.

## IOCTL 정보

- **매크로**: `DRM_IOCTL_V3D_SUBMIT_CPU`
- **명령 코드**: `DRM_IOW(DRM_COMMAND_BASE + DRM_V3D_SUBMIT_CPU, struct drm_v3d_submit_cpu)`

## 데이터 구조체

### `struct drm_v3d_submit_cpu`

```c
struct drm_v3d_submit_cpu {
    /* 참조하는 BO 핸들 배열 포인터.
     * 확장 기능에 따라 필요한 BO의 개수와 용도가 달라집니다.
     * - INDIRECT_CSD: 1개 (워크그룹 카운트 포함)
     * - TIMESTAMP_QUERY: 1개 (타임스탬프 저장)
     * - RESET_TIMESTAMP: 1개 (타임스탬프 저장 BO)
     * - COPY_TIMESTAMP: 2개 (타겟 BO, 타임스탬프 원본 BO)
     * - RESET_PERFORMANCE: 0개
     * - COPY_PERFORMANCE: 1개 (결과 저장 BO)
     */
    __u64 bo_handles;
    __u32 bo_handle_count;

    __u32 flags;
    __u64 extensions; // 필수: 수행할 CPU 작업을 정의하는 확장을 연결해야 함
};
```

## 제약 사항 (Constraints)

- **`extensions`**: 반드시 하나 이상의 확장이 연결되어야 하며, 연결된 확장의 종류(ID)에 따라 `bo_handle_count`와 `bo_handles`의 내용이 정확해야 합니다.
- **BO 개수**: 각 확장이 요구하는 정확한 개수의 BO를 제공해야 합니다 (예: Timestamp Query는 1개).
- **CPU Queue 기능**: 커널이 CPU Queue 기능을 지원해야 사용 가능합니다 (`DRM_V3D_PARAM_SUPPORTS_CPU_QUEUE`로 확인).

## 사용 케이스 (Use Cases)

### 1. 타임스탬프 쿼리 (Timestamp Query)
- **`DRM_V3D_EXT_ID_CPU_TIMESTAMP_QUERY`**: GPU 작업 흐름 중 특정 시점의 타임스탬프를 기록합니다. 모든 이전 작업이 완료된 후 실행되도록 `MULTI_SYNC`의 `WAIT` 단계와 함께 사용됩니다.
- **`DRM_V3D_EXT_ID_CPU_RESET_TIMESTAMP_QUERY`**: 쿼리 풀의 가용 상태를 리셋합니다.
- **`DRM_V3D_EXT_ID_CPU_COPY_TIMESTAMP_QUERY`**: 쿼리 결과를 사용자 버퍼(또는 다른 BO)로 복사합니다. `vkCmdCopyQueryPoolResults` 구현에 사용됩니다.

### 2. 성능 모니터 쿼리 (Performance Query)
- **`DRM_V3D_EXT_ID_CPU_RESET_PERFORMANCE_QUERY`**: 성능 카운터 값을 초기화합니다.
- **`DRM_V3D_EXT_ID_CPU_COPY_PERFORMANCE_QUERY`**: 성능 카운터 값을 버퍼로 복사합니다.

### 3. 간접 CSD (Indirect CSD)
- **`DRM_V3D_EXT_ID_CPU_INDIRECT_CSD`**: CPU가 간접 버퍼(Indirect Buffer)의 내용을 읽어 워크그룹 개수를 확인한 뒤, 실제 CSD 작업을 제출합니다. 이는 GPU가 생성한 워크그룹 개수로 CSD를 실행해야 할 때(GPU-driven rendering) 사용됩니다. CPU 큐는 이 과정(대기 -> 읽기 -> 제출)을 커널 내에서 원자적으로 처리합니다.

## 확장 (Extensions)

`drm_v3d_submit_cpu`의 `extensions` 필드는 `struct drm_v3d_extension` 리스트를 가리킵니다. `id` 필드를 통해 확장의 종류를 구분합니다.

### 공통 헤더 (`struct drm_v3d_extension`)

```c
struct drm_v3d_extension {
    __u64 next; // 다음 확장 포인터 (없으면 0)
    __u32 id;   // 확장 ID
    __u32 flags; // mbz (Must be zero)
};
```

### 확장 ID 목록

| 매크로 (`DRM_V3D_EXT_ID_...`) | 값 | 설명 | 문서 섹션 |
| :--- | :--- | :--- | :--- |
| `MULTI_SYNC` | 0x01 | 다중 동기화 지원 (WAIT_BO 등 다른 곳에서도 사용됨) | [동기화 문서](06_synchronization.md) |
| `CPU_INDIRECT_CSD` | 0x02 | 간접 CSD (Indirect Compute Shader Dispatch) | 아래 참조 |
| `CPU_TIMESTAMP_QUERY` | 0x03 | 타임스탬프 쿼리 | 아래 참조 |
| `CPU_RESET_TIMESTAMP_QUERY` | 0x04 | 타임스탬프 쿼리 리셋 | 아래 참조 |
| `CPU_COPY_TIMESTAMP_QUERY` | 0x05 | 타임스탬프 쿼리 결과 복사 | 아래 참조 |
| `CPU_RESET_PERFORMANCE_QUERY` | 0x06 | 성능 쿼리 리셋 | 아래 참조 |
| `CPU_COPY_PERFORMANCE_QUERY` | 0x07 | 성능 쿼리 결과 복사 | 아래 참조 |

### 간접 CSD (`struct drm_v3d_indirect_csd`)

CPU 작업이 간접 CSD 의존성을 기다렸다가, 시그널이 오면 CSD 작업 설정을 업데이트하고 실행을 허용합니다.

```c
struct drm_v3d_indirect_csd {
    struct drm_v3d_extension base;
    struct drm_v3d_submit_csd submit; // 실행할 CSD 작업 정보
    __u32 indirect; // 워크그룹 카운트가 저장된 간접 BO 핸들
    __u32 offset;   // BO 내 워크그룹 카운트 오프셋
    __u32 wg_size;  // 워크그룹 크기
    __u32 wg_uniform_offsets[3]; // 유니폼 스트림 내 워크그룹 카운트 유니폼의 인덱스
};
```

### 타임스탬프 쿼리 (`struct drm_v3d_timestamp_query`)

타임스탬프를 계산하여 BO에 업데이트하고 syncobj를 시그널합니다.

```c
struct drm_v3d_timestamp_query {
    struct drm_v3d_extension base;
    __u64 offsets; // 타임스탬프 BO 내 오프셋 배열
    __u64 syncs;   // 가용성을 알릴 syncobj 배열
    __u32 count;   // 쿼리 개수
    __u32 pad;
};
```

### 타임스탬프 리셋 (`struct drm_v3d_reset_timestamp_query`)

타임스탬프 쿼리 가용성을 리셋합니다.

```c
struct drm_v3d_reset_timestamp_query {
    struct drm_v3d_extension base;
    __u64 syncs;   // 리셋할 syncobj 배열
    __u32 offset;  // 첫 번째 쿼리의 오프셋
    __u32 count;   // 쿼리 개수
};
```

### 타임스탬프 복사 (`struct drm_v3d_copy_timestamp_query`)

타임스탬프 결과를 지정된 버퍼로 복사합니다.

```c
struct drm_v3d_copy_timestamp_query {
    struct drm_v3d_extension base;
    __u8 do_64bit;        // 64비트 쓰기 여부
    __u8 do_partial;      // 가용하지 않아도 쓰기 허용 여부
    __u8 availability_bit;// 가용성 비트 쓰기 여부
    __u8 pad;
    __u32 offset;         // 타겟 BO 내 오프셋
    __u32 stride;         // 스트라이드
    __u32 count;          // 쿼리 개수
    __u64 offsets;        // 타임스탬프 BO 내 원본 오프셋 배열
    __u64 syncs;          // 가용성 확인용 syncobj 배열
};
```

### 성능 쿼리 리셋 (`struct drm_v3d_reset_performance_query`)

성능 모니터 값을 리셋하고 쿼리 가용성을 리셋합니다.

```c
struct drm_v3d_reset_performance_query {
    struct drm_v3d_extension base;
    __u64 syncs;         // 리셋할 syncobj 배열
    __u32 count;         // 쿼리 개수
    __u32 nperfmons;     // 성능 모니터 개수
    __u64 kperfmon_ids;  // perfmon ID 배열의 포인터
};
```

### 성능 쿼리 복사 (`struct drm_v3d_copy_performance_query`)

성능 쿼리 결과를 버퍼로 복사합니다.

```c
struct drm_v3d_copy_performance_query {
    struct drm_v3d_extension base;
    __u8 do_64bit;
    __u8 do_partial;
    __u8 availability_bit;
    __u8 pad;
    __u32 offset;        // 타겟 BO 내 오프셋
    __u32 stride;        // 스트라이드
    __u32 nperfmons;     // 성능 모니터 개수
    __u32 ncounters;     // 카운터 개수
    __u32 count;         // 쿼리 개수
    __u64 syncs;         // 가용성 확인용 syncobj 배열
    __u64 kperfmon_ids;  // perfmon ID 배열 포인터
};
```
