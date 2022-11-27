class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        if(n<3)return 0;
        int i=0;
        while(i<n-2)
        {
             int dif=nums[i]-nums[i+1];
             int c=0;
             for(int j=i+1;j<n-1;j++)
             {
                 if(nums[j]-nums[j+1]==dif)
                 {
                     c++;
                 }
                 else
                 {
                     ans+=c*(c+1)/2;
                     i=j;
                     c=0;
                     break;
                 }
             }
            if(c!=0)
            {
                ans+=c*(c+1)/2;
                break;
            }
        }return ans;
    }
};
