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
    int ans=0;
    void f(TreeNode *root,int target,vector<int>&list)
    {
        if(root==nullptr)return ;
        list.push_back(root->val);
        f(root->left,target,list);
        f(root->right,target,list);
        long long temp=0;
        for(int i=list.size()-1;i>=0;i--)
        {
            temp+=list[i];
            if(temp==target)ans++;
        }
        list.pop_back(); 
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>list;
        f(root,targetSum,list);
        return ans;
    }
};
