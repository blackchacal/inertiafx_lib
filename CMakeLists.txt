cmake_minimum_required(VERSION 3.22)

project(InertiaFX VERSION 0.1.0 DESCRIPTION "Physics Engine" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.1.1
)     
FetchContent_MakeAvailable(fmt)

add_executable(inertiafx main.cpp)
target_link_libraries(inertiafx PRIVATE fmt::fmt)

target_include_directories(inertiafx PUBLIC "${PROJECT_BINARY_DIR}")
configure_file(Core/Inc/InertiaFXConfig.h InertiaFX.h)

