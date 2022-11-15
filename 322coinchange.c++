class Solution {
public:
    // recursion
    /*int f(int sum,vector<int>&coins,vector<int>&dp)
    {
        if(sum==0)
        {
            return 0;
        }
        if(dp[sum]!=-1)return dp[sum];
        int x=1e7;
        for(int ele:coins)
        {
            if(sum>=ele)
            {
                x=min(x,1+f(sum-ele,coins,dp));
            }
        }
        return dp[sum]= x;
    }*/
    int coinChange(vector<int>& coins, int amount) {
        // recursion+memozization
        /*vector<int>dp(amount+1,-1);
        int x=f(amount,coins,dp);
        if(x<1e7)
            return x;
        return -1;*/
        vector<int>dp(amount+2,0);
        for(int i=1;i<=amount;i++)
        {
            int x=1e7;
            for(int ele:coins)
            {
                if(ele<=i)
                {
                    x=min(x,1+dp[i-ele]);
                }
            }
            dp[i]=x;
        }
        return dp[amount]<1e7?dp[amount]:-1;
        
    }
};
