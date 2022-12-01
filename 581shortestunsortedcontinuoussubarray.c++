class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        /*vector<int>nums1=nums;
        sort(nums1.begin(),nums1.end());
        int n=nums.size();
        int p1=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=nums1[i])
            {
                p1=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums1[i]!=nums[i])
            {
                return i-p1+1;
            }
        }return 0;*/
        
        // O(1) solution
        int n=nums.size();
        int mn=INT_MAX,mx=INT_MIN;
        int st=-1,en=-2;
        for(int i=0;i<n;i++)
        {
            mn=min(mn,nums[n-1-i]);
            mx=max(mx,nums[i]);
            if(nums[n-i-1]>mn)st=n-i-1;
            if(nums[i]<mx) en=i;
        }
        return en-st+1;
    }
};
