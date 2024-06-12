class Solution {
public:
    int MOD = 1e9+7;
    int rec(string &s, int &mn, int &mx , int ind, bool av, int ps, vector<vector<vector<int>>> &memo) {
        int sz = s.size();
        if(ind == sz) {
            // cout << "ps :" << ps << endl;
            if(mn <= ps && ps <= mx) return 1;
            else return 0;
        }
        if(memo[ind][av][ps] != -1) return memo[ind][av][ps];

        if(av) {
            int a1 = 0;
            for(int i=0; i<10; i++) {
                a1 = (a1+rec(s, mn, mx, ind+1, true, ps+i, memo))%MOD;
            }
            memo[ind][av][ps] = a1%MOD;
            return a1%MOD;
        }
        else {
            int sind = s[ind]-'0';
            // cout << "sind :" << sind << endl;
            int a2 = 0;
            if(sind == 0) {
                a2 = (a2+rec(s, mn, mx, ind+1, false, ps, memo))%MOD;
            }
            else {
                for(int i=0; i<sind; i++) {
                    a2 = (a2+rec(s, mn, mx, ind+1, true, ps+i, memo))%MOD;
                }
                a2 = (a2+rec(s, mn, mx, ind+1, false, ps+sind, memo))%MOD;
                // a2 %= MOD;
            }
            memo[ind][av][ps] = a2%MOD;
            return a2%MOD;
        }
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        int sz = num1.size();
        int ind = sz-1;
        while(ind >= 0) {
            if(num1[ind] == '0') {
                num1[ind] = '9';
                ind--;
            }
            else {
                num1[ind] = num1[ind]-1;
                break;
            }
        }
        if(num1.size() != 1 && num1[0] == '0') num1.erase(0, 1);

        vector<vector<vector<int>>> memo1(num1.size()+1, vector<vector<int>>(2, vector<int>(401, -1)));
        vector<vector<vector<int>>> memo2(num2.size()+1, vector<vector<int>>(2, vector<int>(401, -1)));
        int big_ans = rec(num2, min_sum, max_sum, 0, false, 0, memo2);
        int small_ans = rec(num1, min_sum, max_sum, 0, false, 0, memo1);
        if(num1.size() == 1 && num1[0] == '0') small_ans = 0;

        return big_ans-small_ans;
    }
};