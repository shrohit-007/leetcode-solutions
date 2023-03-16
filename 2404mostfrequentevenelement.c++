class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>m;
        int ans=-1,x=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                m[nums[i]]++;
                if(m[nums[i]]>x)
                {
                    x=m[nums[i]];
                    ans=nums[i];
                }
                else if(m[nums[i]]==x and nums[i]<ans)
                {
                    ans=nums[i];
                }
            }
        }
        return ans;
    }
};
