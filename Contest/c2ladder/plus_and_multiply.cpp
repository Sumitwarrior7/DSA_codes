#include <bits/stdc++.h>
using namespace std;
#define int long long
 
string funcn(int n, int a, int b) {
    if (a == 1) {
        if ((n-1) % b == 0) return "Yes";
        return "No";
    }

    int i = 0;
    while(pow(a, i) <= n) {
        int ai = pow(a, i);
        if ((n-ai) % b == 0) return "Yes";
        i++;
    }
    return "No";
}
 
 
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
 
        string ans = funcn(n, a, b);
        cout << ans << endl;
    }
 
}