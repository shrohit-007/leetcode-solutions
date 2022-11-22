class Solution {
public:
    /*int f(int sum,vector<int>&v,vector<int>&dp)
    {
        if(sum==0)
        {
            return 0;
        }
        if(dp[sum]!=-1)
            return dp[sum];
        int x=1e8;
        for(int coin:v)
        {
            if(sum-coin>=0)
            x=min(x,1+f(sum-coin,v,dp));
        }
        return dp[sum]=x;
        
    }*/
    int numSquares(int sum) {
        vector<int>v;
        for(int i=1;i*i<=sum;i++)
        {
            v.push_back(i*i);
        }
        vector<int>dp(sum+1,1e8);
        dp[0]=0;
        //return f(sum,v,dp);
        for(int i=1;i<=sum;i++)
        {
            for(int coin:v)
            {
                if(i-coin>=0)
                {
                    dp[i]=min(dp[i],1+dp[i-coin]);
                }
            }
        }return dp[sum];
    }
};
