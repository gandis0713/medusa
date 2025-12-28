# 버퍼 객체 오프셋 조회 (Get BO Offset)

### `DRM_V3D_GET_BO_OFFSET`

이미 생성된 BO의 V3D 주소 공간 오프셋을 다시 조회합니다. `create_bo` 시 반환받은 값과 동일합니다. 주로 다른 프로세스나 컨텍스트에서 BO를 공유받았을 때 오프셋을 확인하는 용도로 사용됩니다.

- **매크로**: `DRM_IOCTL_V3D_GET_BO_OFFSET`
- **명령 코드**: `DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_GET_BO_OFFSET, struct drm_v3d_get_bo_offset)`

#### `struct drm_v3d_get_bo_offset`

```c
struct drm_v3d_get_bo_offset {
    __u32 handle;  // 조회할 BO의 핸들 (입력)
    __u32 offset;  // V3D 주소 공간에서의 오프셋 (출력)
};
```
