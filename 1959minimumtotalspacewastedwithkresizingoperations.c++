class Solution {
public:
    int x=100000000;
    int dp[203][203];
    int f(vector<int>&nums,int i,int k)
    {
        if(i==nums.size())return 0;
        if(k<0)return x;
        if(dp[i][k]!=-1)return dp[i][k];
        long long mx=0;
        long long sum=0, ans=x;
        for(int j=i;j<nums.size();j++)
        {
            mx=max(mx,1ll*nums[j]);
            sum+=nums[j];
            ans=min(ans,mx*(j-i+1)-sum+f(nums,j+1,k-1));
        }
        return dp[i][k]=ans;
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return f(nums,0,k);
    }
};
