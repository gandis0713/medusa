# 메모리 관리 (Memory Management)

V3D DRM은 GEM(Graphics Execution Manager)을 기반으로 버퍼 객체(Buffer Object, BO)를 관리합니다. 이 챕터에서는 V3D 하드웨어에서 사용되는 메모리 할당, 매핑 및 관리 방법에 대해 설명합니다.

## 세부 항목

### 1. [버퍼 객체 생성 (Create BO)](./02_memory_management/01_create_bo.md)
`DRM_V3D_CREATE_BO` IOCTL을 사용하여 새로운 GEM 버퍼 객체를 생성합니다. 셰이더, 텍스처, 버텍스 데이터 등 GPU가 접근해야 하는 모든 데이터는 BO에 저장되어야 합니다.

### 2. [버퍼 객체 매핑 (Mmap BO)](./02_memory_management/02_mmap_bo.md)
`DRM_V3D_MMAP_BO` IOCTL을 사용하여 BO를 사용자 공간(User Space)에 매핑하기 위한 오프셋을 얻습니다. 이후 `mmap()` 시스템 콜을 통해 CPU에서 해당 메모리에 직접 접근할 수 있습니다.

### 3. [버퍼 객체 오프셋 조회 (Get BO Offset)](./02_memory_management/03_get_bo_offset.md)
`DRM_V3D_GET_BO_OFFSET` IOCTL을 사용하여 이미 생성된 BO의 V3D 가상 주소(GPU 오프셋)를 조회합니다. 주로 공유된 BO의 주소를 확인할 때 사용됩니다.
