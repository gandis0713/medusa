#include <memory>
#include <spdlog/spdlog.h>
#include <vulkan/vulkan.h>

int main(int argc, char** argv)
{
    // Initialize logger
    auto logger = spdlog::default_logger();
    logger->set_pattern("[%n] [%^%l%$] %v");
    logger->set_level(spdlog::level::info);

    spdlog::info("=== Medusa Vulkan Driver Sample ===");
    spdlog::info("Running on Raspberry Pi 5");

    // Prepare Vulkan instance creation info
    VkApplicationInfo app_info{};
    app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pApplicationName = "Medusa Sample";
    app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    app_info.pEngineName = "Medusa";
    app_info.engineVersion = VK_MAKE_VERSION(0, 0, 1);
    app_info.apiVersion = VK_API_VERSION_1_3;

    VkInstanceCreateInfo create_info{};
    create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    create_info.pApplicationInfo = &app_info;

    // Create Vulkan instance using Medusa driver
    VkInstance instance = VK_NULL_HANDLE;
    VkResult result = vkCreateInstance(&create_info, nullptr, &instance);

    if (result != VK_SUCCESS)
    {
        spdlog::error("Failed to create Vulkan instance, error: {}", static_cast<int>(result));
        return 1;
    }

    spdlog::info("Vulkan instance created successfully!");
    spdlog::info("Instance handle: {}", static_cast<void*>(instance));

    // Destroy instance
    vkDestroyInstance(instance, nullptr);
    spdlog::info("Vulkan instance destroyed");

    spdlog::info("Sample completed successfully");
    return 0;
}