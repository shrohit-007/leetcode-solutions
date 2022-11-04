class Solution {
public:
    string reverseVowels(string s) {
        vector<char>v;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U')
            {
                v.push_back(s[i]);
            }
        }
        int j=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U')
            {
                s[i]=v[j];
                j++;
            }
        }
        return s;
    }
};
