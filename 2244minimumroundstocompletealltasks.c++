class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>m;
        for(int i=0;i<tasks.size();i++)
        {
            m[tasks[i]]++;
        }
        int ans=0;
        for(auto &it:m)
        {
            if(it.second==1)
            {
                return -1;
            }
            ans+=it.second/3;
            ans+=(it.second%3!=0);
        }
        return ans;
    }
};
