class Solution {
public:
    vector<string>ans;
    void  f(string &s,int i,string ans1)
    {
        if(i==s.length())
        {
            ans.push_back(ans1);
            return;
        }
        if(s[i]>='0' and s[i]<='9')
        {
            f(s,i+1,ans1+s[i]);
        }
        else
        {
            f(s,i+1,ans1+s[i]);
            if(s[i]>=97)
                f(s,i+1,ans1+char(s[i]-32));
            else
                f(s,i+1,ans1+char(s[i]+32));
        }
        
    }
    vector<string> letterCasePermutation(string s) {
        f(s,0,"");
        return ans;
    }
};
