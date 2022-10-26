class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<long long,int>m;
        long long s=0;
        m[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            int a=nums[i];
            s=(s+a%k +k)%k;
            if(m.find(s)!=m.end())
            {
                if(i-m[s]>1)
                    return true;
            }
            else
            m[s]=i;
        }
        return false;
    }
};
