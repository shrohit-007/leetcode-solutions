class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>m,m1;
        for(int i=0;i<matches.size();i++)
        {
            int win=matches[i][0];
            int lose=matches[i][1];
            m[win]++;
            m1[lose]++;
        }
        vector<vector<int>>ans;
        vector<int>temp;
        for(auto &it:m)
        {
            int x=it.first;
            if(m1.find(x)==m1.end())
            {
                temp.push_back(x);
            }
        }sort(temp.begin(),temp.end());
        ans.push_back(temp);
        temp.clear();
        for(auto &it:m1)
        {
            if(it.second==1)
            {
                temp.push_back(it.first);
            }
        }sort(temp.begin(),temp.end());
        ans.push_back(temp);
        return ans;
    }
};
