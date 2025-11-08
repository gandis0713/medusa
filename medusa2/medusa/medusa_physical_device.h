#ifndef MEDUSA_PHYSICAL_DEVICE_H
#define MEDUSA_PHYSICAL_DEVICE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    struct medusa_physical_device
    {
        int32_t render_fd;
        int32_t primary_fd;
    };

#ifdef __cplusplus
}
#endif

#endif // MEDUSA_PHYSICAL_DEVICE_H