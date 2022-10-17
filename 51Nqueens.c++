class Solution {
public:
    bool checkplacement(int i,int j,vector<string>&board)
    {
        int n=board.size();
        bool ok=true;
                int col=0,row=0;
                while(col<n)
                {
                    if(col!=j and board[i][col]=='Q')
                    {
                        ok=false;
                        break;
                    }col++;
                }
                while(row<n)
                {
                    if(row!=i and board[row][j]=='Q')
                    {
                        ok=false;
                        break;
                    }row++;
                }
                row=i+1,col=j+1;
                while(row<n and col<n)
                {
                    if(board[row][col]=='Q')
                    {
                        ok=false;
                        break;
                    }row++,col++;
                }
                row=i-1,col=j-1;
                while(row>=0 and col>=0)
                {
                    if(board[row][col]=='Q')
                    {
                        ok=false;
                        break;
                    }row--,col--;
                }
                row=i+1,col=j-1;
                while(row<n and col>=0)
                {
                    if(board[row][col]=='Q')
                    {
                        ok=false;
                        break;
                    }row++,col--;
                }
                row=i-1,col=j+1;
                while(row>=0 and col<n)
                {
                    if(board[row][col]=='Q')
                    {
                        ok=false;
                        break;
                    }row--,col++;
                }
        return ok;
    }
    void generate(vector<string>&board,int n,int j,vector<vector<string>>&ans)
    {
        if(j==n)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(checkplacement(i,j,board))
            {
            board[i][j]='Q';
            generate(board,n,j+1,ans);
            board[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board;
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            string s(n,'.');
            board.push_back(s);
        }
        generate(board,n,0,ans);
        return ans;
    }
};
