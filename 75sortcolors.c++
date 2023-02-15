class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int zero=0,two=0,one=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                zero++;
            else if(nums[i]==2)
                two++;
            else
                one++;
        }
        int st=0,end=nums.size()-1,mid=zero;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]==2 and two>0)
            {
                swap(nums[j],nums[end]);
                two--;
                end--;
                j--;
            }
            else if(nums[j]==0 and zero>0)
            {
                swap(nums[j],nums[st]);
                zero--;
                st++;
            }
            else if(one>0)
            {
                swap(nums[j],nums[mid]);
                mid++;
                j--;
                one--;
            }
        }
    }
};
