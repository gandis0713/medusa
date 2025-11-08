cmake_minimum_required(VERSION 3.22)

project(
    medusa2_sample
    VERSION 0.1
    DESCRIPTION "medusa2 sample"
    LANGUAGES C CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(spdlog CONFIG REQUIRED)

# Collect source files
file(GLOB_RECURSE srcs "*.cpp" "*.c" "*.hpp" "*.h")

# Create executable
add_executable(medusa2_sample
    ${srcs}
)

MESSAGE(STATUS "medusa2_sample source files: ${srcs}")

target_include_directories(medusa2_sample
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/device
)

# Link Vulkan loader and spdlog (for logging)
# NOTE: Do NOT link medusa2::medusa2 (ICD) - it will be loaded by Vulkan loader at runtime
target_link_libraries(medusa2_sample
    PRIVATE
    spdlog::spdlog
)

# Set compile options
target_compile_options(medusa2_sample
    PRIVATE
    -Wall
    -Werror
    -Wno-unused-parameter
    -Wno-unused-function
    -Wno-unused-but-set-variable
    -Wno-unused-variable
    # -fno-rtti # for c++
)