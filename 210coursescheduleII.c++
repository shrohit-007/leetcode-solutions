class Solution {
public:
    bool dfs(vector<vector<int>>&edges,int root,vector<int>&vis,vector<int>&ans)
    {
        for(int child:edges[root])
        {
            if(!vis[child])
            {
                vis[child]=2;
                if(dfs(edges,child,vis,ans))
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
        ans.push_back(root);
        //cout<<"YES1"<<endl;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<vector<int>>edges(n);
        for(int i=0;i<prerequisites.size();i++)
        {
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i]=2;
                if(dfs(edges,i,vis,ans))
                {
                   // cout<<"YES"<<endl;
                    return ans={};
                }
                vis[i]=1;

            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
