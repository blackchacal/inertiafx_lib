cmake_minimum_required(VERSION 3.22)
project(SI_UnitTests)

add_executable(SI_UnitTests
    test_decimal_prefix.cpp
    test_physical_units.cpp
    test_fundamental_qtys.cpp
    test_derived_qtys.cpp
)

target_link_libraries(SI_UnitTests PRIVATE
    gtest gtest_main
    Core
)

add_test(NAME SI_UnitTests COMMAND SI_UnitTests)