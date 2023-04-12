#!/bin/bash

# Compiling
echo ""
echo "======================================================"
echo "     Compiling"
echo "======================================================"
echo ""
cmake -B build
cmake --build build

# System tests
echo ""
./build/test/system_tests/arsenalgear_containers
./build/test/system_tests/arsenalgear_math
./build/test/system_tests/arsenalgear_operators
./build/test/system_tests/arsenalgear_stream
./build/test/system_tests/arsenalgear_system
./build/test/system_tests/arsenalgear_type
./build/test/system_tests/arsenalgear_utils

# Memory tests
echo ""
echo "======================================================"
echo "     MEMORY TESTS"
echo "======================================================"
./test/profiling.sh memcheck ./build/test/system_tests/arsenalgear_containers
./test/profiling.sh memcheck ./build/test/system_tests/arsenalgear_math
./test/profiling.sh memcheck ./build/test/system_tests/arsenalgear_operators
./test/profiling.sh memcheck ./build/test/system_tests/arsenalgear_stream
./test/profiling.sh memcheck ./build/test/system_tests/arsenalgear_system
./test/profiling.sh memcheck ./build/test/system_tests/arsenalgear_type

# Threading tests
echo ""
echo "======================================================"
echo "     THREADING TESTS"
echo "======================================================"
echo ""
./test/profiling.sh helgrind ./build/test/system_tests/arsenalgear_containers
./test/profiling.sh helgrind ./build/test/system_tests/arsenalgear_math
./test/profiling.sh helgrind ./build/test/system_tests/arsenalgear_operators
./test/profiling.sh helgrind ./build/test/system_tests/arsenalgear_stream
./test/profiling.sh helgrind ./build/test/system_tests/arsenalgear_system
./test/profiling.sh helgrind ./build/test/system_tests/arsenalgear_type
./test/profiling.sh helgrind ./build/test/system_tests/arsenalgear_utils

# Unit tests
echo ""
echo "======================================================"
echo "     UNIT TESTS"
echo "======================================================"
echo ""
./build/test/unit_tests/arsenalgear_unit_tests

# Include tests
echo ""
echo "======================================================"
echo "     INCLUDE TESTS"
echo "======================================================"
echo ""
./test/include_tests.sh constants.hpp
./test/include_tests.sh containers.hpp
./test/include_tests.sh math.hpp
./test/include_tests.sh operators.hpp
./test/include_tests.sh stream.hpp
./test/include_tests.sh system.hpp
./test/include_tests.sh type.hpp
./test/include_tests.sh utils.hpp

