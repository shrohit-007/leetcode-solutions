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
    bool check(TreeNode *root1,TreeNode* root2)
    {
        if(root1==nullptr and root2==nullptr)
        {
            return true;
        }
        if(root1==nullptr or root2==nullptr)
            return false;
        bool x=true;
        bool y=true;
        if(root1->val==root2->val)
        {
            x&=check(root1->left,root2->left);
            x&=check(root1->right,root2->right);
            y&=check(root1->left,root2->right);
            y&=check(root1->right,root2->left);
        }
        else
            return false;
        return x|y;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return check(root1,root2);
    }
};
