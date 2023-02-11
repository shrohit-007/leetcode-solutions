class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<pair<int,int>>>dp1(n,vector<pair<int,int>>(n,{0,0})),dp2(n,vector<pair<int,int>>(n,{0,0}));
        vector<vector<int>>mines1(n,vector<int>(n,1));
        for(int i=0;i<mines.size();i++)
        {
            int x=mines[i][0],y=mines[i][1];
            mines1[x][y]=0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!i or !j or mines1[i][j]==0)
                {
                    dp1[i][j].first=mines1[i][j];
                    dp1[i][j].second=mines1[i][j];
                }
                else
                {
                    dp1[i][j].first=dp1[i][j-1].first+1;
                    dp1[i][j].second=dp1[i-1][j].second+1;
                }
            }
        }
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==n-1 or j==n-1 or mines1[i][j]==0)
                {
                    dp2[i][j].first=mines1[i][j];
                    dp2[i][j].second=mines1[i][j];
                }
                else
                {
                    dp2[i][j].first=dp2[i][j+1].first+1;
                    dp2[i][j].second=dp2[i+1][j].second+1;
                }
                ans=max(ans,min(min(dp2[i][j].first,dp2[i][j].second),min(dp1[i][j].first,dp1[i][j].second)));
            }
        }
        return ans;
    }
};
