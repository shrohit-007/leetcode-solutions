class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int s=1,e=2e9;
        int ans=0;
        for(int i=0;i<m;i++)
        {
            ans=max(ans,quantities[i]);
        }
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int c=0;
            for(int i=0;i<m;i++)
            {
                c+=quantities[i]/mid;
                c+=quantities[i]%mid!=0;
            }
            if(c>n)
            {
                s=mid+1;
            }
            else 
            {
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
    }
    
};
