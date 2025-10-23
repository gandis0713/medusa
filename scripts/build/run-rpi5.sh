#!/bin/bash

# Run script for medusa on Raspberry Pi 5 using Docker
# This script runs the built medusa binary in a Docker container

set -e  # Exit on error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Default values
IMAGE_NAME="medusa-rpi5-builder"
IMAGE_TAG="latest"
CONTAINER_NAME="medusa-rpi5-run"
INTERACTIVE=true
BUILD_TYPE="release"

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

Run medusa in a Docker container

OPTIONS:
    -t, --tag TAG           Docker image tag (default: latest)
    -n, --name NAME         Docker container name (default: medusa-rpi5-run)
    -b, --build-type TYPE   Build type: debug, release, relinfo (default: release)
    -d, --detach            Run in detached mode (background)
    --rm                    Automatically remove container when it exits (default)
    -h, --help              Show this help message

COMMAND:
    Optional command to run in the container. If not specified, runs bash shell.
    Examples:
        - /app/build/arm64-rpi5-ninja/release/sample/medusa_sample
        - bash

EXAMPLES:
    # Run interactive bash shell in the container
    $0

    # Run the medusa sample application
    $0 /app/build/arm64-rpi5-ninja/release/sample/medusa_sample

    # Run debug version
    $0 --build-type debug /app/build/arm64-rpi5-ninja/debug/sample/medusa_sample

    # Run in background
    $0 --detach /app/build/arm64-rpi5-ninja/release/sample/medusa_sample
EOF
    exit 0
}

# Parse command line arguments
DOCKER_OPTS="--rm"
COMMAND=""
while [[ $# -gt 0 ]]; do
    case $1 in
        -t|--tag)
            IMAGE_TAG="$2"
            shift 2
            ;;
        -n|--name)
            CONTAINER_NAME="$2"
            shift 2
            ;;
        -b|--build-type)
            BUILD_TYPE="$2"
            shift 2
            ;;
        -d|--detach)
            INTERACTIVE=false
            DOCKER_OPTS="$DOCKER_OPTS -d"
            shift
            ;;
        --rm)
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
BUILD_DIR_MAP=( ["debug"]="debug" ["release"]="release" ["relinfo"]="relinfo" )
BUILD_DIR="${BUILD_DIR_MAP[$BUILD_TYPE]}"

print_info "Running medusa in Docker container..."
print_info "Docker image: ${IMAGE_NAME}:${IMAGE_TAG}"
print_info "Build type: ${BUILD_TYPE}"

# Check if Docker is installed
if ! command -v docker &> /dev/null; then
    print_error "Docker is not installed. Please install Docker first."
    exit 1
fi

# Check if image exists
if ! docker image inspect ${IMAGE_NAME}:${IMAGE_TAG} &> /dev/null; then
    print_error "Docker image ${IMAGE_NAME}:${IMAGE_TAG} not found."
    print_info "Please build the image first using: ./scripts/build/build-rpi5.sh"
    exit 1
fi

# Set default command if not specified
if [ -z "$COMMAND" ]; then
    if [ "$INTERACTIVE" = true ]; then
        COMMAND="/bin/bash"
        DOCKER_OPTS="$DOCKER_OPTS -it"
    else
        print_error "Command required when running in detached mode"
        exit 1
    fi
else
    if [ "$INTERACTIVE" = true ]; then
        DOCKER_OPTS="$DOCKER_OPTS -it"
    fi
fi

print_info "Command: ${COMMAND}"
print_info "Starting container..."

# Run the container
docker run \
    $DOCKER_OPTS \
    --name ${CONTAINER_NAME} \
    --platform linux/arm64 \
    -e DISPLAY=${DISPLAY:-:0} \
    -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
    ${IMAGE_NAME}:${IMAGE_TAG} \
    ${COMMAND}

EXIT_CODE=$?

if [ $EXIT_CODE -eq 0 ]; then
    print_info "Container exited successfully"
else
    print_error "Container exited with code: $EXIT_CODE"
fi

exit $EXIT_CODE
