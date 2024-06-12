#include<bits/stdc++.h>
using namespace std;

/*

* For binary search to be applied, array must be sorted

* Time Compexity : O(log n)

* For Overflow case :-
    mid = l + (r-l)/2

*/


// Iterative Approach
int bs_iterative(vector<int> arr, int target) {
    int l = 0;
    int r = arr.size()-1;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) r = mid-1;
        else if (arr[mid] < target) l = mid+1;
    }
    return -1;
}


// Recursive Approach
int bs_recursive(vector<int> arr, int target, int l, int r) {
    // Base case
    if (l > r) return -1;

    int mid = (l + r) / 2;

    if (arr[mid] == target) return mid;
    else if (arr[mid] > target) return bs_recursive(arr, target, l, mid-1);
    else if (arr[mid] < target) return bs_recursive(arr, target, mid+1, r);
}