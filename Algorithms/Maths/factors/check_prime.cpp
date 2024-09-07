#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))

// Time Complexity : O(root n) [Most Optimized]
vector<int> get_all_factors(int num) {
    vector<int> factors;
    for(int i = 1; i*i <= num; i++) {
        if(num%i == 0) {
            factors.push_back(i);
            if(i != (num/i)) factors.push_back(num/i);
        }
    }
    return factors;
}


bool is_prime(int num) {
    if(num == 1) return false;
    int total_primes = get_all_factors(num).size();
    if(total_primes == 2) return true;
    else return false;
}   



signed main() {
    vector<int> arr = {1, 2, 5, 24, 36, 100, 210, 23};

    cout << "Checking prime numbers :-" << endl;
    for(auto it: arr) {
        cout << it << " :" << is_prime(it) << endl;
    }
    cout << endl;
}