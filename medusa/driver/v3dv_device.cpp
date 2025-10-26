#include "v3dv_device.hpp"

#include "utils/log.hpp"

namespace medusa
{

v3dv_device::v3dv_device()
{
    LOG_INFO("v3dv_device created");
}

v3dv_device::~v3dv_device()
{
    LOG_INFO("Destroying v3dv_device");
}

} // namespace medusa
