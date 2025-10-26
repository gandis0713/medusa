#include <utils/log.hpp>
#include <vulkan/vulkan.h>

int main(int argc, char** argv)
{
    // Initialize logger
    medusa::utils::Logger::init("MedusaSample", spdlog::level::info);

    LOG_INFO("=== Medusa Vulkan Driver Sample ===");
    LOG_INFO("Running on Raspberry Pi 5");

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
        LOG_ERROR("Failed to create Vulkan instance, error: {}", static_cast<int>(result));
        return 1;
    }

    LOG_INFO("Vulkan instance created successfully!");
    LOG_INFO("Instance handle: {}", static_cast<void*>(instance));

    // Destroy instance
    vkDestroyInstance(instance, nullptr);
    LOG_INFO("Vulkan instance destroyed");

    LOG_INFO("Sample completed successfully");
    return 0;
}