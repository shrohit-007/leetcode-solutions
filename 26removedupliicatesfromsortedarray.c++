class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        stack<int>s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.empty())
            {
                s.push(nums[i]);
            }
            else
            {
                if(s.top()==nums[i])
                {
                    continue;
                }
                else
                {
                    s.push(nums[i]);
                }
            }
        }
        int i=s.size();
        while(!s.empty())
        {
            nums[s.size()-1]=s.top();
            s.pop();
        }
        return i;
    }
};
