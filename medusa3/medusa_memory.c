#include "medusa_memory.h"

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

static void medusa_memory_init(struct medusa_memory* memory, struct medusa_device* device, uint32_t handle, uint32_t size, uint32_t offset, const char* name)
{
    memory->device = device;
    memory->handle = handle;
    memory->size = size;
    memory->offset = offset;
    memory->map_size = 0;
    memory->map = NULL;
    memory->name = name;
}

static bool medusa_memory_map_async(struct medusa_memory* memory, uint32_t size)
{
    assert(memory != NULL && size <= memory->size);

    if (memory->map)
        return (bool)memory->map;

    struct drm_v3d_mmap_bo map;
    memset(&map, 0, sizeof(map));
    map.handle = memory->handle;
    int ret = v3d_ioctl(memory->device->pdevice->render_fd,
                        DRM_IOCTL_V3D_MMAP_BO, &map);
    if (ret != 0)
    {
        mesa_loge("map ioctl failure\n");
        return false;
    }

    memory->map = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED,
                       memory->device->pdevice->render_fd, map.offset);
    if (memory->map == MAP_FAILED)
    {
        mesa_loge("mmap of bo %d (offset 0x%016llx, size %d) failed\n",
                  memory->handle, (long long)map.offset, (uint32_t)memory->size);
        return false;
    }
    // VG(VALGRIND_MALLOCLIKE_BLOCK(memory->map, memory->size, 0, false));

    memory->map_size = size;

    return true;
}

struct medusa_memory* medusa_memory_alloc(struct medusa_device* device, uint32_t size, const char* name)
{
    mesa_logi("medusa_memory_alloc: size=%u, name=%s", size, name);
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

    struct medusa_memory* memory = (struct medusa_memory*)malloc(sizeof(struct medusa_memory));
    if (!memory)
        return NULL;

    assert(create.offset % PAGE_SIZE == 0);
    assert((create.offset & 0xffffffff) == create.offset);

    mesa_logi("  BO created: handle=%u, size=%u, offset=%u", create.handle, create.size, create.offset);

    medusa_memory_init(memory, device, create.handle, create.size, create.offset, name);

    return memory;
}

bool medusa_memory_free(struct medusa_memory* memory)
{
    if (!memory)
    {
        mesa_loge("medusa_memory is NULL");
        return false;
    }

    if (memory->map)
    {
        medusa_memory_unmap(memory);
    }

    int render_fd = memory->device->pdevice->render_fd;
    uint32_t handle = memory->handle;
    /* Our BO structs are stored in a sparse array in the physical device,
     * so we don't want to free the BO pointer, instead we want to reset it
     * to 0, to signal that array entry as being free.
     *
     * We must do the reset before we actually free the BO in the kernel, since
     * otherwise there is a chance the application creates another BO in a
     * different thread and gets the same array entry, causing a race.
     */
    memset(memory, 0, sizeof(*memory));

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
        free(memory);
    }

    return true;
}

bool medusa_memory_wait(struct medusa_memory* memory, uint64_t timeout_ns)
{
    struct drm_v3d_wait_bo wait = {
        .handle = memory->handle,
        .timeout_ns = timeout_ns,
    };
    return v3d_ioctl(memory->device->pdevice->render_fd,
                     DRM_IOCTL_V3D_WAIT_BO, &wait) == 0;
}

bool medusa_memory_map(struct medusa_memory* memory, uint32_t size)
{
    if (!medusa_memory_map_async(memory, size))
    {
        return false;
    }

    return medusa_memory_wait(memory, 0);
}

void medusa_memory_unmap(struct medusa_memory* memory)
{
    assert(memory && memory->map && memory->map_size > 0);

    munmap(memory->map, memory->map_size);
    memory->map = NULL;
    memory->map_size = 0;
}