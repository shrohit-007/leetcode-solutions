class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1,e=2e9;
        int n=nums.size();
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                cnt+=ceil(1.0*nums[i]/mid);
            }
            if(cnt<=threshold)
            {
                e=mid-1;
            }
            else
               s=mid+1;
        }
        return e+1;
    }
};
