class FWT {
    public:
    // bit will follow 1-based indexing
    vector<int> bit;

    FWT(int sz) {
        bit.resize(sz+1, 0);
    }

    void build(vector<int> &arr, map<int, int> &mp) {
        for(auto sm: arr) {
            addition(mp[sm], 1);
        }  
    }

    void clear_data() {
        for(int i=0; i<bit.size(); i++) bit[i] = 0;  
    }

    int query_sum(int num) {
        int ans = 0;
        for(int i=num; i>0; i-=(i&(-i))) {
            ans += bit[i];
        }
        return ans;
    }

    void addition(int num, int val) {
        for(int i=num; i<bit.size(); i+=(i&(-i))) {
            bit[i] += val;
        }
    }
};


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if(n==1) {
            if(lower <= nums[0] && nums[0]<=upper) return 1;
            else return 0;
        }
        int l = lower;
        int r = upper;
        vector<int> sum_i;
        int temp = 0;
        for(int i=0; i<=n-2; i++) {
            temp += nums[i];
            sum_i.push_back(temp);
        }

        // Fenwick Tree creation
        set<int> st;
        int sm = 0;
        for(int i=0; i<n; i++){
            sm += nums[i];
            st.insert(sm);
            st.insert(sm+lower);
            st.insert(sm+upper);
            st.insert(sm+lower-1);
        }
        for(auto it: st) cout << it << " ";
        cout << endl;
        map<int, int> sum_to_int;
        int iter = 1;
        for(auto it: st) {
            sum_to_int[it] = iter;
            iter++;
        }
        // cout << "Map :-" << endl;
        // for(auto pr: sum_to_int) cout << pr.first << " :" << pr.second << endl;
        // cout << endl;

        // cout << "sum j :";
        // for(auto it: sum_j) cout << it << " ";
        // cout << endl;

        FWT fwt(st.size());
        int main_ans = 0;
        for(int i=-1; i<=n-2; i++) {
            int nl = lower;
            int nr = upper;
            if(i != -1) {
                nl += sum_i[i];
                nr += sum_i[i];
            }
            // cout << "nl :" << nl << "    nr :" << nr << endl;

            vector<int> sum_j;
            int temp_sum = 0;
            for(int j=i+1; j<n; j++) {
                temp_sum += nums[j];
                sum_j.push_back(temp_sum);
            }
            fwt.build(sum_j, sum_to_int);
            cout << "BIT :";
            for(auto it: fwt.bit) cout << it << " ";
            cout << endl;

            int r_sum = fwt.query_sum(sum_to_int[nr]);
            int l_sum = fwt.query_sum(sum_to_int[nl-1]);
            // cout << "l_sum :" << l_sum << "    r_sum :" << r_sum << endl;
            fwt.clear_data();
            main_ans += r_sum-l_sum;
        }
        return main_ans;
    }
};