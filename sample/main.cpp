#include <spdlog/spdlog.h>
#include <vk_instance.h>

int main(int argc, char** argv)
{
    spdlog::info("=== Medusa Vulkan Driver Sample ===");
    spdlog::info("Running on Raspberry Pi 5");

    // Create instance (avoid Most Vexing Parse)
    medusa::vk_instance instance;

    // Initialize the instance
    if (!instance.initialize())
    {
        spdlog::error("Failed to initialize Vulkan instance");
        return 1;
    }

    spdlog::info("Sample completed successfully");
    return 0;
}