#include <bits/stdc++.h>
using namespace std;


/* ------------------< 0-based indexing >------------------ */ 
void dfs_recursion(vector<vector<int>>& adj, int node, vector<bool>& vis) {
    vis[node] = true;
    // Operation
    cout << node << " ";

    for (int nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs_recursion(adj, nbr, vis);
        }
    }
}

void dfs(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);

    cout << "Depth-First Search: ";
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs_recursion(adj, i, visited);
        }
    }
    cout << endl;
}

int main() {
    vector<vector<int>> adj = {
        {1, 2},    // 0 is connected to 1 and 2
        {0, 2},    // 1 is connected to 0 and 2
        {0, 1},    // 2 is connected to 0 and 1
        {3},       // 3 is an isolated vertex
        {4, 5},    // 4 is connected to 5
        {4}        // 5 is connected to 4
    };
    dfs(adj);
    return 0;
}


