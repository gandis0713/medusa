#include <spdlog/spdlog.h>

#include "medusa_device.h"
#include "medusa_instance.h"
#include "medusa_physical_device.h"

int main(int argc, char** argv)
{
    // Initialize logger
    auto logger = spdlog::default_logger();
    logger->set_pattern("[%n] [%^%l%$] %v");
    logger->set_level(spdlog::level::info);

    spdlog::info("=== Medusa2 Sample Application ===");
    spdlog::info("Application started successfully");

    // Create Medusa instance
    struct medusa_instance* instance = medusa_instance_create();
    if (!instance)
    {
        spdlog::error("Failed to create Medusa instance");
        return -1;
    }

    // Use the Medusa instance...

    // Destroy Medusa instance
    medusa_instance_destroy(instance);

    spdlog::info("Sample completed successfully");
    return 0;
}