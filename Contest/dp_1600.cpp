/* ----------------------------------Basic Template---------------------------------- */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))



int func(int n, vector<pair<int, int>> &arr) {
    priority_queue<int, vector<int>, greater<int>> mh;
    int ans = 0;
    for(int i=0; i<n; i++) {
        int l = arr[i].first;
        int r = arr[i].second;
        if (i == 0) {
            mh.push(r);
            continue;
        }
        if(l <= mh.top()) {
            ans += mh.size();
            mh.push(r);
        }
        else {
            while(!mh.empty()) {
                int top = mh.top();
                if(top < l) mh.pop();
                else {
                    ans += mh.size();
                    break;
                }
            }
            mh.push(r);
        }
    }
    return ans;
}


signed main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int li, ri;
        cin >> li >> ri;
        a.push_back({li, ri});
    } 
    sort(a.begin(), a.end());   
    int ans = func(n, a);
    cout << ans;
}

