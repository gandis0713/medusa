#include "vk_instance.h"

#include <spdlog/spdlog.h>
#include <stdexcept>

namespace medusa {

vk_instance::vk_instance()
{
    spdlog::info("vk_instance created");
}

vk_instance::~vk_instance()
{
    spdlog::info("Destroying vk_instance");
}

bool vk_instance::initialize()
{
    spdlog::info("Initializing Vulkan instance...");
    return true;
}

} // namespace medusa
