#include <memory>
#include <spdlog/spdlog.h>

#include "medusa_instance.h"
// #include "medusa_physical_device.h"

int main(int argc, char** argv)
{
    spdlog::set_level(spdlog::level::trace);

    struct medusa_instance* instance = medusa_instance_alloc();
    if (!instance)
    {
        spdlog::error("Failed to create Medusa instance");
        return -1;
    }

    struct medusa_physical_device* physical_device = medusa_instance_get_physical_device(instance);
    if (!physical_device)
    {
        spdlog::error("Failed to get physical device from instance");
        medusa_instance_free(instance);
        return -1;
    }

    struct medusa_device* device = medusa_instance_create_device(physical_device);
    if (!device)
    {
        spdlog::error("Failed to create Medusa device");
        medusa_instance_free(instance);
        return -1;
    }

    spdlog::info("Medusa device created successfully");

    // finalize
    {
        medusa_instance_free(instance);
    }

    return 0;
}