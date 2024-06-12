#include <bits/stdc++.h>
using namespace std;


int min_coins(int n, long int tar, vector< long int> &v, vector< long int> &memo) {
    if (memo[tar] != -2) return memo[tar];

    long int ans = INT_MAX;
    long int one = 1;
    for (auto coin: v) {
        if (tar > coin) {
            if (memo[tar-coin] == -2) memo[tar-coin] = min_coins(n, tar-coin, v, memo);
            long int rec = memo[tar-coin];
            if (rec >= 0) ans = min(ans, 1+rec);
        } else if (tar == coin) {
            ans = min(ans, one);
        }
    }
    if (ans == INT_MAX) {
        memo[tar] = -1;
        return -1;
    }
    else {
        memo[tar] = ans;
        return ans;
    }
    
}


int main() {
    int n;
    long int x;
    cin >> n >> x;
    vector<long int> v;
    vector<long int> memo(x+1, -2);
    for (int i = 0; i < n; i++) {
        long int item;
        cin >> item;
        v.push_back(item);
    }
    int ans = min_coins(n, x, v, memo);
    cout << ans;
}