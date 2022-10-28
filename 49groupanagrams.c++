class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        for(int i=0;i<strs.size();i++)
        {
            string st=strs[i];
            sort(st.begin(),st.end());
            if(m.find(st)==m.end())
            {
                m[st].push_back(strs[i]);
            }
            else
            {
                m[st].push_back(strs[i]);
            }
        }
        vector<vector<string>>ans;
        for(auto &it:m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
