class Solution {
public:
    int maximum69Number (int num) {
        string st=to_string(num);
        for(int i=0;i<st.length();i++)
        {
            if(st[i]=='6')
            {
                st[i]='9';
                break;
            }
        }
        num=stoi(st);
        return num;
    }
};
