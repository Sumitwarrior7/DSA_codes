/* ----------------------------------Basic Template---------------------------------- */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))



void func(int sx, int sy, int l, vector<vector<char>> &arr) {
    if(l == 0) return;
    int tm = pow(3, l-1);
    int nx = sx+tm;
    int ny = sy+tm;
    for(int i=nx; i<nx+tm; i++) {
        for(int j=ny; j<ny+tm; j++) {
            arr[i][j] = '.';
        }
    }

    for(int i=sx; i<sx+(3*tm); i+=tm) {
        for(int j=sy; j<sy+(3*tm); j+=tm) {
            func(i, j, l-1, arr);
        }
    }
}


signed main() {
    int n;
    cin >> n;

    vector<vector<char>> v(pow(3, n), vector<char>(pow(3, n), '#'));
    func(0, 0, n, v);
    for(auto it: v) {
        for(auto item: it) cout << item;
        cout << endl;
    }
}