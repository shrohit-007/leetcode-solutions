class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n=positions.size();
        multimap<int,pair<int,int>>m;
        vector<int>ans;
        int mxhight=0;
        for(int i=0;i<n;i++)
        {
            int left=positions[i][0];
            int hight=positions[i][1];
            int right=left+hight-1;
            if(m.empty())
            {
                m.insert({hight,{left,right}});
            }
            else
            {
                int phight=0;
                for(auto &it:m)
                {
                    if(it.second.first>right)continue;
                    if(it.second.second<left)continue;
                    phight=max(phight,it.first);
                }
                hight+=phight;
                m.insert({hight,{left,right}});
            }
            mxhight=max(mxhight,hight);
            ans.push_back(mxhight);
        }
        return ans;
    }
};
