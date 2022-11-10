class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int c=0;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty())
            {
                st.push({s[i],1});
            }
            else
            {
                int cnt=st.top().second;
                if(st.top().first==s[i] and cnt==k-1)
                {
                    int c=k-1;
                    while(c>0)
                    {
                        st.pop();
                        c--;
                    }
                    continue;
                }
                if(s[i]==st.top().first)
                {
                    st.push({s[i],cnt+1});
                }
                else
                {
                    st.push({s[i],1});
                }
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
