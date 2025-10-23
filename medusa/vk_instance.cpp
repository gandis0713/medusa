#include "vk_instance.hpp"

#include "utils/log.hpp"
#include <stdexcept>

namespace medusa
{

vk_instance::vk_instance()
{
    LOG_INFO("vk_instance created");
}

vk_instance::~vk_instance()
{
    LOG_INFO("Destroying vk_instance");
}

bool vk_instance::initialize()
{
    LOG_INFO("Initializing Vulkan instance...");
    return true;
}

} // namespace medusa
