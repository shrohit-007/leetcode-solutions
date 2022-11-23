class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            vector<int>v(10,0);
            vector<int>v1(10,0);
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    v[board[i][j]-'0']++;
                    if(v[board[i][j]-'0']>=2)
                        return false;
                }   
                if(board[j][i]!='.')
                {
                    v1[board[j][i]-'0']++;
                    if(v1[board[j][i]-'0']>=2)return false;
                }
            }
        }
        for(int i=0;i<7;i+=3)
        {
            for(int j=0;j<7;j+=3)
            {
                int x=i,y=j;
                vector<int>v(10,0);
                for(int k=x;k<=x+2;k++)
                {
                    for(int l=y;l<=y+2;l++)
                    {
                        if(board[k][l]!='.')
                        {
                            v[board[k][l]-'0']++;
                            if(v[board[k][l]-'0']>=2)return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
