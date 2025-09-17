// Broadcast Tree for Subnet (C++ Implementation)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, root;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<vector<int>> adj(n);
    cout << "Enter adjacency matrix (0/1):\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            int x; cin >> x;
            if(x) adj[i].push_back(j);
        }
    cout << "Enter root node: ";
    cin >> root;
    vector<bool> visited(n, false);
    queue<int> q;
    visited[root] = true;
    q.push(root);
    cout << "Broadcast tree edges:\n";
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(!visited[v]) {
                cout << u << " - " << v << endl;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return 0;
}
