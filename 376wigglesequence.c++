class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        
        // dynamic programming approach
        // if(n==1)
        // return n;
        // vector<pair<int,int>>dp(n,{0,0});
        // dp[0]={1,1};
        // for(int i=1;i<n;i++)
        // {
        //     for(int j=i-1;j>=0;j--)
        //     {
        //         if(nums[j]<nums[i])
        //         {
        //             dp[i].first=max(dp[i].first,dp[j].second+1);
        //         }
        //         if(nums[j]>nums[i])
        //         {
        //             dp[i].second=max(dp[i].second,dp[j].first+1);
        //         }
        //     }
        // }
        // return max(dp[n-1].first,max(dp[n-1].second,1));
        
        
        // greedy approach
        int ans=1;
        int flag=-1;
        for(int i=1;i<n;i++)
        {
            if(flag==-1 and nums[i]!=nums[i-1])
            {
                ans++;
                if(nums[i]>nums[i-1])
                    flag=1;
                else
                    flag=0;
            }
            else if(flag!=-1)
            {
                if(flag)
                {
                    if(nums[i]<nums[i-1])
                    {
                        ans++;
                        flag=0;
                    }
                }
                else
                {
                    if(nums[i]>nums[i-1])
                    {
                        ans++;
                        flag=1;
                    }
                }
            }
        }
        return ans;
        
        
    }
};
