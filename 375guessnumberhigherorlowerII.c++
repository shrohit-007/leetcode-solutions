class Solution {
public:
    // question of merging two intervals
    int f(int s,int e,vector<vector<int>>&dp)
    {
        if(s>=e)return 0;
        if(dp[s][e]!=-1)
            return dp[s][e];
        int ans=INT_MAX;
        for(int i=s;i<=e;i++)
        {
            int temp=i+max(f(s,i-1,dp),f(i+1,e,dp));
            ans=min(ans,temp);
        }
        return dp[s][e]=ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n,dp);
    }
};
