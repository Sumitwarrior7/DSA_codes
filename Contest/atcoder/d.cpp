/* ----------------------------------Test cases template---------------------------------- */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))



int funcn(int n, int x) {
    if(x < 3) return 0;

    int ans = 0;
    for(int i=1; i<=(x-2); i++) {
        if(i >= x) break;
        if(i >= n) break;
        int nv = (x/i)+1;
        for(int j=1; j<=nv; j++) {
            if(i+j >= x) break;
            if(i*j >= n) break;
            int nv2 = (n/j)+1;
            int nnv = min(nv, nv2);
            for(int k=1; k<=nnv; k++) {
                if(i+j+k > x) break;
                if(((i*j) +(j*k) +(k*i)) > n) break;
                ans++;
            }
        }
    }
    return ans;
}


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;

        int ans = funcn(n, x);
        cout << ans << endl;
    }

}