#include <bits/stdc++.h>
using namespace std;

long int cc1(long int n, long int tar, vector<long int> &coins, vector<long int> &memo) {
    const int MOD = 1000000007;
    if (tar == 0) return 1;

    if (memo[tar] != -1) return memo[tar];

    long int ways = 0;
    for (auto c :coins) {
        if (tar >= c) {
            if (memo[tar-c] == -1) memo[tar-c] = cc1(n, tar-c, coins, memo);
            ways = (ways + memo[tar-c]) % MOD;
        }
    }
    memo[tar] = ways;
    return ways;
}


int main() {
    long int n;
    long int x;
    cin >> n >> x;
    vector<long int> v;
    vector<long int> memo(x+1, -1);
    for (int i = 0; i < n; i++) {
        long int item;
        cin >> item;
        v.push_back(item);
    }

    long int sol = cc1(n, x, v, memo);
    cout << sol;
}