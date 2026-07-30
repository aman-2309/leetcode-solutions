/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> qu;
        qu.push(root);
        bool flag = true;
        while(!qu.empty()){
            int n = qu.size();
            vector<int> v;
            while(n--){
                TreeNode* p = qu.front();
                qu.pop();
                if(p->left) qu.push(p->left);
                if(p->right) qu.push(p->right);
                v.push_back(p->val);
            }
            if(flag){
                flag = false;
            }else{
                reverse(v.begin(),v.end());
                flag = true;
            }
            ans.push_back(v);
        }
        return ans;
    }
};