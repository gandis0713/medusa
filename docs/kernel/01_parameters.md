# 파라미터 조회 (Parameters)

`DRM_V3D_GET_PARAM` IOCTL을 사용하여 V3D 드라이버 및 하드웨어의 기능을 조회할 수 있습니다.

## IOCTL 정보

- **매크로**: `DRM_IOCTL_V3D_GET_PARAM`
- **명령 코드**: `DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_GET_PARAM, struct drm_v3d_get_param)`

## 데이터 구조체

### `struct drm_v3d_get_param`

파라미터 조회를 위한 구조체입니다.

## 제약 사항 (Constraints)

- **`pad`**: 반드시 0으로 초기화되어야 합니다.
- **`param`**: 정의되지 않은 파라미터 ID를 사용하면 `EINVAL` 에러가 발생합니다.

## 사용 케이스 (Use Cases)

이 IOCTL은 다음과 같은 상황에서 사용됩니다.

### 1. 하드웨어/드라이버 기능 지원 여부 확인
특정 기능이 커널 드라이버나 하드웨어에서 지원되는지 런타임에 확인합니다.
- `DRM_V3D_PARAM_SUPPORTS_CSD`: CSD (Compute Shader Dispatch) 지원 여부 확인.
- `DRM_V3D_PARAM_SUPPORTS_TFU`: TFU (Texture Formatting Unit) 지원 여부 확인.
- `DRM_V3D_PARAM_SUPPORTS_CACHE_FLUSH`: 명시적 캐시 플러시 플래그 지원 여부 확인.
- `DRM_V3D_PARAM_SUPPORTS_PERFMON`: 성능 모니터링 기능 지원 여부 확인.
- `DRM_V3D_PARAM_SUPPORTS_MULTISYNC_EXT`: 동기화 확장을 통한 복잡한 의존성 관리 지원 여부 확인. (Vulkan 등에서 필수적)
- `DRM_V3D_PARAM_SUPPORTS_CPU_QUEUE`: CPU 타임스탬프 쿼리, 간접 CSD 등을 위한 CPU 큐 지원 여부 확인.

### 2. 하드웨어 정보 및 식별
디바이스별 리비전이나 설정을 확인하여 드라이버 동작을 조정합니다.
- `DRM_V3D_PARAM_V3D_CORE0_IDENT0`: V3D 코어 버전 확인 (예: 4.2 vs 7.1). 버전에 따라 CL 패킷 포맷 등이 달라짐.
- `DRM_V3D_PARAM_V3D_UIFCFG`: Uniform Image Format 설정값 확인.

### 3. 리소스 제한 확인
하드웨어의 제한 사항을 확인하여 리소스 할당 시 참고합니다.
- `DRM_V3D_PARAM_MAX_PERF_COUNTERS`: 한 번에 활성화할 수 있는 최대 성능 카운터 수 확인.

### 4. GPU 상태 모니터링 (리셋 감지)
GPU 행(Hang) 발생으로 인한 리셋 여부를 감지하여 복구 로직을 수행합니다.
- `DRM_V3D_PARAM_GLOBAL_RESET_COUNTER`: 전체 GPU 리셋 횟수 확인.
- `DRM_V3D_PARAM_CONTEXT_RESET_COUNTER`: 현재 컨텍스트와 관련된 리셋 횟수 확인. (Robustness 지원 시 사용)

## 파라미터 목록 (`enum drm_v3d_param`)

`param` 필드에 사용할 수 있는 값들은 다음과 같습니다.

| 파라미터 이름 | 설명 |
| :--- | :--- |
| `DRM_V3D_PARAM_V3D_UIFCFG` | V3D UIF(Uniform Image Format) 설정 레지스터 값. |
| `DRM_V3D_PARAM_V3D_HUB_IDENT1` | V3D Hub Identification 1 레지스터 값. 리비전 정보 등을 포함. |
| `DRM_V3D_PARAM_V3D_HUB_IDENT2` | V3D Hub Identification 2 레지스터 값. |
| `DRM_V3D_PARAM_V3D_HUB_IDENT3` | V3D Hub Identification 3 레지스터 값. |
| `DRM_V3D_PARAM_V3D_CORE0_IDENT0` | V3D Core 0 Identification 0 레지스터 값. V3D 아키텍처 버전(예: 4.2, 7.1) 확인에 사용. |
| `DRM_V3D_PARAM_V3D_CORE0_IDENT1` | V3D Core 0 Identification 1 레지스터 값. VPM 메모리 크기 등 포함. |
| `DRM_V3D_PARAM_V3D_CORE0_IDENT2` | V3D Core 0 Identification 2 레지스터 값. |
| `DRM_V3D_PARAM_SUPPORTS_TFU` | TFU(Texture Formatting Unit) 작업 제출 지원 여부. (1: 지원, 0: 미지원) |
| `DRM_V3D_PARAM_SUPPORTS_CSD` | CSD(Compute Shader Dispatch) 작업 제출 지원 여부. (1: 지원, 0: 미지원) |
| `DRM_V3D_PARAM_SUPPORTS_CACHE_FLUSH` | 캐시 플러시 플래그(`DRM_V3D_SUBMIT_CL_FLUSH_CACHE`) 지원 여부. |
| `DRM_V3D_PARAM_SUPPORTS_PERFMON` | 성능 모니터링(PerfMon) 기능 지원 여부. |
| `DRM_V3D_PARAM_SUPPORTS_MULTISYNC_EXT` | 멀티 싱크(`DRM_V3D_EXT_ID_MULTI_SYNC`) 확장 지원 여부. |
| `DRM_V3D_PARAM_SUPPORTS_CPU_QUEUE` | CPU 큐(`DRM_V3D_SUBMIT_CPU`) 지원 여부. |
| `DRM_V3D_PARAM_MAX_PERF_COUNTERS` | 하나의 PerfMon에서 동시에 추적 가능한 최대 성능 카운터 수. |
| `DRM_V3D_PARAM_SUPPORTS_SUPER_PAGES` | 슈퍼 페이지(Large Pages) 지원 여부. |
| `DRM_V3D_PARAM_GLOBAL_RESET_COUNTER` | 전역 리셋 카운터. GPU가 리셋된 횟수를 반환. |
| `DRM_V3D_PARAM_CONTEXT_RESET_COUNTER` | 컨텍스트 리셋 카운터. 현재 컨텍스트가 리셋된 횟수를 반환. |
