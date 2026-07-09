class Solution {
public:
    int digitDiff(int n) {
        int s = 9;
        int l = 0;
        while (n > 0) {
            int d = n % 10;
            s = min(s, d);
            l = max(l, d);
            n /= 10;
        }

        return l - s;
    }
    int maxDigitRange(vector<int>& nums) {
        int mx = 0;
        for (int num : nums) {
            mx = max(mx, digitDiff(num));
        }
        int ans = 0;
        for (int num : nums) {
            if (mx == digitDiff(num)) {
                ans += num;
            }
        }

        return ans;
    }
};