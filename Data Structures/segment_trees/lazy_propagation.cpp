#include<bits/stdc++.h>
using namespace std;

/* Key Points */

/* Key Points */

// Sum Range Query based Segment Tree
// Lazy Propagation
class SGTree {
    public:
        vector<int> seg;
        vector<int> lazy;
        SGTree(int n) {
            seg.resize(4*n+1);
            lazy.resize(4*n+1);
        }

        void build(int m, vector<int> &arr, int low, int high, int seg_ind) {
            if(low == high) {
                seg[seg_ind] = arr[low];
                return;
            }

            int mid = (low+high)/2;
            build(m, arr, low, mid, 2*seg_ind+1);
            build(m, arr, mid+1, high, 2*seg_ind+2);
            seg[seg_ind] = seg[2*seg_ind+1] + seg[2*seg_ind+2];
        }

        int query(int seg_ind, int low, int high, int ql, int qr) {
            // Update the previous remining updates & propagate downwards
            if(lazy[seg_ind] != 0) {
                seg[seg_ind] += (high-low+1)*lazy[seg_ind];
                if(low != high) {
                    lazy[2*seg_ind+1] += lazy[seg_ind];
                    lazy[2*seg_ind+2] += lazy[seg_ind];
                }
                lazy[seg_ind] = 0;
            }

            // No Overlap
            if (high < ql || qr < low) return 0;

            // Complete Overlap
            if (ql <= low && high <= qr) return seg[seg_ind];

            // Partial Overlap
            int mid = (low+high)/2;
            int left = query(2*seg_ind+1, low, mid, ql, qr);
            int right = query(2*seg_ind+2, mid+1, high, ql, qr);
            return left+right;
        }

        // Range Update 
        void update(int seg_ind, int low, int high, pair<int, int> pos, int val) {
            // Update the previous remining updates & propagate downwards
            if(lazy[seg_ind] != 0) {
                seg[seg_ind] += (high-low+1)*lazy[seg_ind];
                // Downward Propagation for lazy updates
                if(low != high) {
                    lazy[2*seg_ind+1] += lazy[seg_ind];
                    lazy[2*seg_ind+2] += lazy[seg_ind];
                }
                lazy[seg_ind] = 0;
            }

            // No Overlap
            if(high < pos.first || pos.second < low) return;
            // Complete Overlap
            if(pos.first <= low && high <= pos.second) {
                seg[seg_ind] += (high-low+1)*val;
                if(low != high) {
                    lazy[2*seg_ind+1] += val;
                    lazy[2*seg_ind+2] += val;
                }
                return;
            }
            // Partial Overlap
            int mid = (low+high)/2;
            update(2*seg_ind+1, low, mid, pos, val);
            update(2*seg_ind+2, mid+1, high, pos, val);
            seg[seg_ind] = seg[2*seg_ind+1] + seg[2*seg_ind+2];
        }
};


int main() {
    int n = 10;
    vector<int> arr = {1, 2, 4, 5, 6, 7, 3, 5, 7, 9};
    SGTree seg_tree(n);
    seg_tree.build(n, arr, 0, n-1, 0);
    int q1 = seg_tree.query(0, 0, n-1, 0, 3);
    cout << "q1 :" << q1 << endl;

    seg_tree.update(0, 0, n-1, {1, 2}, 2);
    int q2 = seg_tree.query(0, 0, n-1, 0, 3);
    cout << "q2 :" << q2 << endl;

}   
