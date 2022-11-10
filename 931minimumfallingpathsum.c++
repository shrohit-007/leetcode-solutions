class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=matrix[i][j]+(i>0?min(dp[i-1][j],(j<n-1?dp[i-1][j+1]:0)):0);
                }
                else if(j==n-1)
                {
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                }
                else
                {
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],min(dp[i-1][j+1],dp[i-1][j-1]));
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
           
            ans=min(ans,dp[n-1][i]);
        }return ans;
    }
};
