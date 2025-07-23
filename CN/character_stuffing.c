// Character Stuffing
#include <stdio.h>
#include <string.h>

int main() {
    char data[100], stuffed[200] = "";
    printf("Enter data: ");
    scanf("%s", data);
    strcat(stuffed, "DLE STX ");
    for (int i = 0; data[i]; i++) {
        if (data[i] == 'D' && data[i+1] == 'L' && data[i+2] == 'E') {
            strcat(stuffed, "DLE DLE ");
            i += 2;
        } else {
            strncat(stuffed, &data[i], 1);
        }
    }
    strcat(stuffed, " DLE ETX");
    printf("Stuffed Frame: %s\n", stuffed);
    return 0;
}
