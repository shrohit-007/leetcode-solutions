class Solution {
public:
    bool halvesAreAlike(string s) {
        int c1=0,c2=0;
        vector<char>v={'a','e','i','o','u','A','E','I','O','U'};
        int n=s.length();
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<v.size();j++)
            {
                if(v[j]==s[i])
                {
                    if(i<n/2)
                        c1++;
                    else
                        c2++;
                }
            }
        }
        return c1==c2;
    }
};
