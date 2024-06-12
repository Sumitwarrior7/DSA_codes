#include <bits/stdc++.h>
using namespace std;
#define float double

int funcn(int n, vector<float> &arr) {
    if (n == 1) return 0;
    int mx = 0;
    for (int i = 0; i < n ; i++) {
        for (int j = i+1; j < n; j++) {
            if (i == j) continue;
            else {
                float d = (arr[j]-arr[i]) / (j-i);
                float a = arr[i] - (i*d);
                int c = 0;
                for (int k = 0; k < n; k++) {
                    if (abs(arr[k] - (a +(k*d))) < 1e-9) c++;
                }
                mx = max(mx, c);
            }
        }
    }
    return n-mx;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<float> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        } 

        int ans = funcn(n, v);
        cout << ans << endl;
    }

}

