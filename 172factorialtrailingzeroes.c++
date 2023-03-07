class Solution {
public:
    int trailingZeroes(int n) {
        int x=0;
        while(n>=5)
        {
            x+=n/5;
            n=n/5;
        }
        return x;
    }
};
