class Solution {
public:
    bool canBeValid(string s, string locked) {
         int op,cl,flip;
        if(s.length()%2!=0)
        {
            return false;
        }
        op=0;cl=0;flip=0;
        for(int i=0;i<s.length();i++)
        {
            if(locked[i]=='0')
            {
                flip++;
            }
            else
            {
                if(s[i]=='(')
                    op++;
                else
                    cl++;
            }
            if(op+flip<cl)
            {
                return false;
            }
        }op=0;cl=0;flip=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(locked[i]=='0')
            {
                flip++;
            }
            else
            {
                if(s[i]=='(')
                    op++;
                else
                    cl++;
            }
            if(cl+flip<op)
            {
                return false;
            }
        }
      
        return true;
    }
};
