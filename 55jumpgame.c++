class Solution {
public:
    bool canJump(vector<int>& v) {
        int n=v.size();
        int j=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(v[i]>=(j-i))
            {
                j=i;
            }
        }
        if(j==0)
        {
            return true;
        }
        return false;
        
    }
};
