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
    TreeNode *createtree(vector<int>&inorder,int is,int ie,vector<int>&postorder,int ps,int pe)
    {
        if(ps>pe)return NULL;
        TreeNode *newnode=new TreeNode(postorder[pe]);
        int pos=-1;
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==postorder[pe])
            {
                pos=i;
                break;
            }
        }
        newnode->left=createtree(inorder,is,pos-1,postorder,ps,ps+pos-is-1);
        newnode->right=createtree(inorder,pos+1,ie,postorder,ps+pos-is,pe-1);
        return newnode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return createtree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};
