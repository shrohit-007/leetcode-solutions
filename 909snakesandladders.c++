class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<pair<int,int>>v(n*n+1);
        vector<int>columns(n);
        iota(columns.begin(),columns.end(),0);
        int p=1;
        for(int r=n-1;r>=0;r--)
        {
            for(int c:columns)
            {
                v[p++]={r,c};
            }
            reverse(columns.begin(),columns.end());
        }
        vector<int>dis(n*n+1,-1);
        dis[1]=0;
        queue<int>q;
        q.push(1);
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            for(int nxt=cur+1;nxt<=min(n*n,cur+6);nxt++)
            {
                int dest=board[v[nxt].first][v[nxt].second]==-1?nxt:board[v[nxt].first][v[nxt].second];
                if(dis[dest]==-1)
                {
                    dis[dest]=dis[cur]+1;
                    q.push(dest);
                }
            }
        }
        return dis[n*n];
    }
};
