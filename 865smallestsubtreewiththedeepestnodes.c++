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
    int depth(TreeNode *root)
    {
        if(!root)return -1;
        int left=depth(root->left);
        int right=depth(root->right);
        return 1+max(left,right);
    }
    TreeNode *dfs(TreeNode *root,int dis,int d)
    {
        if(!root)return NULL;
        if(dis==d)
        {
            return root;
        }
        TreeNode *left=dfs(root->left,dis+1,d);
        TreeNode *right=dfs(root->right,dis+1,d);
        if(left!=NULL and right!=NULL)
        {
            return root;
        }
        if(left)return left;
        return right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int d=depth(root);
        return dfs(root,0,d);
        
    }
};
