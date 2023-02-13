class Solution {
public:
    // bool check(string &s,string &p,int i,int j,vector<vector<int>>&dp)
    // {
    //     if(j==p.length() and i==s.length())return true;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(i<s.length() && j<p.length() && (s[i]==p[j] || p[j]=='?'))
    //     {
    //         return dp[i][j]=check(s,p,i+1,j+1,dp);
    //     }
    //     else if(j<p.length() && p[j]=='*')
    //     {
    //         bool st=false;
    //         if(i<s.length())
    //             st|=check(s,p,i+1,j,dp);
    //         st|=check(s,p,i,j+1,dp);
    //         return dp[i][j]=st;
    //     }
    //     else
    //         return dp[i][j]=false;
    // }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,0));
        dp[s.length()][p.length()]=true;
        //return check(s,p,0,0,dp);
        for(int i=s.length();i>=0;i--)
        {
            for(int j=p.length()-1;j>=0;j--)
            {
                if(i<s.length() && j<p.length() && (s[i]==p[j] || p[j]=='?'))
                {
                    dp[i][j]=dp[i+1][j+1];
                }
                else if(j<p.length() && p[j]=='*')
                {
                    bool st=false;
                    if(i<s.length())
                        st|=dp[i+1][j];
                    st|=dp[i][j+1];
                    dp[i][j]=st;
                }
                else
                    dp[i][j]=false;
            }
        }
        return dp[0][0];
    }
};
