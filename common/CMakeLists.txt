cmake_minimum_required(VERSION 3.22)

project(
    medusa_common
    VERSION 0.0.1
    DESCRIPTION "Common utilities for Medusa project"
    LANGUAGES CXX
)

# Add subdirectories for common modules
add_subdirectory(utils)
