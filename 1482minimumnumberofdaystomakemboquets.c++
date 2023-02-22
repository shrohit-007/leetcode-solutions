class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<(m*1LL*k))
            return -1;
        int s=0,e=2e9;
        int ans=s;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int c=0;
            int c1=0;
            for(int i=0;i<bloomDay.size();i++)
            {
                if(bloomDay[i]<=mid)
                {
                    c1++;
                }
                else
                {
                    c+=c1/k;
                    c1=0;
                }
            }
            c+=c1/k;
        if(c>=m)
        {
            ans=mid;
            e=mid-1;
        }
        else
            s=mid+1;
        }
        return ans;
    }
};
