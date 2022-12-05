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

# Include directories
include_directories( . )

# Compile tests
add_subdirectory( test )

# Create static library
file( GLOB source src/*cpp )
add_library( arsenalgear STATIC ${source} )
add_library( arsenalgear::arsenalgear ALIAS arsenalgear )

# Compiling with the right standard
set_property( TARGET arsenalgear PROPERTY CXX_STANDARD 17 )
set_property( TARGET arsenalgear PROPERTY CXX_STANDARD_REQUIRED ON )

# Installing headers
if( UNIX )
    set( INSTALLATION_DIR_INCLUDE /usr/include )
elseif( APPLE )
    set( INSTALLATION_DIR_INCLUDE /usr/local/include )
elseif( WIN32 )
    set( WIN_INSTALLATION_DIR_INCLUDE "" CACHE STRING "Installation directory for Windows OSs." )
    set( INSTALLATION_DIR_INCLUDE ${WIN_INSTALLATION_DIR_INCLUDE} )
endif()

file( GLOB INCLUDE_FILES include/*.hpp )
INSTALL(
    FILES ${INCLUDE_FILES}
    DESTINATION ${INSTALLATION_DIR_INCLUDE}/arsenalgear
)

# Installing libraries
if( UNIX )
    set( INSTALLATION_DIR_LIB /usr/lib )
elseif( APPLE )
    set( INSTALLATION_DIR_LIB /usr/local/lib )
elseif( WIN32 )
    set( WIN_INSTALLATION_DIR_LIB "" CACHE STRING "Installation directory for Windows OSs." )
    set( INSTALLATION_DIR_LIB ${WIN_INSTALLATION_DIR_LIB} )
endif()

# Creating the package files
install( 
    TARGETS arsenalgear
    EXPORT arsenalgearTargets
    DESTINATION ${INSTALLATION_DIR_LIB}
)

install(
    EXPORT arsenalgearTargets
    FILE arsenalgearTargets.cmake
    NAMESPACE arsenalgear::
    DESTINATION ${INSTALLATION_DIR_LIB}/cmake/arsenalgear
)

# Configure package files
include( CMakePackageConfigHelpers )

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/arsenalgearConfig.cmake"
    INSTALL_DESTINATION "${INSTALLATION_DIR_LIB}/cmake/arsenalgear"
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
    DESTINATION ${INSTALLATION_DIR_LIB}/cmake/arsenalgear
)

export( EXPORT arsenalgearTargets
    FILE "${CMAKE_CURRENT_BINARY_DIR}/arsenalgearTargets.cmake"
)