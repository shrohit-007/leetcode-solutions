class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>>dp(n+2,vector<int>(m+2,1e9));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 or j==m-1)
                {
                    dp[i][j]=dungeon[i][j]+(i<n-1?dp[i+1][j]:0)+(j<m-1?dp[i][j+1]:0);
                }
                else
                {
                    dp[i][j]=dungeon[i][j]+max(dp[i+1][j],dp[i][j+1]);
                }
                if(dp[i][j]>0)dp[i][j]=0;
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        if(dp[0][0]>0)return 0;
        return abs(dp[0][0])+1;
    }
};
