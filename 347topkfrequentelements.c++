class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            auto it=m.find(nums[i]);
            if(it!=m.end())
            {
                it->second+=1;
            }
            else
            {
                m[nums[i]]=0;
            }
        }
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(auto &it:m)
        {
            pq.push({it.second,it.first});
        }
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
