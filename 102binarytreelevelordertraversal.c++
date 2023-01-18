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
    void dfs(vector<vector<int>>&ans,TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int x=q.size();
            vector<int>temp;
            for(int i=0;i<x;i++)
            {
                TreeNode* y=q.front();
                q.pop();
                temp.push_back(y->val);
                if(y->left!=NULL)
                    q.push(y->left);
                if(y->right!=NULL)
                    q.push(y->right);
            }
            ans.push_back(temp);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        dfs(ans,root);
        return ans;
    }
};
