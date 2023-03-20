class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                }
            }
        }
        //cout<<q.size()<<endl;
        vector<vector<int>>vis(n,vector<int>(m,0));
        while(!q.empty())
        {
            pair<pair<int,int>,int>top=q.front();
            q.pop();
            int x=top.first.first;
            int y=top.first.second;
            vis[x][y]=1;
            grid[x][y]=0;
            int c=top.second;
            ans=max(ans,c);
            if(x+1<n and grid[x+1][y]==1 and !vis[x+1][y])
            {
                vis[x+1][y]=1;
                q.push({{x+1,y},c+1});
            }
            if(x-1>=0 and grid[x-1][y]==1 and !vis[x-1][y])
            {
                vis[x-1][y]=1;
                q.push({{x-1,y},c+1});
            }
            if(y-1>=0 and grid[x][y-1]==1 and !vis[x][y-1])
            {
                vis[x][y-1]=1;
                q.push({{x,y-1},c+1});
            }
            if(y+1<m and grid[x][y+1]==1 and !vis[x][y+1])
            {
                vis[x][y+1]=1;
                q.push({{x,y+1},c+1});
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)return -1;
            }
        }
        return ans;
    }
};
