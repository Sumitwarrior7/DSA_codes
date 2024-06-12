#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
    
set<int> get_prime_factors(int num) {
    set<int> factors;
    vector<int> fs;
    vector<int> sc;
    for(int i = 1; i*i <= num; i++) {
        if (num%i == 0) {
            if (i != 1) {
                fs.push_back(i);
            }
            if (num/i != 1) {
                sc.push_back(num/i);
            }
        }
    }
    for(auto it: fs) factors.insert(it);
    for(int i = sc.size()-1; i >= 0; i--) factors.insert(sc[i]);


    set<int> st;
    int curr = num;
    for(auto i: factors) {
        if (curr%i == 0) {
            if (i != 1) {
                while(true) {
                    if(curr%i == 0) curr = curr/i;
                    else break;
                }
                st.insert(i);
            }
        }
    }
    return st;
}