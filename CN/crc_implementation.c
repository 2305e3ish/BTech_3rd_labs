#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
const char* binary_divide(const char* dividend, const char* divisor, int crc_bits);
const char* binary_xor(const char* a, const char* b, int len);
void print_division_step(const char* dividend, const char* divisor, const char* remainder, int step);
int check_crc(const char* data, const char* polynomial, int crc_bits);

// Global variables for formatting output
int step_count = 0;
int is_receiver = 0;

// CRC Polynomials
// CRC-12: x^12 + x^11 + x^3 + x^2 + x + 1 = 1100000001011
// CRC-16: x^16 + x^15 + x^2 + 1 = 10001000000100001
// CRC-CCITT: x^16 + x^12 + x^5 + 1 = 10001000000100001

const char* CRC_12_POLY = "1100000001011";      // 13 bits
const char* CRC_16_POLY = "10001000000100001";  // 17 bits
const char* CRC_CCITT_POLY = "10001000000100001"; // 17 bits (same as CRC-16 in this implementation)

int main() {
    char input_data[100];
    char received_data[100];
    char transmitted_data[100];
    char crc_result[20];
    int choice;
    
    printf("=== CRC Implementation Program ===\n");
    printf("1. CRC-12 (x^12 + x^11 + x^3 + x^2 + x + 1)\n");
    printf("2. CRC-16 (x^16 + x^15 + x^2 + 1)\n");
    printf("3. CRC-CCITT (x^16 + x^12 + x^5 + 1)\n");
    printf("Choose CRC type (1-3): ");
    scanf("%d", &choice);
    
    const char* polynomial;
    int crc_bits;
    
    switch(choice) {
        case 1:
            polynomial = CRC_12_POLY;
            crc_bits = 12;
            printf("\nUsing CRC-12 polynomial: %s\n", polynomial);
            break;
        case 2:
            polynomial = CRC_16_POLY;
            crc_bits = 16;
            printf("\nUsing CRC-16 polynomial: %s\n", polynomial);
            break;
        case 3:
            polynomial = CRC_CCITT_POLY;
            crc_bits = 16;
            printf("\nUsing CRC-CCITT polynomial: %s\n", polynomial);
            break;
        default:
            printf("Invalid choice! Using CRC-12 by default.\n");
            polynomial = CRC_12_POLY;
            crc_bits = 12;
    }
    
    printf("\n=== SENDER SIDE ===\n");
    printf("Enter data to transmit (binary): ");
    scanf("%s", input_data);
    
    // Append zeros equal to CRC bits
    strcpy(transmitted_data, input_data);
    for(int i = 0; i < crc_bits; i++) {
        strcat(transmitted_data, "0");
    }
    
    printf("\nData with appended zeros: %s\n", transmitted_data);
    printf("\nPerforming CRC division:\n");
    printf("%s ) %s\n", polynomial, transmitted_data);
    
    step_count = 0;
    is_receiver = 0;
    const char* crc_code = binary_divide(transmitted_data, polynomial, crc_bits);
    
    // Pad CRC code if necessary
    strcpy(crc_result, "");
    int crc_len = strlen(crc_code);
    for(int i = crc_len; i < crc_bits; i++) {
        strcat(crc_result, "0");
    }
    strcat(crc_result, crc_code);
    
    printf("\nCRC code: %s\n", crc_result);
    
    // Create final transmitted data
    strcpy(transmitted_data, input_data);
    strcat(transmitted_data, crc_result);
    printf("Final transmitted data: %s\n", transmitted_data);
    
    printf("\n=== RECEIVER SIDE ===\n");
    printf("Enter received data (binary): ");
    scanf("%s", received_data);
    
    printf("\nVerifying received data:\n");
    printf("%s ) %s\n", polynomial, received_data);
    
    step_count = 0;
    is_receiver = 1;
    int error_status = check_crc(received_data, polynomial, crc_bits);
    
    if(error_status == 0) {
        printf("\nRemainder is zero - Data transmitted correctly!\n");
    } else {
        printf("\nRemainder is non-zero - Error detected in transmission!\n");
    }
    
    return 0;
}

const char* binary_divide(const char* dividend, const char* divisor, int crc_bits) {
    static char remainder[100];
    static char quotient[100];
    char temp_dividend[100];
    char temp_remainder[100];
    
    strcpy(temp_dividend, dividend);
    int dividend_len = strlen(dividend);
    int divisor_len = strlen(divisor);
    
    // Initialize remainder with first divisor_len bits
    strncpy(remainder, temp_dividend, divisor_len);
    remainder[divisor_len] = '\0';
    
    int pos = divisor_len;
    quotient[0] = '\0';
    
    while(pos <= dividend_len) {
        if(remainder[0] == '1') {
            // Perform XOR
            strcpy(temp_remainder, binary_xor(remainder, divisor, divisor_len));
            print_division_step(remainder, divisor, temp_remainder, ++step_count);
            
            // Remove leading zeros
            int i = 0;
            while(i < strlen(temp_remainder) && temp_remainder[i] == '0') {
                i++;
            }
            
            if(i == strlen(temp_remainder)) {
                strcpy(remainder, "0");
            } else {
                strcpy(remainder, temp_remainder + i);
            }
            
            strcat(quotient, "1");
        } else {
            strcat(quotient, "0");
        }
        
        // Bring down next bit
        if(pos < dividend_len) {
            char next_bit[2] = {temp_dividend[pos], '\0'};
            strcat(remainder, next_bit);
        }
        pos++;
    }
    
    // Return last crc_bits of remainder
    int rem_len = strlen(remainder);
    if(rem_len >= crc_bits) {
        return remainder + (rem_len - crc_bits);
    } else {
        static char padded_remainder[100];
        strcpy(padded_remainder, "");
        for(int i = rem_len; i < crc_bits; i++) {
            strcat(padded_remainder, "0");
        }
        strcat(padded_remainder, remainder);
        return padded_remainder;
    }
}

const char* binary_xor(const char* a, const char* b, int len) {
    static char result[100];
    
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

void print_division_step(const char* dividend, const char* divisor, const char* remainder, int step) {
    printf("                    %s\n", dividend);
    printf("                    %s\n", divisor);
    printf("                    ");
    for(int i = 0; i < strlen(divisor); i++) {
        printf("-");
    }
    printf("\n");
    printf("                    %s\n", remainder);
}

int check_crc(const char* data, const char* polynomial, int crc_bits) {
    const char* remainder = binary_divide(data, polynomial, crc_bits);
    
    // Check if remainder is all zeros
    for(int i = 0; i < strlen(remainder); i++) {
        if(remainder[i] == '1') {
            return 1; // Error detected
        }
    }
    return 0; // No error
}
