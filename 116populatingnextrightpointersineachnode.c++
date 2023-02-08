/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void zigzag(Node *root)
    {
        queue<Node*>q;
        if(root!=NULL)
        {
            q.push(root);
        }
        while(!q.empty())
        {
            int x=q.size();
            //cout<<x<<endl;
            for(int i=0;i<x;i++)
            {
                Node *top=q.front();
                q.pop();
                if(i<x-1)
                {
                    top->next=q.front();
                }
                else
                {
                    top->next=NULL;
                }
                if(top->left!=NULL)q.push(top->left);
                if(top->right!=NULL)q.push(top->right);
            }
        }
    }
    Node* connect(Node* root) {
        zigzag(root);
        return root;
    }
};
