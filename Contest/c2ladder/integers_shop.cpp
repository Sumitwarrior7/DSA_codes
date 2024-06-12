#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> funcn(int n, vector<vector<int>> &arr) {
    vector<int> ans;
    ans.push_back(arr[0][2]);
    
    int minL = arr[0][0];
    int r = arr[0][1];
    int valL = arr[0][2];

    int maxR = arr[0][1];
    int l = arr[0][0];
    int valR = arr[0][2];

    for (int i = 1; i < n; i++) {
        int li = arr[i][0];
        int ri = arr[i][1];
        int wi = arr[i][2];

        if ((ri>maxR && li<minL) || (minL==li && ri>maxR) || (li<minL && ri==maxR)) {
            minL = li;
            r = ri;
            valL = wi;
            maxR = ri;
            l = li;
            valR = wi;
            ans.push_back(wi);
        }
        else if (ri == maxR && li == minL) {
            if ((minL == l) && (r == maxR)) {
                if (wi < valL) {
                    minL = li;
                    r = ri;
                    valL = wi;
                    maxR = ri;
                    l = li;
                    valR = wi;
                    ans.push_back(wi);
                } else {
                    ans.push_back(valL);
                }
            } else {
                if (wi < valL+valR) {
                    minL = li;
                    r = ri;
                    valL = wi;
                    maxR = ri;
                    l = li;
                    valR = wi;
                    ans.push_back(wi);
                } else {
                    ans.push_back(valL+valR);
                }
            }
        } else {
            if (ri > maxR) {
                maxR = ri;
                l = li;
                valR = wi;
            } else if (ri == maxR && wi < valR) {
                maxR = ri;
                l = li;
                valR = wi;
            }

            if (li < minL) {
                minL = li;
                r = ri;
                valL = wi;
            } else if (li == minL && wi < valL) {
                minL = li;
                r = ri;
                valL = wi;
            }

            if ((minL == l) && (r == maxR)) ans.push_back(valL);
            else ans.push_back(valL+valR);
        }

    }
    return ans;
}


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            vector<int> ind;
            int l, r, c;
            cin >> l >> r >> c;
            ind.push_back(l);
            ind.push_back(r);
            ind.push_back(c);
            v.push_back(ind);
        } 

        vector<int> ans = funcn(n, v);
        for (auto it: ans) cout << it << endl;
    }
    return 0;
}