cmake_minimum_required(VERSION 3.22)
project(SI_UnitTests)

add_executable(SI_UnitTests
    # Test general classes
    test_decimal_prefix.cpp

    # Test physical units
    test_metre.cpp
    test_second.cpp
    test_kilogram.cpp
    test_ampere.cpp
    test_kelvin.cpp
    test_mole.cpp
    test_candela.cpp
    test_newton.cpp
    
    # Test fundamental quantities
    test_length.cpp
    test_mass.cpp
    test_time.cpp

    # Test derived scalar quantities
    test_volume.cpp

    # Test derived vector quantities
    test_position.cpp
    test_velocity.cpp
    test_acceleration.cpp
    test_force.cpp
)

target_link_libraries(SI_UnitTests PRIVATE
    gtest gtest_main
    Core
)

add_test(NAME SI_UnitTests COMMAND SI_UnitTests)