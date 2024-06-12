#include <bits/stdc++.h>
using namespace std;
#define int long long

string funcn(int n, vector<int> &arr) {
    for (int i = 0; i < n-1; i++) {
        int fs = 0;
        for (int j = 0; j <= i; j++) {
            fs ^= arr[j];
        }

        int ss = 0;
        for (int k = i+1; k < n; k++) {
            ss ^= arr[k];
        }
        if (fs == ss) return "YES";
    }

    for (int i = 0; i < n-2; i++) {
        int a = 0;
        for (int j = 0; j <= i; j++) {
            a ^= arr[j];
        }

        int flag = 0;
        int b = 0;
        for (int k = i+1; k < n; k++) {
            b ^= arr[k];
            if (flag == 0 && b == a) {
                flag = 1;
                b = 0;
            }
        }
        if (flag == 1) {
            if (b == a) return "YES";
        }
    }
    return "NO";
}


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        } 

        string ans = funcn(n, v);
        cout << ans << endl;
    }

}