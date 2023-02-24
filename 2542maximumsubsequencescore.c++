class Solution {
public:
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans=0;
        long long sum=0;
        int n=nums1.size();
        vector<pair<int,int>>v;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<k;i++)
        {
            sum+=v[i].second;
            pq.push(v[i].second);
        }
        ans=sum*v[k-1].first;
        for(int i=k;i<n;i++)
        {
            sum-=pq.top();
            pq.pop();
            sum+=v[i].second;
            pq.push(v[i].second);
            ans=max(ans,sum*v[i].first);
        }
        return ans;
    }
};
