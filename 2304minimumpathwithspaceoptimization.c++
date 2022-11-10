class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ans=INT_MAX;
        int n=grid.size();
        int m=grid[0].size();
        vector<int>prev(m,0);
        for(int i=1;i<n;i++)
        {
            vector<int>curr(m,0);
            for(int j=0;j<m;j++)
            {
                int cost=INT_MAX;
                for(int k=0;k<m;k++)
                {
                    cost=min(cost,prev[k]+grid[i-1][k]+moveCost[grid[i-1][k]][j]);
                }
                curr[j]=cost;
            }
            prev=curr;
        }
        for(int i=0;i<grid[0].size();i++)
        {
            ans=min(prev[i]+grid[n-1][i],ans);
        }
        return ans;
    }
};
