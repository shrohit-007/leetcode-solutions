class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>ans(m,-1);
        for(int j=0;j<m;j++)
        {
            int x=0,y=j,f=0;
            while(x<n and y<m)
            {
                f=1;
                if(grid[x][y]==1)
                {
                    if(y+1<m and grid[x][y+1]!=-1)
                    {
                        x++;
                        y++;
                    }
                    else
                    {
                        x=-1;
                        y=-1;
                        break;
                    }
                }
                else
                {
                    if(y-1>=0 and grid[x][y-1]!=1)
                    {
                        x++;
                        y--;
                    }
                    else
                    {
                        x=-1;
                        y=-1;
                        break;
                    }
                }
            }
            if(f==0 or (x==-1 and y==-1))
                ans[j]=-1;
            else
                ans[j]=y;
        }
        return ans;
    }
};
