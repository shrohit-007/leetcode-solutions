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
    TreeNode *target(TreeNode*root,int start)
    {
        if(!root)return NULL;
        if(root->val==start)return root;
        TreeNode *left=target(root->left,start);
        TreeNode *right=target(root->right,start);
        if(left!=NULL)
            return left;
        return right;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* currentnode=que.front();
            que.pop();
            if(currentnode->left)
            {
                parent_track[currentnode->left]=currentnode;
                que.push(currentnode->left);
            }
            if(currentnode->right)
            {
                parent_track[currentnode->right]=currentnode;
                que.push(currentnode->right);
            }
        }
        queue<pair<int,TreeNode*>>q;
        TreeNode* target_node=target(root,start);
        visited[target_node]=true;
        q.push({0,target_node});
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front().second;
                int dis=q.front().first;
                ans=max(ans,dis);
                q.pop();
                if(curr->left and !visited[curr->left])
                {
                    q.push({dis+1,curr->left});
                    visited[curr->left]=true;
                }
                if(curr->right and !visited[curr->right])
                {
                    q.push({dis+1,curr->right});
                    visited[curr->right]=true;
                }
                if(parent_track[curr] and !visited[parent_track[curr]])
                {
                    q.push({dis+1,parent_track[curr]});
                    visited[parent_track[curr]]=true;
                }
            }
        }
        return ans;
    }
};
