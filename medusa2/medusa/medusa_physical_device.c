#include "medusa_physical_device.h"

#include <fcntl.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <xf86drm.h>
#include <xf86drmMode.h>

#include "common/medusa_util.h"
#include "drm-uapi/v3d_drm.h"
#include "util/log.h"

// #ifdef MAJOR_IN_MKDEV
// #include <sys/mkdev.h>
// #endif
// #ifdef MAJOR_IN_SYSMACROS
// #include <sys/sysmacros.h>
// #endif

static bool
medusa_has_feature(struct medusa_physical_device* device, enum drm_v3d_param feature)
{
    struct drm_v3d_get_param param = {
        .param = feature,
    };
    if (medusa_ioctl(device->render_fd, DRM_IOCTL_V3D_GET_PARAM, &param) != 0)
        return false;
    return param.value;
}

void medusa_physical_device_init(struct medusa_physical_device* physical_device, int32_t render_fd, int32_t primary_fd)
{
    physical_device->render_fd = render_fd;
    physical_device->primary_fd = primary_fd;

    physical_device->fetures.UIFCFG = medusa_has_feature(physical_device, DRM_V3D_PARAM_V3D_UIFCFG);
    physical_device->fetures.HUB_IDENT1 = medusa_has_feature(physical_device, DRM_V3D_PARAM_V3D_HUB_IDENT1);
    physical_device->fetures.HUB_IDENT2 = medusa_has_feature(physical_device, DRM_V3D_PARAM_V3D_HUB_IDENT2);
    physical_device->fetures.HUB_IDENT3 = medusa_has_feature(physical_device, DRM_V3D_PARAM_V3D_HUB_IDENT3);
    physical_device->fetures.CORE0_IDENT0 = medusa_has_feature(physical_device, DRM_V3D_PARAM_V3D_CORE0_IDENT0);
    physical_device->fetures.CORE0_IDENT1 = medusa_has_feature(physical_device, DRM_V3D_PARAM_V3D_CORE0_IDENT1);
    physical_device->fetures.CORE0_IDENT2 = medusa_has_feature(physical_device, DRM_V3D_PARAM_V3D_CORE0_IDENT2);
    physical_device->fetures.SUPPORTS_TFU = medusa_has_feature(physical_device, DRM_V3D_PARAM_SUPPORTS_TFU);
    physical_device->fetures.SUPPORTS_CSD = medusa_has_feature(physical_device, DRM_V3D_PARAM_SUPPORTS_CSD);
    physical_device->fetures.SUPPORTS_CACHE_FLUSH = medusa_has_feature(physical_device, DRM_V3D_PARAM_SUPPORTS_CACHE_FLUSH);
    physical_device->fetures.SUPPORTS_PERFMON = medusa_has_feature(physical_device, DRM_V3D_PARAM_SUPPORTS_PERFMON);
    physical_device->fetures.SUPPORTS_MULTISYNC_EXT = medusa_has_feature(physical_device, DRM_V3D_PARAM_SUPPORTS_MULTISYNC_EXT);
    physical_device->fetures.SUPPORTS_CPU_QUEUE = medusa_has_feature(physical_device, DRM_V3D_PARAM_SUPPORTS_CPU_QUEUE);
    physical_device->fetures.SUPPORTS_SUPER_PAGES = medusa_has_feature(physical_device, DRM_V3D_PARAM_SUPPORTS_SUPER_PAGES);

    medusa_logi("Physical Device Features:");
    medusa_logi("  UIFCFG: %s", physical_device->fetures.UIFCFG ? "Yes" : "No");
    medusa_logi("  HUB_IDENT1: %s", physical_device->fetures.HUB_IDENT1 ? "Yes" : "No");
    medusa_logi("  HUB_IDENT2: %s", physical_device->fetures.HUB_IDENT2 ? "Yes" : "No");
    medusa_logi("  HUB_IDENT3: %s", physical_device->fetures.HUB_IDENT3 ? "Yes" : "No");
    medusa_logi("  CORE0_IDENT0: %s", physical_device->fetures.CORE0_IDENT0 ? "Yes" : "No");
    medusa_logi("  CORE0_IDENT1: %s", physical_device->fetures.CORE0_IDENT1 ? "Yes" : "No");
    medusa_logi("  CORE0_IDENT2: %s", physical_device->fetures.CORE0_IDENT2 ? "Yes" : "No");
    medusa_logi("  SUPPORTS_TFU: %s", physical_device->fetures.SUPPORTS_TFU ? "Yes" : "No");
    medusa_logi("  SUPPORTS_CSD: %s", physical_device->fetures.SUPPORTS_CSD ? "Yes" : "No");
    medusa_logi("  SUPPORTS_CACHE_FLUSH: %s", physical_device->fetures.SUPPORTS_CACHE_FLUSH ? "Yes" : "No");
    medusa_logi("  SUPPORTS_PERFMON: %s", physical_device->fetures.SUPPORTS_PERFMON ? "Yes" : "No");
    medusa_logi("  SUPPORTS_MULTISYNC_EXT: %s", physical_device->fetures.SUPPORTS_MULTISYNC_EXT ? "Yes" : "No");
    medusa_logi("  SUPPORTS_CPU_QUEUE: %s", physical_device->fetures.SUPPORTS_CPU_QUEUE ? "Yes" : "No");
    medusa_logi("  SUPPORTS_SUPER_PAGES: %s", physical_device->fetures.SUPPORTS_SUPER_PAGES ? "Yes" : "No");
}