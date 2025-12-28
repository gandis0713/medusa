# 작업 제출 (Job Submission)

V3D 엔진에 작업을 제출하는 다양한 방법을 설명합니다. 렌더링, 텍스처 처리, 컴퓨트 셰이더, 그리고 CPU 확장을 포함합니다.

## 세부 항목

### 1. [렌더링 제출 (Render CL)](./03_job_submission/01_render_cl.md)
`DRM_V3D_SUBMIT_CL` IOCTL을 사용하여 3D 렌더링 작업을 제출합니다. Binning Command List(BCL)와 Render Command List(RCL)를 포함합니다.

### 2. [TFU 제출 (Texture Formatting)](./03_job_submission/02_tfu.md)
`DRM_V3D_SUBMIT_TFU` IOCTL을 사용하여 텍스처 포맷 변환 및 밉맵 생성 작업을 하드웨어 TFU 유닛에 제출합니다.

### 3. [CSD 제출 (Compute Shader)](./03_job_submission/03_csd.md)
`DRM_V3D_SUBMIT_CSD` IOCTL을 사용하여 범용 컴퓨트 셰이더 작업을 제출합니다.

### 4. [CPU 확장 제출 (CPU Extensions)](./03_job_submission/04_cpu_extensions.md)
`DRM_V3D_SUBMIT_CPU` IOCTL을 사용하여 타임스탬프 쿼리, 성능 쿼리, 간접 CSD 등 CPU가 관여하거나 확장된 기능을 수행합니다.
