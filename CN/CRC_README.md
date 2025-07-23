# CRC (Cyclic Redundancy Check) Implementation

## Overview
This repository contains implementations of three different CRC algorithms used for error detection in data transmission:

1. **CRC-12**: 12-bit CRC with polynomial x^12 + x^11 + x^3 + x^2 + x + 1
2. **CRC-16**: 16-bit CRC with polynomial x^16 + x^15 + x^2 + 1
3. **CRC-CCITT**: 16-bit CRC with polynomial x^16 + x^12 + x^5 + 1

## Algorithm Explanation

### How CRC Works:
1. **Sender Side:**
   - Append n zeros to the original data (where n is the degree of the polynomial)
   - Divide the augmented data by the generator polynomial using binary division
   - The remainder becomes the CRC checksum
   - Transmit original data + CRC checksum

2. **Receiver Side:**
   - Receive the data (original + CRC)
   - Divide the received data by the same generator polynomial
   - If remainder is zero → No error detected
   - If remainder is non-zero → Error detected

### Binary Division:
- Uses XOR operation instead of subtraction
- Continue division until remainder is smaller than divisor
- The final remainder is the CRC code

## Files Description

### 1. `crc_complete.c` - Comprehensive Implementation
- Interactive program supporting all three CRC types
- Menu-driven interface
- Detailed step-by-step output
- Supports custom input data
- Automatic verification

### 2. `crc_12.c` - CRC-12 Implementation
- Polynomial: x^12 + x^11 + x^3 + x^2 + x + 1
- Binary: 1100000001011
- 12-bit checksum

### 3. `crc_16.c` - CRC-16 Implementation
- Polynomial: x^16 + x^15 + x^2 + 1
- Binary: 10001000000100001
- 16-bit checksum

### 4. `crc_ccitt.c` - CRC-CCITT Implementation
- Polynomial: x^16 + x^12 + x^5 + 1
- Binary: 10001000000100001
- 16-bit checksum

## Compilation Instructions

```bash
# Compile individual programs
gcc -o crc_12 crc_12.c
gcc -o crc_16 crc_16.c
gcc -o crc_ccitt crc_ccitt.c

# Compile comprehensive program
gcc -o crc_complete crc_complete.c
```

## Usage Examples

### Running CRC-12:
```bash
./crc_12
```
**Input:**
```
Enter transferred data (binary): 11011
Enter received data (binary): 11011
```

### Running CRC-16:
```bash
./crc_16
```
**Input:**
```
Enter transferred data (binary): 11011
Enter received data (binary): 11011
```

### Running Comprehensive Program:
```bash
./crc_complete
```
**Sample Session:**
```
=== CRC Implementation Program ===
This program implements three CRC algorithms:
1. CRC-12  (x^12 + x^11 + x^3 + x^2 + x + 1)
2. CRC-16  (x^16 + x^15 + x^2 + 1)
3. CRC-CCITT (x^16 + x^12 + x^5 + 1)
4. Test all three CRC methods
Enter your choice (1-4): 1

Enter data to transmit (binary string): 11011
```

## Sample Output

### CRC-16 Example:
```
=== CRC-16 Implementation ===
Polynomial: x^16 + x^15 + x^2 + 1
Binary representation: 10001000000100001

Enter transferred data (binary): 11011
Enter received data (binary): 11011

Sender Side - Computing CRC:
10001000000100001 ) 110110000000000000000 (
                    10001000000100001
                    -----------------
                    10100000001000010
                    10001000000100001
                    -----------------
                    10100000110001100
                    10001000000100001
                    -----------------
                    1010001101011010
                    -----------------

CRC-16 checksum: 1010001101011010
Transmitted data: 110111010001101011010

Receiver Side - Verifying Data:
10001000000100001 ) 110111010001101011010 (
                    10001000000100001
                    -----------------
                    10101010000101001
                    10001000000100001
                    -----------------
                    10001000000100001
                    10001000000100001
                    -----------------
                    00000000000000000
                    -----------------

✓ Data transferred correctly
```

## Key Features

1. **Error Detection**: Detects single-bit and burst errors
2. **Polynomial Division**: Implements binary polynomial division
3. **Multiple Standards**: Supports industry-standard CRC polynomials
4. **Interactive Interface**: User-friendly input/output
5. **Verification**: Automatic sender/receiver verification

## Mathematical Background

### CRC Polynomials:
- **CRC-12**: x^12 + x^11 + x^3 + x^2 + x + 1 = 1100000001011
- **CRC-16**: x^16 + x^15 + x^2 + 1 = 10001000000100001
- **CRC-CCITT**: x^16 + x^12 + x^5 + 1 = 10001000000100001

### Binary Arithmetic:
- Addition: XOR operation
- Subtraction: XOR operation
- Multiplication: Shift and XOR

## Applications

1. **Network Communication**: Ethernet, WiFi
2. **Storage Systems**: Hard drives, CDs, DVDs
3. **Data Transmission**: Serial communication, modems
4. **Error Detection**: File integrity checking

## Notes

- CRC detects errors but cannot correct them
- Different polynomials provide different error detection capabilities
- CRC-16 and CRC-CCITT use the same polynomial in this implementation
- The algorithm assumes binary input data

## Author
BTech 3rd Year - Computer Networks Laboratory
