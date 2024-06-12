#include <bits/stdc++.h>
using namespace std;



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

    vector<bool> vis(n+1, false);
    vis[0] = true;
    vector<int> parent(n+1, -1);

    // BFS
    queue<pair<int, int>> q;
    int src = 1;
    q.push({src, -1});
    vis[src] = true;
    while(!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();
        parent[f.first] = f.second;
        for(auto nbr: adj[f.first]) {
            if (vis[nbr] == false) {
                q.push({nbr, f.first});
                vis[nbr] = true;
            }
        }
    }

    if (parent[n] == -1) cout << "IMPOSSIBLE" << endl;
    else {
        vector<int> path;
        path.push_back(n);
        int node = n;
        while(node != 1) {
            int par = parent[node];
            // cout << "par :" << par << endl;
            path.push_back(par);
            node = par;
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for(auto it: path) cout << it << " ";
    }


}
