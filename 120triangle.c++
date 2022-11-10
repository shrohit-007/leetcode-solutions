class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>prev(n,0);
        for(int i=0;i<n;i++)
        {
            vector<int>curr(n,0);
            for(int j=0;j<=i;j++)
            {
                if(i==0 or j==0)
                {
                    curr[j]=triangle[i][j]+(i>0?prev[j]:0);
                }
                else if(i==j)
                {
                    curr[j]=triangle[i][j]+prev[j-1];
                }
                else
                {
                    curr[j]=triangle[i][j]+min(prev[j-1],prev[j]);
                }
            }prev=curr;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,prev[i]);
        }
        return ans;
    }
};
