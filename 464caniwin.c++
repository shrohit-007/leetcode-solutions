class Solution {
public:
    unordered_map<string,int>dp;
    bool findwin(int maxn,int sum,string &s,bool visited[])
    {
        if(sum<=0)return false;
        if(dp.find(s)!=dp.end())return dp[s];
        for(int i=1;i<=maxn;i++)
        {
            if(!visited[i])
            {
                visited[i]=true;
                s[i-1]='1';
                bool subproblem=findwin(maxn,sum-i,s,visited);
                visited[i]=false;
                if(subproblem==false){// here is the catch if here on this last number 
                    // resutl is false it means the previous state is a winning state 
                    // because it can force other player to lose by chosing this value;
                    s[i-1]='0';
                    return dp[s]=true;
                }
                s[i-1]='0';
            }
        }
        return dp[s]=false;
    }
    bool canIWin(int maxn, int sum) {
        int n=maxn;
        maxn=(maxn)*(maxn+1)/2;
        if(maxn<sum)return false;
        if(sum==0)return true;
        string s(n,'0');
        bool arr[22]={false};
        return findwin(n,sum,s,arr);
    }
};
