class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>check1;
    void find1(vector<int>&nums,int ind,vector<int>&v)
    {
        if(ind==nums.size())
        {
            if(v.size()>=2 and check1.find(v)==check1.end())
            {
                check1.insert(v);
                ans.push_back(v);
            }
            return;
        }
        if(v.empty())
        {
            v.push_back(nums[ind]);
            find1(nums,ind+1,v);
            v.pop_back();
            find1(nums,ind+1,v);
        }
        else
        {
            if(nums[ind]>=v.back())
            {
                v.push_back(nums[ind]);
                find1(nums,ind+1,v);
                v.pop_back();
                find1(nums,ind+1,v);
            }
            else
                find1(nums,ind+1,v);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>v;
        find1(nums,0,v);
        return ans;
    }
};
