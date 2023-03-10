class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>divisors(nums.size());
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            int ind=-1,sz=0;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%divisors[j].back()==0 and sz<divisors[j].size())
                {
                    sz=divisors[j].size();
                    ind=j;
                }
            }
            if(ind!=-1)
            {
                for(int j=0;j<divisors[ind].size();j++)
                {
                    divisors[i].push_back(divisors[ind][j]);
                }
            }
            divisors[i].push_back(nums[i]);
            
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(divisors[i].size()>ans.size())
            {
                ans=divisors[i];
            }
        }
        return ans;
    }
};
