class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(4, vector<int>(n));
        for (int i = 0; i < 4; i++) {
            if (i % 2 == 0) {
                dp[i][0] = -1 * prices[0];
            } else {
                dp[i][0] = 0;
            }
        }
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < 4; i++) {
                if (i % 2 == 0) {
                    if (i == 0) {
                        dp[i][j] = max((-1 * prices[j]), dp[i][j - 1]);
                    } else {
                        dp[i][j] =
                            max((dp[i][j - 1]), (dp[i - 1][j - 1] - prices[j]));
                    }
                } else {
                    dp[i][j] =
                        max((dp[i][j - 1]), (dp[i - 1][j - 1] + prices[j]));
                }
            }
        }
        return dp[3][n - 1];
    }
};