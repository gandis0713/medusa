cmake_minimum_required(VERSION 3.22)

project(
  medusa
  VERSION 0.0.1
  DESCRIPTION "Implement Vulkan Driver for raspberry pi 5"
  LANGUAGES CXX
)

# Set compile options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(common)
add_subdirectory(medusa)
add_subdirectory(sample)
