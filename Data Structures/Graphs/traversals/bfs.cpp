#include <bits/stdc++.h>
using namespace std;


/* ------------------< 0-based indexing >------------------ */ 
void bfs(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> vis(n, false);

    // Queue for BFS
    queue<int> q;

    // Traverse all vertices
    for (int i = 0; i < n; ++i) {
        // If the current vertex is not visited, start BFS from it
        if (!vis[i]) {
            q.push(i);
            vis[i] = true;

            while (!q.empty()) {
                int current = q.front();
                q.pop();
                // Operation
                cout << current << " ";

                // Visit all adjacent vertices of the current vertex
                for (int neighbor : adj[current]) {
                    if (!vis[neighbor]) {
                        q.push(neighbor);
                        vis[neighbor] = true;
                    }
                }
            }
        }
    }
}

int main() {
    // Example usage
    vector<vector<int>> adj = {
        {1, 2},    // 0 is connected to 1 and 2
        {0, 2},    // 1 is connected to 0 and 2
        {0, 1},    // 2 is connected to 0 and 1
        {3},       // 3 is an isolated vertex
        {4, 5},    // 4 is connected to 5
        {4}        // 5 is connected to 4
    };

    cout << "BFS traversal : ";
    bfs(adj);

    return 0;
}
