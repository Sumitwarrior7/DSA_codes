#include<bits/stdc++.h>
using namespace std;

/*  Minimum costs for the complete path by either taking 1 step or 2 steps */ 
int rec(int &n, vector<int> &h, int i, vector<int> &memo) {
    // Base case
    if (i == n-1) {
        return 0;
    }
    else if (i == n-2) {
        return abs(h[n-1] - h[n-2]);
    }
    
    // Memoization
    if (memo[i] != -1) {
        return memo[i];
    }
    
    int rec_1 = rec(n, h, i+1, memo) + abs(h[i+1] - h[i]);
    int rec_2 = rec(n, h, i+2, memo) + abs(h[i+2] - h[i]);
    memo[i] = min(rec_1, rec_2);
    return min(rec_1, rec_2);
}

int main() {
    int n; 
    vector<int> v;
    cin >> n;
    vector<int> memo(n, -1);
    for (int j = 0; j < n; j++) {
        int inp;
        cin >> inp;
        v.push_back(inp);
    }
    
    cout << rec(n, v, 0, memo);
}



#include<bits/stdc++.h>
using namespace std;

int rec(int &n, vector<int> &a, vector<int> &b, vector<int> &c, int i, int ps, vector<vector<int>> &memo) {
    // Base case
    if (i == n-1) {
        if (ps == 1) {
            return max(b[i], c[i]);
        } else if (ps == 2) {
            return max(a[i], c[i]);
        } else if (ps == 3) {
           return max(a[i], b[i]); 
        } else if (ps == 0) {
           return max({a[i], b[i], c[i]});  
        }
    }
    
    // Memoization
    if (memo[i][ps] != -1) {
        return memo[i][ps];
    }
    
    
    if (ps == 0) {
        if (memo[i+1][1] != -1) {
            memo[i+1][1] = rec(n, a, b, c, i+1, 1, memo);
        }
        int ans_1 = a[i] + memo[i+1][1]; 
        
        if (memo[i+1][2] == -1) {
            memo[i+1][2] = rec(n, a, b, c, i+1, 2, memo);
        }
        int ans_2 = b[i] + memo[i+1][2]; 
        
        if (memo[i+1][3] == -1) {
            memo[i+1][3] = rec(n, a, b, c, i+1, 3, memo);
        }
        int ans_3 = c[i] + memo[i+1][3]; 

        memo[i][ps] = max({ans_1, ans_2, ans_3});
        return max({ans_1, ans_2, ans_3});
    } 
    else if (ps == 1) {
        if (memo[i+1][2] == -1) {
            memo[i+1][2] = rec(n, a, b, c, i+1, 2, memo);
        }
        int ans_2 = b[i] + memo[i+1][2]; 
        
        if (memo[i+1][3] == -1) {
            memo[i+1][3] = rec(n, a, b, c, i+1, 3, memo);
        }
        int ans_3 = c[i] + memo[i+1][3];        
        
        memo[i][ps] = max(ans_2, ans_3);
        return max(ans_2, ans_3);
    } 
    else if (ps == 2) {
        if (memo[i+1][1] != -1) {
            memo[i+1][1] = rec(n, a, b, c, i+1, 1, memo);
        }
        int ans_1 = a[i] + memo[i+1][1];  
        
        if (memo[i+1][3] == -1) {
            memo[i+1][3] = rec(n, a, b, c, i+1, 3, memo);
        }
        int ans_3 = c[i] + memo[i+1][3]; 
        
        memo[i][ps] = max(ans_1, ans_3);
        return max(ans_1, ans_3);
    } 
    else if (ps == 3) {
        if (memo[i+1][1] != -1) {
            memo[i+1][1] = rec(n, a, b, c, i+1, 1, memo);
        }
        int ans_1 = a[i] + memo[i+1][1]; 
        
        if (memo[i+1][2] == -1) {
            memo[i+1][2] = rec(n, a, b, c, i+1, 2, memo);
        }
        int ans_2 = b[i] + memo[i+1][2]; 
        
        memo[i][ps] = max(ans_1, ans_2);
        return max(ans_1, ans_2);
    }

}

int main() {
    int n; 
    vector<int> a;
    vector<int> b;
    vector<int> c;
    cin >> n;
    vector<vector<int>> memo(n+1, vector<int>(4, -1));

    for (int j = 0; j < n; j++) {
        int i1, i2, i3;
        cin >> i1 >> i2 >> i3;
        a.push_back(i1);
        b.push_back(i2);
        c.push_back(i3);
    }
    
    cout << rec(n, a, b, c, 0, 0, memo);
}