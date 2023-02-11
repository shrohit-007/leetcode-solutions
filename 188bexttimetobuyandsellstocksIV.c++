class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>>next(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                for(int canhave=1;canhave<=k;canhave++)
                {
                    if(j)
                    {
                        curr[j][canhave]=max(-prices[i]+next[1^j][canhave],next[j][canhave]);
                    }
                    else
                    {
                        curr[j][canhave]=max(prices[i]+next[1^j][canhave-1],next[j][canhave]);
                    }
                }next=curr;
            }
        }return next[1][k];
    }
};
