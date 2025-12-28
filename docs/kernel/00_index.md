# V3D DRM 커널 인터페이스 문서

이 문서는 `medusa/include/drm-uapi/v3d_drm.h` 헤더 파일에 정의된 V3D DRM (Direct Rendering Manager) 커널 인터페이스에 대한 상세한 기술 문서입니다.
Raspberry Pi 5 (V3D 7.1) 및 이전 버전을 지원하는 커널 드라이버와의 인터페이스를 설명합니다.

## 목차 (Table of Contents)

1. [파라미터 조회 (Parameters)](./01_parameters.md) - `DRM_V3D_GET_PARAM`
2. [메모리 관리 (Memory Management)](./02_memory_management.md)
    - [버퍼 객체 생성 (Create BO)](./02_memory_management/01_create_bo.md)
    - [버퍼 객체 매핑 (Mmap BO)](./02_memory_management/02_mmap_bo.md)
    - [버퍼 객체 오프셋 조회 (Get Offset)](./02_memory_management/03_get_bo_offset.md)
3. [렌더링 제출 (CL Submission)](./03_submission_cl.md) - `DRM_V3D_SUBMIT_CL`
4. [기타 작업 제출 (TFU/CSD)](./04_submission_tfu_csd.md)
    - [TFU 제출](./04_submission_tfu_csd/01_submit_tfu.md)
    - [CSD 제출](./04_submission_tfu_csd/02_submit_csd.md)
5. [CPU 작업 및 확장 (CPU Submission)](./05_submission_cpu.md) - `DRM_V3D_SUBMIT_CPU`
6. [동기화 (Synchronization)](./06_synchronization.md)
    - [BO 대기 (Wait BO)](./06_synchronization/01_wait_bo.md)
    - [멀티 싱크 (Multi-Sync)](./06_synchronization/02_multi_sync.md)
7. [성능 모니터링 (Performance Monitoring)](./07_performance_monitoring.md)
    - [생성 및 파괴](./07_performance_monitoring/01_create_destroy.md)
    - [값 조회 및 기타](./07_performance_monitoring/02_get_values.md)

## IOCTL 요약

V3D 드라이버는 다음과 같은 IOCTL들을 제공합니다. 기본 `DRM_COMMAND_BASE`에 아래의 값을 더하여 명령을 생성합니다.

| IOCTL 이름 | 값 | 설명 | 문서 |
| :--- | :--- | :--- | :--- |
| `DRM_V3D_SUBMIT_CL` | 0x00 | 렌더링 커맨드 리스트(BCL, RCL) 제출 | [링크](03_submission_cl.md) |
| `DRM_V3D_WAIT_BO` | 0x01 | 특정 BO의 작업 완료 대기 | [링크](06_synchronization/01_wait_bo.md) |
| `DRM_V3D_CREATE_BO` | 0x02 | 버퍼 객체(BO) 생성 | [링크](02_memory_management/01_create_bo.md) |
| `DRM_V3D_MMAP_BO` | 0x03 | BO의 mmap 오프셋 조회 | [링크](02_memory_management/02_mmap_bo.md) |
| `DRM_V3D_GET_PARAM` | 0x04 | 드라이버/하드웨어 파라미터 조회 | [링크](01_parameters.md) |
| `DRM_V3D_GET_BO_OFFSET` | 0x05 | BO의 V3D 주소 공간 오프셋 조회 | [링크](02_memory_management/03_get_bo_offset.md) |
| `DRM_V3D_SUBMIT_TFU` | 0x06 | 텍스처 포맷팅 유닛(TFU) 작업 제출 | [링크](04_submission_tfu_csd/01_submit_tfu.md) |
| `DRM_V3D_SUBMIT_CSD` | 0x07 | 컴퓨트 셰이더(CSD) 작업 제출 | [링크](04_submission_tfu_csd/02_submit_csd.md) |
| `DRM_V3D_PERFMON_CREATE` | 0x08 | 성능 모니터 생성 | [링크](07_performance_monitoring/01_create_destroy.md) |
| `DRM_V3D_PERFMON_DESTROY` | 0x09 | 성능 모니터 파괴 | [링크](07_performance_monitoring/01_create_destroy.md) |
| `DRM_V3D_PERFMON_GET_VALUES` | 0x0a | 성능 모니터 카운터 값 조회 | [링크](07_performance_monitoring/02_get_values.md) |
| `DRM_V3D_SUBMIT_CPU` | 0x0b | CPU 작업 제출 (타임스탬프, 간접 CSD 등) | [링크](05_submission_cpu.md) |
| `DRM_V3D_PERFMON_GET_COUNTER` | 0x0c | 성능 카운터 정보 조회 | [링크](07_performance_monitoring/02_get_values.md) |
| `DRM_V3D_PERFMON_SET_GLOBAL` | 0x0d | 전역 성능 모니터 설정 | [링크](07_performance_monitoring/02_get_values.md) |
