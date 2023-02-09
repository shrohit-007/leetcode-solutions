class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0,mn=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            mn=max(mn,prices[i]);
            ans=max(ans,mn-prices[i]);
        }
        return ans;
    }
};
