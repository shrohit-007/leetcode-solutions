class Solution {
public:
    vector<vector<string>>ans;
    void dfs(string &beginWord,string  endword,unordered_map<string,int>&hash,vector<string>&ans1)
    {
        if(endword==beginWord)
        {
            reverse(ans1.begin(),ans1.end());
            ans.push_back(ans1);
            reverse(ans1.begin(),ans1.end());
            return;
        }
        int steps=hash[endword];
        for(int i=0;i<endword.size();i++)
        {
            char original=endword[i];
            for(char c='a';c<='z';c++)
            {
                endword[i]=c;
                if(hash.find(endword)!=hash.end() and steps==hash[endword]+1)
                {
                    ans1.push_back(endword);
                    dfs(beginWord,endword,hash,ans1);
                    ans1.pop_back();
                }
            }endword[i]=original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>hash;
        queue<string>q;
        unordered_set<string>Words;
        for(string it:wordList)Words.insert(it);
        q.push(beginWord);// this is initially on 0th level
        hash[beginWord]=1;
        Words.erase(beginWord);
        int sz=beginWord.size();
        int level=0;
        while(!q.empty())
        {
            string root=q.front();
            int steps=hash[root];
            q.pop();
            if(root==endWord)
            {
                break;
            }
            for(int i=0;i<sz;i++)
            {
                char original=root[i];
                for(char c='a';c<='z';c++)
                {
                    root[i]=c;
                    if(Words.count(root))
                    {
                        q.push(root);
                        Words.erase(root);
                        hash[root]=steps+1;
                    }
                }
                root[i]=original;
            }
        }
        vector<string>ans1;
        ans1.push_back(endWord);
        if(hash.find(endWord)!=hash.end())
        dfs(beginWord,endWord,hash,ans1);
        return ans;
    }
};
