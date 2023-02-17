class Solution {
public:
    int mod=1000000007;
    int ways(string &s,int ind,vector<int>&dp)
    {
        if(s[ind]=='0')return 0;
        if(ind==s.size())return 1;
        if(dp[ind]!=-1) return dp[ind];
        int ways1all=0;
        int ways2all=0;
        if(s[ind]=='*')
        {
            for(int i=0;i<9;i++)
            {
                ways1all+=ways(s,ind+1,dp)%mod;
                ways1all%=mod;
            }
            if(ind+1<s.size() and s[ind+1]=='*')
            {
                for(int i=0;i<15;i++)
                {
                    ways2all+=ways(s,ind+2,dp)%mod;
                    ways2all%=mod;
                }
            }
            else if(ind+1<s.size())
            {
                // for s[ind]=='1' then the s[ind+1] can be any character
                ways2all+=ways(s,ind+2,dp)%mod;
                ways2all%=mod;
                // for s[ind]=='2' then the s[ind+1] can only be smaller than 6
                if(s[ind+1]<='6')
                {
                    ways2all+=ways(s,ind+2,dp)%mod;
                    ways2all%=mod;
                }
            }
        }
        else
        {
            ways1all=ways(s,ind+1,dp)%mod;
            ways1all%=mod;
            if(ind+1<s.size() and s[ind+1]=='*')
            {
                for(char c='1';c<='9';c++)
                {
                    string st="";
                    st+=s[ind];
                    st+=c;
                    int num1=stoi(st);
                    if(num1<=26)
                    {
                        ways2all+=ways(s,ind+2,dp)%mod;
                        ways2all%=mod;
                    }
                }
            }
            else if(ind+1<s.size())
            {
                int num=stoi(s.substr(ind,2));
                if(num<=26)
                {
                    ways2all+=ways(s,ind+2,dp)%mod;
                    ways2all%=mod;
                }
            }
        }
        return dp[ind]=(ways1all*1LL+ways2all*1LL)%mod;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,-1);
        return ways(s,0,dp);
    }
};
