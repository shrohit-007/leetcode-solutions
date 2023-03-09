class Solution {
public:
    int mod=1000000007;
    int f(vector<vector<int>>&grid,int i,int j,int k,int n,int m,int sum,vector<vector<vector<int>>>&dp)
    {
        if(i==n or j==m)return 0;
        if(i==n-1 and j==m-1)
        {
            if(sum%k==0)return 1;
            return 0;
        }
        if(dp[i][j][sum]!=-1)return dp[i][j][sum];
        int ans=0;
        if(i<n-1)
        ans+=f(grid,i+1,j,k,n,m,(sum+grid[i+1][j])%k,dp)%mod;
        if(j<m-1)
        ans+=f(grid,i,j+1,k,n,m,(sum+grid[i][j+1])%k,dp)%mod;
        return dp[i][j][sum]=ans%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                grid[i][j]%=k;
               // cout<<grid[i][j]<<" ";
            }//cout<<endl;
        }
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>>dp(n+2,vector<vector<int>>(m+2,vector<int>(k+1,-1)));
       // cout<<n<< " "<<m<<endl;
        int ans=f(grid,0,0,k,n,m,grid[0][0],dp)%mod;
        return ans;
    }
};
