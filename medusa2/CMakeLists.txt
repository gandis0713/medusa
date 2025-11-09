cmake_minimum_required(VERSION 3.22)

project(
    medusa2
    VERSION 0.0.1
    DESCRIPTION "Vulkan Driver Library for Raspberry Pi 5"
    LANGUAGES C CXX
)

# Find required packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBDRM REQUIRED libdrm)
pkg_check_modules(WAYLAND_CLIENT REQUIRED wayland-client)

# Collect source files
file(GLOB_RECURSE MEDUSA_SOURCES "*.c" "*.cpp")
file(GLOB_RECURSE MEDUSA_HEADERS "*.h")


# Exclude Android-specific code
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/u_gralloc/.*")
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/vk_android\\.c$")

# Exclude optional Vulkan layers (not needed for ICD driver)
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/vulkan/device-select-layer/.*")
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/vulkan/anti-lag-layer/.*")
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/vulkan/overlay-layer/.*")
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/vulkan/screenshot-layer/.*")
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/vulkan/vram-report-limit-layer/.*")

# Exclude features requiring pre-compiled shaders (Meson build system dependency)
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/vulkan/runtime/radix_sort/.*")
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/vulkan/runtime/vk_acceleration_structure\\.c$")
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/vulkan/runtime/rmv/.*")
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/vulkan/runtime/vk_texcompress_astc\\.c$")

# Exclude Rust bindings

# Exclude video decoding/encoding utilities (VA-API, VDPAU)
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/vl_zscan_data\\.c$")

# Exclude ASTC texture compression LUTs (not using ASTC software decompression)
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/texcompress_astc_luts.*")

# Exclude pipe buffer slab allocator (Gallium-specific)
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/pb_slab\\.c$")

# Exclude WSI implementations (X11, Windows, Metal)
# Use Wayland and DRM display for rendering
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/wsi_common_x11\\.c$")
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/wsi_common_win32\\.c$")
list(FILTER MEDUSA_SOURCES EXCLUDE REGEX ".*/wsi_common_metal\\.c$")

# Create Vulkan ICD shared library
add_library(medusa2 SHARED
    ${MEDUSA_SOURCES}
    ${MEDUSA_HEADERS}
)

# Set include directories
target_include_directories(medusa2
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/broadcom
        ${CMAKE_CURRENT_SOURCE_DIR}/broadcom/vulkan
        ${CMAKE_CURRENT_SOURCE_DIR}/vulkan
        ${CMAKE_CURRENT_SOURCE_DIR}/vulkan/runtime
        ${CMAKE_CURRENT_SOURCE_DIR}/vulkan/util
        ${CMAKE_CURRENT_SOURCE_DIR}/vulkan/wsi
)

# Set compile options
target_compile_options(medusa2
    PRIVATE
        # -Wall
        # -Werror
        # -Wno-unused-parameter
        # -Wno-unused-function
)

# Set compile definitions
include(CheckIncludeFile)
check_include_file(endian.h HAVE_ENDIAN_H)
if(HAVE_ENDIAN_H)
    target_compile_definitions(medusa2 PRIVATE 
    HAVE_ENDIAN_H)
endif()

include(CheckStructHasMember)
check_struct_has_member("struct timespec" tv_sec "time.h" HAVE_STRUCT_TIMESPEC)
if(HAVE_STRUCT_TIMESPEC)
    target_compile_definitions(medusa2 PRIVATE HAVE_STRUCT_TIMESPEC)
endif()

# Check where major/minor are defined
include(CheckSymbolExists)
check_symbol_exists(major "sys/sysmacros.h" MAJOR_IN_SYSMACROS)
if(MAJOR_IN_SYSMACROS)
    target_compile_definitions(medusa2 PRIVATE MAJOR_IN_SYSMACROS)
endif()

check_symbol_exists(major "sys/mkdev.h" MAJOR_IN_MKDEV)
if(MAJOR_IN_MKDEV)
    target_compile_definitions(medusa2 PRIVATE MAJOR_IN_MKDEV)
endif()

# Check for secure_getenv (available with _GNU_SOURCE)
set(CMAKE_REQUIRED_DEFINITIONS "-D_GNU_SOURCE")
check_symbol_exists(secure_getenv "stdlib.h" HAVE_SECURE_GETENV)
unset(CMAKE_REQUIRED_DEFINITIONS)
if(HAVE_SECURE_GETENV)
    target_compile_definitions(medusa2 PRIVATE HAVE_SECURE_GETENV)
endif()

# Check for sysconf (POSIX function)
check_symbol_exists(sysconf "unistd.h" HAVE_SYSCONF)
if(HAVE_SYSCONF)
    target_compile_definitions(medusa2 PRIVATE HAVE_SYSCONF)
endif()

target_compile_definitions(medusa2 PRIVATE
    # USE_V3D_SIMULATOR
    _GNU_SOURCE
    HAVE_PTHREAD
    HAVE_DL_ITERATE_PHDR
    HAVE_LIBDRM
    V3D_VERSION=71
    PACKAGE_VERSION="${CMAKE_PROJECT_VERSION}"
    MESA_GIT_SHA1=""
    VK_USE_PLATFORM_WAYLAND_KHR)

# Link libraries
target_link_libraries(medusa2 PRIVATE
    medusa::medusa
    ${LIBDRM_LIBRARIES}
    ${WAYLAND_CLIENT_LIBRARIES}
    ${CMAKE_DL_LIBS}
)

# Set output name for ICD library
set_target_properties(medusa2 PROPERTIES
    OUTPUT_NAME "medusa2"
    C_STANDARD 11
    C_STANDARD_REQUIRED ON
)

# Generate ICD manifest JSON file
# Use file(GENERATE) to support generator expressions
file(GENERATE
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/medusa_icd.json
    INPUT ${CMAKE_SOURCE_DIR}/cmake/medusa_icd.json.in
)

add_library(medusa::medusa2 ALIAS medusa2)
