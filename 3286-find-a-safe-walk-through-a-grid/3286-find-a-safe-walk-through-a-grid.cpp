class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> mat(m, vector<int>(n, 0));
        mat[0][0] = grid[0][0]==0? health : health-1;
        queue<pair<int, int>> qu;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        qu.push({0, 0});
        while (!qu.empty()) {
            auto [i, j] = qu.front();
            qu.pop();
            for (auto p : dir) {
                int ni = i + p.first;
                int nj = j + p.second;
                if (ni < 0 or nj < 0 or ni >= m or nj >= n)
                    continue;
                int newh;
                if (grid[ni][nj] == 1) {
                    newh = mat[i][j] - 1;
                } else {
                    newh = mat[i][j];
                }
                if (newh > mat[ni][nj]) {
                    mat[ni][nj] = newh;
                    qu.push({ni, nj});
                }
            }
        }
        return mat[m - 1][n - 1] > 0;
    }
};