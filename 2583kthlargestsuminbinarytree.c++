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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        vector<long long >v;
        q.push(root);
        while(!q.empty())
        {
            int x=q.size();
            long long sum=0;
            for(int i=0;i<x;i++)
            {
                TreeNode* tp=q.front();
                q.pop();
                sum+=tp->val;
                if(tp->left)q.push(tp->left);
                if(tp->right)q.push(tp->right);
            }
            v.push_back(sum);
        }
        sort(v.begin(),v.end());
        if(v.size()<k)
        {
            return -1;
        }
        else
        {
            return v[v.size()-k];
        }
        
    }
};
