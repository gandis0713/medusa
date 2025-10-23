#pragma once

#include <string>
#include <vector>

namespace medusa {

/**
 * @brief Vulkan Instance for Raspberry Pi 5
 */
class vk_instance {
public:
    /**
     * @brief Construct a new vk_instance object
     */
    vk_instance();

    /**
     * @brief Destroy the vk_instance object
     */
    ~vk_instance();

    // Delete copy constructor and assignment operator
    vk_instance(const vk_instance&) = delete;
    vk_instance& operator=(const vk_instance&) = delete;

    /**
     * @brief Initialize the Vulkan instance
     *
     * @return true if initialization succeeded
     * @return false if initialization failed
     */
    bool initialize();

private:
    std::string app_name_;
};

} // namespace medusa
