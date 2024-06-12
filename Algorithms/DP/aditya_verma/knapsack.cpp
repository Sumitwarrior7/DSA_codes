#include<bits/stdc++.h>
using namespace std;
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))


// Array of items(with properties value & weight) is given and we have choice for selecting the items
// Constraint of weight is also given
// =====> KNAPSACK PATTERN <=====
int knapsack_01(vector<int> &val_arr, vector<int> &wt_arr, int n, int i, int cap) {
    if (cap <= 0 || i >= n) return 0;   // Base Case

    if (wt_arr[i] > cap) {
        int choice = rec(val_arr, wt_arr, n, i+1, cap);   // item can't be taken bacuse of its high weight
        return choice;
    } else {
        int choice_item_not_taken = rec(val_arr, wt_arr, n, i+1, cap);
        int choice_item_taken = val_arr[i] + rec(val_arr, wt_arr, n, i+1, cap-wt_arr[i]);
        return max(choice_item_not_taken, choice_item_taken);
    }
}


int knapsack_unbounded(vector<int> &val_arr, vector<int> &wt_arr, int n, int i, int cap) {
    if (cap <= 0 || i >= n) return 0;   // Base Case

    if (wt_arr[i] > cap) {
        int choice = rec(val_arr, wt_arr, n, i+1, cap);   // item can't be taken bacuse of its high weight
        return choice;
    } else {
        int choice_item_not_taken = rec(val_arr, wt_arr, n, i+1, cap);
        int choice_item_taken = val_arr[i] + rec(val_arr, wt_arr, n, i, cap-wt_arr[i]);
        return max(choice_item_not_taken, choice_item_taken);
    }
}