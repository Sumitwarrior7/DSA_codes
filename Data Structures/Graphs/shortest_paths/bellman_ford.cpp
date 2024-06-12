/* It helps to find the shortest distance from the source node to all other nodes */ 
/* Works only for directed graphs, but for undirected graph convert them into directed ones */ 
/* It helps to detect negative cycle in the graph */

#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int n, vector<vector<int>>& edges, int src) {
	vector<int> dist(n, INT_MAX);
	dist[src] = 0;
    // (N-1) relaxations
	for (int i = 0; i < n-1; i++) {
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
			}
		}
	}
	// Nth relaxation to check negative cycle
	for (auto it : edges) {
		int u = it[0];
		int v = it[1];
		int wt = it[2];
		if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
			return { -1}; // Negative Cycle Detected
		}
	}
	return dist;
}






int main() {
	int n = 6;
    // u-->v having weight as wt
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int src = 0;
	vector<int> dist = bellman_ford(n, edges, src);
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;

	return 0;
}