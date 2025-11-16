#include "medusa_device.h"

#include "medusa_instance.h"
#include "medusa_physical_device.h"

#include "util/log.h"
#include <stdlib.h>

struct medusa_device* medusa_device_alloc(struct medusa_physical_device* physical_device)
{
    struct medusa_device* device = (struct medusa_device*)malloc(sizeof(struct medusa_device));
    if (!device)
    {
        mesa_loge("Failed to allocate memory for medusa_device");
        return NULL;
    }

    device->pdevice = physical_device;

    return device;
}

void medusa_device_free(struct medusa_device* device)
{
    if (!device)
    {
        mesa_loge("medusa_device is NULL");
        return;
    }

    free(device);
}