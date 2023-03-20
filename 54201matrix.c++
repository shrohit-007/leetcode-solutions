class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>>q;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int c=q.front().second;
            q.pop();
            ans[x][y]=c;
            if(x+1<n and mat[x+1][y]==1)
            {
                mat[x+1][y]=0;
                q.push({{x+1,y},c+1});
            }
            if(y+1<m and mat[x][y+1]==1)
            {
                mat[x][y+1]=0;
                q.push({{x,y+1},c+1});
            }
            if(x-1>=0 and mat[x-1][y]==1)
            {
                mat[x-1][y]=0;
                q.push({{x-1,y},c+1});
            }
            if(y-1>=0 and mat[x][y-1]==1)
            {
                mat[x][y-1]=0;
                q.push({{x,y-1},c+1});
            }
        }
        return ans;
    }
};
