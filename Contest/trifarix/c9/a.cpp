#include <bits/stdc++.h>
using namespace std;

int func(int n, int x, int y, int z, int t, vector<int> &v) {
    int c_ans = 0;
    for (int i = x; i <= z; i++ ) c_ans = c_ans^v[i-1];

    int r_ans = 0;
    for (int j = y; j <= t; j++ ) r_ans = r_ans^v[j-1];

    return c_ans & r_ans;
}

int main() {
    int n, x, y, z, t;
    cin >> n >> x >> y >> z >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = func(n, x, y, z, t, v);
    cout << ans;

}
