#include <bits/stdc++.h>
using namespace std;


pair<int, vector<vector<int>>> mst_prim(int n, vector<vector <pair<int, int>>> &adj) {
    // pq : {wt, {node, parent}}
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	vector<bool> vis(n, false);
    vector<vector<int>> bst;

	pq.push({0, {0, -1}});
	int sum = 0;
	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();

        int wt = it.first;
		int node = it.second.first;
        int par = it.second.second;
		if (vis[node] == true) continue;
		
		vis[node] = true;
		sum += wt;
        bst.push_back({par, node, wt});
		for (auto nbr : adj[node]) {
			int adj_node = nbr.first;
			int edge_wt = nbr.second;
			if (vis[adj_node] == false) {
				pq.push({edge_wt, {adj_node, node}});
			}
		}
	}
	return {sum, bst};
}




int main() {
	int V = 5;
    vector<vector <pair<int, int>>> adj = {{{1, 2}, {2, 1}}, {{2, 1}}, {{3, 2}}, {{4, 1}}, {{2, 2}}};

	pair<int, vector<vector<int>>> ans = mst_prim(V, adj);
	cout << "The sum of all the edge weights: " << ans.first << endl;

    cout << "BST :-" << endl;
    for (auto it: ans.second) {
        cout << it[0] << " --> " << it[1] << "  = " << it[2] << endl;
    }

	return 0;
}