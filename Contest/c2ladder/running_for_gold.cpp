#include <bits/stdc++.h>
using namespace std;

int funcn(int n, vector<vector<int>> &arr) {
    if (n == 1) return 1;

    int winner = 1;
    for (int i = 2; i <= n; i++) {
        vector<int> winner_arr = arr[winner-1];
        vector<int> curr_arr = arr[i-1];
        int cnt = 0;
        for(int j = 0; j < 5; j++) {
            if (winner_arr[j] < curr_arr[j]) cnt++;
        }
        if (cnt < 3) winner = i;
    }

    for (int i = 1; i <= n; i++) {
        vector<int> w = arr[winner-1];
        vector<int> c = arr[i-1];

        if (winner != i) {
            int count = 0;
            for(int j = 0; j < 5; j++) {
                if (w[j] < c[j]) count++;
            }
            if (count < 3) return -1;
        }
    }
    return winner;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            vector<int> vec(5);
            for (int j= 0; j < 5; j++) {
                cin >> vec[j];
            }
            v.push_back(vec);
        } 

        int ans = funcn(n, v);
        cout << ans << endl;
    }
    return 0;

}