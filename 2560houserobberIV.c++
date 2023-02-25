class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l=0,r=1e9;
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int c=0,i=0;
            while(i<nums.size())
            {
                if(nums[i]<=mid)
                {
                    c++;
                    i+=2;
                }
                else
                    i++;
            }
            if(c>=k)
            {
                r=mid-1;
                ans=mid;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};
