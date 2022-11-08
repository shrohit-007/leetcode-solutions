class Solution {
public:
    string makeGood(string s) {
        string st="";
        while(1)
        {
            for(int i=0;i<s.size();i++)
            {
                if(i+1<s.size())
                {
                    if(abs(s[i]-s[i+1])==32)
                    {
                        s.erase(i,2);
                        break;
                    }
                }
            }
            if(st!=s)
            {
                st=s;
                continue;
            }
            else
            {
                break;
            }
        }
        return s;
    }
};
