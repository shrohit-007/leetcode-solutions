class Solution {
public:
    // recursion
    // int f(vector<int>&prices,int ind,int flag,vector<vector<int>>&dp)
    // {
    //     if(ind>=prices.size())
    //     {
    //         return 0;
    //     }
    //     if(dp[ind][flag]!=-1)
    //         return dp[ind][flag];
    //     int buy=0,notbuy=0,sell=0,notsell=0;
    //     if(flag)
    //     {
    //         buy=-prices[ind]+f(prices,ind+1,0,dp);
    //         notbuy=f(prices,ind+1,flag,dp);
    //     }
    //     else
    //     {
    //         sell=prices[ind]+f(prices,ind+2,1,dp);
    //         notsell=f(prices,ind+1,flag,dp);
    //     }
    //     return dp[ind][flag]=max(max(buy,notbuy),max(sell,notsell));
    // }
    int maxProfit(vector<int>& prices) {
        //vector<vector<int>>dp(prices.size()+5,vector<int>(2,0));
        //return f(prices,0,1,dp);
        
        //tabulation
        // for(int i=prices.size()-1;i>=0;i--)
        // {
        //     for(int j=0;j<=1;j++)
        //     {
        //         if(j)
        //         {
        //             dp[i][j]=max(-prices[i]+dp[i+1][j^1],dp[i+1][j]);
        //         }
        //         else
        //         {
        //             dp[i][j]=max(prices[i]+dp[i+2][j^1],dp[i+1][j]);
        //         }
        //     }
        // }
        // return dp[0][1];
        // space optimized
        vector<int>curr(2,0),next(2,0),next2(2,0);
        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                if(j)
                {
                    curr[j]=max(-prices[i]+next[j^1],next[j]);
                }
                else
                {
                    curr[j]=max(prices[i]+next2[j^1],next[j]);
                }
            }
            next2=next;
            next=curr;
        }
        return curr[1];
        
    }
    
    
};
