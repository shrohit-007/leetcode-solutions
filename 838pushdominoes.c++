class Solution {
public:
    string pushDominoes(string s) {
        int n=s.length();
        vector<int>v;
        string ans="";
        v.push_back(-1);
        for(int i=0;i<n;i++)
        {
            if(s[i]!='.')
                v.push_back(i);
        }
        v.push_back(n);
        for(int i=0;i<v.size()-1;i++)
        {
            int ind1=v[i];
            int ind2=v[i+1];
            if(i==0 and s[ind2]=='L')
            {
                for(int j=0;j<ind2;j++)
                {
                    ans+='L';
                }
            }
            else if(i==0 and s[ind2]=='R')
            {
                for(int j=0;j<ind2;j++)
                {
                    ans+='.';
                }
            }
            else if(i==0 and ind2==n)
            {
                for(int j=0;j<ind2;j++)
                {
                    ans+='.';
                }
                return ans;
            }
            else if(ind2==n)
            {
                if(s[ind1]=='R')
                {
                    for(int j=ind1;j<n;j++)
                    {
                        ans+='R';
                    }
                    return ans;
                }
                else
                {
                    ans+='L';
                    for(int j=ind1+1;j<n;j++)
                    {
                        ans+='.';
                    }
                    return ans;
                }
            }
            else
                {
                    if(s[ind1]=='L' and s[ind2]=='L' or s[ind1]=='R' and s[ind2]=='R')
                    {
                        for(int j=ind1;j<ind2;j++)
                        {
                            ans+=s[ind1];
                        }
                    }
                    else if(s[ind1]=='L' and s[ind2]=='R')
                    {
                        ans+='L';
                        for(int j=ind1+1;j<ind2;j++)
                        {
                            ans+=s[j];
                        }
                    }
                    else
                    {
                        int dif=ind2-ind1-1;
                        ans+='R';
                        if(dif&1)
                        {
                            for(int j=0;j<dif/2;j++)
                            {
                                ans+='R';
                            }
                            ans+='.';
                            for(int j=0;j<dif/2;j++)
                            {
                                ans+='L';
                            }
                        }
                        else
                        {
                            for(int j=0;j<dif;j++)
                            {
                                if(j<dif/2)
                                {
                                    ans+='R';
                                }
                                else
                                    ans+='L';
                            }
                        }
                    }
                }
            }
        return ans;
            
    }
};
