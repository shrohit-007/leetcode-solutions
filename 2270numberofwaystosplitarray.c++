class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long ans=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        long long s=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            s+=nums[i];
            if(s>=sum-s)
                ans++;
        }
        return ans;
    }
};
