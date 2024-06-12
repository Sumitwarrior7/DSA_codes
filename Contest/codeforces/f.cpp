#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))


pair<int, int> bfs(int n, int k, vector<int> &marked, vector<vector<int>> &adj, int node) {
    queue<pair<int, int>> q;
    vector<bool> vis(n+1, false);

    unordered_map<int, bool> mp;
    for(int i = 1; i <= n; i++) {
        mp[i] = false;
    }
    for(auto it : marked) {
        mp[it] = true;
    }

    q.push({node, 0});
    vis[node] = true;
    int fn = node;
    int fd = 0;
    while(!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();

        if (mp[f.first] == true) {
            if (f.second > fd) {
                fd = f.second;
                fn = f.first;
            }
        }
        for (auto nbr: adj[f.first]) {
            if (vis[nbr] == false) {
                q.push({nbr, f.second+1});
                vis[nbr] = true;
            }
        }

    }
    return {fn, fd};
}


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> marked(k);
        for (int i = 0; i < k; i++) {
            cin >> marked[i];
        } 

        vector<vector<int>> adj(n+1);
        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        } 

        pair<int, int> ans1 = bfs(n, k, marked, adj, marked[0]);
        // cout << "Farthest Node :" << ans1.first << endl;
        pair<int, int> ans2 = bfs(n, k, marked, adj, ans1.first);
        int ans;
        if (ans2.second % 2 == 0) ans = ans2.second / 2;
        else ans = (ans2.second/2) +1;

        if (k == 1) cout << 0 << endl;
        else cout << ans << endl;   
    }

}