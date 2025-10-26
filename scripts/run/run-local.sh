#!/bin/bash

# Run script for medusa locally (without Docker)
# This script runs the built medusa binary on the local machine

set -e  # Exit on error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Default values
BUILD_TYPE="release"
RUN_SAMPLE=false

# Script directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"

# Function to print colored output
print_info() {
    echo -e "${GREEN}[INFO]${NC} $1"
}

print_warn() {
    echo -e "${YELLOW}[WARN]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Function to show usage
usage() {
    cat << EOF
Usage: $0 [OPTIONS] [COMMAND]

Run medusa locally (without Docker)

OPTIONS:
    -b, --build-type TYPE   Build type: debug, release, relinfo (default: release)
    -s, --sample            Run the medusa_sample application directly
    -h, --help              Show this help message

COMMAND:
    Optional command to run. If not specified and --sample is not set, shows help.

EXAMPLES:
    # Run the medusa sample application (easy way)
    $0 --sample

    # Run debug version of sample
    $0 --build-type debug --sample

    # Run custom binary
    $0 ${PROJECT_ROOT}/build/arm64-rpi5-ninja/release/sample/medusa_sample
EOF
    exit 0
}

# Parse command line arguments
COMMAND=""
while [[ $# -gt 0 ]]; do
    case $1 in
        -b|--build-type)
            BUILD_TYPE="$2"
            shift 2
            ;;
        -s|--sample)
            RUN_SAMPLE=true
            shift
            ;;
        -h|--help)
            usage
            ;;
        *)
            # Assume remaining arguments are the command to run
            COMMAND="$@"
            break
            ;;
    esac
done

# Validate build type
case $BUILD_TYPE in
    debug|release|relinfo)
        ;;
    *)
        print_error "Invalid build type: $BUILD_TYPE"
        print_info "Available types: debug, release, relinfo"
        exit 1
        ;;
esac

# Map build type to directory name
case $BUILD_TYPE in
    debug)
        BUILD_DIR="debug"
        ;;
    release)
        BUILD_DIR="release"
        ;;
    relinfo)
        BUILD_DIR="relinfo"
        ;;
esac

BUILD_PATH="${PROJECT_ROOT}/build/arm64-rpi5-ninja/${BUILD_DIR}"

print_info "Running medusa locally..."
print_info "Build type: ${BUILD_TYPE}"
print_info "Build path: ${BUILD_PATH}"

# Check if build directory exists
if [ ! -d "${BUILD_PATH}" ]; then
    print_error "Build directory not found: ${BUILD_PATH}"
    print_info "Please build the project first using: cmake --preset arm64-rpi5-ninja-${BUILD_TYPE} && cmake --build --preset arm64-rpi5-ninja-${BUILD_TYPE}"
    exit 1
fi

# Set command based on options
if [ "$RUN_SAMPLE" = true ]; then
    # Run the sample application
    COMMAND="${BUILD_PATH}/sample/medusa_sample"
    print_info "Running sample application: ${COMMAND}"
elif [ -z "$COMMAND" ]; then
    print_error "No command specified. Use --sample or provide a command."
    usage
fi

# Check if command exists
if [ ! -f "${COMMAND}" ] && [ ! -x "$(command -v ${COMMAND})" ]; then
    print_error "Command not found: ${COMMAND}"
    exit 1
fi

# Setup Vulkan ICD environment variables
ICD_JSON_PATH="${BUILD_PATH}/medusa/medusa_icd.json"
ICD_LIB_PATH="${BUILD_PATH}/medusa"

if [ ! -f "${ICD_JSON_PATH}" ]; then
    print_error "ICD manifest not found: ${ICD_JSON_PATH}"
    print_info "Please rebuild the project to generate medusa_icd.json"
    exit 1
fi

if [ ! -f "${ICD_LIB_PATH}/libmedusa_icd.so" ]; then
    print_error "ICD library not found: ${ICD_LIB_PATH}/libmedusa_icd.so"
    print_info "Please rebuild the project to generate libmedusa_icd.so"
    exit 1
fi

export VK_ICD_FILENAMES="${ICD_JSON_PATH}"
export LD_LIBRARY_PATH="${ICD_LIB_PATH}:${LD_LIBRARY_PATH}"
export VK_LOADER_DEBUG=all

print_info "Vulkan ICD manifest: ${VK_ICD_FILENAMES}"
print_info "Vulkan ICD library path: ${ICD_LIB_PATH}"
print_info "Vulkan loader debug enabled"
print_info ""
print_info "Executing: ${COMMAND}"
print_info "======================================"

# Execute the command
exec ${COMMAND}
