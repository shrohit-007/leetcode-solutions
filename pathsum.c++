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
    bool f=false;
    void dfs(TreeNode* root,int targetsum, int sum)
    {
        if(root==NULL)
        {
            return;
        }
        sum+=root->val;
        if(sum==targetsum and root->left==NULL and root->right==NULL)
        {
            f=true;
        }
        dfs(root->left,targetsum,sum);
        dfs(root->right,targetsum,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
         dfs(root,targetSum,0);
         return f;
    }
};
