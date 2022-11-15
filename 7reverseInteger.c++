
class Solution {
public:
    int reverse(int x) {
      int mx=INT_MAX;
        int mn=INT_MIN;
        string mx1=to_string(mx);
        string mn1=to_string(mn);
       /// cout<<mn1<<" "<<mx1<<endl;
       // cout<<mn1.length()<<endl;
        if(x<0)
        {
            string num=to_string(x);
            //cout<<num<<" "<<num.length()<<endl;
            std::reverse(num.begin(),num.end());
            if(num.length()<mn1.length())
            {
                return -1*stoi(num);
            }
            for(int i=0;i<num.length()-1;i++)
            {
                if(num[i]-'0'>mn1[i+1]-'0')
                {
                    return 0;
                }
                else if(num[i]-'0'<mn1[i+1]-'0')
                    break;
            }
            string ans=num.substr(0,num.length()-1);
            return -1*(stoi(ans));
        }
        string num1=to_string(x);
        std::reverse(num1.begin(),num1.end());
        if(num1.length()<mx1.length())
            return stoi(num1);
        for(int i=0;i<num1.length();i++)
        {
            if(num1[i]-'0'>mx1[i]-'0')
                return 0;
            else if(num1[i]-'0'<mx1[i]-'0')
                break;
        }
        return stoi(num1);
        
    }
};
