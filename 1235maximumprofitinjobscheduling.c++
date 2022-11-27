class Solution {
public:
    unordered_map<int,int>dp;
    int f(int i,vector<vector<int>>&v,int n)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp.find(i)!=dp.end())return dp[i];
        int ind=getNextJob(v,i,n);
        int p=v[i][2]+f(ind,v,n);
        int np=f(i+1,v,n);
        return dp[i]=max(p,np);
    }
    int getNextJob(vector<vector<int>>& jobs, int idx, const int& n)
    {
	int lo = idx+1, hi = n-1, ans = n;
	while(lo <= hi) {
		int mid = (lo + hi) >> 1;
		if(jobs[idx][1] <= jobs[mid][0])
		{
			ans = mid;
			hi = mid-1;
		}
		else lo = mid + 1;
	}
	return ans;
    }
    static bool comp(vector<int>&a,vector<int>&b)
    {
        return a[0]<b[0];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int ans=0;
        int n=startTime.size();
        vector<vector<int>>v(n);
        for(int i=0;i<n;i++)
        {
            v[i].push_back(startTime[i]);
            v[i].push_back(endTime[i]);
            v[i].push_back(profit[i]);
        }
        sort(v.begin(),v.end(),comp);
        //vector<int>dp(n,-1);
        return f(0,v,n);
    }
};
