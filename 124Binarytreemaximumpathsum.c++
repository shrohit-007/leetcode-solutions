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
    int mxpathsum(TreeNode *root,int &sum)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=mxpathsum(root->left,sum);
        int right=mxpathsum(root->right,sum);
        int mxsumtillnow=max(max(left,right)+root->val,max(root->val,0));
        sum=max(sum,max(root->val,left+right+root->val));
        return mxsumtillnow;
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        mxpathsum(root,sum);
        return sum;
    }
};
