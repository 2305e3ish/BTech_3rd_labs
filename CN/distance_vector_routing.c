// Distance Vector Routing Algorithm
#include <stdio.h>
#define MAX 10
#define INF 9999

int main() {
    int n, cost[MAX][MAX], dist[MAX][MAX];
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter cost matrix (9999 for no edge):\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &cost[i][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dist[i][j]=cost[i][j];
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
    printf("Routing tables:\n");
    for(int i=0;i<n;i++) {
        printf("Node %d: ", i);
        for(int j=0;j<n;j++)
            printf("%d ", dist[i][j]);
        printf("\n");
    }
    return 0;
}
