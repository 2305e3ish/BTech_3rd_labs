// Dijkstra's Algorithm for Shortest Path
#include <stdio.h>
#define MAX 10
#define INF 9999

int main() {
    int n, cost[MAX][MAX], dist[MAX], visited[MAX], u;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter cost matrix (use 9999 for no edge):\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &cost[i][j]);
    printf("Enter source node: ");
    scanf("%d", &u);
    for(int i=0;i<n;i++) { dist[i]=cost[u][i]; visited[i]=0; }
    visited[u]=1;
    for(int c=1;c<n;c++) {
        int min=INF, v=-1;
        for(int i=0;i<n;i++)
            if(!visited[i] && dist[i]<min) { min=dist[i]; v=i; }
        if(v==-1) break;
        visited[v]=1;
        for(int i=0;i<n;i++)
            if(!visited[i] && dist[v]+cost[v][i]<dist[i])
                dist[i]=dist[v]+cost[v][i];
    }
    printf("Shortest distances from node %d:\n", u);
    for(int i=0;i<n;i++) printf("To %d: %d\n", i, dist[i]);
    return 0;
}
