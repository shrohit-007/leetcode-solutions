class Solution {
public:
    bool static comp(pair<int,string>a,pair<int,string>b)
    {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>m;
        vector<pair<int,string>>v;
        sort(words.begin(),words.end());
        for(int i=0;i<words.size();i++)
        {
            m[words[i]]++;
        }
        for(auto &it:m)
        {
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),comp);
        vector<string>ans;
        for(int i=0;i<v.size();i++)
        {
            if(k>0)
            {
                ans.push_back(v[i].second);
                k--;
            }
        }
        return ans;
        
    }
};
