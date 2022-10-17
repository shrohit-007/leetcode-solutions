class Solution {
public:
    int jump(vector<int>& v) {
        int n=v.size();
        int curfar=0;
        int ans=0;
        int curend=0;
        for(int i=0;i<n-1;i++)
        {
            curfar=max(curfar,i+v[i]);
            if(i==curend)
            {
                ans++;
                curend=curfar;
            }
        }
        return ans;
    }
};
