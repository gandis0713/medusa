# Multi-stage Dockerfile for Raspberry Pi 5 (x64) compilation
FROM --platform=linux/amd64 ubuntu:22.04 AS builder

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
    ln -s /opt/vcpkg/vcpkg /usr/local/bin/vcpkg

ENV VCPKG_ROOT=/opt/vcpkg
ENV PATH="${VCPKG_ROOT}:${PATH}"

# Set working directory
WORKDIR /workspace

# Copy project files
COPY . .

# Configure and build using CMake preset
# Default to release build, can be overridden with --build-arg
ARG BUILD_PRESET=x64-rpi5-ninja-release
RUN cmake --preset ${BUILD_PRESET}

# Build the project
RUN cmake --build --preset ${BUILD_PRESET} -j$(nproc)

# Runtime stage (optional, for smaller final image)
FROM --platform=linux/amd64 ubuntu:22.04 AS runtime

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
ARG BUILD_PRESET=x64-rpi5-ninja-release
COPY --from=builder /workspace/build ./build
COPY --from=builder /workspace/install ./install

# Set environment variables
ENV LD_LIBRARY_PATH=/app/build:$LD_LIBRARY_PATH

CMD ["/bin/bash"]
