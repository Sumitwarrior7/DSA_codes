#include <bits/stdc++.h>
using namespace std;


// Printing LCS(lowest common subsequence)  [Recursive]
string rec(string &s, string &t, int i, int j) {
    if ((i >= s.size()) && (j >= t.size())) return "";
    
    if (s[i] == t[j]) {
        return s[i]+rec(s, t, i+1, j+1);
    } else {
        string s1 = rec(s, t, i, j+1);
        string s2 = rec(s, t, i+1, j);
        if (s1.size() >= s2.size()) return s1;
        else return s2;
    }
}

int main() {
    string s, t;
    cin >> s >> t;
    string ans = rec(s, t, 0, 0);
    cout << ans;
}