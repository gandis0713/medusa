#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <vulkan/vulkan.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Vulkan Instance implementation for Raspberry Pi 5
 *
 * This struct IS the VkInstance. The VkInstance handle returned to
 * the application is simply a pointer to this struct.
 *
 * VkInstance handle = (VkInstance)(vk_instance*)
 */
typedef struct vk_instance
{
    bool valid;
    char app_name[256];
    uint32_t app_version;
    char engine_name[256];
    uint32_t engine_version;
    uint32_t api_version;

    char** enabled_extensions;
    uint32_t enabled_extensions_count;
    char** enabled_layers;
    uint32_t enabled_layers_count;
} vk_instance;

/**
 * @brief Create a Vulkan instance from VkInstanceCreateInfo
 *
 * @param create_info Instance creation parameters
 * @return vk_instance* Pointer to created instance (NULL on failure)
 */
vk_instance* vk_instance_create(const VkInstanceCreateInfo* create_info);

/**
 * @brief Destroy the vk_instance
 */
void vk_instance_destroy(vk_instance* instance);

/**
 * @brief Convert vk_instance* to VkInstance handle
 */
static inline VkInstance vk_instance_as_handle(vk_instance* instance)
{
    return (VkInstance)instance;
}

/**
 * @brief Convert VkInstance handle to vk_instance*
 */
static inline vk_instance* vk_instance_from_handle(VkInstance handle)
{
    return (vk_instance*)handle;
}

/**
 * @brief Check if instance is valid
 */
static inline bool vk_instance_is_valid(const vk_instance* instance)
{
    return instance ? instance->valid : false;
}

#ifdef __cplusplus
}
#endif
