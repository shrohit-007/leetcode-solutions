class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int>d;
        for(int i=0;i<nums.size();i++)
        {
            auto it=lower_bound(d.begin(),d.end(),nums[i]);
            if(it!=d.end())
            {
                *it=nums[i];
            }
            else
                d.push_back(nums[i]);
        }
        return d.size();
    }
};
