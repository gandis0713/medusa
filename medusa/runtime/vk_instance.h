#pragma once

#include "vk_dispatch_table.h"
#include "vk_extensions.h"
#include "vk_object.h"

#include <vulkan/vulkan_core.h>

#ifdef __cplusplus
extern "C"
{
#endif

    struct vk_app_info
    {
        /** VkApplicationInfo::pApplicationName */
        const char* app_name;

        /** VkApplicationInfo::applicationVersion */
        uint32_t app_version;

        /** VkApplicationInfo::pEngineName */
        const char* engine_name;

        /** VkApplicationInfo::engineVersion */
        uint32_t engine_version;

        /** VkApplicationInfo::apiVersion or `VK_API_VERSION_1_0`
         *
         * If the application does not provide a `pApplicationInfo` or the
         * `apiVersion` field is 0, this is set to `VK_API_VERSION_1_0`.
         */
        uint32_t api_version;
    };

    typedef struct vk_instance
    {
        struct vk_object_base base;
        struct vk_app_info app_info;
        VkAllocationCallbacks alloc;

        char** enabled_extensions;
        uint32_t enabled_extensions_count;
        char** enabled_layers;
        uint32_t enabled_layers_count;
    } vk_instance;

    VkResult vk_instance_init(struct vk_instance* instance,
                              const struct vk_instance_extension_table* supported_extensions,
                              const struct vk_instance_dispatch_table* dispatch_table,
                              const VkInstanceCreateInfo* pCreateInfo,
                              const VkAllocationCallbacks* alloc);

    void vk_instance_finish(struct vk_instance* instance);

#ifdef __cplusplus
}
#endif
