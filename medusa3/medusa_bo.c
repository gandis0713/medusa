#include "medusa_bo.h"

#include "drm-uapi/v3d_drm.h"
#include "u_math.h"
#include "util/log.h"
#include "v3d_util.h"

#include "medusa_device.h"
#include "medusa_physical_device.h"

#include <assert.h>

void medusa_bo_init(struct medusa_bo* bo, uint32_t handle, uint32_t size, uint32_t offset, const char* name)
{
    bo->handle = handle;
    bo->size = size;
    bo->offset = offset;
    bo->map_size = 0;
    bo->map = NULL;
    bo->name = name;
}

struct medusa_bo* medusa_bo_alloc(struct medusa_device* device, uint32_t size, const char* name)
{
    mesa_logi("medusa_bo_alloc: size=%u, name=%s", size, name);
    size = align(size, PAGE_SIZE);
    mesa_logi("  aligned size=%u", size);

    // TODO: from cache

    struct drm_v3d_create_bo create = {
        .size = size
    };

    int ret = v3d_ioctl(device->pdevice->render_fd,
                        DRM_IOCTL_V3D_CREATE_BO, &create);

    if (ret != 0)
    {
        mesa_loge("Failed to allocate device memory for BO");
        return NULL;
    }

    struct medusa_bo* bo = (struct medusa_bo*)malloc(sizeof(struct medusa_bo));
    if (!bo)
        return NULL;

    assert(create.offset % PAGE_SIZE == 0);
    assert((create.offset & 0xffffffff) == create.offset);

    mesa_logi("  BO created: handle=%u, size=%u, offset=%u", create.handle, create.size, create.offset);

    medusa_bo_init(bo, create.handle, create.size, create.offset, name);

    return bo;
}

bool medusa_bo_free(struct medusa_device* dev, struct medusa_bo* bo)
{
    return false;
}

bool medusa_bo_map(struct medusa_device* dev, struct medusa_bo* bo, uint32_t size)
{
    return false;
}

void medusa_bo_unmap(struct medusa_device* dev, struct medusa_bo* bo)
{
}