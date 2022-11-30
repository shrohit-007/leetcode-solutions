class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        stack<int>st;
        int ans=0;
        nums.push_back(-1);
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() and nums[i]<nums[st.top()])
            {
                int h=nums[st.top()];
                st.pop();
                int r=i;
                if(st.empty())
                {
                    if(r-1>=k)
                    ans=max(ans,h*r);
                }
                else
                {
                    int l=st.top();
                    if(r-1>=k and l+1<=k)
                    {
                        //cout<<h<<" "<<l<<" "<<r<<endl;
                        ans=max(ans,h*(r-l-1));
                    }
                }
            }
            st.push(i);
        }
        return ans;
    }
};
