class Solution {
public:
    int ans=0;
    void generate(vector<vector<int>>&grid,int i,int j,int cnt,int var)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==-1)
        {
            return;
        }
        if(grid[i][j]==2 and var<cnt)
            return ;
        if(grid[i][j]==2 and cnt==var)
        {
            ans++;
            return;
        }
        //cout<<i<<" "<<j<<endl;
        grid[i][j]=-1;
        var++;
       // cout<<var<<" "<<i<<" "<<j<<endl;
        generate(grid,i+1,j,cnt,var);
        generate(grid,i-1,j,cnt,var);
        generate(grid,i,j+1,cnt,var);
        generate(grid,i,j-1,cnt,var);
        grid[i][j]=0;  
        var--;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int cnt=0;
        int x,y;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=2 and grid[i][j]!=-1)
                    cnt++;
                if(grid[i][j]==1)
                {
                    x=i;
                    y=j;
                }
            }
        }
        generate(grid,x,y,cnt,0);
        return ans;
    }
};
