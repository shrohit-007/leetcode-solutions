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
    TreeNode* createtree(vector<int>&inorder,int ilo,int ihi,vector<int>&preorder,int plo,int phi)
    {
        if(ilo>ihi || plo>phi)
        {
            return NULL;
        }
        TreeNode * nn=new TreeNode(preorder[plo]);
        int pos=-1;
        for(int i=ilo;i<=ihi;i++)
        {
            if(inorder[i]==preorder[plo])
            {
                pos=i;
                break;
            }
        }
        int net=pos-ilo;
        nn->left=createtree(inorder,ilo,pos-1,preorder,plo+1,plo+net);
        nn->right=createtree(inorder,pos+1,ihi,preorder,plo+net+1,phi);
        return nn;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createtree(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1);
        
    }
};
