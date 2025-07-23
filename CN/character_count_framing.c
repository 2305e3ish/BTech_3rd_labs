// Character Count Framing
#include <stdio.h>
#include <string.h>

int main() {
    char data[100];
    printf("Enter data: ");
    scanf("%s", data);
    int len = strlen(data);
    printf("Frame: %d %s\n", len, data);
    return 0;
}
