class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        unordered_map<int,unordered_map<int,int>>m;
        int ans=1;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                int d=nums[i]-nums[j];
                if(m[i].find(d)==m[i].end())
                {
                    if(m[j].find(d)!=m[j].end())
                    {
                        m[i].insert({d,m[j][d]+1});
                        ans=max(ans,m[i][d]);
                    }
                    else
                    {
                        m[i].insert({d,2});
                        ans=max(ans,2);
                    }
                }
            }
        }
        return ans;
    }
};
