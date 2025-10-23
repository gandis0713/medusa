cmake_minimum_required(VERSION 3.22)

project(
    medusa_sample
    VERSION 0.1
    DESCRIPTION "medusa sample"
    LANGUAGES CXX
)
file(GLOB_RECURSE srcs "*.cpp" "*.h")

add_executable(medusa_sample
    ${srcs}
)

if(APPLE)
    target_compile_options(${target}
        PUBLIC
        -Wall
        -Werror
        -Wno-unused-parameter
        -Wno-unused-function
        -Wno-unused-but-set-variable
        -Wno-unused-variable

        PRIVATE
        -fno-rtti # -fno-exceptions
    )
endif()