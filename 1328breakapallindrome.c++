class Solution {
public:
    string breakPalindrome(string s) {
        vector<string>v;
        if(s.length()==1)
        {
            return "";
        }
        for(int i=0;i<s.length();i++)
        {
            string st=s;
            for(int j='a';j<='z';j++)
            {
                if(st[i]!=j)
                {
                    st[i]=j;
                    v.push_back(st);
                    break;
                }
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            string tmp=v[i];
            for(int j=0;j<tmp.size()/2;j++)
            {
                if(tmp[j]!=tmp[tmp.size()-1-j])
                {
                    return tmp;
                }
            }
        }
        return "";
        
    }
};
