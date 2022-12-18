class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int>st;
        st.insert(nums[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            nums[i]=nums[i]+*(--st.end());
            st.insert(nums[i]);
            if(i+k<n)
            {
                st.erase(st.find(nums[i+k]));
            }
        }
        return nums[0];
    }
};
