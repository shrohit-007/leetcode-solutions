class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int>dp(9,0);
        dp[0]=1;
        dp[1]=10;
        for(int i=2;i<=n;i++)
        {
            dp[i]=9;
            int k=9;
            for(int j=1;j<i;j++)
            {
                dp[i]*=k;
                k--;
            }
            dp[i]+=dp[i-1];
        }
        return dp[n];
    }
};
