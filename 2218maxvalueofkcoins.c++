class Solution {
public:
    int f(int ind,int k,vector<vector<int>>&piles,vector<vector<int>>&dp)
    {
        if(ind==piles.size() or k==0)
            return 0;
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        int x=0;
        for(int i=0;i<=min(k,(int)piles[ind].size());i++)
        {
            if(i==0)
                x=max(x,f(ind+1,k-i,piles,dp));
            else
            x=max(x,piles[ind][i-1]+f(ind+1,k-i,piles,dp));
        }
        //cout<<x<<endl;
        return dp[ind][k]=x;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        for(int i=0;i<piles.size();i++)
        {
            //reverse(piles[i].begin(),piles[i].end());
            for(int j=1;j<piles[i].size();j++)
            {
                piles[i][j]=piles[i][j]+piles[i][j-1];
            }
        }
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(k+2,-1));
        return f(0,k,piles,dp);
        
    }
};
