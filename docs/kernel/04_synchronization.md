# 동기화 (Synchronization)

GPU 작업 간의 순서 제어 및 CPU-GPU 간의 동기화는 그래픽스 프로그래밍에서 매우 중요합니다. 이 챕터에서는 V3D DRM이 제공하는 동기화 메커니즘을 설명합니다.

## 세부 항목

### 1. [BO 대기 (Wait BO)](./04_synchronization/01_wait_bo.md)
`DRM_V3D_WAIT_BO` IOCTL을 사용하여 특정 버퍼 객체(BO)와 관련된 작업이 완료될 때까지 CPU가 대기합니다. 가장 기본적인 동기화 방식입니다.

### 2. [멀티 싱크 (Multi-Sync Extension)](./04_synchronization/02_multi_sync.md)
`DRM_V3D_EXT_ID_MULTI_SYNC` 확장을 사용하여 여러 큐(Render, TFU, CSD) 간의 복잡한 의존성을 처리하거나, Vulkan의 세마포어(Semaphore) 동작을 구현합니다.
