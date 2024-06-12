#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    int x;
    cin >> n >> x;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int item;
        cin >> item;
        v.push_back(item);
    }

    // Tabulation
    vector<int> dp(x+1);

    dp[0] = 0;

    for (int i = 1; i < x+1; i++) {
        int ans = INT_MAX;
        for (auto c: v) {
            if (i-c >= 0 && dp[i-c] != -1) ans = min(ans, dp[i-c]);
        }

        if (ans == INT_MAX) dp[i] = -1;
        else dp[i] = 1+ans;
    }

    cout << dp[x];

}