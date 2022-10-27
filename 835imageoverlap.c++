class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2)  {
        vector<pair<int,int>>onesimg2;
        vector<pair<int,int>>onesimg1;
        int ans=0;
        map<string,int>m;
        int n=img1.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img1[i][j])
                    onesimg1.push_back({i,j});
                if(img2[i][j])
                    onesimg2.push_back({i,j});
            }
        }
        for(int i=0;i<onesimg1.size();i++)
        {
            int x=onesimg1[i].first;
            int y=onesimg1[i].second;
            for(int j=0;j<onesimg2.size();j++)
            {
                int x1=onesimg2[j].first;
                int y1=onesimg2[j].second;
                string st="";
                st+=char(x1-x+'0');
                st+=char(y1-y+'0');
                m[st]++;
                ans=max(ans,m[st]);
            }
        }
        return ans;
        
    }
};
