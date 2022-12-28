class Solution {
public:
    int f(vector<int>&v,int i,int j,int turn,vector<vector<vector<int>>>&dp)
    {
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j][turn]!=-1)
            return dp[i][j][turn];
        int sum1=0;
        if(turn==0)
        {
            sum1+=max(v[i]+f(v,i+1,j,1-turn,dp),v[j]+f(v,i,j-1,1-turn,dp));
        }
        else
        {
            sum1+=min(f(v,i+1,j,1-turn,dp),f(v,i,j-1,1-turn,dp));
        }
        return dp[i][j][turn]=sum1;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        vector<vector<vector<int>>>dp(21,vector<vector<int>>(21,vector<int>(2,-1)));
        int ans=f(nums,0,nums.size()-1,0,dp);
        if(ans>=sum-ans)
            return true;
        return false;
    }
};
