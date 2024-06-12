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



#include <bits/stdc++.h>
using namespace std;

string rec(string &s, string &t, int i, int j, vector<vector<string>> &memo) {
    if ((i >= s.size()) || (j >= t.size())) return "";
    
    if (memo[i][j] != "") return memo[i][j];
    
    string ans;
    if (s[i] == t[j]) {
        if (memo[i+1][j+1] == "") memo[i+1][j+1] = rec(s, t, i+1, j+1, memo);
        ans = s[i]+memo[i+1][j+1];
    } 
    else {
        if (memo[i][j+1] == "") memo[i][j+1] = rec(s, t, i, j+1, memo);
        string s1 = memo[i][j+1];
        if (memo[i+1][j] == "") memo[i+1][j] = rec(s, t, i+1, j, memo);
        string s2 = memo[i+1][j];
        
        if (s1.size() >= s2.size()) ans = s1;
        else ans = s2;
    }
    memo[i][j] = ans;
    return ans;
}

int main() {
    string s, t;
    cin >> s >> t;
    vector<vector<string>> memo(s.size()+1, vector<string>(t.size()+1, ""));
    string ans = rec(s, t, 0, 0, memo);
    cout << ans;
}







int main() {
    string s, t;
    cin >> s >> t;
    string ans = rec(s, t, 0, 0);
    cout << ans;
}