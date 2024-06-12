#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))


/* -------------------------------------------------------< Segment Tree 1 >------------------------------------------------------- */
1) Segment Tree : It stores min value and its count in the range
struct node {
  int mv = INT_MAX;
  int cnt = 0;
};
class SGMin {
    public:
        vector<node> seg;
        SGMin(int n) {
            seg.resize(4*n+1);
        }

        void build(vector<int> &arr, int low, int high, int seg_ind) {
            if(low == high) {
                seg[seg_ind].mv = arr[low];
                seg[seg_ind].cnt = 1;
                return;
            }

            int mid = (low+high)/2;
            build(arr, low, mid, 2*seg_ind+1);
            build(arr, mid+1, high, 2*seg_ind+2);
            node ln = seg[2*seg_ind+1];
            node rn = seg[2*seg_ind+2];
            if(ln.mv == rn.mv) {
                seg[seg_ind].mv = ln.mv;
                seg[seg_ind].cnt = ln.cnt+rn.cnt;
            }
            else {
                seg[seg_ind].mv = min(ln.mv, rn.mv);
                seg[seg_ind].cnt = (ln.mv<rn.mv)?ln.cnt:rn.cnt;
            }
        }

        node query(int seg_ind, int low, int high, int ql, int qr) {
            // No Overlap
            if (high < ql || qr < low) {
                node empty_node;
                return empty_node;
            }

            // Complete Overlap
            if (ql <= low && high <= qr) return seg[seg_ind];

            // Partial Overlap
            int mid = (low+high)/2;
            node left = query(2*seg_ind+1, low, mid, ql, qr);
            node right = query(2*seg_ind+2, mid+1, high, ql, qr);
            node new_node;
            new_node.mv = min(left.mv, right.mv);
            if(left.mv == right.mv) new_node.cnt = left.cnt+right.cnt;
            else if (left.mv > right.mv) new_node.cnt = right.cnt;
            else new_node.cnt = left.cnt;
            return new_node;
        }
};
/* -------------------------------------------------------< Segment Tree 1 >------------------------------------------------------- */


/* -------------------------------------------------------< Segment Tree 2 >------------------------------------------------------- */
2) Segment Tree : It stores GCD of the range
class SGGcd {
    public:
        vector<int> seg;
        SGGcd(int n) {
            seg.resize(4*n+1);
        }

        void build(vector<int> &arr, int low, int high, int seg_ind) {
            if(low == high) {
                seg[seg_ind] = arr[low];
                return;
            }

            int mid = (low+high)/2;
            build(arr, low, mid, 2*seg_ind+1);
            build(arr, mid+1, high, 2*seg_ind+2);
            seg[seg_ind] = gcd(seg[2*seg_ind+1], seg[2*seg_ind+2]);
        }

        int query(int seg_ind, int low, int high, int ql, int qr) {
            // No Overlap
            if (high < ql || qr < low) return -1;

            // Complete Overlap
            if (ql <= low && high <= qr) return seg[seg_ind];

            // Partial Overlap
            int mid = (low+high)/2;
            int left = query(2*seg_ind+1, low, mid, ql, qr);
            int right = query(2*seg_ind+2, mid+1, high, ql, qr);
            if(left == -1) return right;
            else if(right == -1) return left;
            else return gcd(left, right);
        }
};
/* -------------------------------------------------------< Segment Tree 2 >------------------------------------------------------- */





signed main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    SGMin seg_min(n);
    seg_min.build(arr, 0, n-1, 0); 
    SGGcd seg_gcd(n);
    seg_gcd.build(arr, 0, n-1, 0); 
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int gcd_val = seg_gcd.query(0, 0, n-1, l, r);
        node min_node = seg_min.query(0, 0, n-1, l, r);
        if(gcd_val == min_node.mv) cout << r-l+1-min_node.cnt << endl;
        else cout << r-l+1 << endl;
    }

}