cmake_minimum_required(VERSION 3.22)

# Find dependencies
find_package(spdlog CONFIG REQUIRED)

# Collect source files
file(GLOB UTILS_SOURCES "*.cpp")
file(GLOB UTILS_HEADERS "*.hpp")

# Create utils library
add_library(medusa_utils STATIC
    ${UTILS_SOURCES}
    ${UTILS_HEADERS}
)

# Set include directories
target_include_directories(medusa_utils
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/.. # common/ directory
)

# Link dependencies
target_link_libraries(medusa_utils
    PUBLIC
    spdlog::spdlog
)

# Set compile options
target_compile_options(medusa_utils
    PRIVATE
    -Wall
    -Wno-unused-parameter
    -Wno-unused-function
)

# Set C++ standard
target_compile_features(medusa_utils PUBLIC cxx_std_20)

# Create alias for consistent naming
add_library(medusa::utils ALIAS medusa_utils)
