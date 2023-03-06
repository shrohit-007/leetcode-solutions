class Solution {
public:
    long long coloredCells(int n) {
        long long x=0;
        long long ans=1;
        if(n==1)
            return 1;
        for(int i=1;i<=n;i++)
        {
            ans+=x;
            x+=4;
        }
        return ans;
    }
};
