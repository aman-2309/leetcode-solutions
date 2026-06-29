class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> vec(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            vec[i][i] = 0;
        }
        for (auto& v : edges) {
            vec[v[0]][v[1]] = v[2];
            vec[v[1]][v[0]] = v[2];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if (vec[i][k] == INT_MAX)
                    continue;

                for (int j = 0; j < n; j++) {
                    if (vec[k][j] == INT_MAX)
                        continue;

                    vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
                }
            }
        }
        int ans = -1;
        int ng = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cities = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (vec[i][j] <= distanceThreshold)
                        cities++;
                }
            }
            if (cities <= ng) {
                ans = i;
                ng = cities;
            }
        }

        return ans;
    }
};