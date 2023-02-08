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
    vector<int>ans;
    void zigzag(TreeNode* root)
    {
	queue<TreeNode*>q;
    if(root!=NULL)
	q.push(root);
	while(!q.empty())
	{
		int x=q.size();
          vector<int>temp;
		for(int i=0;i<x;i++)
		{
			TreeNode* top=q.front();
			q.pop();
			temp.push_back(top->val);
			if(top->left!=NULL)q.push(top->left);
			if(top->right!=NULL)q.push(top->right);
		}
        ans.push_back(temp.back());
        
	}
}
    vector<int> rightSideView(TreeNode* root) {
        zigzag(root);
        return ans;
    }
};
