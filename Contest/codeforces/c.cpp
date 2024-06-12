/* ----------------------------------Basic Template---------------------------------- */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))

// Minimum Range Query based Segment Tree
class SGTree {
    public:
        vector<int> seg;
        SGTree(int n) {
            seg.resize(4*n+1, 0);
        }

        int query(int seg_ind, int low, int high, int ql, int qr) {
            // No Overlap
            if (high < ql || qr < low) return 0;

            // Complete Overlap
            if (ql <= low && high <= qr) return seg[seg_ind];

            // Partial Overlap
            int mid = (low+high)/2;
            int left = query(2*seg_ind+1, low, mid, ql, qr);
            int right = query(2*seg_ind+2, mid+1, high, ql, qr);
            return left + right;
        }

        void update(int seg_ind, int low, int high, int num) {
            if(low == high) {
                seg[seg_ind]++;
                return;
            }
            int mid = (low+high)/2;
            if(num <= mid) update(2*seg_ind+1, low, mid, num);
            else update(2*seg_ind+2, mid+1, high, num);
            seg[seg_ind] = seg[2*seg_ind+1] + seg[2*seg_ind+2];
        }
};


signed main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    } 

    // int mx = 1;
    set<int> st;
    map<int, int> mp1;
    vector<int> fwd_arr;
    for(int i=0; i<n-1; i++) {
        mp1[arr[i]]++;
        fwd_arr.push_back(mp1[arr[i]]);
        // mx = max(mx, mp1[arr[i]]);
        // st.insert(mp1[arr[i]]);
        st.insert(mp1[arr[i]]-1);
    }

    map<int, int> mp2;
    vector<int> bwd_arr;
    for(int i=n-1; i>0; i--) {
        mp2[arr[i]]++;
        bwd_arr.push_back(mp2[arr[i]]);
        // mx = max(mx, mp2[arr[i]]);
        st.insert(mp2[arr[i]]);
    }  
    reverse(bwd_arr.begin(), bwd_arr.end());

    // Mapping
    map<int, int> mapping;
    int iter = 0;
    for(auto it: st) {
        mapping[it] = iter;
        iter++;
    }

    int ans = 0;
    SGTree seg_tree(st.size());
    for(int i=n-2; i>=0; i--) {
        seg_tree.update(0, 0, st.size()-1, mapping[bwd_arr[i]]);
        if(fwd_arr[i] != 1) ans += seg_tree.query(0, 0, st.size()-1, 0, mapping[fwd_arr[i]-1]);
    }
    cout << ans << endl;
}