class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>v;
        int n=plantTime.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({growTime[i],plantTime[i]});
        }
        sort(v.begin(),v.end());
        int ans=0,p=0;
        for(int i=n-1;i>=0;i--)
        {
            p+=v[i].second;
            ans=max(ans,p+v[i].first);
        }
        return ans;
    }
};
