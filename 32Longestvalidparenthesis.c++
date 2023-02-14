class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        if(n<=1)return 0;
        vector<int>dp(n,0);
        int curr=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]==')')
            {
                if(s[i-1]=='(')
                {
                    dp[i]=(i-2>=0)?dp[i-2]+2:2;
                    curr=max(curr,dp[i]);
                }
                else
                {
                    if(i-dp[i-1]-1>=0 and s[i-dp[i-1]-1]=='(')
                    {
                        dp[i]=dp[i-1]+2+((i-dp[i-1]-2>=0)?dp[i-dp[i-1]-2]:0);
                        curr=max(curr,dp[i]);
                    }
                }
            }
        }
        return curr;
    }
};
