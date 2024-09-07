/* ----------------------------------Basic Template---------------------------------- */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))

// My own macros
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORI(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define pii pair<int, int>
/*
    वसुधा का नेता कौन हुआ? भूखण्ड-विजेता कौन हुआ?
    अतुलित यश क्रेता कौन हुआ? नव-धर्म प्रणेता कौन हुआ?
    जिसने न कभी आराम किया,
    विघ्नों में रहकर नाम किया।
*/
// Notes :-
// ASCII -> UpperCase letter : [65, 90]
// ASCII -> LowerCase letter : [97, 122]
// ASCII -> Number : [48, 57] for {0, 1, 2, ... 9}

int count_element(int val, int l, int r, map<int, vector<int>> &mp) {
    if(mp.find(val) == mp.end()) return 0;
    auto lbi = lower_bound(mp[val].begin(), mp[val].end(), l);
    if(lbi == mp[val].end()) return 0;

    auto ubi = lower_bound(mp[val].begin(), mp[val].end(), r);
    // if(ubi == mp[val].end()) return 0;
    if (ubi == mp[val].begin()) {
        if (*ubi > val) return 0;
        return ubi-lbi+1;
    }
    if(*ubi == val) return ubi-lbi+1;
    else return (ubi-1-lbi+1);
}

    int get_occurrence(int num, int l, int r, map<int, vector<int>> &pos) {
        auto iter = pos.find(num);
        if (iter == pos.end()) {
            return 0;
        }
        const auto& vec = iter->second;
        auto iter_l = lower_bound(vec.begin(), vec.end(), l);
        if (iter_l == vec.end()) {
            return 0;
        }
        auto iter_r = upper_bound(vec.begin(), vec.end(), r);
        return iter_r - iter_l;
    }

signed main() {
    map<int, vector<int>> mp;
    mp[3].push_back(0);
    mp[3].push_back(1);
    mp[3].push_back(2);
    mp[3].push_back(4);
    mp[3].push_back(8);
    mp[3].push_back(9);
    // int ans = count_element(3, 1, 8, mp);
    int ans = get_occurrence(3, 1, 8, mp);
    cout << ans << endl;
}