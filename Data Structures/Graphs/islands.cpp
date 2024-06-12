#include <bits/stdc++.h>
using namespace std;

/* Using BFS */
int num_of_islands(vector<vector <int>> &mat) {
    int m = mat.size();     // Rows
    int n = mat[0].size();  // Cols

    vector<vector <bool>> vis(m, vector<bool>(n, false));
    vector<pair<int, int>> arr = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1 && vis[i][j] == false) {
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()) {
                    pair<int, int> node = q.front();
                    q.pop();
                    vis[node.first][node.second] = true;
                    for(auto a: arr) {
                        int ni = node.first + a.first;
                        int nj = node.second + a.second;
                        if (0 <= ni && ni < m && 0 <= nj && nj < n) {
                            if (mat[ni][nj] == 1 && vis[ni][nj] == false) {
                                q.push({ni, nj});
                            }
                        }
                    }
                }
                ans++;
            }
        }
    }
    return ans;
}


int main() {
    // Define the size of the matrix
    const int rows = 3;
    const int cols = 4;

    // Create a 2D matrix and manually add sample data
    vector<vector<int>> matrix = {
        {1, 1, 1, 1},
        {0, 1, 1, 0},
        {1, 1, 0, 0}
    };

    int sol = num_of_islands(matrix);
    cout << sol;


    return 0;
}