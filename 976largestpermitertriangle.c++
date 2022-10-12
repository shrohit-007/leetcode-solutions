class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int>v;
        for(int i=0;i<=2;i++)
        {
            v.push_back(nums[i]);
        }
        int sum=0;
        sort(v.begin(),v.end());
        if(v[1]+v[0]>v[2])
        {
            sum=max(sum,v[0]+v[1]+v[2]);
            return sum;
        }
        for(int i=3;i<n;i++)
        {
            v[2]=nums[i];
            sort(v.begin(),v.end());
            if(v[1]+v[0]>v[2])
            {
                sum=max(sum,v[0]+v[1]+v[2]);
                return sum;
            }
        }
        return sum;
    }
};
