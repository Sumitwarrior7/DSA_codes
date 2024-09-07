/* 
Time Complexity : O(n logn)
-> You can't print the actual lis with this approach, only lis length is given by this approach
*/


class Solution {
public:
    int lower_bound(vector<int> &arr, int val) {
        int n = arr.size();
        int ans = -1;
        int i = 0;
        int j = n-1;
        while(i <= j) {
            int m = (i+j)/2;
            if(arr[m] >= val) {
                ans = m;
                j = m-1;
            }
            else i=m+1;
        }
        return ans;
    }


    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> modified_lis_arr;
        for(int i=0; i<n; i++) {
            if(i == 0) modified_lis_arr.push_back(nums[i]);
            else {
                if(nums[i] > modified_lis_arr[modified_lis_arr.size()-1]) modified_lis_arr.push_back(nums[i]);
                else {
                    int lbi = lower_bound(modified_lis_arr, nums[i]);
                    modified_lis_arr[lbi] = nums[i];
                }
            }
        }
        return modified_lis_arr.size();
    }
};