class Solution {
public:
    int lis(vector<int>&arr)
    {
        vector<int>d;
        for(int i=0;i<arr.size();i++)
        {
            auto it=lower_bound(d.begin(),d.end(),arr[i]);
            if(it==d.end())
            {
                d.push_back(arr[i]);
            }
            else
            {
                *it=arr[i];
            }
        }return d.size();
    }
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i=0;i<target.size();i++)
        {
            m[target[i]]=i;
        }
        vector<int>narr;
        for(int i=0;i<arr.size();i++)
        {
            if(m.find(arr[i])!=m.end())
            {
                narr.push_back(m[arr[i]]);
            }
        }
        int liis=lis(narr);
        return target.size()-liis;
    }
};
