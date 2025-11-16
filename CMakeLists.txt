cmake_minimum_required(VERSION 3.22)

project(
  medusa
  VERSION 0.0.1
  DESCRIPTION "Implement Vulkan Driver for raspberry pi 5"
)

# Add subdirectories
add_subdirectory(medusa)
# add_subdirectory(medusa2)
add_subdirectory(medusa3)
add_subdirectory(sample)
