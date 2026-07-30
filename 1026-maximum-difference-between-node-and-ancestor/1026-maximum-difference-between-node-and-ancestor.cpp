
class Solution {
public:
    void maxDiff(TreeNode* root, int& ans, int mx, int mn) {
        if (!root)
            return;
        mx = max(mx, root->val);
        mn = min(mn, root->val);

        ans = max(ans, mx - mn);
        maxDiff(root->left, ans, mx, mn);
        maxDiff(root->right, ans, mx, mn);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN;
        maxDiff(root, ans, root->val, root->val);
        return ans;
    }
};