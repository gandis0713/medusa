cmake_minimum_required(VERSION 3.22)

project(
    medusa_sample
    VERSION 0.1
    DESCRIPTION "medusa3 sample1"
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(spdlog CONFIG REQUIRED)

# Collect source files
file(GLOB_RECURSE srcs "*.cpp" "*.hpp" "*.h")

# Create executable
add_executable(medusa3_sample1
    ${srcs}
)

target_link_libraries(medusa3_sample1
    PRIVATE
    spdlog::spdlog
    medusa::medusa3
)

# Set compile options
target_compile_options(medusa3_sample1
    PRIVATE
    -Wall
    -Werror
    -Wno-unused-parameter
    -Wno-unused-function
    -Wno-unused-but-set-variable
    -Wno-unused-variable
    -fno-rtti
)