# BO 대기 (Wait BO)

V3D 작업 간 또는 CPU와 GPU 간의 동기화 메커니즘을 설명합니다.

### `DRM_V3D_WAIT_BO`

특정 BO에 대한 마지막 `DRM_V3D_SUBMIT_CL` 렌더링 작업이 완료될 때까지 대기합니다.
여러 프로세스가 하나의 BO에 렌더링하는 경우, 모든 렌더링이 끝났는지 확인할 때 유용합니다.

- **매크로**: `DRM_IOCTL_V3D_WAIT_BO`
- **명령 코드**: `DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_WAIT_BO, struct drm_v3d_wait_bo)`

#### `struct drm_v3d_wait_bo`

```c
struct drm_v3d_wait_bo {
    __u32 handle;      // 대기할 BO 핸들 (입력)
    __u32 pad;
    __u64 timeout_ns;  // 타임아웃 (나노초). 0이면 폴링하지 않고 즉시 반환 가능. (입력)
};
```

### 제약 사항 (Constraints)

- **`pad`**: 0이어야 합니다.
- **`timeout_ns`**: 절대 시간이 아닌 상대 시간(duration)입니다. `INT64_MAX` 등 매우 큰 값을 주면 사실상 무한 대기입니다.

### 사용 케이스 (Use Cases)

- **CPU 대기 (Blocking Wait)**: CPU가 GPU 작업 완료를 기다려야 할 때 (예: 맵핑된 버퍼 읽기 전).
- **타임아웃 처리**: 작업이 너무 오래 걸리거나 행이 걸렸는지 확인할 때 (`timeout_ns` 사용).
- **폴링 (Polling)**: `timeout_ns`를 0으로 설정하여 현재 완료 상태만 빠르게 확인할 때.
