class Solution {
public:
    int solve(string beginWord,string endWord,unordered_set<string>&v)
    {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        int ans=INT_MAX;
        while(!q.empty()) 
        {
            string st=q.front().first;
            int c=q.front().second;
            q.pop();
            if(st==endWord)
            {
                ans=min(ans,c);
                continue;
            }
            vector<string>temp;
            for(auto &it:v)
            {
                if(st.length()-it.length()==0)
                {   int c1=0;
                    for(int j=0;j<st.length();j++)
                    {
                        if(st[j]!=it[j])
                            c1++;
                    }
                    if(c1==1)
                    {
                        q.push({it,c+1});
                        temp.push_back(it);
                    }
                }
            }
            for(int i=0;i<temp.size();i++)v.erase(temp[i]);
        }
        return ans;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& v) {
        auto it=find(v.begin(),v.end(),endWord);
        if(it==v.end() or beginWord.length()!=endWord.length())return 0;
        unordered_set<string>s;
        for(string str:v)
            s.insert(str);
        int ans=solve(beginWord,endWord,s);
        return ans==INT_MAX?0:ans;
    }
};
