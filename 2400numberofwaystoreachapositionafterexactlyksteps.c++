class Solution {
public:
    int mod=1e9+7;
    int allways(int s,int e,int k,vector<vector<int>>&dp)
    {
        if(k==0)
        {
            if(s==e)return 1;
            return 0;
        }
        if(dp[s+1000][k]!=-1)
            return dp[s+1000][k];
        int left=allways(s-1,e,k-1,dp)%mod;
        int right=allways(s+1,e,k-1,dp)%mod;
        return dp[s+1000][k]=(left+right)%mod;
        
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(3003,vector<int>(1002,-1));
        return allways(startPos,endPos,k,dp);
        
    }
};
