class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int ans=0;
        vector<int>prefix(nums.size(),0),suffix(nums.size(),0);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            prefix[i]=i==0?nums[i]:max(prefix[i-1],nums[i]);
            suffix[n-i-1]=i==0?nums[n-1]:min(nums[n-i-1],suffix[n-i]);
        }
        for(int i=1;i<n-1;i++)
        {
            if(prefix[i-1]<nums[i] and suffix[i+1]>nums[i])
                ans+=2;
            else if(nums[i-1]<nums[i] and nums[i]<nums[i+1])
                ans++;
        }
        return ans;
    }
};
