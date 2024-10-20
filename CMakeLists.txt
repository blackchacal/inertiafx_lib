cmake_minimum_required(VERSION 3.22)

project(InertiaFX VERSION 0.1.0 DESCRIPTION "Physics Engine" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD ${ROOT_CXX_STANDARD})
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Core)
add_subdirectory(Reports)

add_executable(inertiafx main.cpp)

target_link_libraries(inertiafx PRIVATE CoreLib ReportsLib)

configure_file(Core/Inc/InertiaFXConfig.h InertiaFX.h)

