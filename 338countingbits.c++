class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        dp[0]=0;
        if(n>0)
        dp[1]=1;
        int id=1;
        for(int i=2;i<=n;i++)
        {
            if(!(i&(i-1)))
            {
                id=i;
                dp[i]=1;
            }
            else
            {
                dp[i]+=1+dp[i-id];
            }
        }
        return dp;
    }
};
