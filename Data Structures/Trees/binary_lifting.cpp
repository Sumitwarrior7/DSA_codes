#include<bits/stdc++.h>
using namespace std;


void sparse_dfs(int nodes, int total_parents, vector<vector<int>> &undirected_tree, int node, int par, vector<vector<int>> &sparse) {
    // Finding all 2^i parents for the current node
    if(par == -1) {
        // node is root 
        for(int i=0; i<total_parents; i++) {
            sparse[node][i] = -1;
        }
    }
    else {
        bool neg_par = false;
        for(int i=0; i<total_parents; i++) {
            if(i == 0) sparse[node][i] = par;
            else {
                if(neg_par == true) {
                    sparse[node][i] = -1;
                } 
                else {
                    int parent_2i = sparse[sparse[node][i-1]][i-1];
                    if(parent_2i == -1) neg_par = true;
                    sparse[node][i] = parent_2i;
                }
            }
        }
    }
    for(auto nbr: undirected_tree[node]) {
        if(nbr != par) {
            sparse_dfs(nodes, total_parents, undirected_tree, nbr, node, sparse);
        }
    }
}
vector<vector<int>> get_sparse_table(int nodes, int total_parents, vector<vector<int>> undirected_tree, int root) {
    vector<vector<int>> sparse(nodes, vector<int>(total_parents, -10));
    sparse_dfs(nodes, total_parents, undirected_tree, root, -1, sparse);
    return sparse;
}

void get_levels(int n, vector<vector<int>> &undirected_tree, int root, vector<int> &level) {
    // BFS
    queue<pair<int, int>> q;
    vector<int> vis(n+1, false);
    q.push({root, 0});
    vis[root] = true;
    while(!q.empty()) {
        auto m = q.front();
        int node = m.first;
        int lev = m.second;
        q.pop();
        level[node] = lev;
        for(auto nbr: undirected_tree[node]) {
            if(vis[nbr] == false) {
                q.push({nbr, lev+1});
                vis[nbr] = true;
            }
        }
    }
} 

int moveup(int n, int total_parents, vector<vector<int>> &adj, vector<vector<int>> &sparse, int node, int level) {
    int ans = node;
    for(int i=total_parents-1; i>=0; i--) {
        if((level&(1<<i)) != 0) {
            ans = sparse[ans][i];
        }
    }
    return ans;
}

int getLCA(int n, int total_parents, vector<vector<int>> &adj, vector<int> &level, vector<vector<int>> &sparse, int u, int v) {
    // Making level of u and v equal
    int lev_u = level[u];
    int lev_v = level[v];
    if(lev_u != lev_v) {
        if(lev_u < lev_v) {
            v = moveup(n, total_parents, adj, sparse, v, abs(lev_u-lev_v));
        } else if(lev_u > lev_v) {
            u = moveup(n, total_parents, adj, sparse, u, abs(lev_u-lev_v));
        }
    }

    if(u == v) return u;

    for(int i=total_parents-1; i>=0; i--) {
        if(sparse[u][i] == sparse[v][i]) continue;
        u = sparse[u][i];
        v = sparse[v][i];
    }
    return sparse[u][0];
}


int main() {
    int n = 8; // Number of vertices
    int total_parents = static_cast<int>(log2(n)) + 2;
    int root = 0;
    vector<vector<int>> adj = {
        {3, 7},
        {2, 3},
        {1, 4, 5},
        {0, 1, 6},
        {2},
        {2},
        {3},
        {0}
    };

    vector<vector<int>> sparse = get_sparse_table(n, total_parents, adj, root);

    vector<int> level(n, 0);
    get_levels(n, adj, root, level);

    int lca = getLCA(n, total_parents, adj, level, sparse, 4, 6);
    cout << "lca :" << lca << endl;
}
