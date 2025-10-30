#include "v3dv_instance.h"

#include "runtime/vk_alloc.h"
#include "runtime/vk_instance.h"
#include "utils/log.h"

#include <stdalign.h>
#include <string.h>

VkResult v3dv_CreateInstance(const VkInstanceCreateInfo* pCreateInfo,
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

    if (pCreateInfo->sType != VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO)
    {
        LOG_ERROR("Invalid sType in VkInstanceCreateInfo");
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    if (!pAllocator)
        pAllocator = vk_default_allocator();

    struct vk_instance* instance = vk_alloc(
        pAllocator,
        sizeof(vk_instance),
        alignof(vk_instance),
        VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE);

    vk_instance_init(
        instance,
        NULL, // supported_extensions
        NULL, // dispatch_table
        pCreateInfo,
        pAllocator);

    // TODO: check for casting validity
    *pInstance = (VkInstance)instance;

    return VK_SUCCESS;
}

void v3dv_DestroyInstance(VkInstance _instance,
                          const VkAllocationCallbacks* pAllocator)
{
    LOG_INFO("vkDestroyInstance called (Medusa ICD)");

    if (!_instance)
    {
        LOG_WARN("vkDestroyInstance called with null instance");
        return;
    }

    struct vk_instance* instance = (struct vk_instance*)_instance;

    vk_instance_finish(instance);
    vk_free(&instance->alloc, instance);
    LOG_INFO("Instance destroyed successfully");
}