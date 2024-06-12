#include<bits/stdc++.h>
using namespace std;

// BFS
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color_arr(V, -1);
	    for (int it = 0; it < V; it++) {
	        if (color_arr[it] == -1) {
	            queue<int> q;
        	    q.push(it);
        	    color_arr[it] = 0;
        	    while(!q.empty()) {
        	        int node = q.front();
        	        q.pop();
        	        int color = color_arr[node];
        	        for(auto nbr: adj[node]) {
        	            if (color_arr[nbr] == -1) {
        	                q.push(nbr);
        	                color_arr[nbr] = 1-color;
        	            } else{
        	                if (color_arr[nbr] == color) return false;
        	            }
        	        }
        	    }
	            
	        }
	    }

	    return true;
    };
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends