class Solution {
public:
    // int allpath(vector<int>&nums,int target,vector<int>&dp)
    // {
    //     if(target==0)
    //     {
    //         return 1;
    //     }
    //     if(dp[target]!=-1)return dp[target];
    //     int ways=0;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(target-nums[i]>=0)
    //         {
    //         //cout<<"YES"<<endl;
    //            ways+=allpath(nums,target-nums[i],dp); 
    //         }
    //     }
    //     return dp[target]=ways;
    // }
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int>dp(target+1,0);
        //return allpath(nums,target,dp);
        dp[0]=1;
        for(int i=1;i<=target;i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i>=nums[j])
                {
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};
