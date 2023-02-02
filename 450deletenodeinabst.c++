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
    int mini(TreeNode *root)
    {
        if(root==NULL)
        {
            return 1e9;
        }
        return min(root->val,mini(root->left));
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        {
            return root;
        }
        if(root->val<key)
            root->right=deleteNode(root->right,key);
        else if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }
        else
        {
            if(root->left==NULL)
            {
                return root->right;
            }
            else if(root->right==NULL)
            {
                return root->left;
            }
            else
            {
                int mn=mini(root->right);
                root->right=deleteNode(root->right,mn);
                root->val=mn;
            }
        }
        return root;
    }
};
