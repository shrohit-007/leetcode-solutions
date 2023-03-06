class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]%space]++;
        }
        unordered_set<int>st;
        int cnt=INT_MIN;
        for(auto &it:m)
        {
            if(cnt<it.second)
            {
                cnt=it.second;
            }
        }
        for(auto &it:m)
        {
            if(cnt==it.second)st.insert(it.first);
        }
        int ans2=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i]%space)!=st.end())
            {
                ans2=min(ans2,nums[i]);
            }
        }
        return ans2;
        
    }
};
