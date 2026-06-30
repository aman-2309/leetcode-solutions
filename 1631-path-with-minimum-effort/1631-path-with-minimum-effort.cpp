class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> minEff(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        pq.push({0, 0, 0});
        minEff[0][0] = 0;
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!pq.empty()) {
            auto [eff , x, y] = pq.top();
            pq.pop();
            for (auto& v : dir) {
                int nx = x + v[0];
                int ny = y + v[1];
                if (nx < 0 or ny < 0 or nx >= m or ny >= n)
                    continue;
                else {
                    int newEff = max(minEff[x][y],
                                     abs(heights[x][y] - heights[nx][ny]));

                    if (newEff < minEff[nx][ny]) {
                        minEff[nx][ny] = newEff;
                        pq.push({newEff, nx, ny});
                    }
                }
            }
        }

        return minEff[m - 1][n - 1];
    }
};