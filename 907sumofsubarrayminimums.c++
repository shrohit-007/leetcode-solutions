class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int,int>>st;
        int mod=1e9+7;
        int ans=0;
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            if(st.empty())
            {
                st.push({arr[i],arr[i]});
                ans+=st.top().second;
                sum+=st.top().second;
                ans%=mod;
            }
            else
            {
                int csum=arr[i];
                sum+=arr[i];
                sum%=mod;
                while(!st.empty() and arr[i]<st.top().first)
                {
                    sum-=st.top().second;
                    sum+=(st.top().second/st.top().first)*arr[i];
                    sum%=mod;
                    csum+=(st.top().second/st.top().first)*arr[i];
                    csum%=mod;
                    st.pop();
                }
                ans+=sum;
                ans%=mod;
                st.push({arr[i],csum});
            }
        }
        return ans;
    }
};
