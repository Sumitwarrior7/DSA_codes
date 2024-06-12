#include <bits/stdc++.h>
using namespace std;

// 0-based indexing
/* ---------------------------------------BFS--------------------------------------- */
bool bfs_detection(int source_node, vector<vector<int>> &adj, vector<bool> &vis) {
    queue<pair<int, int>> q;
    q.push({source_node, -1});
    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;

        q.pop();
        vis[node] = true;
        // operation
        for (auto nbr: adj[node]) {
            if (vis[nbr] == false) {
                q.push({nbr, node});
            } else {
                if (parent != nbr) return true;
            }
        }
    }
    return false;
}

bool cycle_detection_bfs(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (vis[i] == false) {
            if (bfs_detection(i, adj, vis) == true) return true;
        }
    }
    return false;
}


// 0-based indexing
/* ---------------------------------------DFS--------------------------------------- */
bool dfs_detection(int source_node, vector<vector<int>> &adj, vector<bool> &vis, int parent) {
    vis[source_node] = true;
    // Operation

    for (int nbr : adj[source_node]) {
        if (!vis[nbr]) {
            if (dfs_detection(nbr, adj, vis, source_node) == true) return true;
        } else {
            if (nbr != parent) return true;
        }
    }
    return false;
}

bool cycle_detection_dfs(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (vis[i] == false) {
            if (dfs_detection(i, adj, vis, -1) == true) return true;
        }
    }
    return false;
}


int main() {
    // Example usage
    vector<vector<int>> adj_cyclic = {
        {1, 2},     // Node 0 is connected to nodes 1 and 2
        {0, 2},     // Node 1 is connected to nodes 0 and 2
        {0, 1}      // Node 2 is connected to nodes 0 and 1
    };

    vector<vector<int>> adj_acyclic = {
        {1, 2},     // Node 0 is connected to nodes 1 and 2
        {3},        // Node 1 is connected to node 3
        {},         // Node 2 has no connections
        {4},        // Node 3 is connected to node 4
        {}          // Node 4 has no connections
    };

    bool bfs = cycle_detection_bfs(adj_acyclic);
    cout << "BFS :" << bfs << endl;

    bool dfs = cycle_detection_dfs(adj_cyclic);
    cout << "Dfs :" << dfs << endl;
}
