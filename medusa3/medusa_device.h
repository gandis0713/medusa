#ifndef MEDUSA2_DEVICE_H
#define MEDUSA2_DEVICE_H

#include <stdint.h>

#include "medusa_memory.h"

#ifdef __cplusplus
extern "C"
{
#endif

    struct medusa_instance;
    struct medusa_physical_device;
    struct medusa_device
    {
        struct medusa_physical_device* pdevice;
    };

    struct medusa_device* medusa_device_alloc(struct medusa_physical_device* physical_device);
    void medusa_device_free(struct medusa_device* device);
    struct medusa_memory* medusa_device_create_buffer(struct medusa_device* device, uint32_t size, const char* name);
    void medusa_device_destroy_buffer(struct medusa_device* device, struct medusa_memory* bo);

#ifdef __cplusplus
}
#endif

#endif // MEDUSA2_DEVICE_H