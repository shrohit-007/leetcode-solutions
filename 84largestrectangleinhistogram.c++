class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(); 
        stack<int>st;
        int ans=0;
        heights.push_back(-1);
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() and heights[i]<heights[st.top()])
            {
                int h=heights[st.top()];
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
};
