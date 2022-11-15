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
    int cnt=0;
    //bool visited[1000000];
    void dfs(TreeNode*root)
    {
        if(root==NULL)return;
        //if(visited[root->val])return;
       // visited[root->val]=true;
        cnt++;
        dfs(root->left);
        dfs(root->right);
    }
    int countNodes(TreeNode* root) {
        memset(visited,false,sizeof(visited));
        dfs(root);
        return cnt;
    }
};
