#!/bin/bash
# Build and run C++ tests with CMake and Google Test
set -e

# Configure the project
cmake -S . -B build

# Build the project
cmake --build build

# Run tests
cd build
ctest --output-on-failure
