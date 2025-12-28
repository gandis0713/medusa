# PerfMon 생성 및 파괴

V3D 하드웨어의 성능 카운터를 사용하여 렌더링 성능을 분석할 수 있습니다.

### `DRM_V3D_PERFMON_CREATE`

새로운 성능 모니터(PerfMon)를 생성하고, 추적할 카운터들을 지정합니다.

- **구조체**: `struct drm_v3d_perfmon_create`

```c
struct drm_v3d_perfmon_create {
    __u32 id;        // 생성된 PerfMon ID (출력)
    __u32 ncounters; // 요청하는 카운터 개수 (입력)
    __u8 counters[DRM_V3D_MAX_PERF_COUNTERS]; // 카운터 ID 배열 (입력)
};
```
- `DRM_V3D_MAX_PERF_COUNTERS`: 32

### `DRM_V3D_PERFMON_DESTROY`

사용이 끝난 PerfMon을 제거합니다.

- **구조체**: `struct drm_v3d_perfmon_destroy`

```c
struct drm_v3d_perfmon_destroy {
    __u32 id; // 파괴할 PerfMon ID
};
```
