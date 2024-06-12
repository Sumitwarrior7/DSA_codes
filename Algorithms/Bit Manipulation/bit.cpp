#include <bits/stdc++.h>
using namespace std;

// Finding missing number :-
int missingNumber(vector<int>& nums) {
    int n = nums.size() + 1;

    int main_xor = nums[0];
    for (int i = 1; i < n-1; i++) main_xor ^= nums[i];

    int mask = 0;
    for (int j = 1; j < n; j++) mask ^= j;

    return main_xor^mask;
}


// Find unique elemnet else all are repeating 3 times :-
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int zeroes = 0;
        int ones = 0;
        for (auto num: nums) {
            if ((num & (1<<i)) != 0) ones++;
            else zeroes++;
        }
        zeroes %= 3;
        ones %= 3;
        if (ones == 1) ans += 1<<i;
    }
    return ans;
}

