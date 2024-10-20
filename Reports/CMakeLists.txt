# include(FetchContent)
# FetchContent_Declare(
#     root
#     GIT_REPOSITORY https://github.com/root-project/root.git
#     GIT_TAG v6-32-06
# )
# FetchContent_MakeAvailable(root)

set(ROOT_DIR "~/Documentos/progs/root/cmake")
find_package(ROOT REQUIRED COMPONENTS Gpad)

# Add the include directory (for headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Inc)

# Set the source folder
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Src)
# Recursively collect all .cpp files in the source folder and subfolders
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")

# Add the source files for the Core module
add_library(ReportsLib ${SOURCES})

target_sources(ReportsLib PUBLIC ${SOURCES})
target_link_libraries(ReportsLib PUBLIC CoreLib ROOT::Gpad)

# Specify public include directories so other modules can access the module headers
target_include_directories(ReportsLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc ${PROJECT_BINARY_DIR})
target_include_directories(ReportsLib PRIVATE ${ROOT_INCLUDE_DIRS})
