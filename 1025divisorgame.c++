class Solution {
public:
    bool divisorGame(int n) {
        /// dp approach
        // vector<int>dp(n+1,0);
        // if(n>1)
        // dp[2]=1;
        // for(int i=3;i<=n;i++)
        // {
        //     for(int j=i-1;j>=1;j--)
        //     {
        //         if(i%j==0)
        //         {
        //             if(dp[i-j]==false)
        //                 dp[i]=true;
        //         }
        //     }
        // }
        // return dp[n];
        
        
        // greedy or mathematical solution
        /*
        since we know the player who will reach at 1 will lose this game 
        and the player who will end up reaching 2 will win 
        and odd number always have odd divisors then num-odddivisor=even always
        then this player who will get even always make it odd by reducing 1 by choosing 1
        then we can say if alice would get odd number he will lose this game
        because the other player will always make it odd by reducing 1
        */
        
        return n%2==0;
        
    }
};
