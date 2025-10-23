cmake_minimum_required(VERSION 3.22)

project(
    medusa_sample
    VERSION 0.1
    DESCRIPTION "medusa sample"
    LANGUAGES CXX
)

# Collect source files
file(GLOB_RECURSE srcs "*.cpp" "*.h")

# Create executable
add_executable(medusa_sample
    ${srcs}
)

# Link medusa library
target_link_libraries(medusa_sample
    PRIVATE
        medusa
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