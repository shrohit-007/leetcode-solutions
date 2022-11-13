class Solution {
public:
    // back trackig solution
    bool f(int ind,int sum,vector<int>&arr,vector<bool>&visited,int k,int sum1)
    {
        if(k==1)return true;
        if(sum==sum1)
        {
            return f(0,0,arr,visited,k-1,sum1);
        }
        for(int j=ind+1;j<arr.size();j++)
        {
            if(visited[j] or sum+arr[j]>sum1)continue;
            visited[j]=true;
            if(f(j,sum+arr[j],arr,visited,k,sum1))
                return true;
            visited[j]=false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        if(k==1)
            return true;
        for(int I:nums)
            sum+=I;
        if(sum%k!=0)
            return false;
        vector<bool>visited(nums.size()+2,false);
        return f(0,0,nums,visited,k,sum/k);
    }
};
