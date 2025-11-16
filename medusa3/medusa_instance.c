#include "medusa_instance.h"

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <xf86drm.h>
#include <xf86drmMode.h>

#include "util/log.h"

static void print_memory_info()
{
    struct sysinfo info;
    sysinfo(&info);

    uint64_t total_ram = (uint64_t)info.totalram * (uint64_t)info.mem_unit;
    uint64_t free_ram = (uint64_t)info.freeram * (uint64_t)info.mem_unit;

    mesa_logi("Device Memory Information:");
    mesa_logi("  Total RAM: %llu MB", total_ram / (1024 * 1024));
    mesa_logi("  Free RAM:  %llu MB", free_ram / (1024 * 1024));
}

static bool try_device(const char* path, int* fd, const char* target)
{
    drmVersionPtr version = NULL;

    *fd = open(path, O_RDWR | O_CLOEXEC);
    if (*fd < 0)
    {
        mesa_loge("Opening %s failed: %s\n", path, strerror(errno));
        return false;
    }

    if (!target)
        return true;

    version = drmGetVersion(*fd);
    if (!version)
    {
        mesa_loge("Retrieving device version failed: %s\n", strerror(errno));
        goto fail;
    }

    if (strcmp(version->name, target) != 0)
        goto fail;

    drmFreeVersion(version);
    return true;

fail:
    drmFreeVersion(version);
    close(*fd);
    *fd = -1;
    return false;
}

static void try_display_device(const char* path, int32_t* fd)
{
    *fd = open(path, O_RDWR | O_CLOEXEC);
    if (*fd < 0)
    {
        mesa_loge("Opening %s failed: %s\n", path, strerror(errno));
        return;
    }

    /* The display driver must have KMS capabilities */
    if (!drmIsKMS(*fd))
        goto fail;

    // medusa tests on wayland, so skip check
    if (false)
    {
        /* If using VK_KHR_display, we require the fd to have a connected output.
         * We need to use this strategy because Raspberry Pi 5 can load different
         * drivers for different types of connectors and the one with a connected
         * output may not be vc4, which unlike Raspberry Pi 4, doesn't drive the
         * DSI output for example.
         */
        drmModeResPtr mode_res = drmModeGetResources(*fd);
        if (!mode_res)
        {
            mesa_loge("Failed to get DRM mode resources: %s\n", strerror(errno));
            goto fail;
        }

        drmModeConnection connection = DRM_MODE_DISCONNECTED;

        /* Only use a display device if there is at least one connected connector */
        for (int c = 0; c < mode_res->count_connectors && connection == DRM_MODE_DISCONNECTED; c++)
        {
            drmModeConnectorPtr connector = drmModeGetConnector(*fd, mode_res->connectors[c]);

            if (!connector)
                continue;

            connection = connector->connection;
            drmModeFreeConnector(connector);
        }

        drmModeFreeResources(mode_res);

        if (connection == DRM_MODE_DISCONNECTED)
            goto fail;
    }

    return;

fail:
    close(*fd);
    *fd = -1;
}

static void create_physical_device(struct medusa_instance* instance, int32_t render_fd, int32_t display_fd)
{
    struct medusa_physical_device physical_device;

    medusa_physical_device_init(&physical_device, instance, render_fd, display_fd);

    instance->physical_device = physical_device;
}

static void enumerate_physical_devices(struct medusa_instance* instance)
{
    drmDevicePtr devices[8];
    int max_devices;

    max_devices = drmGetDevices2(0, devices, ARRAY_SIZE(devices));
    mesa_logi("Found %d DRM devices\n", max_devices);
    if (max_devices < 1)
    {
        mesa_loge("No DRM devices found\n");
        return;
    }

    int32_t render_fd = -1;
    int32_t primary_fd = -1;
    for (unsigned i = 0; i < (unsigned)max_devices; i++)
    {
        /* On actual hardware, we should have a gpu device (v3d) and a display
         * device. We will need to use the display device to allocate WSI
         * buffers and share them with the render node via prime. We want to
         * allocate the display buffer on the WSI device as the display device
         * may not have a MMU (this is true at least on Raspberry Pi 4).
         */
        if (devices[i]->bustype != DRM_BUS_PLATFORM)
            continue;

        if ((devices[i]->available_nodes & 1 << DRM_NODE_RENDER))
        {
            try_device(devices[i]->nodes[DRM_NODE_RENDER], &render_fd, "v3d");
        }
        else if (primary_fd == -1 &&
                 (devices[i]->available_nodes & 1 << DRM_NODE_PRIMARY))
        {
            try_display_device(devices[i]->nodes[DRM_NODE_PRIMARY], &primary_fd);
        }

        if (render_fd >= 0 && primary_fd >= 0)
            break;
    }

    if (render_fd < 0 || primary_fd < 0)
    {
        mesa_loge("Failed to find suitable DRM devices\n");
        if (render_fd >= 0)
            close(render_fd);
        if (primary_fd >= 0)
            close(primary_fd);
        return;
    }

    mesa_logi("Using render node fd %d and primary fd %d\n", render_fd, primary_fd);
    create_physical_device(instance, render_fd, primary_fd);

    drmFreeDevices(devices, max_devices);
}

struct medusa_instance* medusa_instance_alloc()
{
    struct medusa_instance* instance = (struct medusa_instance*)malloc(sizeof(struct medusa_instance));
    if (!instance)
        return NULL;

    enumerate_physical_devices(instance);

    print_memory_info();

    return instance;
}

void medusa_instance_free(struct medusa_instance* instance)
{
    close(instance->physical_device.render_fd);
    close(instance->physical_device.primary_fd);

    if (!instance)
        return;

    free(instance);
}

struct medusa_physical_device* medusa_instance_get_physical_device(struct medusa_instance* instance)
{
    return &instance->physical_device;
}
