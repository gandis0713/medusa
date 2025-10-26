#include <vulkan/vulkan.h>
#include "vk_instance.hpp"
#include "utils/log.hpp"

#include <cstring>

using namespace medusa::runtime;

// Internal implementation functions
static VKAPI_ATTR VkResult VKAPI_CALL medusa_CreateInstance(
    const VkInstanceCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkInstance* pInstance)
{
    LOG_INFO("vkCreateInstance called (Medusa ICD)");

    if (!pCreateInfo) {
        LOG_ERROR("pCreateInfo is null");
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    if (!pInstance) {
        LOG_ERROR("pInstance is null");
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    // Create the instance - vk_instance* IS VkInstance
    vk_instance* instance = vk_instance::create(pCreateInfo);
    if (!instance) {
        LOG_ERROR("Failed to create instance");
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    // Convert to VkInstance handle
    *pInstance = instance->as_handle();
    LOG_INFO("vkCreateInstance succeeded, handle: {}", static_cast<void*>(*pInstance));
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL medusa_DestroyInstance(
    VkInstance handle,
    const VkAllocationCallbacks* pAllocator)
{
    LOG_INFO("vkDestroyInstance called (Medusa ICD)");

    if (!handle) {
        LOG_WARN("vkDestroyInstance called with null instance");
        return;
    }

    // Convert VkInstance handle back to vk_instance*
    vk_instance* instance = vk_instance::from_handle(handle);
    vk_instance::destroy(instance);
    LOG_INFO("Instance destroyed successfully");
}

// ICD entry point - this is the only exported symbol
extern "C" {

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vk_icdGetInstanceProcAddr(
    VkInstance instance,
    const char* pName)
{
    if (!pName) {
        return nullptr;
    }

    LOG_DEBUG("vk_icdGetInstanceProcAddr: {}", pName);

    // Global functions (no instance required)
    if (strcmp(pName, "vkCreateInstance") == 0) {
        return reinterpret_cast<PFN_vkVoidFunction>(medusa_CreateInstance);
    }
    if (strcmp(pName, "vkEnumerateInstanceExtensionProperties") == 0) {
        // TODO: Implement
        return nullptr;
    }
    if (strcmp(pName, "vkEnumerateInstanceLayerProperties") == 0) {
        // TODO: Implement
        return nullptr;
    }

    // Instance-level functions
    if (instance) {
        if (strcmp(pName, "vkDestroyInstance") == 0) {
            return reinterpret_cast<PFN_vkVoidFunction>(medusa_DestroyInstance);
        }
        if (strcmp(pName, "vkEnumeratePhysicalDevices") == 0) {
            // TODO: Implement
            return nullptr;
        }
        // Add more instance functions as needed
    }

    LOG_WARN("Unknown function requested: {}", pName);
    return nullptr;
}

// ICD negotiation version
VKAPI_ATTR VkResult VKAPI_CALL vk_icdNegotiateLoaderICDInterfaceVersion(
    uint32_t* pSupportedVersion)
{
    if (!pSupportedVersion) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    // We support ICD interface version 5
    *pSupportedVersion = 5;
    LOG_INFO("ICD interface version negotiated: {}", *pSupportedVersion);
    return VK_SUCCESS;
}

} // extern "C"
