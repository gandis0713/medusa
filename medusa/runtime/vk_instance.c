#include "vk_instance.h"
#include "utils/log.h"

#include <string.h>

VkResult vk_instance_init(struct vk_instance* instance,
                          const struct vk_instance_extension_table* supported_extensions,
                          const struct vk_instance_dispatch_table* dispatch_table,
                          const VkInstanceCreateInfo* pCreateInfo,
                          const VkAllocationCallbacks* alloc)
{
    memset(instance, 0, sizeof(*instance));
    vk_object_base_instance_init(instance, &instance->base, VK_OBJECT_TYPE_INSTANCE);
    instance->alloc = *alloc;

    return VK_SUCCESS;
}

void vk_instance_finish(struct vk_instance* instance)
{
}
