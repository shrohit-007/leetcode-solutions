class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int n=nums.size();
        int x=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]&1)
            {
                pq.push(nums[i]*2);
                x=min(x,nums[i]*2);
            }
            else
            {
                pq.push(nums[i]);
                x=min(x,nums[i]);
            }
        }
        int ans=pq.top()-x;
        while(pq.top()%2==0)
        {
            ans=min(ans,pq.top()-x);
            x=min(x,pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        return min(ans,pq.top()-x);
        
    }
};
