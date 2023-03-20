class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>>q;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               // cout<<board[i][j]<<" "<<i<<" "<<j<<endl;
                if(board[i][j]=='O' and (i==0 or j==0  or i==n-1 or j==m-1))
                {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            board[x][y]='K';
            q.pop();
            if(x+1<n and board[x+1][y]=='O')
            {
                q.push({x+1,y});
            }
            if(x-1>=0 and board[x-1][y]=='O')
            {
                q.push({x-1,y});
            }
            if(y+1<m and board[x][y+1]=='O')
            {
                q.push({x,y+1});
            }
            if(y-1>=0 and board[x][y-1]=='O')
            {
                q.push({x,y-1});
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]!='K')
                    board[i][j]='X';
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='K')
                    board[i][j]='O';
            }
        }
        return ;
    }
};
