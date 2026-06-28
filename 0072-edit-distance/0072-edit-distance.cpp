class Solution {
public:
    int minDistance(string text1, string text2) {
        int m = text1.size() + 1;
        int n = text2.size() + 1;
        vector<vector<int>> dp(m,vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(i==0 or j==0){
                    dp[i][j]= max(i,j);
                }else if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else if(text1[i-1]!=text2[j-1]){
                    dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[m-1][n-1];

    }
};