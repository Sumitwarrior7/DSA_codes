#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))


vector<int> Centroid(int n, vector<vector<int>> &adj) {
    vector<int> centroid;
    vector<int> sz(n+1);
    function<void (int, int)> dfs = [&](int node, int prev) {
        sz[node] = 1;
        bool is_centroid = true;
        for (auto nbr : adj[node]) {
            if (nbr != prev) {
                dfs(nbr, node);
                sz[node] += sz[nbr];
                if (sz[nbr] > n / 2) is_centroid = false;
            }
        }
        if (n - sz[node] > n / 2) is_centroid = false;
        if (is_centroid) centroid.push_back(node);
    };
    dfs(1, -1);
    return centroid;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n+1);
        for (int i = 0; i < n-1; i++) {
            int ai, bi;
            cin >> ai >> bi;
            adj[bi].push_back(ai);
            adj[ai].push_back(bi);
        } 

        vector<int> cent = Centroid(n, adj);
        // for(auto it: cent) cout << it << " ";

        if (cent.size() == 1) {
            cout << cent[0] << " " << adj[cent[0]][0] << endl;
            cout << cent[0] << " " << adj[cent[0]][0] << endl;
        } else {
            int elm;
            for(auto it: adj[cent[1]]) {
                if (it != cent[0]) {
                    elm = it;
                    break;
                }
            }
            cout << cent[1] << " " << elm << endl;
            cout << cent[0] << " " << elm << endl;
        }

    }

}