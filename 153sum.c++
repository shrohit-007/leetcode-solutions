class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int k=n-1;
            int need=-nums[i];
            vector<int>temp;
            while(j<k)
            {
                if(nums[j]+nums[k]==need)
                {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    st.insert(temp);
                    temp.clear();
                    j++,k--;
                }
                else if(nums[j]+nums[k]>need)
                {
                    k--;
                }
                else
                    j++;
            }
        }
        for(auto &it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
    
};
