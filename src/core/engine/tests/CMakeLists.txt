cmake_minimum_required(VERSION 3.22)
project(Engine_UnitTests)

add_executable(Engine_UnitTests
    test_point_mass.cpp
)

target_link_libraries(Engine_UnitTests PRIVATE
    gtest gtest_main
    Core
)

add_test(NAME Engine_UnitTests COMMAND Engine_UnitTests)