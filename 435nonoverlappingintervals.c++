class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i=1;
        int prev=0;
        int ans=0;
        while(i<intervals.size())
        {
            int currbegin=intervals[i][0];
            int currend=intervals[i][1];
            int prevbegin=intervals[prev][0];
            int prevend=intervals[prev][1];
            if(prevend>currbegin)
            {
                ans++;
                if(prevend>currend)
                {
                    prev=i;
                }
            }
            else
                prev=i;
            i++;
        }
        return ans;
    }
};
