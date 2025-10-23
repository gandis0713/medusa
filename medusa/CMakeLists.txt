cmake_minimum_required(VERSION 3.22)

project(
    medusa_lib
    VERSION 0.0.1
    DESCRIPTION "Vulkan Driver Library for Raspberry Pi 5"
    LANGUAGES CXX
)

# Find dependencies
find_package(Vulkan REQUIRED)
find_package(spdlog CONFIG REQUIRED)

# Collect source files
file(GLOB_RECURSE MEDUSA_SOURCES "*.cpp")
file(GLOB_RECURSE MEDUSA_HEADERS "*.hpp")

# Create library
add_library(medusa STATIC
    ${MEDUSA_SOURCES}
    ${MEDUSA_HEADERS}
)

# Set include directories
target_include_directories(medusa
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE
        ${Vulkan_INCLUDE_DIRS}
)

# Link dependencies
target_link_libraries(medusa
    PUBLIC
        spdlog::spdlog
        Vulkan::Headers
)

# Set compile options
target_compile_options(medusa
    PRIVATE
        -Wall
        -Werror
        -Wno-unused-parameter
        -Wno-unused-function
)
