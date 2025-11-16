#include "medusa_buffer.h"

#include "drm-uapi/v3d_drm.h"
#include "u_math.h"
#include "util/log.h"
#include "v3d_util.h"

#include "medusa_device.h"
#include "medusa_physical_device.h"

#include <assert.h>
#include <errno.h>
#include <sys/mman.h>

// static

static void medusa_buffer_init(struct medusa_buffer* bo, struct medusa_device* device, uint32_t handle, uint32_t size, uint32_t offset, const char* name)
{
    bo->device = device;
    bo->handle = handle;
    bo->size = size;
    bo->offset = offset;
    bo->map_size = 0;
    bo->map = NULL;
    bo->name = name;
}

static bool medusa_buffer_map_async(struct medusa_buffer* bo, uint32_t size)
{
    assert(bo != NULL && size <= bo->size);

    if (bo->map)
        return (bool)bo->map;

    struct drm_v3d_mmap_bo map;
    memset(&map, 0, sizeof(map));
    map.handle = bo->handle;
    int ret = v3d_ioctl(bo->device->pdevice->render_fd,
                        DRM_IOCTL_V3D_MMAP_BO, &map);
    if (ret != 0)
    {
        mesa_loge("map ioctl failure\n");
        return false;
    }

    bo->map = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED,
                   bo->device->pdevice->render_fd, map.offset);
    if (bo->map == MAP_FAILED)
    {
        mesa_loge("mmap of bo %d (offset 0x%016llx, size %d) failed\n",
                  bo->handle, (long long)map.offset, (uint32_t)bo->size);
        return false;
    }
    // VG(VALGRIND_MALLOCLIKE_BLOCK(bo->map, bo->size, 0, false));

    bo->map_size = size;

    return true;
}

struct medusa_buffer* medusa_buffer_alloc(struct medusa_device* device, uint32_t size, const char* name)
{
    mesa_logi("medusa_buffer_alloc: size=%u, name=%s", size, name);
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

    struct medusa_buffer* bo = (struct medusa_buffer*)malloc(sizeof(struct medusa_buffer));
    if (!bo)
        return NULL;

    assert(create.offset % PAGE_SIZE == 0);
    assert((create.offset & 0xffffffff) == create.offset);

    mesa_logi("  BO created: handle=%u, size=%u, offset=%u", create.handle, create.size, create.offset);

    medusa_buffer_init(bo, device, create.handle, create.size, create.offset, name);

    return bo;
}

bool medusa_buffer_free(struct medusa_buffer* bo)
{
    if (!bo)
    {
        mesa_loge("medusa_buffer is NULL");
        return false;
    }

    if (bo->map)
    {
        medusa_buffer_unmap(bo);
    }

    int render_fd = bo->device->pdevice->render_fd;
    uint32_t handle = bo->handle;
    /* Our BO structs are stored in a sparse array in the physical device,
     * so we don't want to free the BO pointer, instead we want to reset it
     * to 0, to signal that array entry as being free.
     *
     * We must do the reset before we actually free the BO in the kernel, since
     * otherwise there is a chance the application creates another BO in a
     * different thread and gets the same array entry, causing a race.
     */
    memset(bo, 0, sizeof(*bo));

    struct drm_gem_close c;
    memset(&c, 0, sizeof(c));
    c.handle = handle;
    int ret = v3d_ioctl(render_fd, DRM_IOCTL_GEM_CLOSE, &c);
    if (ret != 0)
    {
        mesa_loge("close object %d: %s\n", handle, strerror(errno));
        return false;
    }

    // TODO: if use sparse array, do not free bo pointer
    if (true)
    {
        free(bo);
    }

    return true;
}

bool medusa_buffer_wait(struct medusa_buffer* bo, uint64_t timeout_ns)
{
    struct drm_v3d_wait_bo wait = {
        .handle = bo->handle,
        .timeout_ns = timeout_ns,
    };
    return v3d_ioctl(bo->device->pdevice->render_fd,
                     DRM_IOCTL_V3D_WAIT_BO, &wait) == 0;
}

bool medusa_buffer_map(struct medusa_buffer* bo, uint32_t size)
{
    if (!medusa_buffer_map_async(bo, size))
    {
        return false;
    }

    return medusa_buffer_wait(bo, 0);
}

void medusa_buffer_unmap(struct medusa_buffer* bo)
{
    assert(bo && bo->map && bo->map_size > 0);

    munmap(bo->map, bo->map_size);
    bo->map = NULL;
    bo->map_size = 0;
}