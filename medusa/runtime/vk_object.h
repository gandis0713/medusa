#ifndef VK_OBJECT_H
#define VK_OBJECT_H

#include <vulkan/vk_icd.h>
#include <vulkan/vulkan_core.h>

struct vk_object_base
{
    VK_LOADER_DATA icd_loader_data;
    VkObjectType type;
    struct vk_instance* instance;
    struct vk_device* device;
    const char* object_name;
};

/** Initialize a vk_base_object
 *
 * :param device:       |in|  The vk_device this object was created from or NULL
 * :param base:         |out| The vk_object_base to initialize
 * :param obj_type:     |in|  The VkObjectType of the object being initialized
 */
void vk_object_base_device_init(struct vk_device* device,
                                struct vk_object_base* base,
                                VkObjectType obj_type);

/** Initialize a vk_base_object for an instance level object
 *
 * :param instance:     |in|  The vk_instance this object was created from
 * :param base:         |out| The vk_object_base to initialize
 * :param obj_type:     |in|  The VkObjectType of the object being initialized
 */
void vk_object_base_instance_init(struct vk_instance* instance,
                                  struct vk_object_base* base,
                                  VkObjectType obj_type);

#endif // VK_OBJECT_H