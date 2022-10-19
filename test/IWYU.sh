#!/bin/bash

# Variables
declare -a header_files=(
    "constants.hpp"
    "containers.hpp"
    "math.hpp"
    "operators.hpp"
    "stream.hpp"
    "system.hpp"
    "type.hpp"
    "utils.hpp"
)

declare -a source_files=(
    "stream.cpp"
    "system.cpp"
    "utils.cpp"
)

# Header files check
echo ""
echo "======================================================"
echo "     Header files check"
echo "======================================================"
echo ""
for header in "${header_files[@]}"
do
    include-what-you-use \
    -std=c++17 \
    -I/usr/lib/llvm-14/lib/clang/14.0.0/include \
    include/"$header"

    echo ""
    echo "--------------------------------------------------"
    echo ""
done

# Source code check
echo ""
echo "======================================================"
echo "     Source code check"
echo "======================================================"
echo ""
for source in "${source_files[@]}"
do
    include-what-you-use \
    -std=c++17 \
    -I/usr/lib/llvm-14/lib/clang/14.0.0/include \
    src/"$source"

    echo ""
    echo "--------------------------------------------------"
    echo ""
done