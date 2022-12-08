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
    void dfs(vector<int>&v,TreeNode* root)
    {
        if(root==NULL)return;
        if(root->left==NULL and root->right==NULL)
        {
            v.push_back(root->val);
            return;
        }
        dfs(v,root->left);
        dfs(v,root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v,v1;
        dfs(v,root1);
        dfs(v1,root2);
        if(v==v1)
        return true;
        return false;
    }
};
