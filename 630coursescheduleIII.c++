class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int>pq;
        sort(courses.begin(),courses.end(),comp);
        int currsum=0;
        for(int i=0;i<courses.size();i++)
        {
            currsum+=courses[i][0];
            pq.push(courses[i][0]);
            if(currsum>courses[i][1])
            {
                currsum-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
         
    }
};
