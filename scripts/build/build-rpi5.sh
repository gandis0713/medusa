#!/bin/bash

# Build script for Raspberry Pi 5 using Docker
# This script builds the medusa project for arm64 architecture

set -e  # Exit on error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Default values
IMAGE_NAME="medusa-rpi5-builder"
IMAGE_TAG="latest"
BUILD_PRESET="arm64-rpi5-ninja-release"
CONTAINER_NAME="medusa-rpi5-build"
BUILD_ONLY=false

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
Usage: $0 [OPTIONS]

Build medusa for Raspberry Pi 5 using Docker

OPTIONS:
    -p, --preset PRESET      CMake preset to use (default: arm64-rpi5-ninja-release)
                            Available: arm64-rpi5-ninja-debug, arm64-rpi5-ninja-release, arm64-rpi5-ninja-relinfo
    -t, --tag TAG           Docker image tag (default: latest)
    -n, --name NAME         Docker container name (default: medusa-rpi5-build)
    -b, --build-only        Only build the Docker image, don't compile the project
    --no-cache              Build Docker image without cache
    -h, --help              Show this help message

EXAMPLES:
    # Build with default settings (release)
    $0

    # Build debug version
    $0 --preset arm64-rpi5-ninja-debug

    # Build without Docker cache
    $0 --no-cache

    # Only build Docker image
    $0 --build-only
EOF
    exit 0
}

# Parse command line arguments
NO_CACHE=""
while [[ $# -gt 0 ]]; do
    case $1 in
        -p|--preset)
            BUILD_PRESET="$2"
            shift 2
            ;;
        -t|--tag)
            IMAGE_TAG="$2"
            shift 2
            ;;
        -n|--name)
            CONTAINER_NAME="$2"
            shift 2
            ;;
        -b|--build-only)
            BUILD_ONLY=true
            shift
            ;;
        --no-cache)
            NO_CACHE="--no-cache"
            shift
            ;;
        -h|--help)
            usage
            ;;
        *)
            print_error "Unknown option: $1"
            usage
            ;;
    esac
done

# Validate preset
case $BUILD_PRESET in
    arm64-rpi5-ninja-debug|arm64-rpi5-ninja-release|arm64-rpi5-ninja-relinfo)
        ;;
    *)
        print_error "Invalid preset: $BUILD_PRESET"
        print_info "Available presets: arm64-rpi5-ninja-debug, arm64-rpi5-ninja-release, arm64-rpi5-ninja-relinfo"
        exit 1
        ;;
esac

print_info "Starting Raspberry Pi 5 build process..."
print_info "Project root: ${PROJECT_ROOT}"
print_info "Build preset: ${BUILD_PRESET}"
print_info "Docker image: ${IMAGE_NAME}:${IMAGE_TAG}"

# Check if Docker is installed
if ! command -v docker &> /dev/null; then
    print_error "Docker is not installed. Please install Docker first."
    exit 1
fi

# Build Docker image with BuildKit for caching
print_info "Building Docker image with BuildKit cache..."
DOCKER_BUILDKIT=1 docker build \
    ${NO_CACHE} \
    --platform linux/arm64 \
    --build-arg BUILD_PRESET=${BUILD_PRESET} \
    -t ${IMAGE_NAME}:${IMAGE_TAG} \
    -f "${SCRIPT_DIR}/Dockerfile" \
    "${PROJECT_ROOT}"

if [ $? -ne 0 ]; then
    print_error "Docker image build failed!"
    exit 1
fi

print_info "Docker image built successfully: ${IMAGE_NAME}:${IMAGE_TAG}"

# Exit if build-only mode
if [ "$BUILD_ONLY" = true ]; then
    print_info "Build-only mode: Skipping project compilation"
    exit 0
fi

# Extract build artifacts from Docker image
print_info "Extracting build artifacts..."

# Remove old container if exists
docker rm -f ${CONTAINER_NAME}-temp 2>/dev/null || true

# Create temporary container
docker create --name ${CONTAINER_NAME}-temp ${IMAGE_NAME}:${IMAGE_TAG}

# Extract build and install directories
mkdir -p "${PROJECT_ROOT}/build-output"
docker cp ${CONTAINER_NAME}-temp:/app/build "${PROJECT_ROOT}/build-output/" || true
docker cp ${CONTAINER_NAME}-temp:/app/install "${PROJECT_ROOT}/build-output/" || true

# Cleanup
docker rm -f ${CONTAINER_NAME}-temp

print_info "Build artifacts extracted to: ${PROJECT_ROOT}/build-output"
print_info ""
print_info "Build completed successfully!"
print_info "You can now copy the build-output directory to your Raspberry Pi 5"
