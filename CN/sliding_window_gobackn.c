// Sliding Window and Go-Back-N
#include <stdio.h>
#define MAX 10

int main() {
    int frames[MAX], n, window, i, ack = 0;
    printf("Enter number of frames: ");
    scanf("%d", &n);
    printf("Enter window size: ");
    scanf("%d", &window);
    printf("Enter frame data: ");
    for(i=0;i<n;i++) scanf("%d", &frames[i]);
    i = 0;
    while(i < n) {
        printf("Sending frames: ");
        for(int j=i;j<i+window && j<n;j++) printf("%d ", frames[j]);
        printf("\nEnter last ACK received (-1 for loss): ");
        scanf("%d", &ack);
        if(ack == -1) printf("Resending window from %d\n", i);
        else i = ack+1;
    }
    printf("All frames sent successfully.\n");
    return 0;
}
