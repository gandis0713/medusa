# 성능 모니터링 (Performance Monitoring)

애플리케이션의 성능을 분석하고 최적화하기 위해 V3D 하드웨어는 다양한 성능 카운터를 제공합니다. 이 챕터에서는 PerfMon(Performance Monitor) 객체를 생성하고 제어하는 방법을 설명합니다.

## 세부 항목

### 1. [생성 및 파괴 (Create & Destroy)](./05_performance_monitoring/01_create_destroy.md)
`DRM_V3D_PERFMON_CREATE` 및 `DRM_V3D_PERFMON_DESTROY` IOCTL을 사용하여 성능 모니터를 생성하고 제거합니다. 생성 시 추적할 카운터들을 지정할 수 있습니다.

### 2. [값 조회 및 설정 (Get Values & Global Set)](./05_performance_monitoring/02_get_values.md)
`DRM_V3D_PERFMON_GET_VALUES`를 통해 수집된 카운터 값을 읽어오거나, `DRM_V3D_PERFMON_SET_GLOBAL`을 통해 전역 모니터링을 설정합니다. 또한 `DRM_V3D_PERFMON_GET_COUNTER`로 각 카운터의 상세 정보를 확인할 수 있습니다.
