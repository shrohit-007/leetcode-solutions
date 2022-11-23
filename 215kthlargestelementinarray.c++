class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int>v(20002,0);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                v[10000+nums[i]]++;
            }
            else
                v[10001+nums[i]]++;
        }
        vector<int>sorted;
        for(int i=0;i<v.size();i++)
        {
            if(i<=10000)
            {
                for(int j=0;j<v[i];j++)
                {
                    sorted.push_back(i-1e4);
                }
            }
            else
            {
                for(int j=0;j<v[i];j++)
                {
                    sorted.push_back(i-10001);
                }
            }
        }
        return sorted[(sorted.size()-k)];
    }
};
