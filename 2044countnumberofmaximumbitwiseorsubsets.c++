class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ans=0;
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            x|=nums[i];
        }
        for(int i=0;i<(1<<nums.size());i++)
        {
            int temp=0;
            for(int j=0;j<nums.size();j++)
            {
                if(i&(1<<j))temp|=nums[j];
            }
            if(temp==x)ans++;
        }
        return ans;
    }
};
