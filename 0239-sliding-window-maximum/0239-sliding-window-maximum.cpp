class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k and nums[i - k] == dq.front()) {
                dq.pop_front();
            }
            while (not dq.empty() and dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            if (i >= k - 1)
                ans.push_back(dq.front());
        }

        return ans;
    }
};