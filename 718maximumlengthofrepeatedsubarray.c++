class Solution {
public:
    int findLength(vector<int>& v1, vector<int>& v2) {
        int n1=v1.size();
        int n2=v2.size();
        if(n1==0 or n2==0)
            return 0;
        int ans=0,j,k,cnt=0;
        for(int i=0;i<n1;i++)
        {
            j=i;
            k=0;
            cnt=0;
            while(k<n2 and j<n1)
            {
                if(v1[j]==v2[k])
                {
                    k++;
                    j++;
                    cnt++;
                }
                else
                {
                    while(k<n2 and v2[k]!=v1[i])
                    {
                        k++;
                    }
                    ans=max(ans,cnt);
                    cnt=0;
                    j=i;
                }
            }
            ans=max(ans,cnt);
        }
        for(int i=0;i<n2;i++)
        {
            j=i;
            k=0;
            cnt=0;
            while(k<n1 and j<n2)
            {
                if(v2[j]==v1[k])
                {
                    k++;
                    j++;
                    cnt++;
                }
                else
                {
                    while(k<n1 and v1[k]!=v2[i])
                    {
                        k++;
                    }
                    ans=max(ans,cnt);
                    cnt=0;
                    j=i;
                }
            }
            ans=max(ans,cnt);
        }
        return ans;
        
    }
};
