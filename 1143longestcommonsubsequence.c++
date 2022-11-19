class Solution {
public:
    // recursion + memozization
   /* int lcs(string &s,string &t,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0 or j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
        {
            return dp[i][j]=1+lcs(s,t,i-1,j-1,dp);
        }
        return dp[i][j]=max(lcs(s,t,i-1,j,dp),lcs(s,t,i,j-1,dp));
    }*///
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,0));
       // return lcs(text1,text2,text1.length()-1,text2.length()-1,dp);
        int n=text1.length(),m=text2.length();
        
        // tabulation
        /*for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }*/
       // return dp[0][0];
        
        // space optmization
        
        vector<int>curr(m+3,0),prev(m+3,0);
        // we have also used shifting of index;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    curr[j]=1+prev[j-1];
                }
                else
                {
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }prev=curr;
        }
        return prev[m];
    }
};
