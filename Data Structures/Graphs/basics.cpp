#include <bits/stdc++.h>
using namespace std;

/* ---------------------Input Format--------------------- */
// n = number of nodes
// m = number of edges
// u -> v  (edge) 



/* ------------------------Graphs with NO weights------------------------ */
// Undirected graph stored using adjency matrix
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector <int>> mat(n+1, vector<int>(n+1));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }
    return 0;
}


// Undirected graph stored using adjency list
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}


// Directed graph stored using adjency list
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    return 0;
}



/* ------------------------Graphs with weights------------------------ */
// Undirected graph stored using adjency matrix with weights
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector <int>> mat(n+1, vector<int>(n+1));
    for (int i = 0; i < m; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;

        mat[u][v] = weight;
        mat[v][u] = weight;
    }
    return 0;
}


// Undirected graph stored using adjency list with weights
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector <pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
    return 0;
}


// Directed graph stored using adjency list with weights
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector <pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;

        adj[u].push_back({v, weight});
        // adj[v].push_back({u, weight});
    }
    return 0;
}
