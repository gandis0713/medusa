#include <spdlog/spdlog.h>

#include "device.h"

int main(int argc, char** argv)
{
    // Initialize logger
    auto logger = spdlog::default_logger();
    logger->set_pattern("[%n] [%^%l%$] %v");
    logger->set_level(spdlog::level::info);

    spdlog::info("=== Medusa2 Sample Application ===");
    spdlog::info("Application started successfully");

    print_memory_info();

    spdlog::info("Sample completed successfully");
    return 0;
}