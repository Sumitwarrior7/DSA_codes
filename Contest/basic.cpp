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



int func(int n, vector<int> &v) {
    return 0;
}


signed main() {
    int n;
    cin >> n;
    vi v(n);
    FOR(i, n) {
        cin >> v[i];
    } 
    int ans = func(n, v);
    cout << ans;
}


/* ----------------------------------Test cases template---------------------------------- */
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

    

int funcn(int n, vector<int> &arr) {
    
}


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi v(n);
        FOR(i, n) {
            cin >> v[i];
        } 

        int ans = funcn(n, v);
        cout << ans << endl;
    }

}
