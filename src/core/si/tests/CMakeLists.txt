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
    
    # Test fundamental quantities
    test_length.cpp
    test_mass.cpp
    test_time.cpp

    # Test derived quantities
    test_derived_qtys.cpp
)

target_link_libraries(SI_UnitTests PRIVATE
    gtest gtest_main
    Core
)

add_test(NAME SI_UnitTests COMMAND SI_UnitTests)