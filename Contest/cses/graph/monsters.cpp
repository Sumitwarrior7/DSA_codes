#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> count_matrix(int n, int m, vector<vector<char>> &grid, vector<pair<int, int>> &monsters) {
    vector<vector<int>> mat(n, vector<int>(m, -1));

    vector<pair<int, int>> arr = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    // vector<vector<bool>> vis(n, vector<bool>(m, false));
    cout << "bakc" << endl;
    for (auto mon: monsters) {
        cout << "NO" << " ";
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        q.push({{mon.first, mon.second}, 0});
        vis[mon.first][mon.second] = true;
        mat[mon.first][mon.second] = 0;
        while(!q.empty()) {
            cout << "YES" << " ";
            pair<pair<int, int>, int> f = q.front();
            int r = f.first.first;
            int c = f.first.second;
            int dist = f.second;
            q.pop();

            for(auto nbr: arr) {
                int nr = r + nbr.first;
                int nc = c + nbr.second;
                if (grid[nr][nc] != '#' && vis[nr][nc] == false) {
                    if ((0 <= nr && nr < n) && (0 <= nc && nc < m)) {
                        q.push({{nr, nc}, dist+1});
                        if (mat[nr][nc] == -1) mat[nr][nc] = dist+1;
                        else mat[nr][nc] = min(mat[nr][nc], dist+1);
                        vis[nr][nc] = true;
                    }
                }
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m ; j++) {
        //         vis[i][j] = false;
        //     }
        // } 

    }
    return mat;

}

vector<char> path(vector<vector<char>> &moves, pair<int, int> node, pair<int, int> src, vector<vector<pair<int, int>>> &parent) {
    vector<char> ans;
    pair<int, int> curr = node;
    while(curr != src) {
        pair<int, int> par = parent[curr.first][curr.second];
        char move = moves[curr.first][curr.second];
        ans.push_back(move);
        curr = par;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<char> bfs_src(int n, int m, pair<int, int> src, vector<vector<char>> &grid, vector<vector<int>> &mat) {
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<pair<pair<int, int>, char>> arr = {{{-1, 0}, 'U'}, {{0, 1}, 'R'}, {{1, 0}, 'D'}, {{0, -1}, 'L'}};
    vector<vector<char>> moves(n, vector<char>(m, 'Z'));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    q.push({{src.first, src.second}, 0});
    vis[src.first][src.second] = true;
    moves[src.first][src.second] = 'X';

    while(!q.empty()) {
        pair<pair<int, int>, int> f = q.front();
        q.pop();
        int r = f.first.first;
        int c = f.first.second;
        int dist = f.second;
        if (r == 0 || r == n-1 || c == 0 || c == m-1) {
           vector<char> pth = path(moves, {r, c}, src, parent);
           return pth;
        }

        for(auto nbr: arr) {
            int nr = r + nbr.first.first;
            int nc = c + nbr.first.second;
            if (grid[nr][nc] != '#' && vis[nr][nc] == false) {
                if ((0 <= nr && nr < n) && (0 <= nc && nc < m)) {
                    if (mat[nr][nc] == -1 || mat[nr][nc] > dist+1) {
                        q.push({{nr, nc}, dist+1});
                        vis[nr][nc] = true;
                        moves[nr][nc] = nbr.second;
                        parent[nr][nc] = {r, c};
                    }
                }
            }
        }
    }
    return {'B'};
}


int main() {
    int n, m;
    cin >> n >> m;
    pair<int, int> src;
    vector<pair<int, int>> monsters;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            char si;
            cin >> si;
            grid[i][j] = si;
            if (si == 'A') src = {i, j};
            else if (si == 'M') monsters.push_back({i, j});
        }
    } 

    vector<vector<int>> countMatrix = count_matrix(n, m, grid, monsters);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            cout << countMatrix[i][j] << " ";
        }
        cout << endl;
    } 

    // vector<char> ans = bfs_src(n, m, src, grid, countMatrix);
    // if (ans.size() == 1 && ans[0] == 'B') cout << "NO" << endl;
    // else {
    //     cout << "YES" << endl;
    //     cout << ans.size() << endl;
    //     for(auto it: ans) cout << it;
    // }
}



