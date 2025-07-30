#include <stdio.h>
#include <string.h>

// Perform bitwise division (modulo-2) as in the manual
unsigned int crc(const char *data, const char *type) {
    unsigned int poly, width;
    if (strcmp(type, "crc-12") == 0) {
        poly = 0x80F; width = 12;
    } else if (strcmp(type, "crc-16") == 0) {
        poly = 0x11021; width = 17; // 17 bits for division (poly is x^16 + ...)
    } else if (strcmp(type, "ccitt") == 0) {
        poly = 0x11021; width = 17;
    } else {
        printf("Unknown CRC type.\n");
        return 0;
    }

    // Prepare the bit array (append width-1 zeros)
    int len = strlen(data);
    int total = len + width - 1;
    char bits[1024] = {0};
    for (int i = 0; i < len; i++)
        bits[i] = data[i] - '0';
    for (int i = len; i < total; i++)
        bits[i] = 0;

    // Perform division
    for (int i = 0; i <= total - width; i++) {
        if (bits[i]) {
            for (int j = 0; j < width; j++)
                bits[i + j] ^= (poly >> (width - 1 - j)) & 1;
        }
    }

    // Collect remainder as CRC
    unsigned int crc = 0;
    for (int i = total - (width - 1); i < total; i++) {
        crc = (crc << 1) | bits[i];
    }
    return crc;
}

void print_binary(unsigned int num, int width) {
    for (int i = width - 1; i >= 0; i--)
        printf("%d", (num >> i) & 1);
    printf("\n");
}

int main() {
    char tx[256], rx[256], type[16];
    int width = 16;

    printf("Enter transmitted data: ");
    scanf("%s", tx);
    printf("Enter received data: ");
    scanf("%s", rx);
    printf("Enter CRC type (crc-12, crc-16, ccitt): ");
    scanf("%s", type);

    if (strcmp(type, "crc-12") == 0) width = 12;
    else width = 16;

    unsigned int tx_crc = crc(tx, type);
    unsigned int rx_crc = crc(rx, type);

    printf("CRC is: ");
    print_binary(tx_crc, width);

    // To check correctness, append CRC to received data and check if remainder is zero
    char rx_full[512];
    strcpy(rx_full, rx);
    for (int i = width - 1; i >= 0; i--)
        rx_full[strlen(rx) + width - 1 - i] = ((tx_crc >> i) & 1) + '0';
    rx_full[strlen(rx) + width - 1] = '\0';

    unsigned int check = crc(rx_full, type);
    if (check == 0)
        printf("Data received right.\n");
    else
        printf("Data received wrong.\n");
    return 0;
}