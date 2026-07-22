class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<int> ans;
        int d = 0;
        int i=0,j=0;
        while(ans.size()<m*n){
            // cout<<matrix[i][j]<<' ';
            ans.push_back(matrix[i][j]);
            matrix[i][j] = -101;
            int ni = i+dir[d][0];
            int nj = j+dir[d][1];
            if(ni>=m or nj>=n or ni<0 or nj<0 or matrix[ni][nj]==-101){
                d++;
                d%=4;
                ni = i+dir[d][0];
                nj = j+dir[d][1];
            }
            i=ni;
            j=nj;
        }
        return ans;
    }
};