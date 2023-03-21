class Solution {
public:
    // bool dfs(vector<vector<int>>&edges,int root,vector<int>&vis)
    // {
    //     for(int child:edges[root])
    //     {
    //         if(!vis[child])
    //         {
    //             vis[child]=2;
    //             if(dfs(edges,child,vis))
    //             {
    //                 return true;
    //             }
    //             vis[child]=1;
    //         }
    //         else if(vis[child]==2)
    //             return true;
    //     }return false;
    // }
    
    bool bfskahn(vector<vector<int>>&edges,int V)
    {
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(int j:edges[i])
            {
                indegree[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(!indegree[i])q.push(i);
        }
        int cnt=0;
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            cnt++;
            for(int child:edges[top])
            {
                indegree[child]--;
                if(!indegree[child])
                    q.push(child);
            }
        }
        return cnt==V;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>edges(n);
        
        for(int i=0;i<prerequisites.size();i++)
        {
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // dfs--> part
        // vector<int>vis(n,0);
        // for(int i=0;i<n;i++)
        // {
        //     if(!vis[i])
        //     {
        //         vis[i]=2;
        //         if(dfs(edges,i,vis))
        //         {
        //             return false;
        //         }
        //         vis[i]=1;
        //     }
        // }return true;
        
        
        //by bfs khan algo--> 
        
        return bfskahn(edges,n);
    }
};
