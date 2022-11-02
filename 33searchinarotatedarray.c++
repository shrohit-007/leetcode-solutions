class Solution {
public:
    int binarysearch(int start,int end,int target,vector<int>&v)
    {
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(v[mid]==target)
            {
                return mid;
            }
            else if(v[mid]>target)
            {
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int k=n-1;
        int s=1,end=n-1;
        while(s<=end)
        {
            int mid=s+(end-s)/2;
            if(nums[mid]>nums[0])
            {
                s=mid+1;
            }
            else
            {
                k=mid;
                end=mid-1;
            }
        }
        int x=binarysearch(0,k-1,target,nums);
        if(x!=-1)
            return x;
        int y=binarysearch(k,n-1,target,nums);
        return y;
    }
};
