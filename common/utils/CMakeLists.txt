cmake_minimum_required(VERSION 3.22)

# Collect source files
file(GLOB UTILS_SOURCES "*.c")
file(GLOB UTILS_HEADERS "*.h")

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

# Set compile options
target_compile_options(medusa_utils
    PRIVATE
    -Wall
    -Wno-unused-parameter
    -Wno-unused-function
)

# Enable Position Independent Code for linking with shared libraries
set_target_properties(medusa_utils PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
    C_STANDARD_REQUIRED ON
)

# Create alias for consistent naming
add_library(medusa::utils ALIAS medusa_utils)
