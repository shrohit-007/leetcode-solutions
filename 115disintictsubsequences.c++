class Solution {
public:
    int dp[1002][1002];
    // int f(string &s,string &t,int i,int j)
    // {
    //     if(j==t.length())return 1;
    //     if(i==s.length())return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int ans=0;
    //     if(s[i]==t[j])
    //     {
    //         ans+=f(s,t,i+1,j+1);
    //     }
    //     ans+=f(s,t,i+1,j);
    //     return dp[i][j]=ans;
    // }
    int numDistinct(string s, string t) {
        memset(dp,0,sizeof(dp));
        int n=s.length(),m=t.length();
        for(int i=0;i<=s.length();i++)
        {
            dp[i][m]=1;
        }
        if(s.length()<t.length())return 0;
       // return f(s,t,0,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                dp[i][j]=dp[i+1][j];
                if(s[i]==t[j] and dp[i][j]+1ll+dp[i+1][j+1]<INT_MAX)
                    dp[i][j]+=dp[i+1][j+1];   
            }
        }
        
        return dp[0][0];
    }
};
