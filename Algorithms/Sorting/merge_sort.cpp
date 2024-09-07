#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(n logn)
// Space Complexity: O(n) [Auxiliary Space]


void merge(int n, vector<int> &arr, int l, int m, int h) {
    vector<int> temp;
    int i = l;
    int j = m+1;
    while(i<=m && j<=h) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;  
        }
    }

    for(int it=i; it<=m; it++) temp.push_back(arr[it]);
    for(int it=j; it<=h; it++) temp.push_back(arr[it]);
    for(int it=0; it<temp.size(); it++) {
        arr[it+l] = temp[it];
    }
}

void merge_sort(int n, vector<int> &arr, int l, int h) {
    if(l == h) return;

    int m = (h+l)/2;
    merge_sort(n, arr, l, m);
    merge_sort(n, arr, m+1, h);
    merge(n, arr, l, m, h);
}


signed main() {
    int n = 5;
    vector<int> arr = {3, 7, 1, 2, 6};
    
    merge_sort(n, arr, 0, n-1);
    for(auto it: arr) cout << it << " ";
}