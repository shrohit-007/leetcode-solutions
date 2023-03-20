class Solution {
public:
    void dfs(vector<vector<char>>&grid,int i,int j)
    {
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]=='0')
        {
            return;
        }
        if(grid[i][j]=='1')
        {
            grid[i][j]='0';
            dfs(grid,i+1,j);
            dfs(grid,i-1,j);
            dfs(grid,i,j+1);
            dfs(grid,i,j-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        //vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    c++;
                    dfs(grid,i,j);
                }
            }
        }
        return c;
    }
};
