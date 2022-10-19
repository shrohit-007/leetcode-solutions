class Solution {
public:
    void generate(vector<vector<int>>&ans,int target,int cnt,int k,vector<int>&temp,int ind)
    {
        if(target<=0)
        {
            if(target==0 and cnt==k)
            {
                ans.push_back(temp);
            }
            return ;
        }
        for(int i=ind;i<=9;i++)
        {

            if(target>=i)
            {
                temp.push_back(i);
                generate(ans,target-i,cnt+1,k,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        generate(ans,n,0,k,temp,1);
        return ans;
    }
};
