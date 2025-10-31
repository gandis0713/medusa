#include "v3dv_instance.h"

#include "utils/log.h"
#include "v3dv_entrypoints.h"
#include "vk_alloc.h"
#include "vk_instance.h"

#include <stdalign.h>
#include <string.h>

static const struct vk_instance_extension_table instance_extensions = {
    .KHR_device_group_creation = true,
#ifdef VK_USE_PLATFORM_DISPLAY_KHR
    .KHR_display = true,
    .KHR_get_display_properties2 = true,
    .EXT_direct_mode_display = true,
    .EXT_acquire_drm_display = true,
#endif
    .KHR_external_fence_capabilities = true,
    .KHR_external_memory_capabilities = true,
    .KHR_external_semaphore_capabilities = true,
    .KHR_get_physical_device_properties2 = true,
#ifdef V3DV_USE_WSI_PLATFORM
    .KHR_get_surface_capabilities2 = true,
    .KHR_surface = true,
    .KHR_surface_protected_capabilities = true,
    .EXT_surface_maintenance1 = true,
    .EXT_swapchain_colorspace = true,
#endif
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    .KHR_wayland_surface = true,
#endif
#ifdef VK_USE_PLATFORM_XCB_KHR
    .KHR_xcb_surface = true,
#endif
#ifdef VK_USE_PLATFORM_XLIB_KHR
    .KHR_xlib_surface = true,
#endif
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
    .EXT_acquire_xlib_display = true,
#endif
#ifndef VK_USE_PLATFORM_WIN32_KHR
    .EXT_headless_surface = true,
#endif
    .EXT_debug_report = true,
    .EXT_debug_utils = true,
};

VKAPI_ATTR VkResult VKAPI_CALL v3dv_CreateInstance(const VkInstanceCreateInfo* pCreateInfo,
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

    struct v3dv_instance* instance = vk_alloc(
        pAllocator,
        sizeof(struct v3dv_instance),
        alignof(struct v3dv_instance),
        VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE);

    struct vk_instance_dispatch_table dispatch_table;
    vk_instance_dispatch_table_from_entrypoints(
        &dispatch_table, &v3dv_instance_entrypoints, true);

    vk_instance_init(
        &instance->vk,
        &instance_extensions,
        &dispatch_table,
        pCreateInfo,
        pAllocator);

    // TODO: check for casting validity
    *pInstance = (VkInstance)instance;

    return VK_SUCCESS;
}

VKAPI_ATTR void VKAPI_CALL v3dv_DestroyInstance(VkInstance _instance,
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