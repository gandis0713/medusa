# Multi-stage Dockerfile for Raspberry Pi 5 (arm64) compilation
FROM --platform=linux/arm64 ubuntu:22.04 AS builder

# Prevent interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install essential build tools and dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    pkg-config \
    curl \
    zip \
    unzip \
    tar \
    ninja-build \
    python3 \
    python3-pip \
    autoconf \
    automake \
    libtool \
    m4 \
    gperf \
    bison \
    flex \
    libx11-dev \
    libxrandr-dev \
    libxinerama-dev \
    libxcursor-dev \
    libxi-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libwayland-dev \
    libxkbcommon-dev \
    libegl1-mesa-dev \
    libgbm-dev \
    && rm -rf /var/lib/apt/lists/*

# Install Vulkan SDK components
RUN apt-get update && apt-get install -y \
    vulkan-tools \
    libvulkan-dev \
    vulkan-validationlayers \
    && rm -rf /var/lib/apt/lists/*

# Install vcpkg
WORKDIR /opt
RUN git clone https://github.com/Microsoft/vcpkg.git && \
    cd vcpkg && \
    ./bootstrap-vcpkg.sh && \
    mkdir -p /opt/vcpkg/archives && \
    ln -s /opt/vcpkg/vcpkg /usr/local/bin/vcpkg

ENV VCPKG_ROOT=/opt/vcpkg
ENV PATH="${VCPKG_ROOT}:${PATH}"
ENV VCPKG_DEFAULT_BINARY_CACHE="${VCPKG_ROOT}/archives"

# Set working directory
WORKDIR /workspace

# Copy project files
COPY . .

# Configure and build using CMake preset
# Default to release build, can be overridden with --build-arg
# Use BuildKit cache mount for vcpkg binary cache to speed up builds
ARG BUILD_PRESET=arm64-rpi5-ninja-release
RUN --mount=type=cache,target=/opt/vcpkg/archives,sharing=locked \
    --mount=type=cache,target=/root/.cache/vcpkg,sharing=locked \
    cmake --preset ${BUILD_PRESET}

# Build the project
RUN --mount=type=cache,target=/opt/vcpkg/archives,sharing=locked \
    --mount=type=cache,target=/root/.cache/vcpkg,sharing=locked \
    cmake --build --preset ${BUILD_PRESET} -j$(nproc)

# Runtime stage (optional, for smaller final image)
FROM --platform=linux/arm64 ubuntu:22.04 AS runtime

# Install only runtime dependencies
RUN apt-get update && apt-get install -y \
    libvulkan1 \
    libwayland-client0 \
    libx11-6 \
    libxrandr2 \
    libxinerama1 \
    libxcursor1 \
    libxi6 \
    && rm -rf /var/lib/apt/lists/*

# Copy built artifacts from builder stage
WORKDIR /app
ARG BUILD_PRESET=arm64-rpi5-ninja-release
COPY --from=builder /workspace/build ./build

# Set environment variables
ENV LD_LIBRARY_PATH=/app/build

CMD ["/bin/bash"]
