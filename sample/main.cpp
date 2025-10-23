#include "utils/log.hpp"
#include "vk_instance.hpp"

int main(int argc, char** argv)
{
    LOG_INFO("=== Medusa Vulkan Driver Sample ===");
    LOG_INFO("Running on Raspberry Pi 5");

    // Create instance (avoid Most Vexing Parse)
    medusa::vk_instance instance;

    // Initialize the instance
    if (!instance.initialize())
    {
        spdlog::error("Failed to initialize Vulkan instance");
        return 1;
    }

    LOG_INFO("Sample completed successfully");
    return 0;
}