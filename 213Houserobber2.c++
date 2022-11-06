class Solution {
public:
    int ans(vector<int>&v)
    {
        int prev2=v[0];
        int prev1=v[0];
        int curr;
        for(int i=1;i<v.size();i++)
        {
            int p=v[i]+(i>1?prev2:0);
            int np=prev1;
            curr=max(p,np);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int ele=nums[nums.size()-1];
        nums.pop_back();
        int ans1=ans(nums);
        nums.push_back(ele);
        nums.erase(nums.begin());
        int ans2=ans(nums);
        //cout<<ans1<<" "<<ans2<<endl;
        return max(ans1,ans2);
    }
};
