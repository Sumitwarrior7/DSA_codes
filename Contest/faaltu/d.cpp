/* ----------------------------------Basic Template---------------------------------- */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))

vector<int> get_distances_from_node(int n, int src, vector<vector<int>> &adj) {
    vector<int> distances(n+1, 0);
    vector<bool> vis(n+1, false);
    queue<pair<int, int>> q;

    q.push({src, 0});
    vis[src] = true;
    while(!q.empty()) {
        pair<int, int> m = q.front();
        q.pop();
        distances[m.first] = m.second;

        for(auto nbr : adj[m.first]) {
            if (vis[nbr] == false) {
                q.push({nbr, m.second+1});
                vis[nbr] = true;
            }
        }
    }
    return distances;
}


set<int> get_all_leaves(int n, vector<vector<int>> &adj) {
    set<int> leaves;
    vector<bool> vis(n+1, false);
    queue<int> q;

    q.push(1);
    vis[1] = true;
    while(!q.empty()) {
        int m = q.front();
        q.pop();
        // cout << "size of :" << m << "  is :" << adj[m].size() << endl;
        if (adj[m].size() == 1) {
            leaves.insert(m);
        }

        for(auto nbr : adj[m]) {
            if (vis[nbr] == false) {
                q.push(nbr);
                vis[nbr] = true;
            }
        }
    }
    return leaves;
}


signed main() {
    int n, x;
    cin >> n >> x;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        int ai, bi;
        cin >> ai >> bi;
        adj[ai].push_back(bi);
        adj[bi].push_back(ai);
    } 
    
    set<int> leaves_set = get_all_leaves(n, adj);
    // cout << "leaves :";
    // for(auto it : leaves_set) cout << it << " ";
    // cout << endl;

    vector<int> alice_dist = get_distances_from_node(n, 1, adj);
    vector<int> bob_dist = get_distances_from_node(n, x, adj);

    int ans = 0;
    for(auto l: leaves_set) {
        if (alice_dist[l] > bob_dist[l]) ans = max(ans, 2*alice_dist[l]);
    }
    cout << ans << endl;
}
