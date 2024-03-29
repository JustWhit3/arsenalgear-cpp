# CMake project settings
cmake_minimum_required( VERSION 3.15 )

project( arsenalgear-cpp-system-tests
    VERSION 1.0
    DESCRIPTION "Build system for arsenalgear-cpp system tests."
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
set( CONTAINERS "arsenalgear_containers" )
set( MATH "arsenalgear_math" )
set( OPERATORS "arsenalgear_operators" )
set( STREAM "arsenalgear_stream" )
set( SYSTEM "arsenalgear_system" )
set( TYPE "arsenalgear_type" )
set( UTILS "arsenalgear_utils" )

# Create executables
add_executable( ${CONTAINERS} containers.cpp )
add_executable( ${MATH} math.cpp )
add_executable( ${OPERATORS} operators.cpp )
add_executable( ${TYPE} type.cpp )
add_executable( ${STREAM} stream.cpp )
add_executable( ${SYSTEM} system.cpp )
add_executable( ${UTILS} utils.cpp )

# Adding specific compiler flags
if( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )
    set( COMPILE_FLAGS "/Wall /Yd" )
else()
    set( COMPILE_FLAGS "-Wall -Wextra -pedantic" )
endif()
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

# Adding specific linker flags
target_link_libraries( ${STREAM} PRIVATE arsenalgear::arsenalgear )
target_link_libraries( ${SYSTEM} PRIVATE arsenalgear::arsenalgear )
target_link_libraries( ${UTILS} PRIVATE arsenalgear::arsenalgear )