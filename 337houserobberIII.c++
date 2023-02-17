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
    // recursion with memoization solution
    // unordered_map<TreeNode*,int>dp;
    // int mxreturn(TreeNode*root)
    // {
    //     if(root==NULL)
    //     {
    //         return 0;
    //     }
    //     if(dp[root])
    //         return dp[root];
    //     int pick=root->val;
    //     int leftl=(root->left!=nullptr)?mxreturn(root->left->left):0;
    //     int leftr=(root->left!=nullptr)?mxreturn(root->left->right):0;
    //     int rightl=(root->right!=nullptr)?mxreturn(root->right->left):0;
    //     int rightr=(root->right!=nullptr)?mxreturn(root->right->right):0;
    //     // non pick
    //     int npick=mxreturn(root->left)+mxreturn(root->right);
    //     return dp[root]=max(pick+leftl+leftr+rightl+rightr,npick);
    // }
    
    // bfs or level order traversal solution;
    pair<int,int>dfs(TreeNode*root)
    {
        if(root==nullptr)return {0,0};
        pair<int,int>left=dfs(root->left);
        pair<int,int>right=dfs(root->right);
        int rootrobbed=root->val+left.second+right.second;
        int rootnotrobbed=max(left.second,left.first)+max(right.first,right.second);
        return {rootrobbed,rootnotrobbed};
    }
    int rob(TreeNode* root) {
        //return mxreturn(root);
        pair<int,int>ans=dfs(root);
        return max(ans.first,ans.second);
    }
};
