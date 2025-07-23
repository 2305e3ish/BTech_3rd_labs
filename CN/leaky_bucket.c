// Leaky Bucket Algorithm for Congestion Control
#include <stdio.h>

int main() {
    int bucket_size, n, pkt_size, rem=0, rate;
    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);
    printf("Enter output rate: ");
    scanf("%d", &rate);
    printf("Enter number of packets: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        printf("Enter packet size: ");
        scanf("%d", &pkt_size);
        if(pkt_size+rem > bucket_size)
            printf("Packet dropped\n");
        else {
            rem += pkt_size;
            if(rem >= rate) {
                printf("Sent %d bytes\n", rate);
                rem -= rate;
            } else {
                printf("Sent %d bytes\n", rem);
                rem = 0;
            }
        }
    }
    return 0;
}
