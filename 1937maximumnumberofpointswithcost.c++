class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        // logic for example 
        // 1 5 5 3  on index (0,1,2,3)
        // for getting max till particular index
        // we will get it by  max_till_i=max(max_till_i-1,valueofindexi);
        long long ans=0;
        int n=points.size(),m=points[0].size();
        vector<vector<long long>>dp(n,vector<long long>(m,0));
        for(int i=0;i<m;i++)
        {
            dp[0][i]=points[0][i];
            ans=max((int)ans,points[0][i]);
        }
        for(int i=1;i<n;i++)
        {
            vector<long long>left=dp[i-1];
            vector<long long>right=dp[i-1];
            for(int j=1;j<m;j++)
            {
                left[j]=max(left[j-1]-1,left[j]);
            }
            for(int j=m-2;j>=0;j--)
            {
                right[j]=max(right[j+1]-1,right[j]);
            }
            for(int j=0;j<m;j++)
            {
                dp[i][j]=points[i][j]+max(right[j],left[j]);
                //cout<<dp[i][j]<<" ";
                ans=max(ans,dp[i][j]);
            }//cout<<endl;
        }
        return ans;
    }
};
