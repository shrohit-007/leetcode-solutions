class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
       // vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
       // return mxprofit(prices,0,1,0,dp);
        int ans=0;
        int mx=INT_MIN;
        for(int i=prices.size()-1;i>=0;i--)
        {
            if(mx>prices[i])
            {
                ans+=mx-prices[i];
                mx=prices[i];
            }
            else
            mx=max(mx,prices[i]);
        }
        return ans;
    }
};
