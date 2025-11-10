cmake_minimum_required(VERSION 3.22)

project(
    medusa_sample
    VERSION 0.1
    DESCRIPTION "medusa2 sample1"
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Vulkan (for loader, not ICD)
find_package(Vulkan REQUIRED)
find_package(spdlog CONFIG REQUIRED)

# Collect source files
file(GLOB_RECURSE srcs "*.cpp" "*.hpp" "*.h")

# Create executable
add_executable(medusa2_sample1
    ${srcs}
)

# Link Vulkan loader and spdlog (for logging)
# NOTE: Do NOT link medusa::medusa (ICD) - it will be loaded by Vulkan loader at runtime
target_link_libraries(medusa2_sample1
    PRIVATE
    Vulkan::Vulkan
    spdlog::spdlog
)

# Set compile options
target_compile_options(medusa2_sample1
    PRIVATE
    -Wall
    -Werror
    -Wno-unused-parameter
    -Wno-unused-function
    -Wno-unused-but-set-variable
    -Wno-unused-variable
    -fno-rtti
)