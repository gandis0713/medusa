cmake_minimum_required(VERSION 3.22)

project(v3d_sample2
    VERSION 0.0.1
    DESCRIPTION "QPU Direct Programming Sample 2"
    LANGUAGES C
)

add_executable(v3d_sample2
    qpu_simple_add.c
    # test_immediate.c
)

target_link_libraries(v3d_sample2 PRIVATE 
    medusa::medusa
)