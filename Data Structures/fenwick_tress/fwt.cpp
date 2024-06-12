#include<bits/stdc++.h>
using namespace std;

/* ----------------------------------------Range Sum Query--------------------------------------- */
/*
1) All the input paramters of functions 'query_sum' and 'update' will follow 0-based indexing for
   input paramters as they are based out of 'arr'
2) There is No need to modify the actual 'arr' if you are doing addition operation at a particular index,
   But if you are repacing a particular value at an index of 'arr', you have to modify the 
   'arr'(for that you have to create a copy of arr, and update the copy) as well 
*/
class FWT {
    public:
    // bit will follow 1-based indexing
    vector<int> bit;

    FWT(vector<int> &arr) {
        int n = arr.size();
        bit.resize(n+1, 0);
        for(int i=0; i<n; i++) {
            addition(i, arr[i]);
        }
    }

    int query_sum(int ind) {
        int ans = 0;
        for(int i=ind+1; i>0; i-=(i&(-i))) {
            ans += bit[i];
        }
        return ans;
    }

    void addition(int ind, int val) {
        for(int i=ind+1; i<bit.size(); i+=(i&(-i))) {
            bit[i] += val;
        }
    }
};




int main() {
    // arr follows 0-based indexing
    vector<int> arr = {1, 3, 5, 7, 9 , 2, 5};
    int n = arr.size();

    FWT fwt(arr);

    // First Query for getting sum of range(0->4)
    cout << "Query Sum :" << fwt.query_sum(0) << endl;

    // Second Query will update the value at index '1' of arr by adding '8' at the value present in arr at index '1'
    fwt.addition(1, 8);

    // Third Query for getting sum of range(0->2) in the updated fenwick tree
    cout << "Query Sum :" << fwt.query_sum(2) << endl;
}