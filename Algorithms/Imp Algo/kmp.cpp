#include<bits/stdc++.h>
using namespace std;

// Largest prefix that matches a suffix
vector<int> kmp(string s){
    vector<int> lps(s.size(), 0);

    for(int i=1;i<lps.size();i++){
        int prev_idx = lps[i-1];
        while(prev_idx>0 && s[i] != s[prev_idx]){
            prev_idx = lps[prev_idx-1];
        }
        lps[i] = prev_idx + (s[i]==s[prev_idx] ? 1 : 0);
    }
    return lps;
}


int main() {
    string s = "mynameissumit,onedayiwillhavethebiggestbusinessempireintheworld";
    string pattern = "the";
    string reqd = pattern + "#" + s;

    vector<int> lps(reqd);
}