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
    void insert(TreeNode *root,TreeNode * node1,TreeNode *parent,int f)
    {
         if(root==NULL)
         {
             if(f==1)
             {
                 parent->right=node1;
             }
             else
                 parent->left=node1;
             return ;
         }
         if(root->val<node1->val)
         {
            insert(root->right,node1,root,1);
         }
         else
             insert(root->left,node1,root,0);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *newnode=new TreeNode(val);
        if(root==NULL)return newnode;
        insert(root,newnode,NULL,-1);
        return root;
        
    }
};
