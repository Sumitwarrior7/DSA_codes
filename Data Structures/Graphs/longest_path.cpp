#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))

// To get the farthest node from any given node in an undirected, unweighted graph
int bfs1(int n, int node, vector<vector<int>> &adj) {
    queue<pair<int, int>> q;
    vector<bool> vis(n+1, false);
    q.push({node, 0});
    vis[node] = true;
    int max_dist = 0;
    int req_node;

    while(!q.empty()) {
        pair<int, int> m = q.front();
        q.pop();
        if (m.second >= max_dist) {
            max_dist = m.second;
            req_node = m.first;
        }
        for(auto nbr : adj[m.first]) {
            if (vis[nbr] == false) {
                q.push({nbr, m.second+1});
                vis[nbr] = true;
            }
        }
    }
    return req_node;
}

// To get all the nodes in the longest path in an undirected, unweighted graph
vector<int> bfs2(int n, int node, vector<vector<int>> &adj) {
    queue<pair<int, int>> q;
    vector<bool> vis(n+1, false);
    vector<int> parent(n+1);

    q.push({node, 0});
    vis[node] = true;
    parent[node] = -1;
    int max_dist = 0;
    int req_node;

    while(!q.empty()) {
        pair<int, int> m = q.front();
        q.pop();
        if (m.second >= max_dist) {
            max_dist = m.second;
            req_node = m.first;
        }
        for(auto nbr : adj[m.first]) {
            if (vis[nbr] == false) {
                q.push({nbr, m.second+1});
                vis[nbr] = true;
                parent[nbr] = m.first;
            }
        }
    }
    
    vector<int> ans_arr;
    int curr = req_node;
    while(curr != -1) {
        ans_arr.push_back(curr);
        curr = parent[curr];
    }
    return ans_arr;
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

        int start_node = 1;
        int rn = bfs1(n, start_node, adj);
        
        vector<int> ans_arr = bfs2(n, rn, adj);
        for(auto it: ans_arr) cout << it << " ";

    }

}