# CMake project settings
cmake_minimum_required( VERSION 3.15 )

project( arsenalgear-cpp
    VERSION 1.0
    DESCRIPTION "Build system for arsenalgear-cpp."
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

# Fetching dependencies
add_subdirectory( deps )

# Include directories
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include )

# Create static library
add_library( arsenalgear STATIC
    src/stream.cpp
    src/system.cpp
    src/utils.cpp
)
add_library( arsenalgear::arsenalgear ALIAS arsenalgear )

# Compile tests
option( ARSENALGEAR_TESTS "Enable / disable tests." ON )
if( ARSENALGEAR_TESTS )
    add_subdirectory( test )
else()
    message( STATUS "Skipping tests." )
endif()

# Setting installation paths
target_include_directories( arsenalgear INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

install(
    DIRECTORY include/arsenalgear
    DESTINATION include
)

# Creating the package files
install( 
    TARGETS arsenalgear
    EXPORT arsenalgearTargets
    DESTINATION lib
)

install(
    EXPORT arsenalgearTargets
    FILE arsenalgearTargets.cmake
    NAMESPACE arsenalgear::
    DESTINATION lib/cmake/arsenalgear
)

# Configure package files
include( CMakePackageConfigHelpers )

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/arsenalgearConfig.cmake"
    INSTALL_DESTINATION "lib/cmake/arsenalgear"
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/arsenalgearConfigVersion.cmake"
  VERSION "${Tutorial_VERSION_MAJOR}.${Tutorial_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion
)

install( FILES
    ${CMAKE_CURRENT_BINARY_DIR}/arsenalgearConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/arsenalgearConfigVersion.cmake
    DESTINATION lib/cmake/arsenalgear
)

export( EXPORT arsenalgearTargets
    FILE "${CMAKE_CURRENT_BINARY_DIR}/arsenalgearTargets.cmake"
)