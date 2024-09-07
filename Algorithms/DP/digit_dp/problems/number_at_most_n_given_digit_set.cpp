# Problem Link : https://leetcode.com/problems/numbers-at-most-n-given-digit-set

class Solution {
public:
    int rec(int n, string &s, map<int, bool> mp, int ind, bool av, bool lz, vector<vector<vector<int>>> &memo) {
        if(ind >= n) {
            if(lz == false) return 1;
            else return 0;
        }

        if(memo[ind][av][lz] != -1) return memo[ind][av][lz];

        int ans = 0;
        int lim = (av)?9:s[ind]-'0';
        for(int i=0; i<=lim; i++) {
            if(i == lim) {
                if(i == 0) {
                    if(lz == true) ans += rec(n, s, mp, ind+1, (av)?true:false, true, memo);
                }
                else {
                    if(mp[i] == true) ans += rec(n, s, mp, ind+1, (av)?true:false, false, memo);
                }
            }
            else {
                if(i == 0) {
                    if(lz == true) ans += rec(n, s, mp, ind+1, true, true, memo);
                }
                else {
                    if(mp[i] == true) ans += rec(n, s, mp, ind+1, true, false, memo);
                }
            }
        }
        memo[ind][av][lz] = ans;
        return ans;
    }


    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        map<int, bool> mp;
        for(auto it: digits) mp[stoi(it)] = true;
        vector<vector<vector<int>>> memo(s.size()+2, vector<vector<int>>(2, vector<int>(2, -1)));
        int ans = rec(s.size(), s, mp, 0, false, true, memo);
        return ans;
    }
};