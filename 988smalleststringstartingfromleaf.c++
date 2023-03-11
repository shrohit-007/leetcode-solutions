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
    void dfs(TreeNode *root,string&ans,string cmp)
    {
        if(!root)return;
        cmp.push_back(root->val+'a');
        if(root->left==NULL and root->right==NULL)
        {
            //cout<<cmp<<endl;
            string tmp=cmp;
            reverse(tmp.begin(),tmp.end());
            if(ans.size()==0)ans=tmp;
            else if(tmp<ans)ans=tmp;
            return ;
        }
        dfs(root->left,ans,cmp);
        dfs(root->right,ans,cmp);
        cmp.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        dfs(root,ans,"");
        return ans;
    }
};
