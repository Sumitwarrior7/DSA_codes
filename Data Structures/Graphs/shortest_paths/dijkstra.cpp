#include <bits/stdc++.h>
using namespace std;


/* Approach 1 : Using Set */
vector<int> dijkstra_set(int n, vector<vector<pair<int, int>>> &adj, int source) {
    set<pair<int, int>> st; // {distance from source, node}
    vector<int> dist(n, INT_MAX);

    dist[source] = 0;
    st.insert({0, source});

    while (!st.empty()) {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        st.erase(it);

        for (auto nbr : adj[node]) {
            int edge_wt = nbr.first;
            int adj_node = nbr.second;

            if (dis + edge_wt < dist[adj_node]) {
                // erase if it was visited previously at a greater cost.
                if (dist[adj_node] != 1e9)
                    st.erase({dist[adj_node], adj_node});

                // If current distance is smaller, push it into the queue
                dist[adj_node] = dis + edge_wt;
                st.insert({dist[adj_node], adj_node});
            }
        }
    }
    return dist;
}

/* Approach 2 : Using Priority Queue */
vector<int> dijkstra_pq(int n, vector<vector<pair<int, int>>> adj, int source_node) {
    // Stores {distance from source, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dis_arr(n, INT_MAX);
    dis_arr[source_node] = 0;
    pq.push({0, source_node});

    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Very Powerful line in terms of Time Complexity
        if (dis_arr[node] < dis) continue;

        for (auto nbr : adj[node]) {
            int wt = nbr.first;
            int v = nbr.second;
            if (dis + wt < dis_arr[v]) {
                dis_arr[v] = dis + wt;
                pq.push({dis + wt, v});
            }
        }
    }
    return dis_arr;
}




int main()
{
    int n1 = 5;
    vector<vector<pair<int, int>>> adj1(n1 + 1);
    adj1[1] = {{1, 2}, {4, 3}};
    adj1[2] = {{2, 3}, {5, 4}};
    adj1[3] = {{1, 4}};
    adj1[4] = {};
    adj1[5] = {};

    int source1 = 1;
    vector<int> result_set = dijkstra_set(n1, adj1, source1);
    vector<int> result_pq = dijkstra_pq(n1, adj1, source1);

    cout << "Using set: ";
    for (int d : result_set)  cout << (d == INT_MAX ? "INT_MAX" : to_string(d)) << " ";
    cout << endl;

    cout << "Using PQ: ";
    for (int d : result_pq)  cout << (d == INT_MAX ? "INT_MAX" : to_string(d)) << " ";
    cout << endl;   

    return 0;
}