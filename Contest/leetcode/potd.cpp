class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long tp = 1; 
        for(auto it: nums) tp *= it;
        long long dvd = abs(tp);

        bool tpp = true;
        if(tp<0) tpp = false;

        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            bool np = true;
            if(nums[i]<0) np = false;
            int power = 0;
            int num = abs(nums[i]);
            int pwr = 0;
            while(num*pow(2, power) <= tp) {
                pwr = power;
                power++;
            }

            int ind_ans = 0;
            for(int j=pwr; j>=0; j--) {
                if(num*pow(2, j) <= dvd) ind_ans += pow(2, j);
            }
            
            if((tpp<0 && np>=0)||(tpp>=0 && np<0)) ans.push_back(-ind_ans);
            else ans.push_back(ind_ans);
        }
        return ans;
    }
};