#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))


// It takes TC : O(nlogn)
// Returns the value of maximum itersetcion of the intervals at a point
int sweep_line(vector<pair<int, int>> &intervals_arr) {
    map<int, int> mp;
    for(auto& interval : intervals_arr){
        mp[interval.first]++;
        mp[interval.second+1]--;    // (+1 or not) depends on the question
    }

    int ans = 0;
    int count = 0;
    for(auto& it : mp){
        count += it.second;
        ans = max(ans, count);
    }
    return ans;
}


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        } 

        int ans = sweep_line(v);
        cout << ans << endl;
    }

}
