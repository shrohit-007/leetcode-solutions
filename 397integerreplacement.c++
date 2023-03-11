class Solution {
public:
    unordered_map<int,int>m;
    int f(long long n)
    {
        if(n<=1)return 0;
        if(m.find(n)!=m.end())return m[n];
        int ans=INT_MAX;
        if(n%2==0)ans=1+f(n/2);
        else
        {
            int c1=f(n+1)+1;
            int c2=f(n-1)+1;
            ans=min(c1,c2);
        }
        return m[n]=ans;
    }
    int integerReplacement(int n) {
        return f(n);
    }
};
