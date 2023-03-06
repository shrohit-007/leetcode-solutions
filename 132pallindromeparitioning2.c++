class Solution {
public:
    bool ispallindrome(string &s)
    {
        int i=0,j=s.length()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int dp[2003];
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
            if(ispallindrome(temp))
            {
                cost=1+mini(s,j+1);
                minCost=min(minCost,cost);
            }
        }
        return dp[cur]=minCost;
        
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return mini(s,0)-1;
    }
};
