class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ans=INT_MAX;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int cost=INT_MAX;
                for(int k=0;k<m;k++)
                {
                    cost=min(cost,dp[i-1][k]+grid[i-1][k]+moveCost[grid[i-1][k]][j]);
                }
                dp[i][j]=cost;
            }
        }
        for(int i=0;i<grid[0].size();i++)
        {
            ans=min(dp[n-1][i]+grid[n-1][i],ans);
        }
        return ans;
    }
};
