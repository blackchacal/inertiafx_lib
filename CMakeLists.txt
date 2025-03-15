cmake_minimum_required(VERSION 3.22)

project(InertiaFX VERSION 0.1.0 DESCRIPTION "Physics Simulation Library" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define macro INERTIAFX_VERSION to use in code
add_definitions(-DINERTIAFX_VERSION="@InertiaFX_VERSION_MAJOR@.@InertiaFX_VERSION_MINOR@.@InertiaFX_VERSION_PATCH")

add_compile_options(/utf-8)

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Enable unit testing
enable_testing()

# Add Source Folder
add_subdirectory(src)

# Add Unit Tests
add_subdirectory(tests)

