class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0 or nums[i]!=nums[i-1])
            {
                nums[c++]=nums[i];
            }
        }
        return c;
    }
};
