class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int>d;
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<pairs.size();i++)
        {
            auto it=lower_bound(d.begin(),d.end(),pairs[i][0]);
            if(it!=d.end())
            {
                if(pairs[i][1]<*it)
                *it=pairs[i][1];
            }
            else
                d.push_back(pairs[i][1]);
        }
        return d.size();
    }
};
