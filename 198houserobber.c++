class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        int prev2=nums[0];
        int prev=nums[0];
        int curr;
        for(int i=1;i<nums.size();i++)
        {
            int p=nums[i]+(i>1?prev2:0);
            int np=prev;
            curr=max(p,np);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
