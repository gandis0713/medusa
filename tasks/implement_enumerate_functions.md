# vkEnumerateInstanceExtensionProperties 및 관련 함수 구현

## 현재 상황

ICD가 Vulkan loader에 의해 로드되고 있지만, 필수 함수들이 구현되지 않아 검증 단계에서 실패합니다.

### 현재 에러

```
ERROR: loader_scanned_icd_add: Could not get 'vkEnumerateInstanceExtensionProperties'
via 'vk_icdGetInstanceProcAddr' for ICD /app/build/arm64-rpi5-ninja/release/medusa/./libmedusa_icd.so
```

### 작동하는 것

1. ✅ ICD 로드: `vk_icdNegotiateLoaderICDInterfaceVersion` 성공
2. ✅ ICD manifest 파싱: JSON 파일 읽기 성공
3. ✅ 라이브러리 로드: `libmedusa_icd.so` dlopen 성공

### 작동하지 않는 것

1. ❌ `vkEnumerateInstanceExtensionProperties`: nullptr 반환
2. ❌ `vkEnumerateInstanceLayerProperties`: nullptr 반환
3. ❌ ICD 검증 실패로 `vkCreateInstance` 호출 안 됨

## 필수 구현 함수

Vulkan loader가 ICD를 검증하기 위해 요구하는 함수들:

### 1. vkEnumerateInstanceExtensionProperties (필수)

```cpp
static VKAPI_ATTR VkResult VKAPI_CALL medusa_EnumerateInstanceExtensionProperties(
    const char* pLayerName,
    uint32_t* pPropertyCount,
    VkExtensionProperties* pProperties)
```

**목적**: ICD가 지원하는 인스턴스 레벨 확장 열거

**최소 구현**:
```cpp
{
    LOG_DEBUG("vkEnumerateInstanceExtensionProperties called");

    // We don't support any extensions yet
    if (pLayerName != nullptr) {
        // Layer-specific extensions not supported
        return VK_ERROR_LAYER_NOT_PRESENT;
    }

    // Return 0 extensions for now (can add later)
    if (pProperties == nullptr) {
        *pPropertyCount = 0;
        return VK_SUCCESS;
    }

    *pPropertyCount = 0;
    return VK_SUCCESS;
}
```

### 2. vkEnumerateInstanceLayerProperties (선택적, 하지만 권장)

```cpp
static VKAPI_ATTR VkResult VKAPI_CALL medusa_EnumerateInstanceLayerProperties(
    uint32_t* pPropertyCount,
    VkLayerProperties* pProperties)
```

**목적**: ICD가 제공하는 레이어 열거

**최소 구현**:
```cpp
{
    LOG_DEBUG("vkEnumerateInstanceLayerProperties called");

    // We don't provide any layers
    if (pProperties == nullptr) {
        *pPropertyCount = 0;
        return VK_SUCCESS;
    }

    *pPropertyCount = 0;
    return VK_SUCCESS;
}
```

### 3. vk_icdGetInstanceProcAddr 업데이트

vk_api.cpp의 `vk_icdGetInstanceProcAddr`에서 이 함수들을 반환하도록 수정:

```cpp
// Global functions (no instance required)
if (strcmp(pName, "vkCreateInstance") == 0) {
    return reinterpret_cast<PFN_vkVoidFunction>(medusa_CreateInstance);
}
if (strcmp(pName, "vkEnumerateInstanceExtensionProperties") == 0) {
    return reinterpret_cast<PFN_vkVoidFunction>(medusa_EnumerateInstanceExtensionProperties);
}
if (strcmp(pName, "vkEnumerateInstanceLayerProperties") == 0) {
    return reinterpret_cast<PFN_vkVoidFunction>(medusa_EnumerateInstanceLayerProperties);
}
```

## 구현 위치

**파일**: `medusa/runtime/vk_api.cpp`

**위치**:
1. `medusa_DestroyInstance` 함수 다음에 새 함수들 추가
2. `vk_icdGetInstanceProcAddr`에서 nullptr 대신 함수 포인터 반환

## 향후 확장 (선택적)

나중에 실제 확장을 지원할 때:

```cpp
static const VkExtensionProperties supported_extensions[] = {
    {VK_KHR_SURFACE_EXTENSION_NAME, VK_KHR_SURFACE_SPEC_VERSION},
    {VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME, VK_KHR_WAYLAND_SURFACE_SPEC_VERSION},
    // ... 더 추가
};

static VKAPI_ATTR VkResult VKAPI_CALL medusa_EnumerateInstanceExtensionProperties(
    const char* pLayerName,
    uint32_t* pPropertyCount,
    VkExtensionProperties* pProperties)
{
    if (pLayerName != nullptr) {
        return VK_ERROR_LAYER_NOT_PRESENT;
    }

    const uint32_t count = sizeof(supported_extensions) / sizeof(supported_extensions[0]);

    if (pProperties == nullptr) {
        *pPropertyCount = count;
        return VK_SUCCESS;
    }

    uint32_t copy_count = (*pPropertyCount < count) ? *pPropertyCount : count;
    memcpy(pProperties, supported_extensions, copy_count * sizeof(VkExtensionProperties));
    *pPropertyCount = copy_count;

    return (copy_count < count) ? VK_INCOMPLETE : VK_SUCCESS;
}
```

## 테스트 방법

### 1. 빌드
```bash
./scripts/build/build-rpi5.sh
```

### 2. 실행
```bash
./scripts/run/run-rpi5.sh -s
```

### 3. 기대 결과

**성공 시 로그**:
```
[medusa] [info] ICD interface version negotiated: 5
[medusa] [debug] vkEnumerateInstanceExtensionProperties called
[medusa] [info] vkCreateInstance called (Medusa ICD)    ← 이제 호출되어야 함!
[medusa] [info] Creating Vulkan instance...
[medusa] [info] Application: Medusa Sample, Version: 1.0.0
[medusa] [info] Vulkan instance created successfully
[MedusaSample] [info] Vulkan instance created successfully!
```

### 4. 디버그 로그 확인

Vulkan loader 로그에서 에러가 사라져야 함:
```
INFO: Found ICD manifest file /app/build/.../medusa_icd.json
DEBUG: Searching for ICD drivers named ./libmedusa_icd.so
(에러 없이 계속 진행)
```

## 우선순위

**High**: ICD가 작동하려면 반드시 필요한 함수들

## 예상 소요 시간

- 최소 구현: 10분
- 테스트 및 검증: 5분

## 참고

- Vulkan Spec: [vkEnumerateInstanceExtensionProperties](https://registry.khronos.org/vulkan/specs/1.3/html/vkspec.html#vkEnumerateInstanceExtensionProperties)
- ICD 인터페이스: 이 함수들은 `instance` 파라미터 없이 호출되므로 global functions
- 현재 최소 구현으로 0개의 확장을 반환하면 충분함
