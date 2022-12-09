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

# Set c++ standard options
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

# Other settings for paths
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../../include )

# Declare executables vars
if( WIN32 )
    set( UNIT "unit_tests.exe" )
else()
    set( UNIT "unit_tests" )
endif()

# Create executables
#add_executable( ${UNIT} 
#    tests_containers.cpp 
#    tests_operators.cpp 
#    tests_type.cpp 
#    tests_math.cpp 
#    tests_utils.cpp 
#    tests_stream.cpp 
#    tests_system.cpp
#)
add_executable( ${UNIT} 
    tests_containers.cpp 
)

# Adding specific compiler flags
if( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )
    set( COMPILE_FLAGS "/Wall /Yd" )
else()
    set( COMPILE_FLAGS "-Wall -Wextra -pedantic" )
endif()
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

# Linking to libraries
find_package( doctest )
target_link_libraries( ${UNIT} PRIVATE doctest::doctest )
target_link_libraries( ${UNIT} PRIVATE arsenalgear::arsenalgear )