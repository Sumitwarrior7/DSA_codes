#include <bits/stdc++.h>
using namespace std;


pair<int, string> sd(int rows, int cols, vector<vector<char>> &grid, int sx, int sy) {
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    map<pair<int, int>, pair<pair<int, int>, string>> mp;
    queue<pair<int, int>> q; 

    q.push({sx, sy});
    mp[{sx, sy}] = {{-1, -1}, ""};
    while(!q.empty()) {
        pair<int, int> m = q.front();
        int cx = m.first;
        int cy = m.second;

        if (grid[cx][cy] == 'B') {
            int dis = 0;
            string ans_str = "";
            while (grid[cx][cy] != 'A') {
                int px = mp[{cx, cy}].first.first;
                int py = mp[{cx, cy}].first.second;
                string path = mp[{cx, cy}].second;
                ans_str += path;
                dis++;
                cx = px;
                cy = py;
            }
            reverse(ans_str.begin(), ans_str.end());
            return {dis, ans_str};
        }

        q.pop();
        vis[cx][cy] = true;
        vector<pair<int, int>> arr = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<string> s_arr = {"D", "R", "U", "L"};
        for (int i = 0; i < 4; i++) {
            int nx = cx + arr[i].first;
            int ny = cy + arr[i].second;
            if ((0 <= nx && nx < rows) && (0 <= ny && ny < cols)) {
                if (grid[nx][ny] != '#' && vis[nx][ny] == false){
                    q.push({nx, ny});
                    mp[{nx, ny}] = {{cx, cy}, s_arr[i]};
                }
            }
        }

    }
    return {0, ""};
}


int main() {
    int n, m;
    cin >> n >> m;
    int sx, sy;
    vector<vector<char>> grid(n, vector<char>(m, 's'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            grid[i][j] = ch;
            if (ch == 'A') {
                sx = i;
                sy = j;
            }
        }
    }

    pair<int, string> ans = sd(n, m, grid, sx, sy);
    pair<int, string> nl = {0, ""};
    if (ans == nl) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << ans.first << endl;
        cout << ans.second << endl;
    }
}