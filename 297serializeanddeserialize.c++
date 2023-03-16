/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        queue<TreeNode*>q;
        q.push(root);
        string ans="";
        while(!q.empty())
        {
            int x=q.size();
            for(int i=0;i<x;i++)
            {
                TreeNode* cur=q.front();
                q.pop();
                if(cur)
                    ans+=to_string(cur->val);
                else
                    ans+='x';
                ans+='n';
                if(cur)
                q.push(cur->left);
                if(cur)
                q.push(cur->right);
            }
        }
       // cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        int i=0;
        string val="";
        while(i<data.size() and data[i]!='n')
        {
            val+=data[i];
            i++;
        }
        i++;
        TreeNode*root=new TreeNode(stoi(val));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *top=q.front();
            q.pop();
            string val1="",val2="";
            while(i<data.size()-1 and data[i]!='n')
            {
                val1+=data[i];
                i++;
            }i++;
            while(i<data.size()-1 and data[i]!='n')
            {
                val2+=data[i];
                i++;
            }i++;
            if(val1!="x")
            {
                TreeNode* left=new TreeNode(stoi(val1));
                q.push(left);
                top->left=left;
            }
            if(val2!="x")
            {
                TreeNode* right=new TreeNode(stoi(val2));
                q.push(right);
                top->right=right;
            }
            if(i==data.size())break;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
