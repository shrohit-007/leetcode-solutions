class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
        int ans=0;
        vector<unordered_map<long long,int>>dp(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long long dif=(long long)nums[j]-(long long)nums[i];
                dp[i][dif]++;
                if(dp[j].find(dif)!=dp[j].end())
                {
                    dp[i][dif]+=dp[j][dif];
                    ans+=dp[j][dif];
                }
            }
        }
        return ans;
    }
};
