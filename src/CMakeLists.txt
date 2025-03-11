cmake_minimum_required(VERSION 3.22)
project(InertiaFX)

# Add Core module
add_subdirectory(core)

# Add physics modules
add_subdirectory(newtonian_mechanics)
# add_subdirectory(AnalyticalMechanics)   # Future modules
# add_subdirectory(Electromagnetism)

# Add root-level sources to Core
target_sources(Core PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inertiafx.cpp
)

# Ensure root-level headers are available globally
target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

