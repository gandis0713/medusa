# 값 조회 및 기타 설정

### `DRM_V3D_PERFMON_GET_VALUES`

PerfMon이 추적한 카운터들의 누적 값을 조회합니다. 암묵적인 동기화는 수행되지 않으므로, 해당 PerfMon을 사용한 작업이 완료되었음을 보장해야 합니다.

- **구조체**: `struct drm_v3d_perfmon_get_values`

```c
struct drm_v3d_perfmon_get_values {
    __u32 id;         // PerfMon ID
    __u32 pad;
    __u64 values_ptr; // 값을 저장할 __u64 배열 포인터. (ncounters 개수만큼)
};
```

### 제약 사항 (Constraints)

- **`ncounters`**: `DRM_V3D_PARAM_MAX_PERF_COUNTERS`(32)를 초과할 수 없습니다.
- **`counters`**: 유효한 성능 카운터 ID여야 합니다. `DRM_V3D_PERFMON_GET_COUNTER`로 확인 가능합니다.
- **동기화**: `DRM_V3D_PERFMON_GET_VALUES`는 암묵적으로 GPU 작업을 대기하지 않습니다. 사용자는 해당 PerfMon이 연결된 작업이 완료되었음을 (예: `WAIT_BO`, fence 등) 확인한 후 호출해야 합니다.

### 사용 케이스 (Use Cases)

- **성능 프로파일링**: 프레임당 GPU 사이클, 텍스처 캐시 미스율, 메모리 대역폭 사용량 등을 측정하여 최적화 포인트 식별.
- **실시간 모니터링**: 오버레이 등에 현재 GPU 부하 상태 표시.
- **오클루전 쿼리 (Occlusion Query)**: `V3D_PERFCNT_TLB_QUADS_NONZERO_COV` 등의 카운터를 사용하여 렌더링된 픽셀 수(또는 근사치) 측정. (이 경우 PerfMon을 쿼리 풀마다 생성하여 사용)

### 사용 패턴

1. `DRM_V3D_PERFMON_CREATE`로 원하는 카운터들을 포함하는 모니터 생성.
2. `DRM_V3D_SUBMIT_CL` 등의 작업 제출 시 `perfmon_id`에 할당.
3. 작업 완료 대기 (Wait BO/Syncobj).
4. `DRM_V3D_PERFMON_GET_VALUES`로 결과 수집.
5. `DRM_V3D_PERFMON_DESTROY`로 정리.

## 카운터 정보 조회

### `DRM_V3D_PERFMON_GET_COUNTER`

특정 카운터 ID에 대한 이름, 카테고리, 설명을 조회합니다.

- **구조체**: `struct drm_v3d_perfmon_get_counter`

```c
struct drm_v3d_perfmon_get_counter {
    __u8 counter;     // 조회할 카운터 ID
    __u8 name[64];    // 카운터 이름 (출력)
    __u8 category[32];// 카테고리 (출력)
    __u8 description[256]; // 설명 (출력)
    __u8 reserved[7];
};
```

## 전역 설정

### `DRM_V3D_PERFMON_SET_GLOBAL`

모든 작업에 적용될 전역(Global) 성능 모니터를 설정합니다. 전역 PerfMon이 설정되면, 개별 작업에서 정의한 PerfMon은 허용되지 않습니다.

- **구조체**: `struct drm_v3d_perfmon_set_global`

```c
struct drm_v3d_perfmon_set_global {
    __u32 flags; // DRM_V3D_PERFMON_CLEAR_GLOBAL 등을 사용
    __u32 id;    // 설정할 전역 PerfMon ID
};
```

- **플래그**: `DRM_V3D_PERFMON_CLEAR_GLOBAL` (0x0001) - 전역 PerfMon 설정을 해제합니다.
