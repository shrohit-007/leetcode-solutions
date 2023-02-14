class Solution {
public:
    int perform(int x,int y,char op)
    {
        if(op=='+')return x+y;
        else if(op=='-')return x-y;
        else if(op=='*')return x*y;
        return 0;
    }
    vector<int> diffWaysToCompute(string s) {
        bool check=1;
        vector<int>res;
        for(int i=0;i<s.length();i++)
        {
            if(!isdigit(s[i]))
            {
                check=0;
                vector<int>left=diffWaysToCompute(s.substr(0,i));
                vector<int>right=diffWaysToCompute(s.substr(i+1));
                for(int x:left)
                {
                    for(int y:right)
                    {
                        int num=perform(x,y,s[i]);
                        res.push_back(num);
                    }
                }
            }
        }
        if(check==1)res.push_back(stoi(s));
        return res;
    }
};
