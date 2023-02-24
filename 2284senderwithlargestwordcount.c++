class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int>m;
        for(int i=0;i<messages.size();i++)
        {
            int c=1;
            for(int j=0;j<messages[i].length();j++)
            {
                if(messages[i][j]==' ')
                    c++;
            }
            auto it=m.find(senders[i]);
            if(it!=m.end())
            {
                it->second+=c;
            }
            else
            {
                m[senders[i]]=c;
            }
        }
        priority_queue<pair<int,string>>pq;
        for(auto &it:m)
        {
            pq.push({it.second,it.first});
        }
        string ans=pq.top().second;
        int cnt=pq.top().first;
        pq.pop();
        while(!pq.empty() and pq.top().first==cnt)
        {
            if(ans<pq.top().second)
            {
                ans=pq.top().second;
            }
            pq.pop();
        }
        return ans;
    }
};
