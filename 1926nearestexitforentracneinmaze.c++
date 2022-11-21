class Solution {
public:
    int bfs(vector<vector<char>>&v,int i,int j,vector<vector<int>>&visited,int n,int m)
    {
        int ans=INT_MAX;
        queue<pair<pair<int,int>,int>>q;
        q.push({{i,j},0});
        while(!q.empty())
        {
            pair<pair<int,int>,int>top=q.front();
            int c=top.second;
            q.pop();
            int x=top.first.first,y=top.first.second;
            //cout<<x<<" "<<y<<" "<<c<<endl;
            if(c!=0 and (x==0 or y==0 or x==n-1 or y==m-1))
            {
                ans=min(ans,c);
                continue;
            }
            if(x+1>=0 and x+1<n and y>=0 and y<m and v[x+1][y]!='+')
            {
               // cout<<"Yes"<<endl;
                if(!visited[x+1][y])
                {
                    q.push({{x+1,y},c+1});
                    visited[x+1][y]=1;
                }
            }
            if(x>=0 and x<n and y+1>=0 and y+1<m and v[x][y+1]!='+')
            {
                //cout<<"Yes1"<<endl;
                if(!visited[x][y+1])
                {
                    q.push({{x,y+1},c+1});
                    visited[x][y+1]=1;
                }
            }
            if(x-1>=0 and x-1<n and y>=0 and y<m and v[x-1][y]!='+')
            {
                //cout<<"Yes2"<<endl;
                if(!visited[x-1][y])
                {
                    q.push({{x-1,y},c+1});
                    visited[x-1][y]=1;
                }
            }
            if(x>=0 and x<n and y-1>=0 and y-1<m and v[x][y-1]!='+')
            {
               // cout<<"Yes3"<<endl;
                if(!visited[x][y-1])
                {
                    q.push({{x,y-1},c+1});
                    visited[x][y-1]=1;
                }
            }
        }
        return ans==INT_MAX?-1:ans;
        
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<int>>visited(101,vector<int>(101,0));
        visited[entrance[0]][entrance[1]]=1;
        int x=bfs(maze,entrance[0],entrance[1],visited,maze.size(),maze[0].size());
        return x;
    }
};
