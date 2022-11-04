class Solution {
public:
    int strStr(string haystack, string needle) {
        int ind=0;
        int len=haystack.length();
        int n=needle.length();
        if(n>len)
        {
            return -1;
        }
        for(int i=0;i<=len-n;i++)
        {
            if(haystack.substr(i,n)==needle)
            {
                return i;
            }
        }
        return -1;
    }
};
