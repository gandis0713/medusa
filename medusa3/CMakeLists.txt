cmake_minimum_required(VERSION 3.22)

project(
    medusa3
    VERSION 0.1
    DESCRIPTION "medusa3"
    LANGUAGES C
)

# Collect source files
file(GLOB_RECURSE srcs "*.c" "*.h")

# Create library
add_library(medusa3 STATIC
    ${srcs}
)

target_include_directories(medusa3
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(medusa3 PUBLIC
    medusa::medusa
)

# Set compile options
target_compile_options(medusa3
    PRIVATE
    -Wall
    -Werror
    -Wno-unused-parameter
    -Wno-unused-function
    -Wno-unused-but-set-variable
    -Wno-unused-variable
    # -fno-rtti # for c++
)

add_library(medusa::medusa3 ALIAS medusa3)