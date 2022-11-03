class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<pair<char,char>,int>v;
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            char x=words[i][0];
            char y=words[i][1];
            v[{x,y}]++;
        }
        int f=0;
        for(auto &it:v)
        {
            if(it.first.first==it.first.second)
            {
                if(it.second%2==1)
                {
                    f=1;
                    ans+=2*(it.second-1);
                }
                else
                    ans+=2*it.second;
                continue;
            }
           ans+=2*min(v[{it.first.first,it.first.second}],v[{it.first.second,it.first.first}]);
        }
        if(f)
            ans+=2;
        return ans;
    }
};
