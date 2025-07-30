#include <stdio.h>
#define MAX 100

int main() {
    int n, window, ack = -1, i = 0;
    printf("Enter window size\n");
    scanf("%d", &window);
    n = window; // For your output format, number of frames = window size
    while(i < n) {
        for(int j = i; j < i + window && j < n; j++)
            printf("Frame %d has been transmitted.\n", j);
        printf("Please enter the last Acknowledgement received.\n");
        scanf("%d", &ack);
        if(ack < i-1 || ack >= i + window) {
            printf("Invalid ACK. Please enter a valid ACK in the current window.\n");
            continue;
        }
        i = ack + 1;
    }
    return 0;
}