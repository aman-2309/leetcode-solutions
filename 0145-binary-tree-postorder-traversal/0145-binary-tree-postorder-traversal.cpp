class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return {};

        stack<TreeNode*> st;
        vector<int> ans;

        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);

            if (node->left)
                st.push(node->left);

            if (node->right)
                st.push(node->right);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};