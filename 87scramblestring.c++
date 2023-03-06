class Solution {
public:
    unordered_map<string,bool>m;
    bool maker(string s1,string s2,int n)
    {
        if(s1==s2)return m[s1+"#"+s2]=true;
        else if(s1.length()==1)return false;
        else if(m.find(s1+"#"+s2)!=m.end())return m[s1+"#"+s2];
        
        for(int i=1;i<=n-1;i++)
        {
            bool cond1=maker(s1.substr(0,i),s2.substr(0,i),i)&&maker(s1.substr(i,n-i),s2.substr(i,n-i),n-i);
            bool cond2=maker(s1.substr(0,i),s2.substr(n-i),i)&&maker(s1.substr(i,n-i),s2.substr(0,n-i),n-i);
            
            if(cond1 or cond2)return m[s1+"#"+s2]=true;
        }
        return m[s1+"#"+s2]=false;
    }
    bool isScramble(string s1, string s2) {
        return maker(s1,s2,s1.length());
    }
};
