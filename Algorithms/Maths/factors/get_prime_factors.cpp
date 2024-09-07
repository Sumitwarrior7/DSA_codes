#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))


// Time Complexity : O(root n * log n) [Most Optimized]
vector<int> get_prime_factors(int num) {
    vector<int> prime_factors;
    for(int i = 2; i*i <= num; i++) {
        if(num%i == 0) {
            while(num%i == 0) {
                num = num/i;    
            }
            prime_factors.push_back(i);
        }
    }

    if(num > 1) prime_factors.push_back(num);
    return prime_factors;
}



signed main() {
    vector<int> arr = {1, 2, 5, 24, 36, 100, 210, 23};

    cout << "prime factors :-" << endl;
    for(auto it: arr) {
        cout << it << " :";
        for(auto iter: get_prime_factors(it)) cout << iter << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}