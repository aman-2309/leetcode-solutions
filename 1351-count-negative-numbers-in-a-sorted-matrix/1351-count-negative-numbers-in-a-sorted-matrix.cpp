class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int j = n-1;
        for(int i=0;i<m;){
            if(grid[i][j]<0){
                if(j==0){
                    ans+=(n*(m-i));
                    break;
                }else{
                    j--;
                }
            }
            else{
                ans+=(n-j-1);
                i++;
            }
        }
        return ans;
    }
};