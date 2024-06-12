#include<bits/stdc++.h>
using namespace std;

// Smallest ind such that (arr[ind] >= target)
int lower_bound(vector<int> arr, int tar) {
    int l = 0;
    int r = arr.size()-1;
    int ans = -1;
    while (l <= r) {
        int mid = (l+r)/2;

        if (arr[mid] < tar) {
            l = mid+1;
        }
        else {
            ans = mid;
            r = mid-1;
        }
    }
    return ans;

}


// Smallest ind such that (arr[ind] > target)
int upper_bound(vector<int> arr, int tar) {
    int l = 0;
    int r = arr.size()-1;
    int ans = -1;
    while (l <= r) {
        int mid = (l+r)/2;

        if (arr[mid] <= tar) {
            l = mid+1;
        }
        else {
            ans = mid;
            r = mid-1;
        }
    }
    return ans;

}




int main(){
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    v.push_back(8);
    v.push_back(10);
    v.push_back(12);
    v.push_back(13);

    int tar = 1;

    int lb = lower_bound(v, tar);
    cout << lb << endl;
}




