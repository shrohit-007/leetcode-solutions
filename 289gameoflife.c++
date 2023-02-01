class Solution {
public:
    int live(vector<vector<int>>&board,int i,int j)
    {
        int ans=0;
        int n=board.size(),m=board[0].size();
        if(i+1<n and (board[i+1][j]==1 or board[i+1][j]==3))
            ans++;
        if(j+1<m and (board[i][j+1]==1 or board[i][j+1]==3))
            ans++;
        if(i-1>=0 and (board[i-1][j]==1 or board[i-1][j]==3))
            ans++;
        if(j-1>=0 and (board[i][j-1]==1 or board[i][j-1]==3))
            ans++;
        if(i-1>=0 and j-1>=0 and (board[i-1][j-1]==1 or board[i-1][j-1]==3))
            ans++;
        if(i+1<n and j+1<m and (board[i+1][j+1]==1 or board[i+1][j+1]==3))
            ans++;
        if(i-1>=0 and j+1<m and (board[i-1][j+1]==1 or board[i-1][j+1]==3))
            ans++;
        if(i+1<n and j-1>=0 and (board[i+1][j-1]==1 or board[i+1][j-1]==3))
            ans++;
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int val=board[i][j];
                int val1;
                if(val==2)
                {
                    val1=0;
                }
                else if(val==3)
                {
                    val1=1;
                }
                else
                    val1=val;
                int ans=live(board,i,j);
                //cout<<ans<<endl;
                if(val1==1)
                {
                    if(ans<2 or ans>3)
                        board[i][j]=3;
                }
                else
                {
                    if(ans==3)
                        board[i][j]=2;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==2)
                    board[i][j]=1;
                else if(board[i][j]==3)
                    board[i][j]=0;
            }
        }
    }
};
