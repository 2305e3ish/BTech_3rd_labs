// CRC Calculation for CRC-12, CRC-16, CRC-CCITT
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
    printf("Enter data: ");
    scanf("%s", data);
    printf("CRC-12: %X\n", crc(data, 0x80F, 12));
    printf("CRC-16: %X\n", crc(data, 0x8005, 16));
    printf("CRC-CCITT: %X\n", crc(data, 0x1021, 16));
    return 0;
}
