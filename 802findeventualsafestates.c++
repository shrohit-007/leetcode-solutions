class Solution {
public:
    bool dfs(vector<vector<int>>&graph,int root,vector<int>&vis)
    {
        for(int child:graph[root])
        {
            if(!vis[child])
            {
                vis[child]=2;
                if(dfs(graph,child,vis))
                {
                    return true;
                }
                vis[child]=1;
            }
            else if(vis[child]==2)
            {
                return true;
            }
        }
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n=graph.size();
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i]=2;
                if(dfs(graph,i,vis))continue;
                vis[i]=1;
            }
            if(vis[i]!=2)
                ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
