cmake_minimum_required(VERSION 3.22)
project(Core)

# Define the Core static library
add_library(Core STATIC)
target_sources(Core PRIVATE
    core.cpp
)

# Add submodules
# add_subdirectory(tools)
add_subdirectory(si)
# add_subdirectory(engine)

# Collect all public headers
target_include_directories(Core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/tools/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/si/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/engine/Inc
)

# Link submodules into Core
target_link_libraries(Core PRIVATE SI)

# Install Core library
install(TARGETS Core DESTINATION lib)
install(DIRECTORY tools/Inc DESTINATION include)
install(DIRECTORY si/Inc DESTINATION include)
install(DIRECTORY engine/Inc DESTINATION include)