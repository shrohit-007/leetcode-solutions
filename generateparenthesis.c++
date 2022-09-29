class Solution {
public:
    void recu(int n,int i,string ans,vector<string>&ans1,int cnt1)
    {
        if(i==n)
        {
            if(cnt1==0)
            ans1.push_back(ans);
            return;
        }
        if(cnt1<0)
        {
            return;
        }
        recu(n,i+1,ans+'(',ans1,cnt1+1);
        recu(n,i+1,ans+')',ans1,cnt1-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans1;
        recu(2*n,0,"",ans1,0);
        return ans1;
    }
};
