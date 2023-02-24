class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>>ans;
        vector<pair<int,int>>walls;
        for(int i=0;i<buildings.size();i++)
        {
            walls.push_back({buildings[i][0],-buildings[i][2]});
            walls.push_back({buildings[i][1],buildings[i][2]});
        }
        sort(walls.begin(),walls.end());
        multiset<int>heights={0};
        int top=0;
        for(auto w:walls)
        {
            if(w.second<0)
            {
                heights.insert(-w.second);
            }
            else
            {
                heights.erase(heights.find(w.second));
            }
            if(*heights.rbegin()!=top)
            {
                ans.push_back({w.first,top=*heights.rbegin()});
            }
        }
        return ans;
    }
};
