class Solution {
public:
    int answer=0;
    void generate(vector<string>&arr,int i,vector<string>&ans)
    {
        if(i==arr.size())
        {
            vector<int>m(26);
            for(int j=0;j<ans.size();j++)
            {
                for(int k=0;k<ans[j].length();k++)
                {
                    m[ans[j][k]-'a']++;
                }
            }
            int f=0;
            int cnt=0;
            for(int i=0;i<26;i++)
            {
                if(m[i]>=2)
                {
                    f=1;
                    break;
                }
                else if(m[i]>=1)
                {
                    cnt++;
                }
            }
            if(!f)
            {
                answer=max(answer,cnt);
            }
            return;
        }
        ans.push_back(arr[i]);
        generate(arr,i+1,ans);
        ans.pop_back();
        generate(arr,i+1,ans);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        vector<string>ans;
        generate(arr,0,ans);
        return answer;
    }
};
