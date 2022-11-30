class Solution {
public:
    int histogram(vector<int>v)
    {
       stack<int>st;
       int ans=0;
        v.push_back(-1);
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and v[i]<v[st.top()])
            {
                int h=v[st.top()];
                st.pop();
                int r=i;
                if(st.empty())
                {
                    ans=max(ans,h*r);
                }
                else
                {
                    int l=st.top();
                    ans=max(ans,h*(r-l-1));
                }
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>v(m,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                {
                    v[j]=0;
                }
                else
                    v[j]+=1;
            }
            int ans1=histogram(v);
            ans=max(ans,ans1);
        }
        return ans;
    }
    
};
