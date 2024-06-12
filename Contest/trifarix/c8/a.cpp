#include <bits/stdc++.h>
using namespace std;

int func(int n, int k, vector<int> &v) {
    int sc = 0;
    int ec = 0;
    int bc = 0;
    for (auto it: v) {
        if (it == k) ec++;
        else if (it > k) bc++;
        else sc++;
    }

    if (sc ==0 || bc == 0) return 0;
    if (sc == bc) return n;
    int i = 0;
    int j = 0;
    if (bc > sc) {
        int diff = bc-sc;
        while (j < n) {
            sum += arr[j];
            if (sum < k) j++;
            else if (sum == k) {
                ans = max(ans, j-i+1);
                j++;
            }
            else {
                while(sum > k) {
                    sum -= arr[i];
                    i++;
                }
                if (sum == k) ans = max(ans, j-i+1);
                j++;
            }
        }
    }
    else {

    }
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int vi;
            cin >> vi;
            v.push_back(vi);
        } 
        int ans = func(n, k, v);
        cout << ans;
    }


}
