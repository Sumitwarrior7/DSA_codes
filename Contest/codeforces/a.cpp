class Solution {
public:
    bool rec(vector<int>& nums, int &n, int &k, int &tar, int msk, int sm, int cnt, vector<vector<vector<int>>> &memo) {
        if(msk==0) {
            if(k == cnt && sm == 0) return true;
            else return false;
        }

        if(memo[msk][sm][cnt] != -1) return memo[msk][sm][cnt];

        for(int i=0; i<n; i++) {
            if((msk&(1<<i)) != 0) {
                if(sm+nums[i] == tar) {
                    bool c1 = rec(nums, n, k, tar, msk^(1<<i), 0, cnt+1, memo);
                    if(c1) {
                        memo[msk][sm][cnt] = 1;
                        return true;
                    }
                }
                else if (sm+nums[i] < tar) {
                    bool c2 = rec(nums, n, k, tar, msk^(1<<i), sm+nums[i], cnt, memo);
                    if(c2) {
                        memo[msk][sm][cnt] = 1;
                        return true;
                    }
                } 
            }
        }
        memo[msk][sm][cnt] = 0;
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int ts = 0;
        for(auto it: nums) ts += it;
        if(ts%k!=0) return false;

        int tar = ts/k;
        int msk = 0;
        for(int i=0; i<n; i++) msk += pow(2, i);
        vector<vector<vector<int>>> memo(msk+2, vector<vector<int>>(tar+2, vector<int>(k+2, -1)));
        bool check = rec(nums, n, k, tar, msk, 0, 0, memo);
        return check;
    }
};