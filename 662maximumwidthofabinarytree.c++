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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        long long ans=1;
        int j=1;
        while(!q.empty())
        {
            int x=q.size();
            vector<long long>v;
            j++;
            for(int i=0;i<x;i++)
            {
                TreeNode* top=q.front().first;
                long long ind=q.front().second;
                q.pop();
                if(top->left){q.push({top->left,2*ind});v.push_back(2*ind);}
                if(top->right){q.push({top->right,2*ind+1});v.push_back(2*ind+1);}
            }
            if(v.size()>0)
            ans=max(ans,v[v.size()-1]-v[0]+1);
        }
        return ans;
    }
};
