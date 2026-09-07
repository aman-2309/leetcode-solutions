/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        unordered_set<TreeNode*> vis;
        stack<TreeNode*> st;
        vector<int> ans;
        st.push(root);
        while (not st.empty()) {
            TreeNode* node = st.top();
            if (vis.count(node) or (!node->left and !node->right)) {
                ans.push_back(node->val);
                st.pop();
                if(node->right){
                    st.push(node->right);
                }
               
            }else if (node->left) {
                st.push(node->left);
            }
            vis.insert(node);
        }
        return ans;
    }
};