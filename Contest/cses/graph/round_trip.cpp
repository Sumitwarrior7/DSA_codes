#include <bits/stdc++.h>
using namespace std;


vector<int> path(int st, int end, vector<int> &parent) {
    cout << "Parent array :";
    for(auto it: parent) cout << it << " ";
    cout << endl;
    
    vector<int> ans;
    ans.push_back(st);
    int curr = st;
    while(curr != end) {
        int par = parent[curr];
        ans.push_back(par);
        curr = par;
    }
    ans.push_back(st);
    return ans;
}

vector<int> round_trip(int n, vector<vector<int>> &adj) {
    vector<int> parent(n+1, -1);

    vector<int> vis(n+1, false);
    vis[0] = true;

    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            queue<pair<int, int>> q;
            q.push({i, -1});
            vis[i] = true;
            

            while(!q.empty()) {
                pair<int, int> f = q.front();
                int node = f.first;
                int par = f.second;
                q.pop();

                for(auto nbr :adj[node]) {
                    if (vis[nbr] == false) {
                        q.push({nbr, node});
                        vis[nbr] = true;
                        parent[nbr] = node;
                    }
                    else {
                        if (nbr != par) {
                            vector<int> ans = path(node, nbr, parent);
                            return ans;
                        }
                    }
                }
            }
        }
    }
    return {-1};
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

    vector<int> teams = round_trip(n, adj);
    if (teams.size() == 1 && teams[0] == -1) cout << "IMPOSSIBLE" << endl;
    else {
        for (int i = 0; i < teams.size(); i++) {
            cout << teams[i] << " ";
        }
    }

}
