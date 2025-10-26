#pragma once

#include <memory>
#include <string>
#include <vector>
#include <vulkan/vulkan.h>

namespace medusa
{
namespace runtime
{

/**
 * @brief Vulkan Instance implementation for Raspberry Pi 5
 *
 * This class IS the VkInstance. The VkInstance handle returned to
 * the application is simply a pointer to this class.
 *
 * VkInstance handle = reinterpret_cast<VkInstance>(vk_instance*)
 */
class vk_instance
{
public:
    /**
     * @brief Create a Vulkan instance from VkInstanceCreateInfo
     *
     * @param create_info Instance creation parameters
     * @return vk_instance* Pointer to created instance (NULL on failure)
     */
    static vk_instance* create(const VkInstanceCreateInfo* create_info);

    /**
     * @brief Destroy the vk_instance
     */
    static void destroy(vk_instance* instance);

    /**
     * @brief Convert vk_instance* to VkInstance handle
     */
    VkInstance as_handle()
    {
        return reinterpret_cast<VkInstance>(this);
    }

    /**
     * @brief Convert VkInstance handle to vk_instance*
     */
    static vk_instance* from_handle(VkInstance handle)
    {
        return reinterpret_cast<vk_instance*>(handle);
    }

    /**
     * @brief Check if instance is valid
     */
    bool is_valid() const
    {
        return valid_;
    }

private:
    // Private constructor - use create() instead
    explicit vk_instance(const VkInstanceCreateInfo* create_info);
    ~vk_instance();

    // Delete copy constructor and assignment operator
    vk_instance(const vk_instance&) = delete;
    vk_instance& operator=(const vk_instance&) = delete;

    bool valid_;
    std::string app_name_;
    uint32_t app_version_;
    std::string engine_name_;
    uint32_t engine_version_;
    uint32_t api_version_;

    std::vector<std::string> enabled_extensions_;
    std::vector<std::string> enabled_layers_;

    void initialize(const VkInstanceCreateInfo* create_info);
};

} // namespace runtime
} // namespace medusa
