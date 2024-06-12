#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))


char func(string &str) {
    map<char, int> mp = {
        {'a', 0},
        {'b', 1},
        {'c', 2},
        {'d', 3},
        {'e', 4},
        {'f', 5},
        {'g', 6},
        {'h', 7},
        {'i', 8},
        {'j', 9},
        {'k', 10},
        {'l', 11},
        {'m', 12},
        {'n', 13},
        {'o', 14},
        {'p', 15},
        {'q', 16},
        {'r', 17},
        {'s', 18},
        {'t', 19},
        {'u', 20},
        {'v', 21},
        {'w', 22},
        {'x', 23},
        {'y', 24},
        {'z', 25}
    };

    vector<int> arr(26, 0);
    for(auto ch: str) {
        arr[mp[ch]]++;
    }

    int max_char = 25;
    int max_count = arr[25];
    for(int i= 24; i >= 0; i--) {
        if (arr[i] >= max_count){
            max_count = arr[i];
            max_char = i;
        }
    }

    for(auto pr: mp){
        if (max_char == pr.second) return pr.first;
    }
    char c;
    return c;
}


signed main() {
    string str;
    cin >> str;

    char ans = func(str);
    cout << ans << endl;
}
