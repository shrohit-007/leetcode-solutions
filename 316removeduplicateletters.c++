class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        stack<char>st;
        vector<int>freq(26,0);
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
        }
        vector<int>vis(26,0);
        for(int i=0;i<n;i++)
        {
            if(vis[s[i]-'a'])
            {
                freq[s[i]-'a']--;
                continue;
            }
                while(!st.empty() and s[i]<st.top() and freq[st.top()-'a']>0)
                {
                    vis[st.top()-'a']=0;
                    st.pop();
                }    
                st.push(s[i]);
                freq[s[i]-'a']--;
                vis[s[i]-'a']=1;
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
