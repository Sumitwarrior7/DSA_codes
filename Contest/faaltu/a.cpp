#include <bits/stdc++.h>
using namespace std;
#define int long long

int funcn(int n, vector<pair<int, int>> &arr) {
    int mx = 1000000000;
    int one = 1;
    int two = mx;
    set<int> three;
    for (auto it: arr) {
        if (it.first == 1) {
            one = max(one, it.second);
        }
        else if (it.first == 2) {
            two = min(two, it.second);
        }
        else {
            three.insert(it.second);
        }
    }

    if (one == two) {
        for (auto it: three) {
            if ((it == one)) return 0;
        }
        return 1;
    } else if (one > two) {
        return 0;
    } else {
        int ans = 0;
        ans += two - one + 1;
        for (auto it: three) {
            if ((one <= it && it <= two)) ans--;
        }
        return ans;
    }
}


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            int a, x;
            cin >> a >> x;
            v.push_back({a, x});
        } 
        int ans = funcn(n, v);
        cout << ans << endl;
    }
}