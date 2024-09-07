/* ----------------------------------Basic Template---------------------------------- */
#include <bits/stdc++.h>
using namespace std;
// My own macros
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORI(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define pii pair<int, int>


// Next greater element of each number in an array
vector<int> ngef(int n, vector<int>& nums) {
    vector<int> nge(n, -1);
    stack<int> st;
    for(int i=n-1; i>=0; i--) {
        while(!st.empty()) {
            int tp = st.top();
            if(nums[i] >= nums[tp]) st.pop();
            else break;
        }

        if(st.empty()) nge[i] = -1;
        else nge[i] = st.top();
        st.push(i);
    }
    return nge;
}



signed main() {
    // FAST_IO

    vector<int> nums = {2, 4, 0, 9, 6};

    int n = nums.size();
    vector<int> nge = ngef(n, nums);
}