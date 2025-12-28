# 버퍼 객체 생성 (Create BO)

V3D DRM은 GEM(Graphics Execution Manager)을 기반으로 버퍼 객체(Buffer Object, BO)를 관리합니다.

### `DRM_V3D_CREATE_BO`

새로운 V3D 버퍼 객체를 생성합니다.

- **매크로**: `DRM_IOCTL_V3D_CREATE_BO`
- **명령 코드**: `DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_CREATE_BO, struct drm_v3d_create_bo)`

#### `struct drm_v3d_create_bo`

```c
struct drm_v3d_create_bo {
    __u32 size;    // 생성할 버퍼의 크기 (바이트 단위) (입력)
    __u32 flags;   // 플래그 (현재는 사용되지 않음, 0이어야 함) (입력)
    __u32 handle;  // 생성된 BO의 GEM 핸들 (출력)
    __u32 offset;  // V3D 주소 공간에서의 BO 오프셋 (출력)
};
```

- **`offset`**: V3D 하드웨어가 이 버퍼에 접근할 때 사용하는 실제 가상 주소입니다.
    - 0이 아닌 값이어야 합니다.
    - 페이지 단위(4096 바이트)로 정렬된 주소가 반환됩니다.

### 제약 사항 (Constraints)

- **`size`**: 4096 바이트(1 페이지)의 배수여야 합니다. 그렇지 않으면 드라이버가 올림 처리할 수 있지만, 명시적으로 맞추는 것이 좋습니다.
- **`flags`**: 현재는 사용되지 않으므로 반드시 0이어야 합니다. 0이 아니면 향후 호환성을 위해 에러가 발생할 수 있습니다 (현재 커널 구현에 따라 다름).
- **`handle`**: IOCTL 성공 시 커널이 할당한 유효한 GEM 핸들이 반환됩니다.

### 사용 케이스 (Use Cases)

- **일반 버퍼 할당**: 셰이더, 텍스처, 버텍스 데이터, 인덱스 버퍼 등을 저장하기 위한 메모리 할당.
- **타일 할당 메모리 (Tile Allocation Memory)**: 렌더링 시 Binning 단계에서 사용될 타일 상태 정보를 저장할 메모리 할당.
- **셰이더 프로그램 메모리**: 셰이더 코드를 저장할 BO 할당.
- **임포트된 BO (PRIME)**: 다른 드라이버(예: 디스플레이)에서 생성된 dma-buf를 임포트한 후, 오프셋을 확인하기 위해 `DRM_IOCTL_V3D_GET_BO_OFFSET`과 함께 사용되지는 않지만, GEM 핸들을 통해 관리됨. (V3D 드라이버 내에서는 일반 BO와 동일하게 취급)

<br>

```c
// [코드 스니펫 삭제됨: 사용 케이스 설명으로 대체]
```
