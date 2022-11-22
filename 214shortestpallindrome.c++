class Solution {
public:
    string shortestPalindrome(string s) {
        // two pointer solution
        if(s.length()==0)
            return "";
        if((s.find_first_not_of(s[0]) == string::npos))
        {
            return s;
        }
        string t=s;
        reverse(t.begin(),t.end());
        s+=t;
        int n=s.length();
        vector<int>pf(n+2,0);
        //cout<<s<<endl;
        for(int i=1;i<n;i++)
        {
            int j=pf[i-1];
            if(j==(i+1)/2)
                j=0;
            while(j>0 and s[i]!=s[j])
            {
                j=pf[j-1];
            }
            if(s[i]==s[j])
            {
                j++;
            }
            pf[i]=j;
        }
        string st=s.substr(n/2,n/2-pf[n-1]);
        reverse(t.begin(),t.end());
        return st+t;
        
        
    }
};
