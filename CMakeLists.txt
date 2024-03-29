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

include(GNUInstallDirs)

# Include directories
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include )

# Create static library
add_library( arsenalgear
    src/stream.cpp
    src/system.cpp
    src/utils.cpp
)
add_library( arsenalgear::arsenalgear ALIAS arsenalgear )

# Set c++ standard options
target_compile_features(arsenalgear PUBLIC cxx_std_17)

# Export symbols for Visual Studio in case of shared lib
set_target_properties(arsenalgear PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Adding specific compiler flags
if( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )
    set( COMPILE_FLAGS "/Wall /Yd" )
else()
    if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
        set( COMPILE_FLAGS "-Wall -Wextra -pedantic -Wno-reorder -g" )
    else()
        set( COMPILE_FLAGS "-Wall -Wextra -pedantic -Wno-reorder" )
    endif()
endif()
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}" )

# Adding cppcheck properties
if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    set( cppcheck cppcheck "--enable=warning" "--inconclusive" "--force" "--inline-suppr" )
    set_target_properties( arsenalgear PROPERTIES CXX_CPPCHECK ${cppcheck})
endif()

# Compile tests
option( ARSENALGEAR_TESTS "Enable / disable tests." ON )
if( ARSENALGEAR_TESTS )
    # Fetching dependencies
    add_subdirectory( deps )
    
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
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Creating the package files
install( 
    TARGETS arsenalgear
    EXPORT arsenalgearTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
    EXPORT arsenalgearTargets
    FILE arsenalgearTargets.cmake
    NAMESPACE arsenalgear::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/arsenalgear
)

# Configure package files
include( CMakePackageConfigHelpers )

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/arsenalgearConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/arsenalgear"
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
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/arsenalgear
)

export( EXPORT arsenalgearTargets
    FILE "${CMAKE_CURRENT_BINARY_DIR}/arsenalgearTargets.cmake"
)