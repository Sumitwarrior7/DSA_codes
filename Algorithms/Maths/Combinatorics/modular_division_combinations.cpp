#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


/* It calculates values of 'nCr' for large values of n under modulo operation */

vector<long long> factorial;
vector<long long> invFactorial;

// Function to compute x^y % p in O(log y)
long long power(long long x, long long y, long long p) {
    long long result = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            result = (result * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return result;
}

// Precompute factorials and inverse factorials
void precomputeFactorials(int maxN, int mod) {
    factorial.resize(maxN + 1);
    invFactorial.resize(maxN + 1);

    factorial[0] = 1;
    for (int i = 1; i <= maxN; ++i) {
        factorial[i] = factorial[i - 1] * i % mod;
    }

    invFactorial[maxN] = power(factorial[maxN], mod - 2, mod);
    for (int i = maxN - 1; i >= 0; --i) {
        invFactorial[i] = invFactorial[i + 1] * (i + 1) % mod;
    }
}

// Function to compute nCr % mod
long long nCr(int n, int r, int mod) {
    if (r > n) return 0;
    return factorial[n] * invFactorial[r] % mod * invFactorial[n - r] % mod;
}

int main() {
    int maxN = 1000000;
    precomputeFactorials(maxN, MOD);

    int n = 10, r = 2;
    cout << "C(" << n << ", " << r << ") = " << nCr(n, r, MOD) << endl;

    return 0;
}
