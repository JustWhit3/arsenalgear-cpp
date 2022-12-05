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

# Other settings for paths
include_directories( ../.. )

# Declare executables vars
if( WIN32 )
    set( CONTAINERS "containers.exe" )
    set( MATH "math.exe" )
    set( OPERATORS "operators.exe" )
    set( STREAM "stream.exe" )
    set( SYSTEM "system.exe" )
    set( TYPE "type.exe" )
    set( UTILS "utils.exe" )
else()
    set( CONTAINERS "containers" )
    set( MATH "math" )
    set( OPERATORS "operators" )
    set( STREAM "stream" )
    set( SYSTEM "system" )
    set( TYPE "type" )
    set( UTILS "utils" )
endif()

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

# Compiling with the right standard
set_property( TARGET ${STREAM} PROPERTY CXX_STANDARD 17 )
set_property( TARGET ${SYSTEM} PROPERTY CXX_STANDARD 17 )
set_property( TARGET ${UTILS} PROPERTY CXX_STANDARD 17 )

# Adding specific linker flags
target_link_libraries( ${STREAM} PRIVATE arsenalgear::arsenalgear )
target_link_libraries( ${SYSTEM} PRIVATE arsenalgear::arsenalgear )
target_link_libraries( ${UTILS} PRIVATE arsenalgear::arsenalgear )