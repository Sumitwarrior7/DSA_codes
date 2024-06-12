#include <bits/stdc++.h>
using namespace std;
#define int long long

int func(int n, vector<int> &arr) {
    int ans = 0;
    int nind = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) ans++;
        if (arr[i] < 0) nind = i;
    }
    if (nind == -1) return n;

    priority_queue<int> pq;
    for (int j = nind; j >= 0; j--) {
        if (arr[j] < 0) pq.push(arr[j]);
        else if (arr[j] > 0) {
            while (!pq.empty()) {
                int te = pq.top();
                if (abs(te) <= arr[j]) {
                    ans++;
                    arr[j] -= abs(te);
                    pq.pop();
                } else {
                    te += arr[j];
                    pq.pop();
                    pq.push(te);
                    break;
                }
            }
        }
    }
    return ans;
    return 0;
}


signed main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int vi;
        cin >> vi;
        v.push_back(vi);
    } 
    int ans = func(n, v);
    cout << ans;
}