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
    int check(TreeNode* root,bool &ans)
    {
        if(root==NULL)
        return -1;
        int left=check(root->left,ans);
        int right=check(root->right,ans);
        ans&=(abs(left-right)>1)?false:true;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        check(root,ans);
        return ans;
    }
};
