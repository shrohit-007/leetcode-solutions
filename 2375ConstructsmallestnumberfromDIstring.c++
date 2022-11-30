class Solution {
public:
    string smallestNumber(string pattern) {
        string ans="";
        int j=1;
        int c=0;
        for(int i=0;i<pattern.size();i++)
        {
            if(pattern[i]=='I')
            {
                c++;
                int k=j;
                while(c>0)
                {
                    ans+=char(k+'0');
                    k--;
                    c--;
                }
                c=0;
            }
            else
            {
                c++;
            }
            j++;
        }
        c++;
        while(c>0)
        {
            ans+=char(j+'0');
            j--;
            c--;
        }
        return ans;
    }
};
