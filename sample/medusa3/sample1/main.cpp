#include <memory>
#include <spdlog/spdlog.h>

#include "medusa_buffer.h"
#include "medusa_device.h"
#include "medusa_instance.h"
#include "medusa_physical_device.h"

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

    struct medusa_device* device = medusa_physical_device_create_device(physical_device);
    if (!device)
    {
        spdlog::error("Failed to create Medusa device");
        medusa_instance_free(instance);
        return -1;
    }

    struct medusa_buffer* buffer = medusa_device_create_buffer(device, 1024 * 1024, "SampleBuffer");
    if (!buffer)
    {
        spdlog::error("Failed to create buffer object");
        medusa_physical_device_destroy_device(physical_device, device);
        medusa_instance_free(instance);
        return -1;
    }

    bool result = medusa_buffer_map(buffer, 1024 * 1024);
    if (!result)
    {
        spdlog::error("Failed to map buffer object");
        medusa_device_destroy_buffer(device, buffer);
        medusa_physical_device_destroy_device(physical_device, device);
        medusa_instance_free(instance);
        return -1;
    }

    spdlog::info("Medusa device created successfully");

    // finalize
    {
        medusa_device_destroy_buffer(device, buffer);
        medusa_physical_device_destroy_device(physical_device, device);
        medusa_instance_free(instance);
    }

    return 0;
}