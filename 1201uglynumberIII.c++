class Solution {
public:
    int nthUglyNumber(int n, int A, int B, int C) {
        int s=1,e=2e9+3;
        long a=long(A);
        long b=long(B);
        long c=long(C);
        long ab=a*b/__gcd(a,b);
        long bc=b*c/__gcd(b,c);
        long ac=a*c/__gcd(a,c);
        long abc=(a*bc)/__gcd(a,bc);
        while(s<e)
        {
            int mid=s+(e-s)/2;
            int cnt=mid/a+mid/b+mid/c-mid/ab-mid/bc-mid/ac+mid/abc;
            if(cnt<n)
            {
                s=mid+1;
            }
            else
                e=mid;
        }
        return s;
        
    }
};
