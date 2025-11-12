cmake_minimum_required(VERSION 3.22)

project(v3d_sample1
    VERSION 0.0.1
    DESCRIPTION "QPU Direct Programming Sample 1"
    LANGUAGES C
)

add_executable(v3d_sample1
    qpu_simple_add.c
)

target_link_libraries(v3d_sample1 PRIVATE 
    medusa::medusa
)