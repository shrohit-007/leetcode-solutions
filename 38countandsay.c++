class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        while(n>1)
        {
            int len=s.length();
            int cnt=1;
            int i=0;
            string temp="";
            while(i<len)
            {
                if(i+1<len)
                {
                    if(s[i]==s[i+1])
                    {
                        cnt++;
                    }
                    else
                    {
                        temp+=char(cnt+'0');
                        temp+=s[i];
                        cnt=1;
                    }
                }
                else
                {
                    temp+=char(cnt+'0');
                    temp+=s[i];
                    cnt=0;
                }
                i++;
            }
            if(cnt>0)
            {
                temp+=char(cnt+'0');
                temp+=s[len-1];
            }
            s=temp;
            n--;
        }
        return s;
    }
};
