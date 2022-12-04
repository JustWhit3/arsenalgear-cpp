# CMake project settings
cmake_minimum_required( VERSION 3.15 )

project( arsenalgear-cpp-unit-tests
    VERSION 1.0
    DESCRIPTION "Build system for arsenalgear-cpp unit tests."
    LANGUAGES CXX
)

# Error if building out of a build directory
file( TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH )
if( EXISTS "${LOC_PATH}" )
    message( FATAL_ERROR "You cannot build in a source directory (or any directory with "
                         "CMakeLists.txt file). Please make a build subdirectory. Feel free to "
                         "remove CMakeCache.txt and CMakeFiles." )
endif()

# Set compiler options
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

# Other settings for paths
include_directories( ../.. )

# Declare executables vars
if( WIN32 )
    set( UNIT "unit_tests.exe" )
else()
    set( UNIT "unit_tests" )
endif()

# Create executables
file( GLOB source_tests *cpp )
add_executable( ${UNIT} ${source_tests} )

# Adding specific compiler flags
if( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )
    set( COMPILE_FLAGS "/Wall /Yd" )
else()
    set( COMPILE_FLAGS "-Wall -Wextra -pedantic" )
endif()
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

# Fetching doctest
find_package( doctest )

if( NOT doctest_FOUND )
    include(FetchContent)
    FetchContent_Declare(
      doctest
      GIT_REPOSITORY "https://github.com/doctest/doctest"
      GIT_TAG master
    )
    message( STATUS "Fetching doctest..." )
    FetchContent_MakeAvailable( doctest )
endif()

# Linking to libraries
target_link_libraries( ${UNIT} PRIVATE doctest::doctest )
target_link_libraries( ${UNIT} arsenalgear::arsenalgear )