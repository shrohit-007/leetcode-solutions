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
    TreeNode *maketree(vector<int>&preorder,int s,int e)
    {
        if(s>e)return NULL;
       // if(s==e)return new TreeNode(preorder[s]);
        TreeNode *root=new TreeNode(preorder[s]);
        int pos=e+1;
        for(int i=s+1;i<=e;i++)
        {
            if(preorder[i]>preorder[s])
            {
                pos=i;break;
            }
        }
        root->left=maketree(preorder,s+1,pos-1);
        root->right=maketree(preorder,pos,e);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return maketree(preorder,0,preorder.size()-1);
    }
};
