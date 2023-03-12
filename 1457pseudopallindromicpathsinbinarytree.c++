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
    void dfs(TreeNode*root,vector<int>&freq)
    {
        if(!root)return;
        freq[root->val]++;
        if(root->left==NULL && root->right==NULL)
        {
            int o=0;
            for(int i=1;i<=9;i++)
            {
                if(freq[i]%2==1)o++;
            }
            if(o<=1)ans++;
            freq[root->val]--;
            return ;
        }
        dfs(root->left,freq);
        dfs(root->right,freq);
        freq[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>v(10,0);
        dfs(root,v);
        return ans;
    }
};
