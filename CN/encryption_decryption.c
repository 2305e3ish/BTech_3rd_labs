#include <stdio.h>
#include <string.h>

// Simple encryption: add 1 to each character
void encrypt_add1(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] + 1;
    }
}

// Simple decryption: subtract 1 from each character
void decrypt_add1(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] - 1;
    }
}

// XOR with a fixed key
void encrypt_xor(char *text, char key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] ^ key;
    }
}
#define decrypt_xor encrypt_xor // XOR is symmetric

// Reverse string
void encrypt_reverse(char *text) {
    int len = strlen(text);
    for (int i = 0; i < len / 2; i++) {
        char tmp = text[i];
        text[i] = text[len - 1 - i];
        text[len - 1 - i] = tmp;
    }
}
#define decrypt_reverse encrypt_reverse // Reversing twice restores original

// Swap adjacent characters
void encrypt_swap(char *text) {
    int len = strlen(text);
    for (int i = 0; i < len - 1; i += 2) {
        char tmp = text[i];
        text[i] = text[i + 1];
        text[i + 1] = tmp;
    }
}
#define decrypt_swap encrypt_swap // Swapping twice restores original

int main() {
    char text[1000];
    int choice, method;
    char xor_key = 'K'; // You can change this key

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline

    printf("Choose method:\n");
    printf("1. Add 1 to each character\n");
    printf("2. XOR with a key\n");
    printf("3. Reverse string\n");
    printf("4. Swap adjacent characters\n");
    printf("Enter method (1-4): ");
    scanf("%d", &method);

    printf("1. Encrypt\n2. Decrypt\nEnter choice: ");
    scanf("%d", &choice);

    if (method == 1) {
        if (choice == 1) {
            encrypt_add1(text);
            printf("Encrypted text: %s\n", text);
        } else {
            decrypt_add1(text);
            printf("Decrypted text: %s\n", text);
        }
    } else if (method == 2) {
        if (choice == 1) {
            encrypt_xor(text, xor_key);
            printf("Encrypted text: %s\n", text);
        } else {
            decrypt_xor(text, xor_key);
            printf("Decrypted text: %s\n", text);
        }
    } else if (method == 3) {
        if (choice == 1) {
            encrypt_reverse(text);
            printf("Encrypted text: %s\n", text);
        } else {
            decrypt_reverse(text);
            printf("Decrypted text: %s\n", text);
        }
    } else if (method == 4) {
        if (choice == 1) {
            encrypt_swap(text);
            printf("Encrypted text: %s\n", text);
        } else {
            decrypt_swap(text);
            printf("Decrypted text: %s\n", text);
        }
    } else {
        printf("Invalid method.\n");
    }

    return 0;
}