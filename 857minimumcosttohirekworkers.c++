class Solution {
public:
    static bool compare(pair<int,int>a,pair<int,int>b)
    {
        double x=(a.second*1.0)/a.first;
        double y=(b.second*1.0)/b.first;
        return x<=y;
    }
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<int,int>>v;
        int n=quality.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({quality[i],wage[i]});
        }
        sort(v.begin(),v.end(),compare);
        priority_queue<int>pq;
        int qualitysum=0;
        for(int i=0;i<k;i++)
        {
            qualitysum+=v[i].first;
            pq.push(v[i].first);
        }
        double ans=(qualitysum*1.0/v[k-1].first)*v[k-1].second;
        for(int i=k;i<n;i++)
        {
            qualitysum+=v[i].first;
            qualitysum-=pq.top();
            pq.pop();
            pq.push(v[i].first);
            ans=min(ans,(qualitysum*1.0/v[i].first)*v[i].second);
        }
        return ans;
    }
};
