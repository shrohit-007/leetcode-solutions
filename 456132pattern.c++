class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return false;
        int slast=INT_MIN;
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<slast)return true;
            else
            {
                while(!st.empty() and nums[i]>st.top())
                {
                    slast=st.top();
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        return false;
    }
};
