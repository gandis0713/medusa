#ifndef MEDUSA_INSTANCE_H
#define MEDUSA_INSTANCE_H

#include "medusa_physical_device.h"

#ifdef __cplusplus
extern "C"
{
#endif

    struct medusa_instance
    {
        struct medusa_physical_device physical_device;
    };

    struct medusa_instance* medusa_instance_alloc();
    void medusa_instance_free(struct medusa_instance* instance);
    struct medusa_physical_device* medusa_instance_get_physical_device(struct medusa_instance* instance);

#ifdef __cplusplus
}
#endif

#endif // MEDUSA_INSTANCE_H