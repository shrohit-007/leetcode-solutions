class Solution {
public:
    bool generate(vector<vector<char>>&board,string word,int i,int j,int ind)
    {
        if(ind==word.length())
        {
            return true;
        }
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[ind])
        {
            return false;
        }
        board[i][j]='*';
        bool ans=false;
        ans|=generate(board,word,i,j+1,ind+1);
        ans|=generate(board,word,i,j-1,ind+1);
        ans|=generate(board,word,i-1,j,ind+1);
        ans|=generate(board,word,i+1,j,ind+1);
        if(ans)
            return true;
        board[i][j]=word[ind];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    bool x=generate(board,word,i,j,0);
                    if(x==true)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
