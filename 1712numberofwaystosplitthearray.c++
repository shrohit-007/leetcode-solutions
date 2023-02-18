class Solution {
public:
    int mod=1000000007;
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        vector<int>pf(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)cnt++;
            pf[i]=(i-1>=0?pf[i-1]:0)+nums[i];
        }
        if(cnt==n)
        {
            long long ans=n-1;
            ans*=(ans-1);
            ans/=2;
            ans%=mod;return ans;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            
            int x=(pf[i]!=0)?lower_bound(pf.begin(),pf.end(),2*pf[i])-pf.begin():i+1;
            if(x>=n-1)
            {
                break;
            }
            int s=x,e=n-1;
            int midpnt=x-1;
            while(s<=e)
            {
                int mid=(s+e)/2;
                int rightsum=pf[n-1]-pf[mid];
                int midsum=pf[mid]-pf[i];
                if(midsum<=rightsum)
                {
                    midpnt=mid;
                    s=mid+1;
                }
                else
                {
                    e=mid-1;
                }
            }
            //cout<<x<<" "<<midpnt<<endl;
            ans+=(midpnt-x+1)%mod;
            ans%=mod;
        }
        return ans;
        
    }
};
