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
    void dfs(TreeNode *root,int val,int depth,int curr)
    {
        if(root==NULL)
        return;
        if(curr==depth-1)
        {
            TreeNode* l=new TreeNode(val);
            TreeNode* r=new TreeNode(val);
            TreeNode* pl=root->left;
            TreeNode* pr=root->right;
            root->left=l;
            root->right=r;
            l->left=pl;
            r->right=pr;
            return;
        }
        dfs(root->left,val,depth,curr+1);
        dfs(root->right,val,depth,curr+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        dfs(root,val,depth,1);
        return root;
    }
};
