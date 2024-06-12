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
    const int MOD = 1000000007;
    vector<int> dp(x+1);

    dp[0] = 1;

    for (int i = 1; i < x+1; i++) {
        long int ways = 0;
        for (auto c: v) {
            if (i-c >= 0) ways = (ways + dp[i-c]) % MOD;;
        }

        dp[i] = ways;
    }

    cout << dp[x];

}