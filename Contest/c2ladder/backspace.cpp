#include <bits/stdc++.h>
using namespace std;

string funcn(string is, string fs) {
    int nis = is.size();
    int nfs = fs.size();

    int ei = -1;
    int oi = -1;
    for (int i = 0; i < nis; i++) {
        if (ei != -1 && oi != -1) break;

        if (is[i] == fs[0]) {
            if (i%2 == 0 && ei == -1) ei = i;
            else {
                if (oi == -1) oi = i;
            }
        }
    }

    if (ei != -1) {
        int j= 1;
        int prev = ei;
        for (int i = ei+1; i < nis; i++) {
            if (j >= nfs) break;

            if (is[i] == fs[j]) {
                int gap = i-prev-1;
                if (gap%2 == 0) {
                    prev = i;
                    j++;
                }
            }
        }

        if (j >= nfs) {
            if ((nis-prev-1)%2 == 0) return "YES";
        }
    }

    if (oi != -1) {
        int k = 1;
        int pre = oi;
        for (int i = oi+1; i < nis; i++) {
            if (k >= nfs) break;
            
            if (is[i] == fs[k]) {
                int gap = i-pre-1;
                if (gap%2 == 0) {
                    pre = i;
                    k++;
                }
            }
        }

        if (k >= nfs) {
            if ((nis-pre-1)%2 == 0) return "YES";
        }
    }
    return "NO";
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        string is, fs;
        cin >> is >> fs;
        
        string ans = funcn(is, fs);
        cout << ans << endl;
    }
}