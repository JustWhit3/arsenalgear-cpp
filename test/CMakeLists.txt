# CMake project settings
cmake_minimum_required( VERSION 3.15 )

project( arsenalgear-cpp-tests
    VERSION 1.0
    DESCRIPTION "Build system for arsenalgear-cpp tests."
    LANGUAGES CXX
)

# Error if building out of a build directory
file( TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH )
if( EXISTS "${LOC_PATH}" )
    message( FATAL_ERROR "You cannot build in a source directory (or any directory with "
                         "CMakeLists.txt file). Please make a build subdirectory. Feel free to "
                         "remove CMakeCache.txt and CMakeFiles." )
endif()

# Launch system and unit tests
add_subdirectory( system_tests )
#add_subdirectory( unit_tests )#