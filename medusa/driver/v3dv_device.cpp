#include "v3dv_device.hpp"

#include <sys/sysinfo.h>

#include "utils/log.hpp"

namespace medusa
{

v3dv_device::v3dv_device()
{
    LOG_INFO("v3dv_device created");

    struct sysinfo info;
    sysinfo(&info);

    LOG_INFO("System has {} total RAM and {} free RAM (in bytes)", info.totalram, info.freeram);
}

v3dv_device::~v3dv_device()
{
    LOG_INFO("Destroying v3dv_device");
}

} // namespace medusa
