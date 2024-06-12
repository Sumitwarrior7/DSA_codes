#include <bits/stdc++.h>
using namespace std;

void dfs(int rows, int cols, vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j) {
    vis[i][j] = true;
    vector<pair<int, int>> arr = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (auto nbr: arr) {
        int nx = i + nbr.first;
        int ny = j + nbr.second;
        if ((0 <= nx && nx < rows) && (0 <= ny && ny < cols)) {
            if (grid[nx][ny] == '.' && vis[nx][ny] == false){
                dfs(rows, cols, grid, vis, nx, ny);
            }
        }
    }
}


int func(int rows, int cols, vector<vector<char>> &grid) {
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    int ans = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (vis[i][j] == false && grid[i][j] == '.') {
                dfs(rows, cols, grid, vis, i, j);
                ans++;
            }
        }
    }
    return ans;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, 's'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            grid[i][j] = ch;
        }
    }

    int ans = func(n, m, grid);
    cout << ans << endl;
}
































