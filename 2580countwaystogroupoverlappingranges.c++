class Solution {
public:
    long long modpower(int y,int n,long long m1)
    {
        long long res=1;
        long long  x=y;
        while(n>0)
        {
            if(n%2==1)
            {
                res=(res%m1)*(x%m1);
                res%=m1;
            }
            n/=2;
            x*=(x%m1);
            x%=m1;
        }
        return res%m1;
    }
    int countWays(vector<vector<int>>& ranges) {
        stack<pair<int,int>>st;
        int n=ranges.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({ranges[i][0],ranges[i][1]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {   
                st.push({v[i].first,v[i].second});
            }
            else
            {
                pair<int,int>tmp=st.top();
                if(tmp.second<v[i].first)
                {
                    st.push({v[i].first,v[i].second});
                }
                else
                {
                    tmp.second=max(tmp.second,v[i].second);
                    st.pop();
                    st.push(tmp);
                }
            }
        }
        int x=st.size();
       // cout<<x<<endl;
        long long mod=1000000007;
        return modpower(2,x,mod);
    }
};
