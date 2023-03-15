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
    unordered_map<TreeNode*,vector<TreeNode*>>m;
    vector<TreeNode*>leafs;
    unordered_map<TreeNode*,bool>visited;
    void dfs(TreeNode* root,TreeNode* par)
    {
        if(!root)return;
        if(root->left==NULL and root->right==NULL)leafs.push_back(root);
        if(par)m[root].push_back(par);
        if(root->left)m[root].push_back(root->left);
        if(root->right)m[root].push_back(root->right);
        dfs(root->left,root);
        dfs(root->right,root);
    }
    int ans=0;
    void dfs2(TreeNode *root,int d,int dis,TreeNode*parent,TreeNode*grandparent)
    {
        if(m[root].size()==1 and !visited[root] and root!=grandparent and root!=parent)
        {
            if(d<=dis)
            {
                ans++;
            }
        }
        for(TreeNode *child:m[root])
        {
            if(child!=parent)
            {
                dfs2(child,d+1,dis,root,grandparent);
            }
        }
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root,NULL);
        for(int i=0;i<leafs.size();i++)
        {
            dfs2(leafs[i],0,distance,leafs[i],root);
            visited[leafs[i]]=true;
        }
        return ans;
    }
};
