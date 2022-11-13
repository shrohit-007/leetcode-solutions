class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size()/2;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        vector<vector<int>>lefthalf(n+2);
        vector<vector<int>>righthalf(n+2);
        for(int i=0;i<(1<<n);i++)
        {
            int sz=0;
            int lsum=0,rsum=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    sz++;
                    lsum+=nums[j];
                    rsum+=nums[j+n];
                }
            }
            lefthalf[sz].push_back(lsum);
            righthalf[sz].push_back(rsum);
        }
        for(int i=0;i<=n;i++)
        {
            sort(righthalf[i].begin(),righthalf[i].end());
        }
        int ans=min(abs(sum-2*lefthalf[n][0]),abs(sum-2*righthalf[n][0]));
        for(int i=1;i<n;i++)
        {
            for(auto &subsetsum:lefthalf[i])
            {
                int sz=n-i;
                int need=(sum-2*subsetsum)/2;
                auto &v=righthalf[sz];
                auto it =lower_bound(v.begin(),v.end(),need);
                if(it!=v.end())
                {
                    ans=min(ans,abs(sum-2*(subsetsum+*(it))));
                }
                if(it!=v.begin())
                {
                    auto it1=it;
                    --it1;
                    ans=min(ans,abs(sum-2*(subsetsum+*(it1))));
                }
            }
        }
        return ans;
        
    }
};
