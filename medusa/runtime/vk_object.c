#include "vk_object.h"

void vk_object_base_device_init(struct vk_device* device,
                                struct vk_object_base* base,
                                VkObjectType obj_type)
{
    base->icd_loader_data.loaderMagic = ICD_LOADER_MAGIC;
    base->type = obj_type;
    //    base->client_visible = false;
    base->device = device;
    base->instance = NULL;
    base->object_name = NULL;
    //    util_sparse_array_init(&base->private_data, sizeof(uint64_t), 8);
}

void vk_object_base_instance_init(struct vk_instance* instance,
                                  struct vk_object_base* base,
                                  VkObjectType obj_type)
{
    base->icd_loader_data.loaderMagic = ICD_LOADER_MAGIC;
    base->type = obj_type;
    //    base->client_visible = false;
    base->device = NULL;
    base->instance = instance;
    base->object_name = NULL;
    //    util_sparse_array_init(&base->private_data, sizeof(uint64_t), 8);
}