class Solution {
public:
    int countnodes(int root,vector<int>&l,vector<int>&r)
    {
        if(root==-1)return 0;
        return 1+countnodes(l[root],l,r)+countnodes(r[root],l,r);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>degree(n,0);
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1 && degree[leftChild[i]]++==1)
            {
                return false;
            }
            if(rightChild[i]!=-1 && degree[rightChild[i]]++==1)
                return false;
        }
        int root=-1;
        for(int i=0;i<n;i++)
        {
            if(degree[i]==0)
            {
                if(root==-1)
                {
                    root=i;
                }
                else
                    return false;
            }
        }
        if(root==-1)return false;
        return countnodes(root,leftChild,rightChild)==n;
    }
};
