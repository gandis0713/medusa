cmake_minimum_required(VERSION 3.22)

project(
    medusa_sample
    VERSION 0.1
    DESCRIPTION "medusa sample"
    LANGUAGES CXX
)

# Find Vulkan (for loader, not ICD)
find_package(Vulkan REQUIRED)

# Collect source files
file(GLOB_RECURSE srcs "*.cpp" "*.h")

# Create executable
add_executable(medusa_sample
    ${srcs}
)

# Link Vulkan loader and utils (for logging)
# NOTE: Do NOT link medusa::medusa (ICD) - it will be loaded by Vulkan loader at runtime
target_link_libraries(medusa_sample
    PRIVATE
    medusa::utils
    Vulkan::Vulkan
)

# Set compile options
if(APPLE)
    target_compile_options(medusa_sample
        PRIVATE
        -Wall
        -Werror
        -Wno-unused-parameter
        -Wno-unused-function
        -Wno-unused-but-set-variable
        -Wno-unused-variable
        -fno-rtti
    )
else()
    target_compile_options(medusa_sample
        PRIVATE
        -Wall
        -Wno-unused-parameter
        -Wno-unused-function
    )
endif()