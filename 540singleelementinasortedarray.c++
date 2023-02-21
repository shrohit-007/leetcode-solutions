class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(mid+1<nums.size() and nums[mid]==nums[mid+1])
            {
                if((e-mid-1)%2==1)
                {
                    s=mid+2;
                }
                else
                {
                    e=mid-1;
                }
            }
            else if(mid-1>=0 and nums[mid]==nums[mid-1])
            {
                if((e-mid)%2==1)
                {
                    s=mid+1;
                }
                else
                {
                    e=mid-2;
                }
            }
            else
            {
                return nums[mid];
            }
        }
        return nums[s];
    }
};
