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
FetchContent_Declare(
    eigen
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG 3.4.0
)     
FetchContent_MakeAvailable(fmt eigen)

set(core_srcs "Core/Src/Engine.cpp" "Core/Src/World.cpp" "Core/Src/VacuumWorld.cpp" "Core/Src/Body.cpp" "Core/Src/Logger.cpp")
add_executable(inertiafx main.cpp ${core_srcs})
target_link_libraries(inertiafx PRIVATE fmt::fmt Eigen3::Eigen)

target_include_directories(inertiafx PUBLIC "${PROJECT_SOURCE_DIR}/Core/Inc" "${PROJECT_BINARY_DIR}" "${EIGEN3_INCLUDE_DIR}")
configure_file(Core/Inc/InertiaFXConfig.h InertiaFX.h)

