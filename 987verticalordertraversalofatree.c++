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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        queue<pair<pair<int,int>,TreeNode*>>q;
        map<int,vector<pair<int,int>>>m;
        if(root)
        q.push({{0,0},root});
        while(!q.empty())
        {
            int left=q.front().first.first;
            int level=q.front().first.second;
            TreeNode *root=q.front().second;
            m[left].push_back({level,root->val});
            q.pop();
            if(root->left)q.push({{left-1,level+1},root->left});
            if(root->right)q.push({{left+1,level+1},root->right});
        }
        for(auto &it:m)
        {
            sort(it.second.begin(),it.second.end());
            vector<int>temp;
            for(auto it1:it.second)
            {
                temp.push_back(it1.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
