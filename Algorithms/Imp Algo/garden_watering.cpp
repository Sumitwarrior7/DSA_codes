#include <bits/stdc++.h>
using namespace std;

int gw(int n, vector<int> &ranges) {
    int left = 0;
    int right = 0;
    int tap_opens = 0;

    while (right < n) {
        for (int i = 0; i < n; i++) {
            if ((i-ranges[i]) <= left && (i+ranges[i]) > right) {
                right = i+ranges[i];
            } 
        }
        // There is No tap which can water after right, and including the left
        if (left == right) return -1;

        left = right;
        tap_opens++;
    }
    return tap_opens;
}


int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int vi;
        cin >> vi;
        v.push_back(vi);
    } 
    int ans = gw(n, v);
    cout << ans;
}
