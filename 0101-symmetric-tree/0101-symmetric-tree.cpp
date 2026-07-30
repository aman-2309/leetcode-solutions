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
    void fl(TreeNode* root,vector<int> &v){
        if(root==NULL){
            v.push_back(101);
            return;
        }
        v.push_back(root->val);
        fl(root->left,v);
        fl(root->right,v);
        return;

    }
    void fr(TreeNode* root,vector<int> &v){
        if(root==NULL){
            v.push_back(101);
            return;
        }
        v.push_back(root->val);
        fr(root->right,v);
        fr(root->left,v);
        
        return;

    }
    bool isSymmetric(TreeNode* root) {
        vector<int> vl;
        vector<int> vr;
        fl(root->left,vl);
        fr(root->right,vr);
        if(vl.size()!=vr.size()) return false;
        for(int i=0;i<vl.size();i++){
            if(vl[i]!=vr[i]) return false;
        }
        return true;
    }
    
        
};