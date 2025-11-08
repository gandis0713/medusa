#ifndef MEDUSA_PHYSICAL_DEVICE_H
#define MEDUSA_PHYSICAL_DEVICE_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    struct medusa_fetures
    {
        bool UIFCFG;
        bool HUB_IDENT1;
        bool HUB_IDENT2;
        bool HUB_IDENT3;
        bool CORE0_IDENT0;
        bool CORE0_IDENT1;
        bool CORE0_IDENT2;
        bool SUPPORTS_TFU;
        bool SUPPORTS_CSD;
        bool SUPPORTS_CACHE_FLUSH;
        bool SUPPORTS_PERFMON;
        bool SUPPORTS_MULTISYNC_EXT;
        bool SUPPORTS_CPU_QUEUE;
        bool SUPPORTS_SUPER_PAGES;
    };

    struct medusa_physical_device
    {
        int32_t render_fd;
        int32_t primary_fd;

        struct medusa_fetures fetures;
    };

    void medusa_physical_device_init(struct medusa_physical_device* physical_device, int32_t render_fd, int32_t primary_fd);

#ifdef __cplusplus
}
#endif

#endif // MEDUSA_PHYSICAL_DEVICE_H