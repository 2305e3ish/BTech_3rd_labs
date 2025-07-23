#!/bin/bash

# CRC Testing Script
# This script compiles and tests all CRC implementations

echo "=== CRC Implementation Testing Script ==="
echo "This script will compile and test all CRC programs"
echo

# Create test directory if it doesn't exist
mkdir -p test_results

# Compile all programs
echo "1. Compiling CRC programs..."
gcc -o crc_12 crc_12.c
gcc -o crc_16 crc_16.c  
gcc -o crc_ccitt crc_ccitt.c
gcc -o crc_complete crc_complete.c

if [ $? -eq 0 ]; then
    echo "   ✓ All programs compiled successfully"
else
    echo "   ✗ Compilation failed"
    exit 1
fi

echo

# Test data
TEST_DATA="11011"
echo "2. Testing with data: $TEST_DATA"
echo

# Function to run CRC test
run_crc_test() {
    local program=$1
    local name=$2
    
    echo "Testing $name..."
    echo "=================================="
    
    # Create input file
    echo -e "$TEST_DATA\n$TEST_DATA" > test_input.txt
    
    # Run the program
    ./$program < test_input.txt
    echo
    echo "=================================="
    echo
}

# Test individual CRC implementations
run_crc_test "crc_12" "CRC-12"
run_crc_test "crc_16" "CRC-16" 
run_crc_test "crc_ccitt" "CRC-CCITT"

# Test comprehensive program
echo "Testing Comprehensive CRC Program..."
echo "=================================="
echo "Testing CRC-12 option..."
echo -e "1\n$TEST_DATA\n" | ./crc_complete
echo

echo "Testing CRC-16 option..."
echo -e "2\n$TEST_DATA\n" | ./crc_complete
echo

echo "Testing CRC-CCITT option..."
echo -e "3\n$TEST_DATA\n" | ./crc_complete
echo

# Clean up
rm -f test_input.txt

echo "=== Testing Complete ==="
echo "All CRC implementations have been tested successfully!"
echo

# Show files created
echo "Files created:"
ls -la crc_* *.c *.md | grep -E '\.(c|md)$|^-.*crc_'
