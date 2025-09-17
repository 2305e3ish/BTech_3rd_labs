// Distance Vector Routing Algorithm (C++ - Manual Style Input/Output)
// Definitions and Basics:
// - Each node maintains a table (vector) of the cost to reach every other node.
// - The cost matrix represents the direct link cost between nodes. If there is no direct link, input -1.
// - The algorithm finds the shortest path from every node to every other node by updating these tables iteratively.
// - We use INT_MAX to represent infinity (no path).

#include <iostream>
#include <climits>
using namespace std;
#define MAX 10

int main() {
    int n, cost[MAX][MAX], dist[MAX][MAX];
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter cost matrix (-1 for no edge):\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int x; cin >> x;
            if(x == -1)
                cost[i][j] = INT_MAX;
            else
                cost[i][j] = x;
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dist[i][j]=cost[i][j];
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
    cout << "Routing tables:\n";
    for(int i=0;i<n;i++) {
        cout << "Node " << i << ": ";
        for(int j=0;j<n;j++) {
            if(dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
