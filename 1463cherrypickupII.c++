class Solution {
public:
    //recursive code
    
   /* int f(int i,int j1,int j2,vector<vector<int>>grid,vector<vector<vector<int>>>&dp)
    {
        if(j1<0 or j1>=grid[0].size() or j2<0 or j2>=grid[0].size())
        {
            return -1e8;
        }
        if(i==grid.size()-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        int maxi=-1e8;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                int value=0;
                if(j1==j2)
                {
                    value=grid[i][j1];
                }
                else
                {
                    value=grid[i][j1]+grid[i][j2];
                }
                value+=f(i+1,j1+dj1,j2+dj2,grid,dp);
                maxi=max(maxi,value);
            }
        }
        return dp[i][j1][j2]=maxi;    
    }*/
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        //return f(0,0,m-1,grid,dp);
        // tabulation
        for(int i=n-1;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    if(i==n-1)
                    {
                        if(j1==j2)
                        {
                            dp[i][j1][j2]=grid[i][j1];
                        }
                        else
                        {
                            dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
                        }
                    }
                    else
                    {
                        int maxi=-1e8;
                        for(int dj1=-1;dj1<=1;dj1++)
                        {
                            for(int dj2=-1;dj2<=1;dj2++)
                            {
                                int value=0;
                                if(j1==j2)
                                value=grid[i][j1];
                                else value=grid[i][j1]+grid[i][j2];
                                if(j1+dj1>=0 and j1+dj1<m and j2+dj2>=0 and j2+dj2<m)
                                {
                                    value+=dp[i+1][j1+dj1][j2+dj2];
                                }
                                else
                                    value+=-1e8;
                                maxi=max(maxi,value);
                            }
                        } 
                        dp[i][j1][j2]=maxi;
                    }
                }
            }
        }
        return dp[0][0][m-1];
    }
};
