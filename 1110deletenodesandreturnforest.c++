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
    vector<TreeNode*>res;
    TreeNode* dfs(TreeNode *root,unordered_set<int>&v)
    {
        if(root==NULL)return NULL;
        if(v.find(root->val)!=v.end())
        {
            if(root->left and v.find(root->left->val)==v.end())res.push_back(root->left);
            if(root->right and v.find(root->right->val)==v.end())res.push_back(root->right);
            dfs(root->left,v);
            dfs(root->right,v);
            return NULL;
        }
        else
        {
            root->left=dfs(root->left,v);
            root->right=dfs(root->right,v);
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>st;
        for(int i=0;i<to_delete.size();i++)
            st.insert(to_delete[i]);
        dfs(root,st);
        if(st.find(root->val)==st.end())
            res.push_back(root);
        return res;
    }
};
