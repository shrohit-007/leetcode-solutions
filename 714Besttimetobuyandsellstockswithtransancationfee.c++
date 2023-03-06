class Solution {
public:
    int dp[50005][2];
    // int f(vector<int>&prices,int fee,int ind,int flag)
    // {
    //     if(ind==prices.size())return 0;
    //     if(dp[ind][flag]!=-1)return dp[ind][flag];
    //     int buy=0,nbuy=0,sell=0,nsell=0;
    //     if(flag)
    //     {
    //         buy=-prices[ind]+f(prices,fee,ind+1,0);
    //         nbuy=f(prices,fee,ind+1,flag);
    //     }
    //     else
    //     {
    //         sell=prices[ind]-fee+f(prices,fee,ind+1,1);
    //         nsell=f(prices,fee,ind+1,flag);
    //     }
    //     return dp[ind][flag]=max(max(buy,nbuy),max(sell,nsell));
    // }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,0,sizeof(dp));
        //return f(prices,fee,0,1);
        vector<int>curr(2,0),next(2,0);
        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                if(j)
                {
                    curr[j]=max(-prices[i]+next[0],next[1]);
                }
                else
                    curr[j]=max(prices[i]-fee+next[1],next[0]);
            }
            next=curr;
        }
        return curr[1];
    }
};
