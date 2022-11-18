class Solution {
public:
    int nthUglyNumber(int n) {
        long long ans=1;
        set<long long>st;
        st.insert(1);
        for(int i=1;i<=n;i++)
        {
            ans=*st.begin();
            st.insert(2*ans);
            st.insert(3*ans);
            st.insert(5*ans);
            st.erase(st.begin());
        }
        return ans;
    }
};
