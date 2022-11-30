class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        unordered_map<int,int>m1;
        for(auto &it:m)
        {
            if(m1.find(it.second)!=m1.end())
            {
                return false;
            }
            else
            {
                m1.insert({it.second,1});
            }
        }
        return true;
    }
};
