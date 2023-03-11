class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int>letter(26,0);
        int len=0,ans=0;
        for(int i=0;i<s.length();i++)
        {
            int cur=s[i]-'a';
            if(i>0 and s[i-1]!=((cur+25)%26+'a'))len=0;
            len++;
            if(len>letter[cur])
            {
                ans+=len-letter[cur];
                letter[cur]=len;
            }
        }
        return ans;
    }
};
