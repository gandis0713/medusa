# 멀티 싱크 확장 (Multi-Sync Extension)

단일 sync object(`in_sync`, `out_sync`)로는 부족한 복잡한 의존성을 표현하기 위해 `DRM_V3D_EXT_ID_MULTI_SYNC` 확장을 사용할 수 있습니다. 이는 `DRM_V3D_SUBMIT_CL` 등의 `extensions` 필드에 연결하여 사용합니다.

### `struct drm_v3d_multi_sync`

```c
struct drm_v3d_multi_sync {
    struct drm_v3d_extension base;
    /* 대기(Wait) 및 시그널(Signal) 세마포어 배열 */
    __u64 in_syncs;  // 대기할 세마포어(`struct drm_v3d_sem`) 배열 포인터
    __u64 out_syncs; // 시그널할 세마포어(`struct drm_v3d_sem`) 배열 포인터

    /* 항목 개수 */
    __u32 in_sync_count;
    __u32 out_sync_count;

    /* 대기 단계 설정 (v3d_queue) */
    __u32 wait_stage;

    __u32 pad;
};
```

### 제약 사항 (Constraints)
- **`wait_stage`**: `in_syncs`의 세마포어들이 대기될 파이프라인 단계를 지정합니다. `V3D_bin` 또는 `V3D_render` 등 유효한 값이어야 합니다.
- **`pad`**: 0이어야 합니다.

### 사용 케이스 (Use Cases)

- **큐 간 동기화**: 렌더링 큐(CL)와 컴퓨트 큐(CSD) 간의 의존성 처리.
- **세마포어 대기 (Semaphore Wait)**: Vulkan `vkQueueSubmit`의 `pWaitSemaphores` 처리. 작업 시작 전 특정 세마포어가 시그널될 때까지 대기.
- **세마포어 시그널 (Semaphore Signal)**: Vulkan `vkQueueSubmit`의 `pSignalSemaphores` 처리. 작업 완료 후 세마포어 시그널.
- **타임라인 세마포어**: 값이 증가하는 타임라인 세마포어에 대한 대기/시그널 지원 (`point` 필드 사용).
- **파이프라인 단계 제어**: `wait_stage`를 통해 세마포어를 대기할 시점(Binning vs Rendering)을 세밀하게 제어.

바이너리 세마포어 또는 타임라인 세마포어를 정의합니다.

```c
struct drm_v3d_sem {
    __u32 handle; // syncobj 핸들
    __u32 flags;  // 플래그 (현재는 타임라인 관련 혹은 0)
    __u64 point;  // 타임라인 세마포어 지원을 위한 포인트 값
    __u64 mbz[2]; // 예약됨 (0이어야 함)
};
```
