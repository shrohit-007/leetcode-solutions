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
    void dfs(TreeNode*root1,TreeNode*root2,int f,TreeNode*p)
    {
        if(root1==NULL and root2==NULL)return ;
        else if(root1!=NULL and root2!=NULL)
        {
            root1->val+=root2->val;
            dfs(root1->left,root2->left,0,root1);
            dfs(root1->right,root2->right,1,root1);
        }
        else
        {
            if(root1==NULL)
            {
                TreeNode *newnode=new TreeNode(root2->val);
                if(f==0)
                {
                    p->left=newnode;
                }
                else
                    p->right=newnode;
                dfs(newnode->left,root2->left,0,newnode);
                dfs(newnode->right,root2->right,1,newnode);
            }
            else
            {
                dfs(root1->left,root2,0,root1);
                dfs(root1->right,root2,1,root1);
            }
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL or root2==NULL)
        {
            if(root1==NULL)
                return root2;
            return root1;
        }
        dfs(root1,root2,-1,root1);
        return root1;
    }
};
