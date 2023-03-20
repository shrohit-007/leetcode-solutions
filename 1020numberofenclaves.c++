class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 and (i==0 or j==0  or i==n-1 or j==m-1))
                {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            grid[x][y]=0;
            vis[x][y]=1;
            if(x+1<n and grid[x+1][y]==1 and !vis[x+1][y])
            {
                vis[x+1][y]=1;
                q.push({x+1,y});
            }
            if(x-1>=0 and grid[x-1][y]==1 and !vis[x-1][y])
            {
                vis[x-1][y]=1;
                q.push({x-1,y});
            }
            if(y+1<m and grid[x][y+1]==1 and !vis[x][y+1])
            {
                vis[x][y+1]=1;
                q.push({x,y+1});
            }
            if(y-1>=0 and grid[x][y-1]==1 and !vis[x][y-1])
            {
                vis[x][y-1]=1;
                q.push({x,y-1});
            }
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])c++;
            }
        }
        return c;
    }
};
