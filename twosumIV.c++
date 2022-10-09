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
    void dfs(TreeNode*root,map<int,int>&v)
    {
        if(root==NULL)
            return;
        v[root->val]++;
        dfs(root->left,v);
        dfs(root->right,v); 
    }
    bool findTarget(TreeNode* root, int k) {
        map<int,int>v;
        dfs(root,v);
        for(auto &it:v)
        {
            int val=it.first;
            int need=k-val;
            if(need==val)
            {
                if(v.find(need)!=v.end() and it.second>=2)
                {
                    return true;
                }
            
            }
            else
            {
                if(v.find(need)!=v.end())
                return true;
            }
        }
        return false;
    }
};
