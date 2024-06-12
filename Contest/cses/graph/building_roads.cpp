#include <bits/stdc++.h>
using namespace std;

void dfs(int n, vector<vector<int>> &adj, int node, vector<bool> &vis) {
    vis[node] = true;
    for(auto nbr: adj[node]) {
        if (vis[nbr] == false) {
            dfs(n, adj, nbr, vis);
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 

    int comp = 0;
    vector<int> arr;
    vector<bool> vis(n+1, false);
    vis[0] = true;
    for(int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            dfs(n, adj, i, vis);
            comp++;
            arr.push_back(i);
        }
    }   
    int roads = comp-1;
    cout << roads << endl;
    for(int i = 1; i < arr.size(); i++) {
        cout << arr[i-1] << " " << arr[i] << endl;
    }

}
