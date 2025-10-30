#ifndef V3DV_INSTANCE_H
#define V3DV_INSTANCE_H

#include "runtime/vk_instance.h"

#include <vulkan/vulkan_core.h>

struct v3dv_instance
{
    struct vk_instance vk;
};

VkResult v3dv_CreateInstance(const VkInstanceCreateInfo* pCreateInfo,
                             const VkAllocationCallbacks* pAllocator,
                             VkInstance* pInstance);

void v3dv_DestroyInstance(VkInstance _instance,
                          const VkAllocationCallbacks* pAllocator);

#endif // V3DV_INSTANCE_H