#include <bits/stdc++.h>
using namespace std;
#define int long long

int charToInt(char c) {
    return c - '0';
}

int funcn(int l, int r) {
    string l_str = to_string(l);
    string r_str = to_string(r);

    int nl = l_str.size();
    int nr = r_str.size();

    int rv = 0;
    int rc = 1;
    int rp = 0;
    for (int i = nr-1; i >= 0; i--) {
        int ri = charToInt(r_str[i]);
        rv += (ri*rc);
        rp++;
        rc += pow(10, rp);
    }

    int lv = 0;
    int lc = 1;
    int lp = 0;
    for (int j = nl-1; j >= 0; j--) {
        int lj = charToInt(l_str[j]);
        lv += (lj*lc);
        lp++;
        lc += pow(10, lp);
    }

    return rv-lv;
}


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;

        int ans = funcn(l, r);
        cout << ans << endl;
    }

}
