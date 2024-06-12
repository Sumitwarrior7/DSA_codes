class Solution {
public:
    int rec(vector<int> &arr, int ind, int msk, vector<int> &vec, bool et) {
        if(ind >= arr.size()) {
            if(et == false) return 0;
            else return 1;
        }
        
        int ans = 0;
        // ind not taken
        int c1 = rec(arr, ind+1, msk, vec, (et)?true:false);
        ans += c1;

        // ind taken
        int nm = msk;
        bool take = true;
        
        if(arr[ind] != 1) {
            for(int i=0; i<10; i++) {
                if(arr[ind]%vec[i] == 0) {
                    if((nm&(1<<i)) == 0) {
                        nm = (nm^(1<<i));
                    }
                    else {
                        take = false;
                        break;
                    }
                }
            }
        }

        if(take) ans += rec(arr, ind+1, nm, vec, true);
        return ans;
    }

    int squareFreeSubsets(vector<int>& nums) {
        vector<int> arr;
        vector<int> rem = {4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28};
        for(auto it: nums) {
                bool prs = false;
                for(auto item: rem) {
                    if(it == item) {
                        prs = true;
                        break;
                    }
                }
                if(prs) continue;
                else arr.push_back(it);
        }
        for(auto it: arr) cout << it << " ";

        vector<int> v = {2,3,5,7,11,13,17,19,23,29};

        int ans = rec(arr, 0, 0, v, false);
        return ans;
    }
};