class Solution {
public:
    // recursive
    /*
    bool f(int ind,int target,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(target==0)return true;
        if(ind==0)return (nums[0]==target);
        if(dp[ind][target]!=-1)return dp[ind][target];
        int np=dp[ind-1][target];
        int p=false;
        if(nums[ind]<=target)
            p=nums[ind-1][target-nums[ind]];
        return dp[ind][target]=p|np;
    }
    */
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum&1)
            return false;
        sum/=2;
        int n=nums.size();
        // tabulation
        /*vector<vector<int>>dp(nums.size(),vector<int>(sum+1,0));
        dp[0][nums[0]]=true;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j==0)
                {
                    dp[i][j]=true;
                }
                else
                {
                    int np=dp[i-1][j];
                    int p=false;
                    if(nums[i]<=j)
                        p=dp[i-1][j-nums[i]];
                    dp[i][j]=np|p;
                }  
            }
        }
        return dp[n-1][sum];*/
        
        // with space optimization
        if(nums.size()==1)
            return false;
        vector<int>prev(sum+1,0);
        vector<int>curr(sum+1,0);
        prev[0]=curr[0]=1;
        if(nums[0]<=sum)
        prev[nums[0]]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                int np=prev[j];
                int p=false;
                if(nums[i]<=j)
                    p=prev[j-nums[i]];
                curr[j]=p|np;
            }prev=curr;
        }return prev[sum];
    }
};
