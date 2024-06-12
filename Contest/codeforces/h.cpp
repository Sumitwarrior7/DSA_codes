#include <bits/stdc++.h>
using namespace std;


bool dfs_cycle(int node, vector<vector<int>> &adj, vector<bool> &vis, int parent, vector<int> &arr) {
    vis[node] = true;
    arr.push_back(node);

    for(auto nbr : adj[node]) {
        if (vis[nbr] == false) {
            if (dfs_cycle(nbr, adj, vis, node, arr) == true) return true;
        }
        else {
            if(nbr != parent) {
                arr.push_back(nbr);
                return true;
            }
        }
    }
    arr.pop_back();
    return false;
}

unordered_map<int, bool> cyclic_nodes(int n, vector<vector<int>> &adj) {
   unordered_map<int, bool> ump;
   for(int i = 1; i<= n; i++) {
    ump[i] = false;
   } 
   vector<bool> vis(n+1, false);
   vector<int> arr;

   bool dfs_check = dfs_cycle(1, adj, vis, -1, arr);

    int tar = arr.back();
    int size = arr.size();
    bool start = true;
    for(int i = size-1; i >= 0; i--) {
        ump[arr[i]] = true;
        if (arr[i] == tar && start == true) {
            ump[arr[i]] = true;
            start = false;
        } else if (arr[i] == tar && start == false) {
            break;
        }
    }
    return ump;
}

pair<int, int> bfs1(int n, vector<vector<int>> &adj, int node, unordered_map<int, bool> &ump) {
    queue<pair<int, int>> q;
    vector<bool> vis(n+1, false);

    q.push({node, 0});
    vis[node] = true;
    while(!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();

        if (ump[f.first] == true) {
            return {f.first, f.second};
        }
        for (auto nbr: adj[f.first]) {
            if (vis[nbr] == false) {
                q.push({nbr, f.second+1});
                vis[nbr] = true;
            }
        }

    }
    return {-1, -1};
}

int bfs2(int n, vector<vector<int>> &adj, int st, int end) {
    queue<pair<int, int>> q;
    vector<bool> vis(n+1, false);

    q.push({st, 0});
    vis[st] = true;
    while(!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();

        if (f.first == end) {
            return f.second;
        }
        for (auto nbr: adj[f.first]) {
            if (vis[nbr] == false) {
                q.push({nbr, f.second+1});
                vis[nbr] = true;
            }
        }

    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        vector<vector<int>> adj(n+1);
        for(int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (a == b) {
            cout << "no" << endl;
        } else {
            unordered_map<int, bool> ump = cyclic_nodes(n, adj);
            // for(auto it : ump) cout << "key :" << it.first << "   Value :" << it.second << endl;
            pair<int, int> ans1 = bfs1(n, adj, b, ump);
            int ans2 = bfs2(n, adj, a, ans1.first);
            // cout << "val dist :" << ans1.second << endl;
            // cout << "marcel dist :" << ans2 << endl;

            int diff = ans2 - ans1.second;
            if (ans1.second <= ans2) cout << "no"<< endl;
            else cout << "yes" << endl;
        }
    }
}