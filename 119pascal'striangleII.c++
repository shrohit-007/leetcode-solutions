class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>res;
        res.push_back(1);
        for(int i=1;i<=rowIndex;i++)
        {
            long long ans=1;
            long long l=1,r=rowIndex;
            for(int j=1;j<=min(rowIndex-i,i);j++)
            {
                ans*=(r);
                ans/=l;
                l++;r--;
            }
            res.push_back(ans);
        }
        return res;
    }
};
