#include<bits/stdc++.h>
using namespace std;

/* Topological Sort using BFS */
vector<int> topologicalSort(vector<vector<int>> &adj, int V) {
    // Storing Indegress of each nodes
    vector<int> indegree(V);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) indegree[it]++;
    }

    // Queue store only those nodes which have indegree as 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    // BFS
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
    
        for (auto it : adj[node]) {
            indegree[it]--;
            // If indegree becomes 0, push it to the queue
            if (indegree[it] == 0) q.push(it);
        }
    }

    // Check for cycle
    if (result.size() != V) {
        cout << "Graph contains cycle!" << endl;
        return {};
    }

    return result;
}