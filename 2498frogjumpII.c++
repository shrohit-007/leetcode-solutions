class Solution {
public:
    int maxJump(vector<int>& stones) {
        if(stones.size()==2)
        {
            return stones[1]-stones[0];
        }
        int ans=0;
        for(int i=0;i<stones.size();i++)
        {
            if(i<stones.size()-2)
            ans=max(ans,stones[i+2]-stones[i]);
        }
        return ans;
        
    }
};
