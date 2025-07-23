// Bit Stuffing
#include <stdio.h>
#include <string.h>

int main() {
    char data[100], stuffed[200] = "";
    printf("Enter bit string: ");
    scanf("%s", data);
    int count = 0;
    for (int i = 0; data[i]; i++) {
        strncat(stuffed, &data[i], 1);
        if (data[i] == '1') {
            count++;
            if (count == 5) {
                strcat(stuffed, "0");
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    printf("Stuffed Bits: %s\n", stuffed);
    return 0;
}
