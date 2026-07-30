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
    void path(TreeNode* root,vector<int> v,int sum,vector<vector<int>> &ans,int targetSum){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            v.push_back(root->val);
            sum+=root->val;
            if(sum==targetSum){
                ans.push_back(v);
            }
            return;
        }
        v.push_back(root->val);
        sum+=root->val;
        path(root->left,v,sum,ans,targetSum);
        path(root->right,v,sum,ans,targetSum);
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        path(root,v,0,ans,targetSum);
        return ans;
    }
};