class Solution {
public:
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre,
                                     vector<vector<int>>& q) {
        vector<vector<bool>> vec(num, vector<bool>(num, false));
        for (int i = 0; i < num; i++) {

            vec[i][i] = true;
        }
        for (auto& v : pre) {
            vec[v[0]][v[1]] = true;
        }
        for (int k = 0; k < num; k++) {
            for (int i = 0; i < num; i++) {
                if (!vec[i][k])
                    continue; 
                for (int j = 0; j < num; j++) {
                    vec[i][j] = vec[i][j] || (vec[i][k] && vec[k][j]);
                }
            }
        }

        vector<bool> ans;
        for (auto& v : q) {
            ans.push_back(vec[v[0]][v[1]]);
        }

        return ans;
    }
};