#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))


string func(string &str) {
    if (!isupper(str[0])) return "No";
    else {
        for(int i = 1; i < str.size(); i++) {
            if (!islower(str[i])) return "No";
        }
        return "Yes";
    }
}


signed main() {
    string str;
    cin >> str;

    string ans = func(str);
    cout << ans << endl;
}
