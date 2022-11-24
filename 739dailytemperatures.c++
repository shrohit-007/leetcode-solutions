class Solution {
public:
    vector<int> dailyTemperatures(vector<int>&v) {
        stack<pair<int,int>>st;
        int n=v.size();
        int  c=0;
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
            int c=0;
            if(st.empty())
            {
                st.push({v[i],0});
            }
            else
            {
                while(!st.empty() and st.top().first<=v[i])
                {
                    c+=st.top().second+1;
                    st.pop();
                }
                if(!st.empty())
                {
                    ans[i]=c+1;
                }
                else
                {
                    ans[i]=0;
                }
                st.push({v[i],c});
            }
        }
        return ans;
    }
};
