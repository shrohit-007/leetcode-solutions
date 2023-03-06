class Solution {
public:
    int mod=1000000007;
    int f(vector<vector<int>>&types,int target,int i,int cnt,vector<vector<vector<int>>>&dp)
    {
        if(target==0)
        {
            return 1;
        }
        if(i==types.size())return 0;
        if(dp[i][cnt][target]!=-1)return dp[i][cnt][target];
        long long ans=0;
            if(types[i][0]>cnt and target>=types[i][1])
            {
                ans+=f(types,target-types[i][1],i,cnt+1,dp)%mod;
                ans%=mod;
            }
            ans+=f(types,target,i+1,0,dp)%mod;
        ans%=mod;
        return dp[i][cnt][target]=ans%mod;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<vector<vector<int>>>dp(55,vector<vector<int>>(55,vector<int>(1003,-1)));
        return f(types,target,0,0,dp);
    }
};
