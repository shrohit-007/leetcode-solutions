class Solution {
public:
    // recursion
    int f(vector<int>&freq,int ind,vector<int>&dp)
    {
        if(ind>=freq.size())
        {
            return 0;
        }
        if(dp[ind]!=-1)
            return dp[ind];
        int ansforind=0;
        if(freq[ind]==0)
        {
            ansforind=f(freq,ind+1,dp);
        }
        else
        {
            ansforind=max(freq[ind]*ind+f(freq,ind+2,dp),f(freq,ind+1,dp));
        }
        return dp[ind]=ansforind;
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int>freq(1e4+2,0);
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        vector<int>dp(1e4+3,0);
        for(int i=1e4;i>=1;i--)
        {
            if(freq[i]==0)
            {
                dp[i]=dp[i+1];
            }
            else
                dp[i]=max(freq[i]*i+dp[i+2],dp[i+1]);
        }return dp[1];
    }
};
