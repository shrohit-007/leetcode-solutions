class Solution {
public:
    int countSubstrings(string s) {
        
        int cnt=0;
        int n=s.length();
        //odd
        for(int i=0;i<n;i++)
        {
            for(int j=i,k=i;j>=0 and k<n;j--,k++)
            {
                if(s[j]==s[k])
                {
                    cnt++;
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        // even 
        for(int i=0;i<n;i++)
        {
            for(int j=i,k=i+1;j>=0 and k<n;j--,k++)
            {
                if(s[j]==s[k])
                {
                    cnt++;
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        return cnt;
    }
};
