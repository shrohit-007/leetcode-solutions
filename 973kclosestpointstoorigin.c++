class Solution {
public:
    // static bool comp(vector<int>a,vector<int>b)
    // {
    //     double disa=sqrt((a[0]*a[0])+(a[1]*a[1]))*1.0;
    //     double disb=sqrt((b[0]*b[0])+(b[1]*b[1]))*1.0;
    //     //cout<<disa<<" "<<disb<<endl;
    //     return disa<disb;
    // }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //sort(points.begin(),points.end(),comp);
        vector<vector<int>>ans;
        priority_queue<pair<double,vector<int>>>pq;
        for(int i=0;i<points.size();i++)
        {
            double dis=-sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1])*1.0;
            pq.push({dis,points[i]});
        }
        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
