class Solution {
public:
    void dfs(vector<vector<int>>&stones,int cur,vector<bool>&visited)
    {
        visited[cur]=true;
        for(int i=0;i<stones.size();i++)
        {
            if(visited[i])continue;
            if(stones[cur][0]==stones[i][0] or stones[cur][1]==stones[i][1])
                dfs(stones,i,visited);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        //set<int>st;
        int n=stones.size();
        int ans=0;
        vector<bool>visited(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(visited[i])continue;
            dfs(stones,i,visited);
                ans++;
        }
        return n-ans;
    }
};
