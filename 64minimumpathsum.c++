class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //cout<<m<<endl;
        vector<int>dp(m,0);
        for(int i=0;i<n;i++)
        {
            vector<int>temp(m,0);
            for(int j=0;j<m;j++)
            {
                if(i==0 or j==0)
                {
                    temp[j]=grid[i][j]+(i>0?dp[j]:0)+(j>0?temp[j-1]:0);
                }
                else
                {
                    temp[j]=grid[i][j]+min(dp[j],temp[j-1]);
                }
            }
            dp=temp;
        }return dp[m-1];
    }
};
