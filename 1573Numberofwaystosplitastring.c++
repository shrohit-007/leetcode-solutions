class Solution {
public:
    int numWays(string s) {
        int n=s.length();
        int cnt0=0,cnt1=0;
        for(char &c:s)
        {
            if(c=='0')cnt0++;
            else
            {
                cnt1++;
            }
        }
        if(cnt1%3!=0)
        {
            return 0;
        }
        if(cnt1==0)
        {
            return ((n-2)*(1LL)*(n-1)/2)%1000000007;
        }
        int cnt1btw_s1ands2=0,cnt1btw_s2ands3=0;
        int cnt1tillnow=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                cnt1tillnow++;
            }
            if(cnt1tillnow==cnt1/3)
            {
                cnt1btw_s1ands2++;
            }
            if(cnt1tillnow==(cnt1/3)*2)
            {
                cnt1btw_s2ands3++;
            }
        }
        return ((cnt1btw_s1ands2)*(1LL)*(cnt1btw_s2ands3))%1000000007;
    }
};
