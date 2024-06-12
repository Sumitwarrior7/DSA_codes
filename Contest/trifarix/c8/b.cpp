#include <bits/stdc++.h>
using namespace std;

int func(string &s) {
    int n = s.size();
    int trend = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (i == n-1) {
            ans++;
        }
        else {
            if (trend == 0) {
                if (s[i+1] > s[i]) trend = 1;
                else if (s[i+1] < s[i]) trend = -1;
            }
            else if (trend == 1) {
                if (s[i+1] < s[i]){
                    ans++;
                    trend = 0;
                }
            } else {
                 if (s[i+1] > s[i]){
                    ans++;
                    trend = 0;
                }               
            }
        }
    }
    return ans;
}


int main() {
    string s;
    cin >> s;
    int ans = func(s);
    cout << ans;
}
