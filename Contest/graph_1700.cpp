class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<pair<int, int>> arr = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> vis(r+1, vector<bool>(c+1, false));
        queue<pair<int, int>> q;
        int sz = 0;
        int ones = 0;
        int zeros = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = true;
                    sz++;
                    ones++;
                }
                if(grid[i][j] == 0) zeros++;
            }
        }
        if(ones == 0 || zeros == 0) return -1;

        int min = -1;
        while(!q.empty()) {
            int siz = 0;
            min++;
            for(int i=0; i<sz; i++) {
                pair<int, int> m = q.front();
                q.pop();
                for(int k=0; k<4; k++) {
                    int ni = m.first+arr[k].first;
                    int nj = m.second+arr[k].second;
                    if(0<=ni && ni<r && 0<=nj && nj<c) {
                        if(vis[ni][nj] == false) {
                            q.push({ni, nj});
                            vis[ni][nj] = true;
                            siz++;
                        }
                    }
                }
            }
            sz = siz;
        } 
        return min; 
    }
};