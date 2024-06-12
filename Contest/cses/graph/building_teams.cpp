#include <bits/stdc++.h>
using namespace std;


vector<int> print_teams(int n, vector<vector<int>> &adj) {
    vector<int> teams(n+1, 1);

    vector<int> vis(n+1, false);
    vis[0] = true;

    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            queue<pair<pair<int, int>, int>> q;
            q.push({{i, -1}, 1});
            vis[i] = true;
            teams[i] = 1;

            while(!q.empty()) {
                pair<pair<int, int>, int> f = q.front();
                int node = f.first.first;
                int par = f.first.second;
                int clr = f.second;
                q.pop();
                // teams[node] = clr;

                for(auto nbr :adj[node]) {
                    if (vis[nbr] == false) {
                        q.push({{nbr, node}, 3-clr});
                        vis[nbr] = true;
                        teams[nbr] = 3-clr;
                    }
                    else {
                        if (nbr != par) {
                            if (clr == teams[nbr]) return {-1};
                        }
                    }
                }
            }
        }
    }

    // teams.erase(teams.begin());
    return teams;
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

    vector<int> teams = print_teams(n, adj);
    if (teams.size() == 1 && teams[0] == -1) cout << "IMPOSSIBLE" << endl;
    else {
        for (int i = 0; i < teams.size(); i++) {
            if (i != 0) cout << teams[i] << " ";
        }
    }

}
