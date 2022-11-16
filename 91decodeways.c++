class Solution {
public:
    int dp[102];
    // recursion
    /*int f(string s,int ind)
    {
        if(s[ind]=='0')
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        if(ind>=s.length())
        {
            return 1;
        }
        int p1=f(s,ind+1);
        int p2=0;
        if(ind+1<s.length() and (stoi(s.substr(ind,2))<=26))
        {
            p2=f(s,ind+2);
        }
       /// cout<<p1<<" "<<p2<<" "<<s[ind]<<endl;
        return dp[ind]=p1+p2;
    } */
    int numDecodings(string s) {
        memset(dp,0,sizeof(dp));
        if(s[0]=='0')
            return 0;
        dp[0]=1;
        dp[1] = (s[0]=='0') ? 0 : 1;
        int n=s.length();
        for(int i=2;i<=n;i++)
        {
            int d = s[i-1]-'0';
            int dd = 10*(s[i-2]-'0') + s[i-1]-'0';

            if(d>=1) dp[i]+=dp[i-1];
            if(dd>=10 and dd<=26) dp[i]+=dp[i-2];
        }

        return dp[n];
    }
};
