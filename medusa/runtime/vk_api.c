#include "utils/log.h"
#include "vk_instance.h"
#include <vulkan/vulkan.h>

#include <assert.h>
#include <string.h>

/* Internal implementation functions */
static VKAPI_ATTR VkResult VKAPI_CALL medusa_CreateInstance(
    const VkInstanceCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkInstance* pInstance)
{
    LOG_INFO("vkCreateInstance called (Medusa ICD)");

    if (!pCreateInfo)
    {
        LOG_ERROR("pCreateInfo is null");
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    if (!pInstance)
    {
        LOG_ERROR("pInstance is null");
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    /* Create the instance - vk_instance* IS VkInstance */
    vk_instance* instance = vk_instance_create(pCreateInfo);
    if (!instance)
    {
        LOG_ERROR("Failed to create instance");
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    /* Convert to VkInstance handle */
    *pInstance = vk_instance_as_handle(instance);
    LOG_INFO("vkCreateInstance succeeded, handle: %p", (void*)*pInstance);
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL medusa_DestroyInstance(
    VkInstance handle,
    const VkAllocationCallbacks* pAllocator)
{
    LOG_INFO("vkDestroyInstance called (Medusa ICD)");

    if (!handle)
    {
        LOG_WARN("vkDestroyInstance called with null instance");
        return;
    }

    /* Convert VkInstance handle back to vk_instance* */
    vk_instance* instance = vk_instance_from_handle(handle);
    vk_instance_destroy(instance);
    LOG_INFO("Instance destroyed successfully");
}

static VKAPI_ATTR VkResult VKAPI_CALL medusa_EnumerateInstanceExtensionProperties(
    const char* pLayerName,
    uint32_t* pPropertyCount,
    VkExtensionProperties* pProperties)
{
    LOG_DEBUG("vkEnumerateInstanceExtensionProperties called");

    /* We don't support layer-specific extensions */
    if (pLayerName != NULL)
    {
        return VK_ERROR_LAYER_NOT_PRESENT;
    }

    /* Return 0 extensions for now (can add later) */
    if (pProperties == NULL)
    {
        *pPropertyCount = 0;
        return VK_SUCCESS;
    }

    *pPropertyCount = 0;
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL medusa_EnumerateInstanceLayerProperties(
    uint32_t* pPropertyCount,
    VkLayerProperties* pProperties)
{
    LOG_DEBUG("vkEnumerateInstanceLayerProperties called");

    /* We don't provide any layers */
    if (pProperties == NULL)
    {
        *pPropertyCount = 0;
        return VK_SUCCESS;
    }

    *pPropertyCount = 0;
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL medusa_EnumerateInstanceVersion(
    uint32_t* pApiVersion)
{
    LOG_DEBUG("vkEnumerateInstanceVersion called");

    if (!pApiVersion)
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    /* We support Vulkan 1.0 */
    *pApiVersion = VK_API_VERSION_1_0;
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL medusa_EnumeratePhysicalDevices(
    VkInstance instance,
    uint32_t* pPhysicalDeviceCount,
    VkPhysicalDevice* pPhysicalDevices)
{
    LOG_DEBUG("vkEnumeratePhysicalDevices called");

    if (!pPhysicalDeviceCount)
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    /* TODO: Implement physical device enumeration */
    /* For now, return 0 devices */
    if (pPhysicalDevices == NULL)
    {
        *pPhysicalDeviceCount = 0;
        return VK_SUCCESS;
    }

    *pPhysicalDeviceCount = 0;
    return VK_SUCCESS;
}

/* Physical device stub functions - minimal implementation for ICD validation */
static VKAPI_ATTR void VKAPI_CALL medusa_GetPhysicalDeviceFeatures(
    VkPhysicalDevice physicalDevice,
    VkPhysicalDeviceFeatures* pFeatures)
{
    LOG_DEBUG("vkGetPhysicalDeviceFeatures called (stub)");
    if (pFeatures)
    {
        memset(pFeatures, 0, sizeof(VkPhysicalDeviceFeatures));
    }
}

static VKAPI_ATTR void VKAPI_CALL medusa_GetPhysicalDeviceProperties(
    VkPhysicalDevice physicalDevice,
    VkPhysicalDeviceProperties* pProperties)
{
    LOG_DEBUG("vkGetPhysicalDeviceProperties called (stub)");
    if (pProperties)
    {
        memset(pProperties, 0, sizeof(VkPhysicalDeviceProperties));
    }
}

static VKAPI_ATTR void VKAPI_CALL medusa_GetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice physicalDevice,
    uint32_t* pQueueFamilyPropertyCount,
    VkQueueFamilyProperties* pQueueFamilyProperties)
{
    LOG_DEBUG("vkGetPhysicalDeviceQueueFamilyProperties called (stub)");
    if (pQueueFamilyPropertyCount)
    {
        if (pQueueFamilyProperties == NULL)
        {
            *pQueueFamilyPropertyCount = 0;
        }
        else
        {
            *pQueueFamilyPropertyCount = 0;
        }
    }
}

static VKAPI_ATTR void VKAPI_CALL medusa_GetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice physicalDevice,
    VkPhysicalDeviceMemoryProperties* pMemoryProperties)
{
    LOG_DEBUG("vkGetPhysicalDeviceMemoryProperties called (stub)");
    if (pMemoryProperties)
    {
        memset(pMemoryProperties, 0, sizeof(VkPhysicalDeviceMemoryProperties));
    }
}

static VKAPI_ATTR void VKAPI_CALL medusa_GetPhysicalDeviceFormatProperties(
    VkPhysicalDevice physicalDevice,
    VkFormat format,
    VkFormatProperties* pFormatProperties)
{
    LOG_DEBUG("vkGetPhysicalDeviceFormatProperties called (stub)");
    if (pFormatProperties)
    {
        memset(pFormatProperties, 0, sizeof(VkFormatProperties));
    }
}

static VKAPI_ATTR VkResult VKAPI_CALL medusa_GetPhysicalDeviceImageFormatProperties(
    VkPhysicalDevice physicalDevice,
    VkFormat format,
    VkImageType type,
    VkImageTiling tiling,
    VkImageUsageFlags usage,
    VkImageCreateFlags flags,
    VkImageFormatProperties* pImageFormatProperties)
{
    LOG_DEBUG("vkGetPhysicalDeviceImageFormatProperties called (stub)");
    if (pImageFormatProperties)
    {
        memset(pImageFormatProperties, 0, sizeof(VkImageFormatProperties));
    }
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL medusa_EnumerateDeviceExtensionProperties(
    VkPhysicalDevice physicalDevice,
    const char* pLayerName,
    uint32_t* pPropertyCount,
    VkExtensionProperties* pProperties)
{
    LOG_DEBUG("vkEnumerateDeviceExtensionProperties called (stub)");
    if (pLayerName != NULL)
    {
        return VK_ERROR_LAYER_NOT_PRESENT;
    }
    if (pPropertyCount)
    {
        if (pProperties == NULL)
        {
            *pPropertyCount = 0;
        }
        else
        {
            *pPropertyCount = 0;
        }
    }
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL medusa_EnumerateDeviceLayerProperties(
    VkPhysicalDevice physicalDevice,
    uint32_t* pPropertyCount,
    VkLayerProperties* pProperties)
{
    LOG_DEBUG("vkEnumerateDeviceLayerProperties called (stub)");
    if (pPropertyCount)
    {
        if (pProperties == NULL)
        {
            *pPropertyCount = 0;
        }
        else
        {
            *pPropertyCount = 0;
        }
    }
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL medusa_GetPhysicalDeviceSparseImageFormatProperties(
    VkPhysicalDevice physicalDevice,
    VkFormat format,
    VkImageType type,
    VkSampleCountFlagBits samples,
    VkImageUsageFlags usage,
    VkImageTiling tiling,
    uint32_t* pPropertyCount,
    VkSparseImageFormatProperties* pProperties)
{
    LOG_DEBUG("vkGetPhysicalDeviceSparseImageFormatProperties called (stub)");
    if (pPropertyCount)
    {
        if (pProperties == NULL)
        {
            *pPropertyCount = 0;
        }
        else
        {
            *pPropertyCount = 0;
        }
    }
}

static VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL medusa_GetDeviceProcAddr(
    VkDevice device,
    const char* pName)
{
    LOG_DEBUG("vkGetDeviceProcAddr called for: %s", pName ? pName : "NULL");

    /* TODO: Implement device-level function lookup */
    /* For now, return NULL for all device functions */
    return NULL;
}

static VKAPI_ATTR VkResult VKAPI_CALL medusa_CreateDevice(
    VkPhysicalDevice physicalDevice,
    const VkDeviceCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDevice* pDevice)
{
    LOG_DEBUG("vkCreateDevice called (stub)");

    /* TODO: Implement device creation */
    /* For now, return error since we don't have any physical devices */
    return VK_ERROR_INITIALIZATION_FAILED;
}

static VKAPI_ATTR void VKAPI_CALL medusa_DestroyDevice(
    VkDevice device,
    const VkAllocationCallbacks* pAllocator)
{
    LOG_DEBUG("vkDestroyDevice called (stub)");

    /* TODO: Implement device destruction */
}

/* ICD entry point - this is the only exported symbol */
#ifdef __cplusplus
extern "C"
{
#endif

    VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vk_icdGetInstanceProcAddr(
        VkInstance instance,
        const char* pName)
    {
        if (!pName)
        {
            return NULL;
        }

        LOG_DEBUG("vk_icdGetInstanceProcAddr: %s", pName);

        /* Global functions (no instance required) */
        if (strcmp(pName, "vkCreateInstance") == 0)
        {
            return (PFN_vkVoidFunction)medusa_CreateInstance;
        }
        if (strcmp(pName, "vkEnumerateInstanceExtensionProperties") == 0)
        {
            return (PFN_vkVoidFunction)medusa_EnumerateInstanceExtensionProperties;
        }
        if (strcmp(pName, "vkEnumerateInstanceLayerProperties") == 0)
        {
            return (PFN_vkVoidFunction)medusa_EnumerateInstanceLayerProperties;
        }
        if (strcmp(pName, "vkEnumerateInstanceVersion") == 0)
        {
            return (PFN_vkVoidFunction)medusa_EnumerateInstanceVersion;
        }
        if (strcmp(pName, "vkGetInstanceProcAddr") == 0)
        {
            return (PFN_vkVoidFunction)vk_icdGetInstanceProcAddr;
        }

        /* Instance-level functions */
        if (instance)
        {
            if (strcmp(pName, "vkDestroyInstance") == 0)
            {
                return (PFN_vkVoidFunction)medusa_DestroyInstance;
            }
            if (strcmp(pName, "vkGetInstanceProcAddr") == 0)
            {
                return (PFN_vkVoidFunction)vk_icdGetInstanceProcAddr;
            }
            if (strcmp(pName, "vkEnumeratePhysicalDevices") == 0)
            {
                return (PFN_vkVoidFunction)medusa_EnumeratePhysicalDevices;
            }
            if (strcmp(pName, "vkGetPhysicalDeviceFeatures") == 0)
            {
                return (PFN_vkVoidFunction)medusa_GetPhysicalDeviceFeatures;
            }
            if (strcmp(pName, "vkGetPhysicalDeviceProperties") == 0)
            {
                return (PFN_vkVoidFunction)medusa_GetPhysicalDeviceProperties;
            }
            if (strcmp(pName, "vkGetPhysicalDeviceQueueFamilyProperties") == 0)
            {
                return (PFN_vkVoidFunction)medusa_GetPhysicalDeviceQueueFamilyProperties;
            }
            if (strcmp(pName, "vkGetPhysicalDeviceMemoryProperties") == 0)
            {
                return (PFN_vkVoidFunction)medusa_GetPhysicalDeviceMemoryProperties;
            }
            if (strcmp(pName, "vkGetPhysicalDeviceFormatProperties") == 0)
            {
                return (PFN_vkVoidFunction)medusa_GetPhysicalDeviceFormatProperties;
            }
            if (strcmp(pName, "vkGetPhysicalDeviceImageFormatProperties") == 0)
            {
                return (PFN_vkVoidFunction)medusa_GetPhysicalDeviceImageFormatProperties;
            }
            if (strcmp(pName, "vkEnumerateDeviceExtensionProperties") == 0)
            {
                return (PFN_vkVoidFunction)medusa_EnumerateDeviceExtensionProperties;
            }
            if (strcmp(pName, "vkEnumerateDeviceLayerProperties") == 0)
            {
                return (PFN_vkVoidFunction)medusa_EnumerateDeviceLayerProperties;
            }
            if (strcmp(pName, "vkGetPhysicalDeviceSparseImageFormatProperties") == 0)
            {
                return (PFN_vkVoidFunction)medusa_GetPhysicalDeviceSparseImageFormatProperties;
            }
            if (strcmp(pName, "vkGetDeviceProcAddr") == 0)
            {
                return (PFN_vkVoidFunction)medusa_GetDeviceProcAddr;
            }
            if (strcmp(pName, "vkCreateDevice") == 0)
            {
                return (PFN_vkVoidFunction)medusa_CreateDevice;
            }
            if (strcmp(pName, "vkDestroyDevice") == 0)
            {
                return (PFN_vkVoidFunction)medusa_DestroyDevice;
            }
            /* Add more instance functions as needed */
        }

        LOG_WARN("Unknown function requested: %s", pName);
        return NULL;
    }

    /* ICD negotiation version */
    VKAPI_ATTR VkResult VKAPI_CALL vk_icdNegotiateLoaderICDInterfaceVersion(
        uint32_t* pSupportedVersion)
    {
        if (!pSupportedVersion)
        {
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        /* We support ICD interface version 5 */
        *pSupportedVersion = 5;
        LOG_INFO("ICD interface version negotiated: %d", *pSupportedVersion);
        return VK_SUCCESS;
    }

#ifdef __cplusplus
}
#endif
