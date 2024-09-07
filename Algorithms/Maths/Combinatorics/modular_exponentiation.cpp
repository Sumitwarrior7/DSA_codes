#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000000 + 7;
int modPow(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (1LL * result * base) % mod; // Use 1LL to avoid overflow
        }
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return result;
}


int main() {
    int base = 2;
    int exp = 0; 
    int ans = modPow(base, exp, MOD);
    cout << base << "^" << exp << " = " << ans << endl;

}
