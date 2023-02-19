class Solution {
public:
    int mod=1e9+7;
    // int mx(int n,int id)
    // {
    //     if(id>=n)
    //     {
    //         return 1;
    //     }
    //     int pick=mx(n,id+2);
    //     int npick=mx(n,id+1);
    //     return pick+npick;
    // }
    int countHousePlacements(int n) {
        // int x=mx(n,0);
        // return x*x;
        long long prev2=1,prev=1,curr=0;
        for(int i=1;i<=n;i++)
        {
            curr=(prev+prev2)%mod;
            prev2=prev%mod;
            prev=curr%mod;
        }
        return (curr*curr)%mod;
    }
};
