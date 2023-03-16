class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int>q;
        vector<int>ans;
        sort(deck.rbegin(),deck.rend());
        for(int i=0;i<deck.size();i++)
        {
            if(i==0)
                q.push(deck[0]);
            else
            {
                int top=q.front();
                q.pop();
                q.push(top);
                q.push(deck[i]);
            }
        }
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
