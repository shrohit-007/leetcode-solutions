class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i,int j,int clr){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]==0 || grid[i][j]==clr)return;
        grid[i][j]=clr;
        dfs(grid,i+1,j,clr);
        dfs(grid,i-1,j,clr);
        dfs(grid,i,j+1,clr);
        dfs(grid,i,j-1,clr);
    }
    int shortestBridge(vector<vector<int>>& grid) {
       
       int d=0;
       int x,y;
       int r=grid.size(),c=grid[0].size();
       int color=2;
       for(int i=0;i<r;++i){
           for(int j=0;j<c;++j){
               if(grid[i][j]==1)
                dfs(grid,i,j,color++);
           }
       }
        color=2;
        queue< pair <pair <int,int> ,int> >q;
        vector<vector<int>>vis(r,vector<int>(c,0));
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(grid[i][j]==color)
                    q.push({{i,j},0});
            }
        }
      
        int dist=0;
        while(!q.empty()){
            x=q.front().first.first;
            y=q.front().first.second;
            dist=q.front().second;
            q.pop();
            if(x<0 || y<0 || x>=r || y>=c || vis[x][y])continue;
            vis[x][y]=1;
            if(grid[x][y]!=0 && grid[x][y]!=color)
                return dist-1;
            q.push({{x+1,y},dist+1});
            q.push({{x-1,y},dist+1});
            q.push({{x,y+1},dist+1});
            q.push({{x,y-1},dist+1});
        }
        return -1;
    }
};
