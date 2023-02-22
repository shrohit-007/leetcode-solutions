class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int s=1,e=2e9;
        int ans=0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            long long c=0;
            for(int i=0;i<n;i++)
            {
                c+=candies[i]/mid;
            }
            if(c>=k)
            {
                s=mid+1;
                ans=mid;
            }
            else
                e=mid-1;
        }
        return ans;
    }
};
