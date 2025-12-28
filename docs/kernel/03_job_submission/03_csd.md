# CSD (Compute Shader Dispatch) 제출

`DRM_V3D_SUBMIT_CSD` IOCTL은 컴퓨트 셰이더 작업을 제출합니다.

- **IOCTL**: `DRM_IOCTL_V3D_SUBMIT_CSD`
- **구조체**: `struct drm_v3d_submit_csd`

### `struct drm_v3d_submit_csd`

```c
struct drm_v3d_submit_csd {
    __u32 cfg[7];   // Dispatch 설정 레지스터 값들
    __u32 coef[4];  // Shader Coefficients

    __u64 bo_handles;      // 참조 BO 핸들 배열 포인터
    __u32 bo_handle_count; // BO 핸들 개수

    /* 동기화 */
    __u32 in_sync;  // CSD 작업 전 대기할 sync object
    __u32 out_sync; // CSD 작업 완료 후 시그널할 sync object

    __u32 perfmon_id; // PerfMon ID

    __u64 extensions; // 확장

    __u32 flags;

    __u32 pad;
};
```

### 제약 사항 (Constraints)
- **`cfg`**: V3D CSD 디스패치 레지스터 포맷을 따라야 합니다.
- **`pad`**: 0이어야 합니다.
- **자원 참조**: 사용되는 모든 텍스처, 버퍼 BO는 `bo_handles` 목록에 포함되어야 합니다.

### 사용 케이스 (Use Cases)

- **컴퓨트 셰이더 실행**: 범용 연산(GPGPU) 작업 수행.
- **이미지 처리**: 포스트 프로세싱 효과 등.
- **버퍼 조작**: SSBO(Shader Storage Buffer Object) 데이터를 읽고 쓰는 작업.
- **동기화**: 이전 CL/TFU 작업의 결과를 입력으로 사용하거나, 결과를 후속 렌더링에 사용. (Sync Object 필수)
- **간접 디스패치 (Indirect Dispatch)**: (Direct CSD에서는 CPU 큐의 Indirect CSD와 달리, 커널 레벨에서 간접 버퍼를 처리하지 않음. 이 구조체는 주로 직접 디스패치에 사용됨.)

- **동기화**: 같은 FD 내의 CSD 작업은 순서대로 실행됩니다. 렌더링/TFU 또는 다른 FD의 CSD와 동기화하려면 sync object를 사용해야 합니다.
