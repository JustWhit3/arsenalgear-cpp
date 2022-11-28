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
./build/test/system_tests/containers
./build/test/system_tests/math
./build/test/system_tests/operators
./build/test/system_tests/stream
./build/test/system_tests/system
./build/test/system_tests/type
./build/test/system_tests/utils

# Memory tests
echo ""
echo "======================================================"
echo "     MEMORY TESTS"
echo "======================================================"
./test/profiling.sh memcheck ./build/test/system_tests/containers
./test/profiling.sh memcheck ./build/test/system_tests/math
./test/profiling.sh memcheck ./build/test/system_tests/operators
./test/profiling.sh memcheck ./build/test/system_tests/stream
./test/profiling.sh memcheck ./build/test/system_tests/system
./test/profiling.sh memcheck ./build/test/system_tests/type

# Threading tests
echo ""
echo "======================================================"
echo "     THREADING TESTS"
echo "======================================================"
echo ""
./test/profiling.sh helgrind ./build/test/system_tests/containers
./test/profiling.sh helgrind ./build/test/system_tests/math
./test/profiling.sh helgrind ./build/test/system_tests/operators
./test/profiling.sh helgrind ./build/test/system_tests/stream
./test/profiling.sh helgrind ./build/test/system_tests/system
./test/profiling.sh helgrind ./build/test/system_tests/type
./test/profiling.sh helgrind ./build/test/system_tests/utils

# Unit tests
echo ""
echo "======================================================"
echo "     UNIT TESTS"
echo "======================================================"
echo ""
./bin/test/unit_tests/unit_tests

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

# Cppcheck
echo ""
echo "======================================================"
echo "     CPPCHECK TESTS"
echo "======================================================"
echo ""
cppcheck include/* src/*
