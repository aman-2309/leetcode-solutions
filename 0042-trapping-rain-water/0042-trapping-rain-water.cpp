class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int ans = 0;
        int leftMax = height[0], rightMax = height[n - 1];
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    ans += leftMax - height[left];
                left++;
            }else{
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};