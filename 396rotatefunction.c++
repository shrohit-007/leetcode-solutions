class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0;
        int arrsum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i]*i;
            arrsum+=nums[i];
        }
        int ans=sum;
        for(int j=nums.size()-1;j>=0;j--)
        {
            sum-=nums[j]*nums.size();
            sum+=arrsum;
            ans=max(ans,sum);
        }
        return ans;
    }
};
