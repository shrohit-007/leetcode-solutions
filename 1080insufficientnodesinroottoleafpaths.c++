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
    pair<TreeNode*,int> dfs(TreeNode *root,int limit,int sum)
    {
        if(!root)return {NULL,0};
        if(root->left==NULL and root->right==NULL)
        {
            if(sum+root->val<limit)
            {
                return {NULL,1};
            }
        }
        pair<TreeNode*,bool>lefti=dfs(root->left,limit,sum+root->val);
        pair<TreeNode*,bool>righti=dfs(root->right,limit,sum+root->val);
        root->left=lefti.first;
        root->right=righti.first;
        if(root->left==NULL and root->right==NULL and (lefti.second==1 or righti.second==1))
        {
            return {NULL,1};
        }
        return {root,0};
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root,limit,0).first;
    }
};
