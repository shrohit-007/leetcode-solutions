class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int cx=0,cy=0;
        int n=s1.length();
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i] and s1[i]=='x')cx++;
            else if(s1[i]!=s2[i] and s1[i]=='y')cy++;
        }
        if(cy%2!=cx%2)return -1;
        int ans=cy%2+cx%2;
        ans+=cy/2;ans+=cx/2;
        return ans;
    }
};
