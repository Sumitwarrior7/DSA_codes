vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    vector<int> dis(n+1, INT_MAX);
    dis[0] = 0;
    dis[s] = 0;

    vector<vector<pii>> adj(n+1);
    for(auto it: edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[1], it[2]});
    }

    priority_queue<pii, vector<pii>, greater<pii>> mh;
    mh.push({0, s});

    while(!mh.empty()) {
        auto tp = mh.top();
        mh.pop();
        int node = tp.second;
        int dist = tp.first;
        for(auto it: adj[node]) {
            int nbr = it.first;
            int wt = it.second;
            if(dist+wt < dis[nbr]) {
                dis[nbr] = dist+wt;
                mh.push({dist+wt, nbr});
            }
        }
    }

    vector<int> ans;
    for(auto it: dis) {
        if(it == 0) continue;
        else if(it == INT_MAX) ans.push_back(-1);
        else ans.push_back(it);
    }
    return ans;
}