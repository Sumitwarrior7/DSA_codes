#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))

    

string funcn(int n, int m, int k, vector<int> &a, vector<int> &b) {
    unordered_map<int, bool> amp;
    unordered_map<int, bool> bmp;
    // for(int i = 1; i <= 1e6; i++) {
    //     amp[i] = false;
    //     bmp[i] = false;
    // }

    for(auto it: a) amp[it] = true;
    for(auto it: b) bmp[it] = true;

    int ac = 0;
    int bc = 0;
    for(int i = 1; i <= k; i++) {
        if (amp[i] == false && bmp[i] == false) return "NO";
        if (amp[i] == true) ac++;
        if (bmp[i] == true) bc++;
    }

    if (ac < (k/2) || bc < (k/2)) return "NO";
    else return "YES";
}


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        } 
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        } 

        string ans = funcn(n, m, k, a, b);
        cout << ans << endl;
    }

}
