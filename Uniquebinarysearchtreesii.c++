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
    
    vector<TreeNode*>helper(int st,int end)
    {
        vector<TreeNode*>res;
        if(st>end)
        {
            res.push_back(NULL);
            return res;
        }
        for(int i=st;i<=end;i++)
        {
            vector<TreeNode*>lefts=helper(st,i-1);
            vector<TreeNode*>rights=helper(i+1,end);
            for(TreeNode *l:lefts)
            {
                for(TreeNode *r:rights)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                }
            }
        }return res;
            
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)return vector<TreeNode*>(0);
        vector<TreeNode*>ans;
        ans=helper(1,n);
        return ans;
    }
};
