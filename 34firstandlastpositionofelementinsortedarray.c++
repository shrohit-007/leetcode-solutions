class Solution {
public:
    int binarysearch(int s,int e,int target,vector<int>&nums)
    {
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]>=target)
            {
                ans=mid-1;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
    int binarysearch1(int s,int e,int target,vector<int>&nums)
    {
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]>target)
            {
                e=mid-1;
            }
            else
            {
                ans=mid+1;
                s=mid+1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int x=binarysearch(0,nums.size()-1,target,nums);
        int y=binarysearch1(0,nums.size()-1,target,nums);
        vector<int>v;
        v.push_back(x+1);
        v.push_back(y-1);
        if(nums.empty() or nums[x+1]!=target or nums[y-1]!=target)
        {
            v.clear();
            v={-1,-1};
        }
        return v;
    }
};
