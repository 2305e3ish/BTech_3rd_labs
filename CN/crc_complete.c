#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
void calculate_crc(const char* data, const char* polynomial, int crc_bits, const char* crc_name);
const char* binary_divide(const char* dividend, const char* divisor, int crc_bits);
const char* binary_xor(const char* a, const char* b, int len);
void print_division_step(const char* dividend, const char* divisor, const char* remainder);
int verify_crc(const char* received_data, const char* polynomial, int crc_bits);

// CRC Polynomials (in binary representation)
// CRC-12: x^12 + x^11 + x^3 + x^2 + x + 1 = 1100000001011
const char* CRC_12_POLY = "1100000001011";      // 13 bits (degree 12)

// CRC-16: x^16 + x^15 + x^2 + 1 = 10001000000100001  
const char* CRC_16_POLY = "10001000000100001";  // 17 bits (degree 16)

// CRC-CCITT: x^16 + x^12 + x^5 + 1 = 10001000000100001
const char* CRC_CCITT_POLY = "10001000000100001"; // 17 bits (degree 16)

int main() {
    char input_data[100];
    char received_data[100];
    int choice;
    
    printf("=== CRC Implementation Program ===\n");
    printf("This program implements three CRC algorithms:\n");
    printf("1. CRC-12  (x^12 + x^11 + x^3 + x^2 + x + 1)\n");
    printf("2. CRC-16  (x^16 + x^15 + x^2 + 1)\n");
    printf("3. CRC-CCITT (x^16 + x^12 + x^5 + 1)\n");
    printf("4. Test all three CRC methods\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    
    printf("\nEnter data to transmit (binary string): ");
    scanf("%s", input_data);
    
    switch(choice) {
        case 1:
            printf("\n=== CRC-12 Implementation ===\n");
            calculate_crc(input_data, CRC_12_POLY, 12, "CRC-12");
            break;
            
        case 2:
            printf("\n=== CRC-16 Implementation ===\n");
            calculate_crc(input_data, CRC_16_POLY, 16, "CRC-16");
            break;
            
        case 3:
            printf("\n=== CRC-CCITT Implementation ===\n");
            calculate_crc(input_data, CRC_CCITT_POLY, 16, "CRC-CCITT");
            break;
            
        case 4:
            printf("\n=== Testing All CRC Methods ===\n");
            calculate_crc(input_data, CRC_12_POLY, 12, "CRC-12");
            printf("\n" + ('=' * 50) + "\n");
            calculate_crc(input_data, CRC_16_POLY, 16, "CRC-16");
            printf("\n" + ('=' * 50) + "\n");
            calculate_crc(input_data, CRC_CCITT_POLY, 16, "CRC-CCITT");
            break;
            
        default:
            printf("Invalid choice! Exiting...\n");
            return 1;
    }
    
    return 0;
}

void calculate_crc(const char* data, const char* polynomial, int crc_bits, const char* crc_name) {
    char augmented_data[200];
    char transmitted_data[200];
    char received_data[200];
    char crc_code[50];
    
    printf("\n--- %s Calculation ---\n", crc_name);
    printf("Polynomial: %s\n", polynomial);
    printf("Original data: %s\n", data);
    
    // Step 1: Append zeros to data
    strcpy(augmented_data, data);
    for(int i = 0; i < crc_bits; i++) {
        strcat(augmented_data, "0");
    }
    
    printf("Data with %d appended zeros: %s\n", crc_bits, augmented_data);
    
    // Step 2: Perform polynomial division
    printf("\nPerforming polynomial division:\n");
    printf("%s ) %s\n", polynomial, augmented_data);
    
    const char* remainder = binary_divide(augmented_data, polynomial, crc_bits);
    
    // Step 3: Pad CRC code if necessary
    strcpy(crc_code, "");
    int rem_len = strlen(remainder);
    for(int i = rem_len; i < crc_bits; i++) {
        strcat(crc_code, "0");
    }
    strcat(crc_code, remainder);
    
    printf("\n%s checksum: %s\n", crc_name, crc_code);
    
    // Step 4: Create transmitted data
    strcpy(transmitted_data, data);
    strcat(transmitted_data, crc_code);
    printf("Transmitted data (original + CRC): %s\n", transmitted_data);
    
    // Step 5: Verification
    printf("\n--- Receiver Side Verification ---\n");
    printf("Enter received data (or press Enter to use transmitted data): ");
    
    // Clear input buffer
    while(getchar() != '\n');
    
    if(fgets(received_data, sizeof(received_data), stdin) != NULL) {
        // Remove newline character
        received_data[strcspn(received_data, "\n")] = '\0';
        
        if(strlen(received_data) == 0) {
            strcpy(received_data, transmitted_data);
            printf("Using transmitted data: %s\n", received_data);
        } else {
            printf("Received data: %s\n", received_data);
        }
    }
    
    // Verify CRC
    printf("\nVerifying received data:\n");
    printf("%s ) %s\n", polynomial, received_data);
    
    int result = verify_crc(received_data, polynomial, crc_bits);
    
    if(result == 0) {
        printf("\n✓ RESULT: Data transmitted correctly (remainder = 0)\n");
    } else {
        printf("\n✗ RESULT: Error detected in transmission (remainder ≠ 0)\n");
    }
}

const char* binary_divide(const char* dividend, const char* divisor, int crc_bits) {
    static char remainder[200];
    char temp_dividend[200];
    char temp_remainder[200];
    
    strcpy(temp_dividend, dividend);
    int dividend_len = strlen(dividend);
    int divisor_len = strlen(divisor);
    
    // Initialize remainder with first divisor_len bits
    strncpy(remainder, temp_dividend, divisor_len);
    remainder[divisor_len] = '\0';
    
    int pos = divisor_len;
    
    while(pos <= dividend_len) {
        if(remainder[0] == '1') {
            // Perform XOR operation
            strcpy(temp_remainder, binary_xor(remainder, divisor, divisor_len));
            print_division_step(remainder, divisor, temp_remainder);
            
            // Remove leading zeros from remainder
            int i = 0;
            while(i < strlen(temp_remainder) && temp_remainder[i] == '0') {
                i++;
            }
            
            if(i == strlen(temp_remainder)) {
                strcpy(remainder, "0");
            } else {
                strcpy(remainder, temp_remainder + i);
            }
        }
        
        // Bring down next bit if available
        if(pos < dividend_len) {
            char next_bit[2] = {temp_dividend[pos], '\0'};
            strcat(remainder, next_bit);
        }
        pos++;
    }
    
    // Return the remainder (last crc_bits)
    int rem_len = strlen(remainder);
    if(rem_len >= crc_bits) {
        return remainder + (rem_len - crc_bits);
    } else {
        static char padded_remainder[200];
        strcpy(padded_remainder, "");
        for(int i = rem_len; i < crc_bits; i++) {
            strcat(padded_remainder, "0");
        }
        strcat(padded_remainder, remainder);
        return padded_remainder;
    }
}

const char* binary_xor(const char* a, const char* b, int len) {
    static char result[200];
    
    for(int i = 0; i < len; i++) {
        if(a[i] == b[i]) {
            result[i] = '0';
        } else {
            result[i] = '1';
        }
    }
    result[len] = '\0';
    
    return result;
}

void print_division_step(const char* dividend, const char* divisor, const char* remainder) {
    printf("                    %s\n", dividend);
    printf("                    %s\n", divisor);
    printf("                    ");
    for(int i = 0; i < strlen(divisor); i++) {
        printf("-");
    }
    printf("\n");
    printf("                    %s\n", remainder);
}

int verify_crc(const char* received_data, const char* polynomial, int crc_bits) {
    const char* remainder = binary_divide(received_data, polynomial, crc_bits);
    
    // Check if remainder is all zeros
    for(int i = 0; i < strlen(remainder); i++) {
        if(remainder[i] == '1') {
            return 1; // Error detected
        }
    }
    return 0; // No error
}
