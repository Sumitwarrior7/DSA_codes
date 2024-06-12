#include<bits/stdc++.h>
using namespace std;

/* Key Points */
* 'query' and 'update' functions are having O(log n) time complexity
* 'build' functions is having O(n) time complexity
* All the leaf nodes of segment tree will be the values in arr
/* Key Points */


// Minimum Range Query based Segment Tree
class SGTree {
    public:
        vector<int> seg;
        SGTree(int n) {
            seg.resize(4*n+1);
        }

        void build(int m, vector<int> &arr, int low, int high, int seg_ind) {
            if(low == high) {
                seg[seg_ind] = arr[low];
                return;
            }

            int mid = (low+high)/2;
            build(m, arr, low, mid, 2*seg_ind+1);
            build(m, arr, mid+1, high, 2*seg_ind+2);
            seg[seg_ind] = min(seg[2*seg_ind+1], seg[2*seg_ind+2]);
        }

        int query(int seg_ind, int low, int high, int ql, int qr) {
            // No Overlap
            if (high < ql || qr < low) return INT_MAX;

            // Complete Overlap
            if (ql <= low && high <= qr) return seg[seg_ind];

            // Partial Overlap
            int mid = (low+high)/2;
            int left = query(2*seg_ind+1, low, mid, ql, qr);
            int right = query(2*seg_ind+2, mid+1, high, ql, qr);
            return min(left, right);
        }

        void update(int seg_ind, int low, int high, int pos, int val) {
            if(low == high) {
                seg[seg_ind] = val;
                return;
            }
            int mid = (low+high)/2;
            if(pos <= mid) update(2*seg_ind+1, low, mid, pos, val);
            else update(2*seg_ind+2, mid+1, high, pos, val);
            seg[seg_ind] = min(seg[2*seg_ind+1], seg[2*seg_ind+2]);
        }
};


int main() {
    int n = 10;
    vector<int> arr = {1, 2, 4, 5, 6, 7, 3, 5, 7, 9};
    SGTree seg_tree(n);
    seg_tree.build(n, arr, 0, n-1, 0);
    int q1 = seg_tree.query(0, 0, n-1, 2, 9);
    cout << "q1 :" << q1 << endl;

}   
