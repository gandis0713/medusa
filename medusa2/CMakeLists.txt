cmake_minimum_required(VERSION 3.22)

project(
    medusa2_sample
    VERSION 0.1
    DESCRIPTION "medusa2 sample"
    LANGUAGES C CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(spdlog CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBDRM REQUIRED libdrm)

# Collect source files
file(GLOB_RECURSE srcs "*.cpp" "*.c" "*.hpp" "*.h")

# Create executable
add_executable(medusa2_sample
    ${srcs}
)

# Set compile definitions
include(CheckIncludeFile)
check_include_file(endian.h HAVE_ENDIAN_H)
if(HAVE_ENDIAN_H)
    target_compile_definitions(medusa2_sample PRIVATE 
    HAVE_ENDIAN_H)
endif()

include(CheckStructHasMember)
check_struct_has_member("struct timespec" tv_sec "time.h" HAVE_STRUCT_TIMESPEC)
if(HAVE_STRUCT_TIMESPEC)
    target_compile_definitions(medusa2_sample PRIVATE HAVE_STRUCT_TIMESPEC)
endif()

# Check where major/minor are defined
include(CheckSymbolExists)
check_symbol_exists(major "sys/sysmacros.h" MAJOR_IN_SYSMACROS)
if(MAJOR_IN_SYSMACROS)
    target_compile_definitions(medusa2_sample PRIVATE MAJOR_IN_SYSMACROS)
endif()

check_symbol_exists(major "sys/mkdev.h" MAJOR_IN_MKDEV)
if(MAJOR_IN_MKDEV)
    target_compile_definitions(medusa2_sample PRIVATE MAJOR_IN_MKDEV)
endif()

# Check for secure_getenv (available with _GNU_SOURCE)
set(CMAKE_REQUIRED_DEFINITIONS "-D_GNU_SOURCE")
check_symbol_exists(secure_getenv "stdlib.h" HAVE_SECURE_GETENV)
unset(CMAKE_REQUIRED_DEFINITIONS)
if(HAVE_SECURE_GETENV)
    target_compile_definitions(medusa2_sample PRIVATE HAVE_SECURE_GETENV)
endif()

# Check for sysconf (POSIX function)
check_symbol_exists(sysconf "unistd.h" HAVE_SYSCONF)
if(HAVE_SYSCONF)
    target_compile_definitions(medusa2_sample PRIVATE HAVE_SYSCONF)
endif()

# Check for program_invocation_name (GNU extension)
set(CMAKE_REQUIRED_DEFINITIONS "-D_GNU_SOURCE")
check_symbol_exists(program_invocation_name "errno.h" HAVE_PROGRAM_INVOCATION_NAME)
unset(CMAKE_REQUIRED_DEFINITIONS)
if(HAVE_PROGRAM_INVOCATION_NAME)
    target_compile_definitions(medusa2_sample PRIVATE HAVE_PROGRAM_INVOCATION_NAME)
endif()

target_include_directories(medusa2_sample
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/drm-uapi
    ${CMAKE_CURRENT_SOURCE_DIR}/medusa
    ${CMAKE_CURRENT_SOURCE_DIR}/util
    ${LIBDRM_INCLUDE_DIRS}
)

# Link Vulkan loader and spdlog (for logging)
# NOTE: Do NOT link medusa2::medusa2 (ICD) - it will be loaded by Vulkan loader at runtime
target_link_libraries(medusa2_sample
    PRIVATE
    spdlog::spdlog
    ${LIBDRM_LIBRARIES}
    ${CMAKE_DL_LIBS}
)

target_compile_definitions(medusa2_sample PRIVATE
    _GNU_SOURCE
    HAVE_PTHREAD
    HAVE_DL_ITERATE_PHDR
    HAVE_LIBDRM
)

# Set compile options
target_compile_options(medusa2_sample
    PRIVATE
    -Wall
    -Werror
    -Wno-unused-parameter
    -Wno-unused-function
    -Wno-unused-but-set-variable
    -Wno-unused-variable
    # -fno-rtti # for c++
)