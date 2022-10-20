class Solution {
public:
    string intToRoman(int num) {
        string s=to_string(num);
        int cnt=s.length();
        string ans="";
        int j=0;
        while(cnt>0)
        {
            int digit=s[j]-'0';
           // cout<<digit<<" "<<cnt<<endl;
            if(cnt==4)
            {
                for(int i=digit;i>0;i--)
                {
                    ans+="M";
                }
            }
            else if(cnt==3)
            {
                if(digit==9)
                {
                    ans+="CM";
                }
                else if(digit>=5)
                {
                    ans+="D";
                    int di=digit-5;
                    for(int i=0;i<di;i++)
                    {
                        ans+="C";
                    }
                }
                else if(digit==4)
                {
                    ans+="CD";
                }
                else
                {
                    for(int i=0;i<digit;i++)
                    {
                        ans+="C";
                    }
                }
            }
            else if(cnt==2)
            {
                if(digit==9)
                {
                    ans+="XC";
                }
                else if(digit>=5)
                {
                    int di=digit-5;
                    ans+="L";
                    for(int i=0;i<di;i++)
                    {
                        ans+="X";
                    }
                }
                else if(digit==4)
                {
                    ans+="XL";
                }
                else
                {
                    for(int i=0;i<digit;i++)
                    {
                        ans+="X";
                    }
                }
            }
            else
            {
                if(digit==9)
                {
                    ans+="IX";
                }
                else if(digit>=5)
                {
                    ans+="V";
                    int di=digit-5;
                    for(int i=0;i<di;i++)
                    {
                        ans+="I";
                    }
                }
                else if(digit==4)
                {
                    ans+="IV";
                }
                else
                {
                    for(int i=0;i<digit;i++)
                    {
                        ans+="I";
                    }
                }
            }
            j++;
            cnt--;
        }
        return ans;
        
    }
};
