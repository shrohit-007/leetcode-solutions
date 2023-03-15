class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans=0;
        long long num=1;
        nums.push_back(INT_MAX);
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]>num and num<=n)
            {
                num+=num;
                ans++;
            }
            num+=nums[i];
        }
        return ans;
    }
};
