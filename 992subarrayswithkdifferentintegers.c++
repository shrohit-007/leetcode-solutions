class Solution {
public:
    int atmostkdistinct(vector<int>&v,int k)
    {
        int cnt=0;
        int i=0,j=0;
        int n=v.size();
        map<int,int>m;
        while(j<n)
        {
            while(m.size()>k and i<n)
            {
                m[v[i]]--;
                if(m[v[i]]==0)
                {
                    m.erase(m.find(v[i]));
                }
                i++;
            } 
            m[v[j]]++;
            cnt+=j-i;
            j++;
           // cout<<cnt<<endl;
        }
        while(m.size()>k and i<n)
            {
                m[v[i]]--;
                if(m[v[i]]==0)
                {
                    m.erase(m.find(v[i]));
                }
                i++;
            } 
        cnt+=j-i;
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& v, int k) {
        return atmostkdistinct(v,k)-atmostkdistinct(v,k-1);
    }
};
