class Solution {
public:
    void dfs(vector<vector<int>>&edges,int root,vector<int>&vis)
    {
        vis[root]=1;
        for(int i=0;i<edges[root].size();i++)
        {
            if(!vis[i] and edges[root][i])
            {
                dfs(edges,i,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                c++;
                dfs(isConnected,i,vis);
                continue;
            }
        }
        return c;
    }
};
