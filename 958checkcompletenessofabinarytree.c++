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
    int level(TreeNode*root)
    {
        if(root==NULL)return 0;
        return 1+max(level(root->left),level(root->right));
    }
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int lvl=level(root);
        while(!q.empty())
        {
            if(lvl==2)
            {
                int x=q.size();
                int cnt=0,f=0;
                for(int i=0;i<x;i++)
                {
                    TreeNode *top=q.front();
                    q.pop();
                    if(top->left)q.push(top->left);
                    if(top->right)q.push(top->right);
                    if(!f and top->left)cnt++;
                    else f=1;
                    if(!f and top->right)cnt++;
                    else f=1;
                }
                //cout<<cnt<<" "<<q.size()<<endl;
                if(cnt!=q.size())
                    return false;
                else 
                    return true;
            }
            int x=q.size();
            for(int i=0;i<x;i++)
            {
                TreeNode* top=q.front();
                q.pop();
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
            //cout<<lvl<<" "<<q.size()<<" "<<x<<endl;
            if(lvl>2 and q.size()!=2*x)return false;
            lvl--; 
        }
        return true;
    }
};
