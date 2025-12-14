cmake_minimum_required(VERSION 3.22)

project(v3d_sample3
    VERSION 0.0.1
    DESCRIPTION "QPU Direct Programming Sample 3 - Matrix Multiplication"
    LANGUAGES C CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC_FILES
    "*.c"
)

add_executable(v3d_sample3
    ${SRC_FILES}
)

target_link_libraries(v3d_sample3 PRIVATE 
    medusa::medusa
)
