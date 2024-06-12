#include <bits/stdc++.h>
using namespace std;

// Fixed size sliding window
vector<int> arr;
int n = arr.size();
int i = 0;
int j = 0;


while (j < n) {
    // Approaching the sliding window
    if (j-i+1 < k) {
        sum += nums[j];
        j++;
    } 
    else {
        // First sliding window
        if (i == 0) {
            sum += nums[j];
            // Calculations
            i++;
            j++;
        } else {
            sum -= nums[i-1];
            sum += nums[j];
            // Calculations
            i++;
            j++;
        }
    }
}



// Variable size sliding window
int n = 0;
int k = 0;
vector<int> arr;

int ans = 0;
long long sum = 0;
int i = 0;
int j = 0;
while (j < n) {
    sum += arr[j];
    if (sum < k) j++;
    else if (sum == k) {
        ans = max(ans, j-i+1);
        j++;
    }
    else {
        while(sum > k) {
            sum -= arr[i];
            i++;
        }
        if (sum == k) ans = max(ans, j-i+1);
        j++;
    }
}
