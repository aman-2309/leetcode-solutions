class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> st;
        int lastrow = INT_MIN;
        for (int i = 0; i < m; i++) {
            lastrow = i;
            if (matrix[i][0] > target) {
                break;
            }
        }
        if (lastrow == INT_MIN)
            return false;
        int lastcol = INT_MIN;
        for (int i = 0; i < n; i++) {
            lastcol = i;
            if (matrix[0][i] > target) {
                break;
            }
        }
        if (lastcol == INT_MIN)
            return false;

        for (int i = 0; i <= lastrow; i++) {
            for (int j = 0; j <= lastcol; j++) {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};