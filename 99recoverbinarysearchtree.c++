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
    TreeNode *first=NULL,*second=NULL,*prev=new TreeNode(INT_MIN);
    void inorder(TreeNode*root)
    {
        if(!root)return;
        inorder(root->left);
        if(first==NULL and prev->val>root->val)
        {
            first=prev;
        }
        if(first!=NULL and prev->val>=root->val)
        {
            second=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
    }
};
