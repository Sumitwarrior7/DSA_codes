// problem Link : https://atcoder.jp/contests/abc356/tasks/abc356_d



/* ----------------------------------Basic Template---------------------------------- */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
#define MOD 998244353

vector<int> convert_to_binary(int num) {
    vector<int> ans;
    for(int i=0; i<61; i++) {
        ans.push_back((num>>i)&1);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int rec(vector<int> &na, vector<int> &ma, int ind, bool av, int cnt, vector<vector<vector<int>>> &memo) {
    int n = na.size();
    if(ind >= n) {
        return cnt;
    }

    if (memo[ind][av][cnt] != -1) return memo[ind][av][cnt];

    int ans = 0;
    if(av) {
        ans = (ans + rec(na, ma, ind+1, true, cnt, memo)) % MOD;
        ans = (ans + rec(na, ma, ind+1, true, (ma[ind] == 1)?cnt+1:cnt, memo)) % MOD;
    }
    else {
        if(na[ind] == 0) {
            ans = (ans + rec(na, ma, ind+1, false, cnt, memo)) % MOD;
        }
        else {
            ans = (ans + rec(na, ma, ind+1, true, cnt, memo)) % MOD;
            ans = (ans + rec(na, ma, ind+1, false, (ma[ind] == 1)?cnt+1:cnt, memo)) % MOD;
        }
    }
    memo[ind][av][cnt] = ans%MOD;
    return ans%MOD;

}


signed main() {
    int n, m;
    cin >> n >> m;

    if(n == 0 || m == 0) cout << 0;
    else {
        vector<int> na = convert_to_binary(n);
        vector<int> ma = convert_to_binary(m);
        int ind;
        for(int i=0; i<na.size(); i++) {
            if(na[i] == 1) {
                ind = i;
                break;
            }
        }
        vector<int> n_arr, m_arr;
        for(int i=ind; i<na.size(); i++) {
            n_arr.push_back(na[i]);
            m_arr.push_back(ma[i]);
        }

        vector<vector<vector<int>>> memo(n_arr.size()+1, vector<vector<int>>(2, vector<int>(n_arr.size()+1, -1)));
        int ans = rec(n_arr, m_arr, 0, false, 0, memo);
        cout << ans;
    }
}