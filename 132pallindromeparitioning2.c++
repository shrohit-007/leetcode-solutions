class Solution {
public:
    int dp[2003];
    int pallindrome[2001][2001];
    int mini(string s,int cur)
    {
        if(cur==s.length())return 0;
        if(dp[cur]!=-1)return dp[cur];
        string temp="";
        int cost=0;
        int minCost=INT_MAX;
        for(int j=cur;j<s.length();j++)
        {
            temp+=s[j];
            if(pallindrome[cur][j])
            {
                cost=1+mini(s,j+1);
                minCost=min(minCost,cost);
            }
        }
        return dp[cur]=minCost;
        
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        memset(pallindrome,0,sizeof(pallindrome));
        int n=s.length();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i<=2)
                        pallindrome[i][j]=1;
                    else
                        pallindrome[i][j]=pallindrome[i+1][j-1];
                }
            }
        }
        return mini(s,0)-1;
    }
};
