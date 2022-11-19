class Solution {
public:
    static bool comp1(vector<int>a,vector<int>b)
    {
        if(b[1]==a[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    int check(pair<int,int>a,pair<int,int>b,pair<int,int>c)
    {
        return (c.second-a.second)*(b.first-a.first)-(c.first-a.first)*(b.second-a.second);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n=trees.size();
        if(n<=3)
        {
            return trees;
        }
        vector<vector<int>>ans;
        sort(trees.begin(),trees.end());
        stack<pair<int,int>>hull;
        hull.push({trees[0][0],trees[0][1]});
        hull.push({trees[1][0],trees[1][1]});
        // here we will take three points in check function which  will tell 
        // if the last point is going left (positive slope difference) or right(negative slope difference )
        // slope difference between two lines ab and bc will be (cy-by)/(cx-bx) - (by-ay)/(bx-ax)
        // in more generalize way slope difference will be (cy-by)*(bx-ax)-(by-ay)*(cx-bx)
        // if it is greater than 0 means point is on left so no need to worry we will push it 
        // else we will pop it and add another point to check 
        
        // lower hull
        for(int i=2;i<n;i++)
        {
            pair<int,int>top=hull.top();
            hull.pop();
            pair<int,int>c={trees[i][0],trees[i][1]};
            while(!hull.empty() and check(hull.top(),top,c)<0)
            {
                top=hull.top();
                hull.pop();
            }
            hull.push(top);
            hull.push({trees[i][0],trees[i][1]});
        }
        
        // similarly for upper hull
        set<pair<int,int>>st;
        while(!hull.empty())
        {
            pair<int,int>top=hull.top();
            hull.pop();
            if(st.find(top)!=st.end())
            continue;
            else
            {
                st.insert(top);
            }
            vector<int>temp={top.first,top.second};
            ans.push_back(temp);
        }
        hull.push({trees[n-1][0],trees[n-1][1]});
        hull.push({trees[n-2][0],trees[n-2][1]});
        for(int i=n-3;i>=0;i--)
        {
            pair<int,int>top=hull.top();
            hull.pop();
            pair<int,int>c={trees[i][0],trees[i][1]};
            while(!hull.empty() and check(hull.top(),top,c)<0)
            {
                top=hull.top();
                hull.pop();
            }
            hull.push(top);
            hull.push({trees[i][0],trees[i][1]});
        }
         while(!hull.empty())
         {
            pair<int,int>top=hull.top();
            hull.pop();
            if(st.find(top)!=st.end())
            continue;
            else
            {
                st.insert(top);
            }
            vector<int>temp={top.first,top.second};
            ans.push_back(temp);
        }
        return ans;
        
    }
};
