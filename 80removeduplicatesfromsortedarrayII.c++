class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 1;
        int c=0,f=0;
        for(int i=0;i<n;i++)
        {
            if(i==0 or (nums[i]==nums[i-1] and !f) or nums[i]!=nums[i-1])
            {
                if(i!=0 and nums[i]==nums[i-1])
                    f=1;
                else
                    f=0;
                nums[c++]=nums[i];
            }
        }
        return c;
    }
};
