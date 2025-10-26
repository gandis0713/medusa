#include "vk_instance.hpp"
#include "utils/log.hpp"

namespace medusa
{
namespace runtime
{

vk_instance* vk_instance::create(const VkInstanceCreateInfo* create_info)
{
    if (!create_info)
    {
        LOG_ERROR("VkInstanceCreateInfo is null");
        return nullptr;
    }

    try
    {
        vk_instance* instance = new vk_instance(create_info);
        if (!instance->is_valid())
        {
            delete instance;
            return nullptr;
        }
        return instance;
    }
    catch (const std::exception& e)
    {
        LOG_ERROR("Exception creating instance: {}", e.what());
        return nullptr;
    }
}

void vk_instance::destroy(vk_instance* instance)
{
    if (instance)
    {
        delete instance;
    }
}

vk_instance::vk_instance(const VkInstanceCreateInfo* create_info)
    : valid_(false)
    , app_version_(0)
    , engine_version_(0)
    , api_version_(VK_API_VERSION_1_0)
{
    LOG_INFO("Creating Vulkan instance...");
    initialize(create_info);
}

vk_instance::~vk_instance()
{
    LOG_INFO("Destroying Vulkan instance");
}

void vk_instance::initialize(const VkInstanceCreateInfo* create_info)
{
    if (!create_info)
    {
        LOG_ERROR("Invalid VkInstanceCreateInfo");
        return;
    }

    // Parse application info
    if (create_info->pApplicationInfo)
    {
        const VkApplicationInfo* app_info = create_info->pApplicationInfo;

        if (app_info->pApplicationName)
        {
            app_name_ = app_info->pApplicationName;
        }
        app_version_ = app_info->applicationVersion;

        if (app_info->pEngineName)
        {
            engine_name_ = app_info->pEngineName;
        }
        engine_version_ = app_info->engineVersion;
        api_version_ = app_info->apiVersion;

        LOG_INFO("Application: {}, Version: {}.{}.{}",
                 app_name_,
                 VK_VERSION_MAJOR(app_version_),
                 VK_VERSION_MINOR(app_version_),
                 VK_VERSION_PATCH(app_version_));

        LOG_INFO("Engine: {}, API Version: {}.{}.{}",
                 engine_name_.empty() ? "None" : engine_name_,
                 VK_VERSION_MAJOR(api_version_),
                 VK_VERSION_MINOR(api_version_),
                 VK_VERSION_PATCH(api_version_));
    }

    // Parse enabled extensions
    for (uint32_t i = 0; i < create_info->enabledExtensionCount; ++i)
    {
        enabled_extensions_.push_back(create_info->ppEnabledExtensionNames[i]);
        LOG_INFO("Enabled extension: {}", create_info->ppEnabledExtensionNames[i]);
    }

    // Parse enabled layers
    for (uint32_t i = 0; i < create_info->enabledLayerCount; ++i)
    {
        enabled_layers_.push_back(create_info->ppEnabledLayerNames[i]);
        LOG_INFO("Enabled layer: {}", create_info->ppEnabledLayerNames[i]);
    }

    valid_ = true;
    LOG_INFO("Vulkan instance created successfully");
}

} // namespace runtime
} // namespace medusa
