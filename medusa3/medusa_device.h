#ifndef MEDUSA2_DEVICE_H
#define MEDUSA2_DEVICE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    struct medusa_instance;
    struct medusa_physical_device;
    struct medusa_device
    {
        struct medusa_instance* instance;
        struct medusa_physical_device* pdevice;
    };

    struct medusa_device* medusa_device_alloc(struct medusa_physical_device* physical_device);
    void medusa_device_free(struct medusa_device* device);

#ifdef __cplusplus
}
#endif

#endif // MEDUSA2_DEVICE_H