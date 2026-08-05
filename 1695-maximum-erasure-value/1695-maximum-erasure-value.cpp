class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool> vis(10001, false);

        int l = 0, sum = 0, ans = 0;

        for (int r = 0; r < nums.size(); r++) {
            while (vis[nums[r]]) {
                vis[nums[l]] = false;
                sum -= nums[l++];
            }

            vis[nums[r]] = true;
            sum += nums[r];
            ans = max(ans, sum);
        }

        return ans;
    }
};