class Solution {
public:
    bool dfs(vector<vector<int>>&grid,int i,int j)
    {
        if(i+1==grid.size() and j+1==grid[0].size())
        {
            return true;
        }
        if(i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)
        {
            return false;
        }
        grid[i][j]=0;
        return dfs(grid,i+1,j)||dfs(grid,i,j+1);
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if(dfs(grid,0,0)==false)
            return true;
        grid[0][0]=1;
        int n=grid.size();
        return !dfs(grid,0,0);
        
    }
};
