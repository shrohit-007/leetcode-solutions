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
    int prev=0;
    void sums(TreeNode *root)
    {
        if(root->right)sums(root->right);
        prev=root->val=prev+root->val;
        if(root->left)sums(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        sums(root);
        return root;
    }
};
