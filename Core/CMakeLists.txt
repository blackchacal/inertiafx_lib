include(FetchContent)
FetchContent_Declare(
    eigen
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG 3.4.0
)  
FetchContent_MakeAvailable(eigen)

# Add the include directory (for headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Inc)

# Set the source folder
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Src)
# Recursively collect all .cpp files in the source folder and subfolders
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")

# Add the source files for the Core module
add_library(CoreLib ${SOURCES})

target_sources(CoreLib PRIVATE ${SOURCES})
target_link_libraries(CoreLib PUBLIC Eigen3::Eigen ReportsLib)

# Specify public include directories so other modules can access Core's headers
target_include_directories(CoreLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc ${PROJECT_BINARY_DIR} ${EIGEN3_INCLUDE_DIR})