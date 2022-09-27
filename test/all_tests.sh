#!/bin/bash

# Compiling
echo ""
echo "======================================================"
echo "     Compiling"
echo "======================================================"
echo ""
make

# System tests
echo ""
./bin/containers
./bin/math
./bin/operators
./bin/stream
./bin/system
./bin/type
./bin/utils

# Memory tests
echo ""
echo "======================================================"
echo "     MEMORY TESTS"
echo "======================================================"
./test/profiling.sh memcheck ./bin/containers
./test/profiling.sh memcheck ./bin/math
./test/profiling.sh memcheck ./bin/operators
./test/profiling.sh memcheck ./bin/stream
./test/profiling.sh memcheck ./bin/system
./test/profiling.sh memcheck ./bin/type

# Threading tests
echo ""
echo "======================================================"
echo "     THREADING TESTS"
echo "======================================================"
echo ""
./test/profiling.sh helgrind ./bin/containers
./test/profiling.sh helgrind ./bin/math
./test/profiling.sh helgrind ./bin/operators
./test/profiling.sh helgrind ./bin/stream
./test/profiling.sh helgrind ./bin/system
./test/profiling.sh helgrind ./bin/type
./test/profiling.sh helgrind ./bin/utils

# Unit tests
echo ""
echo "======================================================"
echo "     UNIT TESTS"
echo "======================================================"
echo ""
./bin/tests

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
cppcheck include/* src*
