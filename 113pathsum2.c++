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
    void dfs(TreeNode* root,int target,int sum,vector<int>&v,vector<vector<int>>&nodelist)
    {
        if(root==NULL)
        {
            return;
        }
        v.push_back(root->val);
        sum+=root->val;
        //cout<<sum<<endl;
        if(sum==target and root->left==NULL and root->right==NULL)
        {
            nodelist.push_back(v);
            sum-=v[v.size()-1];
            v.pop_back();
            return;
        }
        dfs(root->left,target,sum,v,nodelist);
        dfs(root->right,target,sum,v,nodelist);
        sum-=v[v.size()-1];
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>nodelist;
        vector<int>v;
        dfs(root,targetSum,0,v,nodelist);
        return nodelist;
    }
};
