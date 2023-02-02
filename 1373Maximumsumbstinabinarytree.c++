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
    int maxi=0;
    pair<pair<int,int>,pair<int,bool>> validbst(TreeNode *root)
    {
        if(root==NULL)return {{INT_MAX,INT_MIN},{0,true}};
        pair<pair<int,int>,pair<int,bool>>left=validbst(root->left);
        pair<pair<int,int>,pair<int,bool>>right=validbst(root->right);
        pair<pair<int,int>,pair<int,bool>>ans;
        ans.first.second=max(left.first.second,max(right.first.second,root->val));
        ans.first.first=min(left.first.first,min(right.first.first,root->val));
        if(left.second.second and right.second.second and left.first.second<root->val and right.first.first>root->val)
        {
            ans.second.second=true;
            ans.second.first=left.second.first+right.second.first+root->val;
            maxi=max(maxi,ans.second.first);
        }
        else
        {
            ans.second.second=false;
        }
        return ans;
    }
    int maxSumBST(TreeNode* root) {
        validbst(root);
        return maxi;
    }
};
