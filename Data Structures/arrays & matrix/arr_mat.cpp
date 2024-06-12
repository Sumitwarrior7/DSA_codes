// Code for Spiral Matrix
#include <bits/stdc++.h>
using namespace std;

vector<int> Spiral(vector<vector<int>> mat, int m, int n) {
    vector<int> v;
    int r1 = 0;
    int r2 = m - 1;
    int c1 = 0;
    int c2 = n - 1;

    while (r1 <= r2 && c1 <= c2) {
        if ((r1 <= r2) || (c1 <= c2)) {
            for (int j = c1; j <= c2; j++) v.push_back(mat[r1][j]); 
            r1++;
        }

        if ((r1 <= r2) || (c1 <= c2)) {
            for (int i = r1; i <= r2; i++) v.push_back(mat[i][c2]);
            c2--;
        }

        if ((r1 <= r2) || (c1 <= c2)) {
            for (int j = c2; j >= c1; j--) v.push_back(mat[r2][j]);
            r2--;
        }

        if ((r1 <= r2) || (c1 <= c2)) {
            for (int i = r2; i >= r1; i--) v.push_back(mat[i][c1]);
            c1++;
        }
    }

    return v;
}

int main() {
    // Sample matrix
    int m = 3;
    int n = 3;
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    matrix[0][0] = 2;
    matrix[0][1] = -1;
    matrix[0][2] = 3;
    matrix[1][0] = -4;
    matrix[1][1] = 5;
    matrix[1][2] = -2;
    matrix[2][0] = 1;
    matrix[2][1] = -3;
    matrix[2][2] = 0;


    vector<int> ans;
    ans = Spiral(matrix, m, n);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
