class Solution {
public:
    int color[200];
    bool bipartitedfs(int root,vector<vector<int>>&edges)
    {
        if(color[root]==-1)
        {
            color[root]=1;
        }
        for(int child:edges[root])
        {
            if(color[child]==-1)
            {
                color[child]=1-color[root];
                if(!bipartitedfs(child,edges))
                return false;
            }
            else if(color[child]==color[root])
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int f=0;
        memset(color,-1,sizeof(color));
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
            {
                if(!bipartitedfs(i,graph))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
