class Solution {
public:
    vector<string>ans1;
    void generate(string digits,int ind,string ans,vector<string>&v)
    {
        if(ind==digits.length())
        {
            ans1.push_back(ans);
            return;
        }
        int x=digits[ind]-'0';
        //cout<<x<<endl;
        for(int i=0;i<v[x].length();i++)
        {
            generate(digits,ind+1,ans+v[x][i],v);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v={"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.length()==0)
            return ans1;
        generate(digits,0,"",v);
        return ans1;
    }
};
