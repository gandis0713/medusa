# TFU (Texture Formatting Unit) 제출

`DRM_V3D_SUBMIT_TFU` IOCTL은 TFU 작업을 큐에 추가합니다. TFU는 텍스처 데이터의 포맷 변환, 밉맵 생성 등을 하드웨어적으로 처리합니다.

- **IOCTL**: `DRM_IOCTL_V3D_SUBMIT_TFU`
- **구조체**: `struct drm_v3d_submit_tfu`

### `struct drm_v3d_submit_tfu`

```c
struct drm_v3d_submit_tfu {
    __u32 icfg; // Input Configuration
    __u32 iia;  // Input Image Address
    __u32 iis;  // Input Image Stride
    __u32 ica;  // Input Chroma Address
    __u32 iua;  // Input U Address
    __u32 ioa;  // Input Output Address (Output Buffer)
    __u32 ios;  // Input Output Stride
    __u32 coef[4]; // Coefficients

    /* 참조하는 BO 핸들들. 첫 번째는 출력 BO, 나머지는 입력 BO들입니다.
     * 사용하지 않는 슬롯은 0으로 설정합니다. */
    __u32 bo_handles[4];

    /* 동기화 */
    __u32 in_sync;  // TFU 작업 전 대기할 sync object
    __u32 out_sync; // TFU 작업 완료 후 시그널할 sync object

    __u32 flags;

    __u64 extensions; // 확장

    /* V3D 7.x 전용 필드 */
    struct {
        __u32 ioc; // Input Output Configuration
        __u32 pad;
    } v71;
};
```

### 제약 사항 (Constraints)

- **`pad` / `mbz`**: 예약된 필드나 패딩은 반드시 0이어야 합니다.
- **이미지 주소**: `iia`, `ioa` 등은 128바이트 등 하드웨어가 요구하는 특정 단위로 정렬되어야 합니다.
- **`bo_handles`**: 사용하지 않는 슬롯은 0이어야 하며, 사용하는 슬롯은 유효한 BO 핸들이어야 합니다. 출력 BO는 첫 번째 슬롯이어야 합니다.

### 사용 케이스 (Use Cases)

- **밉맵 생성 (Mipmap Generation)**: 상위 레벨 밉맵(입력)을 읽어 필터링 후 하위 레벨(출력)로 작성.
- **텍스처 포맷 변환**: 타일링된 텍스처를 리니어 포맷으로 변환하거나 그 반대.
- **데이터 복사**: 텍스처 간의 단순 복사 (Blit).
- **멀티 싱크 타일링**: 렌더링 작업(CL)의 결과물을 다음 단계에서 텍스처로 사용하기 전 레이아웃 변환. `extensions`에 `MULTI_SYNC`를 연결하여 렌더링 완료 대기.

- **동기화**: 같은 FD 내의 TFU 작업은 순서대로 실행됩니다. 렌더링 작업과 동기화하려면 sync object를 사용해야 합니다.
