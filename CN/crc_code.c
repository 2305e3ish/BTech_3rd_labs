// CRC Calculation for CRC-12, CRC-16, CRC-CCITT
//
// CRC-12: Polynomial = x^12 + x^11 + x^3 + x^2 + x + 1 (hex: 0x80F), poly_bits = 12
// CRC-16: Polynomial = x^16 + x^15 + x^2 + 1 (hex: 0x8005), poly_bits = 16
// CRC-CCITT: Polynomial = x^16 + x^12 + x^5 + 1 (hex: 0x1021), poly_bits = 16
//
#include <stdio.h>
#include <string.h>

// Calculates the CRC value for the given data using the specified polynomial.
// Parameters:
//   data      - input string to calculate CRC for
//   poly      - CRC polynomial to use
//   poly_bits - number of bits in the polynomial
// Returns:
//   The computed CRC value as an unsigned int.
//
// Manual logic: Usually uses bitwise division (modulo-2) on the entire bitstream, shifting and XORing with the polynomial when the MSB is 1.
// This code: Processes each byte, aligns it to the CRC register, and for each bit, shifts and XORs with the polynomial if needed.
// Both are correct; this version is efficient for short strings and easy to understand for beginners.
// Calculates CRC for a string of '0' and '1' characters as bits
unsigned int crc_bits(char *bitstr, unsigned int poly, int poly_bits) {
    unsigned int reg = 0;
    int len = strlen(bitstr);
    for (int i = 0; i < len; i++) {
        reg <<= 1;
        if (bitstr[i] == '1')
            reg |= 1;
        if (reg & (1 << poly_bits)) // poly_bits+1-th bit
            reg ^= poly;
    }
    return reg & ((1U << poly_bits)-1);
}
unsigned int crc(char *data, unsigned int poly, int poly_bits) {
    unsigned int reg = 0;
    int len = strlen(data);
    for (int i = 0; i < len; i++) {
        reg ^= (data[i] << (poly_bits-8)); // Align byte to MSB of register
        for (int j = 0; j < 8; j++) {
            if (reg & (1 << (poly_bits-1)))
                reg = (reg << 1) ^ poly;
            else
                reg <<= 1;
        }
    }
    return reg & ((1U << poly_bits)-1);
}

int main() {
    char data[100];
    int choice, mode;
    unsigned int checksum = 0;
    printf("Enter data: ");
    scanf("%s", data);
    printf("Select CRC type:\n1. CRC-12\n2. CRC-16\n3. CRC-CCITT\nEnter choice: ");
    scanf("%d", &choice);
    printf("Choose input mode:\n1. ASCII (normal string)\n2. Bitwise (treat string as bits)\nEnter mode: ");
    scanf("%d", &mode);
    if (choice == 1) {
        if (mode == 2)
            checksum = crc_bits(data, 0x80F, 12);
        else
            checksum = crc(data, 0x80F, 12);
        printf("CRC-12 checksum: %X\n", checksum);
        printf("Data to send: %s%03X\n", data, checksum);
    } else if (choice == 2) {
        if (mode == 2)
            checksum = crc_bits(data, 0x8005, 16);
        else
            checksum = crc(data, 0x8005, 16);
        printf("CRC-16 checksum: %X\n", checksum);
        printf("Data to send: %s%04X\n", data, checksum);
    } else if (choice == 3) {
        if (mode == 2)
            checksum = crc_bits(data, 0x1021, 16);
        else
            checksum = crc(data, 0x1021, 16);
        printf("CRC-CCITT checksum: %X\n", checksum);
        printf("Data to send: %s%04X\n", data, checksum);
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}
