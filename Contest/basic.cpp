/* ----------------------------------Basic Template---------------------------------- */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
extern vector<char> charMap = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
extern map<char, int> mp = {
        {'a', 0},{'b', 1},{'c', 2},{'d', 3},{'e', 4},
        {'f', 5},{'g', 6},{'h', 7},{'i', 8},{'j', 9},
        {'k', 10},{'l', 11},{'m', 12},{'n', 13},{'o', 14},{'p', 15},
        {'q', 16},{'r', 17},{'s', 18},{'t', 19},{'u', 20},
        {'v', 21},{'w', 22},{'x', 23},{'y', 24},{'z', 25}
    };



int func(int n, vector<int> &v) {
    return 0;
}


signed main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int vi;
        cin >> vi;
        v.push_back(vi);
    } 
    int ans = func(n, v);
    cout << ans;
}


/* ----------------------------------Test cases template---------------------------------- */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
extern vector<char> charMap = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
extern map<char, int> mp = {
        {'a', 0},{'b', 1},{'c', 2},{'d', 3},{'e', 4},
        {'f', 5},{'g', 6},{'h', 7},{'i', 8},{'j', 9},
        {'k', 10},{'l', 11},{'m', 12},{'n', 13},{'o', 14},{'p', 15},
        {'q', 16},{'r', 17},{'s', 18},{'t', 19},{'u', 20},
        {'v', 21},{'w', 22},{'x', 23},{'y', 24},{'z', 25}
    };

    

int funcn(int n, vector<int> &arr) {
    
}


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        } 

        int ans = funcn(n, v);
        cout << ans << endl;
    }

}
