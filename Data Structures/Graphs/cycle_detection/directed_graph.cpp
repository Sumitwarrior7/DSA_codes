#include <bits/stdc++.h>
using namespace std;

// 0-based indexing
/* ---------------------------------------DFS--------------------------------------- */
bool dfs_detection(int source_node, vector<vector<int>> &adj, vector<bool> &vis, int parent, vector<bool> &path_vis) {
    vis[source_node] = true;
    path_vis[source_node] = true;
    // Operation

    for (int nbr : adj[source_node]) {
        if (!vis[nbr]) {
            if (dfs_detection(nbr, adj, vis, source_node, path_vis) == true) return true;
        } else {
            if (path_vis[nbr] == true) return true;
        }
    }
    path_vis[source_node] = false;
    return false;
}

bool cycle_detection_dfs(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool> vis(n, false);
    vector<bool> path_vis(n, false);
    for (int i = 0; i < n; i++) {
        if (vis[i] == false) {
            if (dfs_detection(i, adj, vis, -1, path_vis) == true) return true;
        }
    }
    return false;
}



int main() {
    // Example usage for a cyclic graph
    vector<vector<int>> adj_cyclic = {
        {1, 2},     // Node 0 is connected to nodes 1 and 2
        {0, 2},     // Node 1 is connected to nodes 0 and 2
        {0, 1}      // Node 2 is connected to nodes 0 and 1
    };

    // Example usage for an acyclic graph
    vector<vector<int>> adj_acyclic = {
        {1, 2},     // Node 0 is connected to nodes 1 and 2
        {3},        // Node 1 is connected to node 3
        {},         // Node 2 has no connections
        {4},        // Node 3 is connected to node 4
        {}          // Node 4 has no connections
    };

    bool ans1 = cycle_detection_dfs(adj_cyclic);
    bool ans2 = cycle_detection_dfs(adj_acyclic);

    cout << "Cyclic Graph: " << ans1 << endl;
    cout << "Acyclic Graph: " << ans2 << endl;

    return 0;
}