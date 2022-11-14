class Solution {
public:

    int f(int ind,int target,vector<int>&nums,map<pair<int,int>,int>&m)
    {
        if(ind<0)
        {
            if(target==0)return 1;
            return 0;
        }
        if(m.find({ind,target})!=m.end())
            return m[{ind,target}];
        int p=f(ind-1,target-nums[ind],nums,m);
        int p2=f(ind-1,target+nums[ind],nums,m);
        return m[{ind,target}]=p+p2;
    }
    int dp[21][2001];
    int f2(int ind,int target,vector<int>&nums,int sum)
    {
        if(ind==nums.size())
        {
            return (target==sum)?1:0;
        }
        if(sum<0)
        {
            if(dp[ind][sum+2001]!=-1)
                return dp[ind][sum+2001];
        }
        else if(sum>=0)
        {
            if(dp[ind][sum]!=-1)
                return dp[ind][sum];
        }
        int add=f2(ind+1,target,nums,sum+nums[ind]);
        int subtract=f2(ind+1,target,nums,sum-nums[ind]);
        return (sum<0)?dp[ind][sum+2001]=add+subtract:dp[ind][sum]=add+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //map<pair<int,int>,int>m;
        //return f(nums.size()-1,target,nums,m);
        
        
        // without map
        //vector<vector<int>dp(21,vector<int>(2005,-1));
        memset(dp,-1,sizeof(dp));
        return f2(0,target,nums,0);
    }
};
