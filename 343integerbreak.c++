class Solution {   
public:
    int integerBreak(int n) {
        
        int ans=1;
        int temp=n;
        for(int i=2;i<n;i++)
        {
            int div=temp/i;
            int rem=temp%i;
            int ans1;
            if(div==1)
            {
                ans1=i*rem;
                ans=max(ans,ans1);
            }
            else
            {
                ans1=pow(i,div-1);
                rem+=i;
                ans1*=rem;
                ans=max(ans,ans1);
                ans1=pow(i,div);
                rem-=i;
                if(rem!=0)ans1*=rem;
                ans=max(ans,ans1);
            }
           // ans=max(ans,ans1);
        }
        return ans;
    }
};
