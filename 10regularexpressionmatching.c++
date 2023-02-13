class Solution {
public:
    // bool check(string &s,string &p,int i,int j,vector<vector<int>>&dp)
    // {
    //     //cout<<i<<" "<<j<<endl;
    //     if(j==p.length()) return i==s.length();
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(j+1<p.length() and p[j+1]=='*')
    //     {
    //         bool check1=check(s,p,i,j+2,dp);
    //         bool check2=(i<s.length() && (s[i]==p[j] || p[j]=='.'))?check(s,p,i+1,j,dp):false;
    //         return dp[i][j]= check1||check2;
    //     }
    //     else
    //     {
    //         return dp[i][j]=(i<s.length() && (s[i]==p[j] || p[j]=='.'))?check(s,p,i+1,j+1,dp):false;
    //     }
    // }
    bool isMatch(string s, string p) {
        // bool ans=false;
        vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,0));
        //ans=check(s,p,0,0,dp);
        // return ans;
        dp[s.length()][p.length()]=1;
        for(int i=s.length();i>=0;i--)
        {
            for(int j=p.length()-1;j>=0;j--)
            {
                bool first_match=(i<s.length() && (p[j]==s[i]|| p[j]=='.'));
                    if(j+1<p.length() && p[j+1]=='*')
                    {
                        dp[i][j]=dp[i][j+2] || (first_match && dp[i+1][j]);
                    }
                else
                {
                    dp[i][j]=first_match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
