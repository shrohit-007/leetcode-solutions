class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            int val=v[i];
            if(val<0)
                val*=-1;
            if(v[val]<0)
            {
                return val;
            }
            v[val]*=-1;
        }
        return -1;
    }
};
