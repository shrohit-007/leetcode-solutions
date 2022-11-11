class Solution {
public:
    //bAckTraCking Solution exploring every path from (0,0) to (n-1,n-1) and for every valid path we are again backtracking to reverse solution
    /*int ans=0;
    void backtrackagain(int r,int c,vector<vector<int>>&grid,int cherry)
    {
        if(r<0 or c<0 or grid[r][c]==-1)
        return;
        if(r==0 and c==0)
        {
            ans=max(ans,cherry);
            return;
        }
        int chery=grid[r][c];
        grid[r][c]=0;
        backtrackagain(r-1,c,grid,cherry+chery);
        backtrackagain(r,c-1,grid,cherry+chery);
        grid[r][c]=chery;
    }
    void backtrack(int r,int c,vector<vector<int>>&grid,int cherry)
    {
        if(r>=grid.size() or c>=grid[0].size() or grid[r][c]==-1)
            return;
        if(r==grid.size()-1 and c==grid[0].size()-1)
        {
            backtrackagain(r,c,grid,cherry);
        }
        int chery=grid[r][c];
        grid[r][c]=0;
        backtrack(r+1,c,grid,cherry+chery);
        backtrack(r,c+1,grid,cherry+chery);
        grid[r][c]=chery;
    }
    */
    int dp[50][50][50];
    int recursive(int r1,int c1,int r2,vector<vector<int>>&grid)
    {
        int c2=r1-r2+c1;
        if(r1>=grid.size() or r2>=grid.size() or c1>=grid[0].size() or c2>=grid[0].size() or grid[r1][c1]==-1 or grid[r2][c2]==-1)
            return INT_MIN;
        if(r1==grid.size()-1 and c1==grid[0].size()-1)
        {
            return grid[r1][c1];
        }
        if(dp[r1][c1][r2]!=0)
            return dp[r1][c1][r2];
        int cherry=0;
        if(r1==r2 and c1==c2)
            cherry+=grid[r1][c1];
        else
            cherry+=grid[r1][c1]+grid[r2][c2];
        int f1=recursive(r1+1,c1,r2+1,grid);
        int f2=recursive(r1+1,c1,r2,grid);
        int f3=recursive(r1,c1+1,r2,grid);
        int f4=recursive(r1,c1+1,r2+1,grid);
        cherry+=max(max(f1,f2),max(f3,f4));
        return dp[r1][c1][r2]=cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        if(grid.size()==1 and grid[0].size()==1)
            return grid[0][0];
        int n=grid.size();
        //backtrack(0,0,grid,0);
        //memoizaton
        //int dp[n][n][n][n]={0};
        int ans=recursive(0,0,0,grid);
        if(ans<0)
            return 0;
        return ans;
        
    }
};
