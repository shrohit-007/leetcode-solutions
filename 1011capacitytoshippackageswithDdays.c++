class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s=0,e=1e6;
        int ans=0;
        for(int i=0;i<weights.size();i++)
        {
            s=max(s,weights[i]);
        }
        ans=s;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int need=0,tmp=mid;
            int i=0,curr=0;
            for(int i=0;i<weights.size();i++)
            {
                int w=weights[i];
                if(curr+w<mid)
                {
                    curr+=w;
                }
                else
                {
                    need++;
                    curr=w;
                }
            }
            if(need>=days)
            {
                ans=mid;
                s=mid+1;
            }
            else
                e=mid-1;
        }
        return ans;
    }
};
