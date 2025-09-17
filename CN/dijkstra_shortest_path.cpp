/*
#include <stdio.h>

#define MAX 50
#define INF 1000000000

int main() {
	int n, s, d;
	int c[MAX][MAX];      // cost / adjacency
	int dist[MAX];        // distance estimates
	int pred[MAX];        // predecessors
	int vis[MAX];         // visited flags

	printf("Enter number of nodes: ");
	if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid n.\n"); return 1; }

	// Read adjacency matrix (-1 means no edge)
	printf("Enter adjacency matrix (%d x %d, -1 for no edge):\n", n, n);
	for (int i = 0, w; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (scanf("%d", &w) != 1) return 1;
			c[i][j] = (i == j) ? 0 : (w == -1 ? INF : w);
		}
	}

	printf("Enter source and destination (0-based indices): ");
	if (scanf("%d %d", &s, &d) != 2 || s < 0 || s >= n || d < 0 || d >= n) { printf("Invalid source/destination.\n"); return 1; }
	if (n <= 26) printf("(Nodes will be shown as letters a..%c)\n", 'a' + n - 1);

	// Initialize
	for (int i = 0; i < n; i++) {
		dist[i] = c[s][i];
		pred[i] = (dist[i] < INF && i != s) ? s : -1;
		vis[i]  = 0;
	}
	dist[s] = 0;
	vis[s]  = 1;
	pred[s] = -1;

	// Dijkstra O(n^2)
	for (int k = 1; k < n; k++) {
		int v = -1, min = INF;
		for (int i = 0; i < n; i++)
			if (!vis[i] && dist[i] < min) { min = dist[i]; v = i; }
		if (v == -1) break;          // no more reachable nodes
		vis[v] = 1;
		for (int i = 0; i < n; i++) {
			if (!vis[i] && c[v][i] < INF) {
				int alt = dist[v] + c[v][i];
				if (alt < dist[i]) { dist[i] = alt; pred[i] = v; }
			}
		}
	}

	if (dist[d] >= INF) { puts("No path"); return 0; }

	// Reconstruct path
	int stack[MAX], t = 0;
	for (int cur = d; cur != -1; cur = pred[cur]) stack[t++] = cur;

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int n, s, d;
	cout << "Enter number of nodes: ";
	cin >> n;
	vector<vector<int>> c(n, vector<int>(n));
	cout << "Enter adjacency matrix (" << n << " x " << n << ", -1 for no edge):\n";
	for (int i = 0, w; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> w;
			c[i][j] = (i == j) ? 0 : (w == -1 ? INT_MAX : w);
		}
	cout << "Enter source and destination (0-based indices): ";
	cin >> s >> d;
	vector<int> dist = c[s], pred(n, -1), vis(n);
	for (int i = 0; i < n; i++) if (dist[i] < INT_MAX && i != s) pred[i] = s;
	dist[s] = 0; vis[s] = 1;
	for (int k = 1; k < n; k++) {
		int v = -1, min = INT_MAX;
		for (int i = 0; i < n; i++)
			if (!vis[i] && dist[i] < min) min = dist[i], v = i;
		if (v == -1) break;
		vis[v] = 1;
		for (int i = 0; i < n; i++)
			if (!vis[i] && c[v][i] < INT_MAX && dist[v] + c[v][i] < dist[i])
				dist[i] = dist[v] + c[v][i], pred[i] = v;
	}
	if (dist[d] >= INT_MAX) { cout << "No path\n"; return 0; }
	vector<int> path;
	for (int cur = d; cur != -1; cur = pred[cur]) path.push_back(cur);
	cout << "Shortest path: ";
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i];
		if (i) cout << " ";
	}
	cout << "\nCost: " << dist[d] << "\n";
	return 0;
}
