// problem Link : https://leetcode.com/problems/number-of-digit-one/description

class Solution {
public:
    int rec(int n, string &s, int ind, bool av, int ones, vector<vector<vector<int>>> &memo) {
        if(ind >= n) {
            return ones;
        }

        if(memo[ind][av][ones] != -1) return memo[ind][av][ones];

        int limit = (av)?9: s[ind]-'0';
        int ans = 0;
        for(int i=0; i<=limit; i++) {
            if(i == limit) {
                ans += rec(n, s, ind+1, (av)?true:false, (av)?ones:((i==1)?ones+1:ones),memo);
            }
            else {
                ans += rec(n, s, ind+1, true, (i==1)?ones+1:ones, memo);
            }
        }
        memo[ind][av][ones] = ans;
        return ans;
    }

    int countDigitOne(int n) {
       if (n == 0) return 0;
       if (n < 10) return 1;
       string s = to_string(n); 
       int sz = s.size();
       vector<vector<vector<int>>> memo(sz + 1, vector<vector<int>>(2, vector<int>(sz + 1, -1)));
       int ans = rec(sz, s, 0, false, 0, memo);
       return ans;
    }
};