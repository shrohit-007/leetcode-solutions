class Solution {
public:
    int lis(vector<int>&v)
    {
        vector<int>d;
        for(int i=0;i<v.size();i++)
        {
            auto it=lower_bound(d.begin(),d.end(),v[i]);
            if(it==d.end())
            {
                d.push_back(v[i]);
            }
            else
            {
                *it=v[i];
            }
            if(d.size()>=3)
            {
                return 3;
            }
        }
        return d.size();
    }
    bool increasingTriplet(vector<int>& v) {
        if(v.size()<3)
        {
            return false;
        }
        int x=lis(v);
        if(x>=3)
        {
            return true;
        }
        return false;
        
    }
};
