class Solution {
public:
    void lexicocounting(int curr,int n,vector<int>&ans)
    {
        if(curr>n)
        {
            return;
        }
        if(curr!=0)
        ans.push_back(curr);
        int i=0;
        if(curr==0)
        {
            i=1;
        }
        for(;i<=9;i++)
        {
            lexicocounting(curr*10+i,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        
        vector<int>ans;
        lexicocounting(0,n,ans);
        return ans;
    }
};
