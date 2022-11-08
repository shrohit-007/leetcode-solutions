class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>dp(m,0);
        for(int i=0;i<n;i++)
        {
            vector<int>temp(m,0);
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)temp[j]=0;
                else if(i==0 and j==0)temp[j]=1;
                else
                {
                    temp[j]=(i>0?dp[j]:0)+(j>0?temp[j-1]:0);
                }
            }dp=temp;
        }return dp[m-1];
    }
};
