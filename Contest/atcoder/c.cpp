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
#define IFOR(i, a, b) for (int i = a; i < b; i++)
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


// int func(int n, vi &s) {
//     if(n==1) return s[0];
//     else if(n==2) return s[0]+(2*s[1]);

//     vector<int> dp(n, 0);
//     dp[0]=s[0];
//     dp[1]=dp[0];
//     IFOR(i, 2, n) {
//         int c1 = dp[i-1];
//         int c2 = dp[i-2]+s[i]+(2*s[i-1]);
//         dp[i] = max(c1, c2);
//     }
//     int ans1 = max(dp[n-1], (2*s[n-1])+dp[n-2]);

//     vector<int> dpn(n, 0);
//     dpn[0]=0;
//     dpn[1]=s[1];
//     dpn[2]=dpn[1];
//     IFOR(i, 3, n) {
//         int c1 = dpn[i-1];
//         int c2 = dpn[i-2]+s[i]+(2*s[i-1]);
//         dpn[i] = max(c1, c2);
//     }
//     int ans2 = max(dpn[n-1], (2*s[n-1])+dpn[n-2]);

//     return max(ans1, ans2);
// }

int func(int n, vi &s) {
    vector<int> dp_odd(n, 0), dp_even(n, 0);
    
    dp_odd[0] = s[0];
    dp_even[0] = 0;
    
    for (int i = 1; i < n; ++i) {
        dp_odd[i] = max(dp_odd[i-1], dp_even[i-1] + s[i]);
        dp_even[i] = max(dp_even[i-1], dp_odd[i-1] + 2 * s[i]);
    }
    
    return max(dp_odd[n-1], dp_even[n-1]);
}



signed main() {
    FAST_IO
    int n;
    cin >> n;
    vi v(n);
    FOR(i, n) {
        cin >> v[i];
    } 
    int ans = func(n, v);
    cout << ans;
}