class Solution {
public:
    /* recursion + memozization
    int f(int i,int j,string &s1,string &s2,vector<vector<int>>&dp)
    {
        if(i==s1.length() or j==s2.length())
        {
            int x=abs((int)s1.length()-i);
            int y=abs((int)s2.length()-j);
            return  max(x,y);
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
        {
            return dp[i][j]=f(i+1,j+1,s1,s2,dp);
        }
        return dp[i][j]=1+min(min(f(i+1,j,s1,s2,dp),f(i,j+1,s1,s2,dp)),f(i+1,j+1,s1,s2,dp));
    }*/
    int minDistance(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //return f(0,0,word1,word2,dp);
        // tabulation
        dp[n][m]=0;
       for(int i=n;i>=0;i--)
       {
        for(int j=m;j>=0;j--)
        {
            if(i==n or j==m)
            {
                dp[i][j]=max(n-i,m-j);
            }
            else if(s1[i]==s2[j])
            {
                dp[i][j]=dp[i+1][j+1];
            }
            else
                dp[i][j]=min(1+dp[i][j+1],min(1+dp[i+1][j],1+dp[i+1][j+1]));
           // cout<<dp[i][j]<<" ";
        }//cout<<endl;
        }
        return dp[0][0];
    }
};
