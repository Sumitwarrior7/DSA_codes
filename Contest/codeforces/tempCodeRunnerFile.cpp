#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))


bool chcek_rectangle(int y, vector<int> &arr) {
    int x = arr.size();
    int cnt = 0;
    for(int i = 0; i < x; i++) {
        cnt += (arr[i]-y);
    }
    if (cnt == 0) return true;
    else return false;
}
    

string func(int n, vector<int> &arr) {
    if (n == 1) return "YES";
    
    int mn = INT_MAX;
    int mx = INT_MIN;
    int sm = 0;
    for(auto it : arr) {
        mn = min(mn, it);
        mx = max(mx, it);
        sm += it;
    }

    int l = mn;
    int r = mx;
    while(l <= r) {
        int mid = l+((r-l)/2);
        if (mid*n <= sm) {
            if (chcek_rectangle(mid, arr) == true) return "YES";
            l = mid+1;
        }
        else {
            r = mid-1;
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        } 

        string ans = func(n, a);
        cout << ans << endl;
    }

}
