cmake_minimum_required(VERSION 3.24)
project(Core)

# Define the Core static library
add_library(Core STATIC)
target_sources(Core PRIVATE
    core.cpp
)

include(FetchContent)

# Fetch GoogleTest if not installed
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add submodules
add_subdirectory(tools)
add_subdirectory(si)
add_subdirectory(engine)

# Collect all public headers
target_include_directories(Core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/tools/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/si/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/engine/inc
)

# Link submodules into Core
target_link_libraries(Core PRIVATE Engine SI Tools)

# Install Core library
install(TARGETS Core DESTINATION lib)
install(DIRECTORY tools/inc DESTINATION include)
install(DIRECTORY si/inc DESTINATION include)
install(DIRECTORY engine/inc DESTINATION include)