class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prevmx=nums[0],prevmn=nums[0],mx,mn;
        int maxi=INT_MIN,mini=INT_MAX;
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            maxi=max(prevmx*nums[i],max(nums[i]*prevmn,nums[i]));
            mini=min(prevmn*nums[i],min(nums[i]*prevmx,nums[i]));
            prevmx=maxi;
            prevmn=mini;
            ans=max(ans,prevmx);
        }
        return ans;
    }
};
