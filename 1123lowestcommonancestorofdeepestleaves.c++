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
    
    void depth(TreeNode *root,int d,int &mx)
    {
        if(root==NULL)return;
        mx=max(mx,d);
        depth(root->left,d+1,mx);
        depth(root->right,d+1,mx);
    }
    TreeNode *lca(TreeNode *root,int d,int mx)
    {
        if(root==NULL)return NULL;
        if(d==mx)
        {
            return root;
        }
        TreeNode *left=lca(root->left,d+1,mx);
        TreeNode *right=lca(root->right,d+1,mx);
        if(left && right)
            return root;
        else if(left)
            return left;
        return right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int mx=0;
        depth(root,0,mx);
        return lca(root,0,mx);
    }
};
