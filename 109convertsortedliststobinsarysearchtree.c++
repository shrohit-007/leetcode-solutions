/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* maketree(vector<int>&v,int s,int e,TreeNode* root)
    {
        if(s>e)
            return NULL;
        int mid=(s+e)/2;
        root=new TreeNode(v[mid]);
        TreeNode *left1=maketree(v,s,mid-1,root->left);
        TreeNode *right1=maketree(v,mid+1,e,root->right);
        root->left=left1;
        root->right=right1;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode* temp=head;
        vector<int>v;
        while(temp)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        TreeNode*root=NULL;
        return maketree(v,0,v.size()-1,root);
    }
};
