class Solution {
public:
    /*int f(int i,int j,string &s,vector<vector<int>>&dp)
    {
        if(i==j or i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==s[j])
        {
            return dp[i][j]= f(i+1,j-1,s,dp);
        }
        return dp[i][j]= 1+min(f(i,j-1,s,dp),f(i+1,j,s,dp));
    }*/
    int minInsertions(string s) {
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),1e6));
        //return f(0,s.length()-1,s,dp);
        int n=s.length();
        // tabulation
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=j)
                {
                    dp[i][j]=0;
                }
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]!=s[j])
                dp[i][j]=1+min(dp[i][j-1],dp[i+1][j]);
                else
                dp[i][j]=dp[i+1][j-1];
            }
        }
        return dp[0][n-1];
    }
};
