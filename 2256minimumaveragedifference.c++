class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long ans=INT_MAX;
        int ind=-1;
        long s=0;
        long s1=0;
        for(int i=0;i<nums.size();i++)
            s1+=nums[i];
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            long x=(i<nums.size()-1)?((s1-s)/(nums.size()-i-1)):0;
            if(ans>abs((long)s/(i+1)-x))
            {
                ans=abs((long)s/(i+1)-x);
                ind=i;
            }
        }
        return ind;
    }
};
