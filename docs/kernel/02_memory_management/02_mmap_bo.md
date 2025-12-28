# 버퍼 객체 매핑 (Mmap BO)

### `DRM_V3D_MMAP_BO`

BO를 사용자 공간(User space)으로 메모리 매핑(mmap)하기 위한 오프셋을 얻습니다. 이 IOCTL 자체가 mmap을 수행하는 것은 아니며, 이후 `mmap()` 시스템 콜에 사용할 인자를 반환합니다.

- **매크로**: `DRM_IOCTL_V3D_MMAP_BO`
- **명령 코드**: `DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_MMAP_BO, struct drm_v3d_mmap_bo)`

#### `struct drm_v3d_mmap_bo`

```c
struct drm_v3d_mmap_bo {
    __u32 handle;  // 매핑할 BO의 핸들 (입력)
    __u32 flags;   // 플래그 (현재 사용되지 않음) (입력)
    __u64 offset;  // mmap() 호출 시 사용할 '가짜' 오프셋 (출력)
};
```

### 사용 케이스 (Use Cases)

- **CPU 접근 (데이터 업로드)**: CPU에서 GPU로 데이터를 전송해야 할 때 (예: 텍스처 업로드, 버퍼 데이터 쓰기).
- **CPU 접근 (데이터 다운로드)**: GPU 작업 결과를 CPU에서 확인해야 할 때 (예: 쿼리 결과, 스크린샷 캡처).
- **디버깅**: BO의 내용을 덤프하거나 검증하기 위해 매핑.

**참고**: 성능을 위해서는 잦은 매핑/언매핑이나 동기화되지 않은 CPU 접근을 피해야 합니다.

- 반환된 `offset`을 사용하여 `mmap(..., offset)`을 호출하면, 실제 BO 메모리에 접근할 수 있습니다.
