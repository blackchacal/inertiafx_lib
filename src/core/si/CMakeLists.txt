cmake_minimum_required(VERSION 3.22)
project(SI)

add_library(SI STATIC)
target_sources(SI PRIVATE
    src/decimal_prefix.cpp

    # Physical Units
    src/physical_unit.cpp
    src/derived_physical_unit.cpp
    src/metre.cpp
    src/second.cpp
    src/kilogram.cpp
    src/ampere.cpp
    src/kelvin.cpp
    src/mole.cpp
    src/candela.cpp
    src/newton.cpp
    src/pascal.cpp

    # Fundamental Quantities
    src/length.cpp
    src/si_time.cpp
    src/mass.cpp
    
    # Derived Scalar Quantities
    src/volume.cpp
    src/density.cpp
    src/temperature.cpp

    # Derived Vector Quantities
    src/position.cpp
    src/velocity.cpp
    src/acceleration.cpp
    src/force.cpp
    src/pressure.cpp
)

add_subdirectory(tests)

target_include_directories(SI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

install(TARGETS SI DESTINATION lib)
install(DIRECTORY inc/ DESTINATION include)