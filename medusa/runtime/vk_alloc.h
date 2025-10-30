
#ifndef VK_ALLOC_H
#define VK_ALLOC_H

#include <vulkan/vulkan_core.h>

#ifdef __cplusplus
extern "C"
{
#endif

    const VkAllocationCallbacks* vk_default_allocator(void);

#ifdef __cplusplus
}
#endif

#endif
