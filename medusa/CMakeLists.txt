cmake_minimum_required(VERSION 3.22)

project(
    medusa_lib
    VERSION 0.0.1
    DESCRIPTION "Vulkan Driver Library for Raspberry Pi 5"
    LANGUAGES C
)

# Collect source files
file(GLOB_RECURSE MEDUSA_SOURCES "*.c")
file(GLOB_RECURSE MEDUSA_HEADERS "*.h")

# Create Vulkan ICD shared library
add_library(medusa SHARED
    ${MEDUSA_SOURCES}
    ${MEDUSA_HEADERS}
)

# Set include directories
target_include_directories(medusa
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set compile options
target_compile_options(medusa
    PRIVATE
        -Wall
        -Werror
        -Wno-unused-parameter
        -Wno-unused-function
)

# Set output name for ICD library
set_target_properties(medusa PROPERTIES
    OUTPUT_NAME "medusa_icd"
    C_STANDARD 11
    C_STANDARD_REQUIRED ON
)

# Generate ICD manifest JSON file
# Use file(GENERATE) to support generator expressions
file(GENERATE
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/medusa_icd.json
    INPUT ${CMAKE_SOURCE_DIR}/cmake/medusa_icd.json.in
)

add_library(medusa::medusa ALIAS medusa)
