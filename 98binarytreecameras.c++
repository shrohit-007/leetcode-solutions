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
    int tree(TreeNode * root)
    {
        if(root==NULL)return 1;
        int left=tree(root->left);
        int right=tree(root->right);
        //cout<<left<<" "<<right<<endl;
        if(left==1 and right==1)
        {
            return -1;
        }
        else if((left==1 and right==-1) or (left==-1 and right==1) or (left==-1 and right==-1))
        {
            ans++;
            return 2;
        }
        else if((left==-1 and right==2) or (left==2 and right==-1))
        {
            ans++;
            return 2;
        }
        else
        {
            return 1;
        }
    }
    int minCameraCover(TreeNode* root) {
        int x=tree(root);
        if(x==-1)ans++;
        return ans;
    }
};
