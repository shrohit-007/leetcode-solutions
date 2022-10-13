class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int ans=0;
        int n=s.length();
        int j=0;
        for(int i=0;i<s.length();i++)
        {
            if(m[s[i]]==0)
                m[s[i]]++;
            else
            {   ans=max(ans,int(m.size()));
                while(m[s[i]]>=1 and j<n)
                {
                    m[s[j]]--;
                    if(m[s[j]]==0)
                    {
                        m.erase(s[j]);
                    }
                    j++;
                }
                m[s[i]]++;
            }
        }
        ans=max(ans,int(m.size()));
        return ans;
    }
};
