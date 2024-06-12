#include <bits/stdc++.h>
using namespace std;

int func(int n, vector<int> v) {
    return 0;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        bool ans = false;
        for (int i = 0; i < n-1; i++) {
            if (s[i+1] != '0') {
                string a = s.substr(0, i+1);
                string b = s.substr(i+1, n-i-1);
                if (stoi(b) > 0 && stoi(a) > 0 && stoi(b) > stoi(a)) {
                    cout << a << " " << b << endl;
                    ans = true;
                    break;
                }
            }
        }
        if (ans == false) {
            cout << -1 << endl;
        }
    }
}






// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color_arr(V, -1);
	    queue<int> q;
	    q.push(0);
	    color_arr[0] = 0;
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
	    return true;
    };
};
