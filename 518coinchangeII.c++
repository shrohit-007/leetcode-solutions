class Solution {
public:
    /*int f(int sum,int ind,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(sum==0)
            return 1;
        if(ind==coins.size())
            return 0;
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        int ntake=f(sum,ind+1,coins,dp);
        int take=0;
        if(coins[ind]<=sum)
            take=f(sum-coins[ind],ind,coins,dp);
        return dp[ind][sum]=take+ntake;
    }*/
    int change(int amount, vector<int>& coins) {
        // recursion+memozization;
       // vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        //return f(amount,0,coins,dp);
        
        //tabulation
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,0));
        int n=coins.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=amount;j++)
            {
                if(j==0)
                    dp[i][j]=1;
                else
                {
                    dp[i][j]=dp[i+1][j]+(coins[i]<=j?dp[i][j-coins[i]]:0);
                }
               // cout<<dp[i][j]<<" ";
            }//cout<<endl;
        }
        return dp[0][amount];
    }
};
