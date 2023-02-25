class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int sz=max(s.size(),shifts.size());
        vector<int>dif(sz+1,0),dif2(sz+1,0);
        for(int i=0;i<shifts.size();i++)
        {
            int l=shifts[i][0];
            int r=shifts[i][1];
            int d=shifts[i][2];
            if(d==0)
            {
                dif[r+1]--;
                dif[l]++;
            }
            else
            {
                dif2[l]++;
                dif2[r+1]--;
            }     
        }
        for(int i=1;i<=sz;i++)
        {
            dif[i]+=dif[i-1];
            dif2[i]+=dif2[i-1];
        }
        for(int i=0;i<s.size();i++)
        {
            int shift=dif2[i]-dif[i];
            if(shift<0)
            {
                shift*=-1;
                shift%=26;
                shift=26-shift;
            }
            else
            shift%=26;
            int extra=s[i]-'a';
            shift=(shift+extra)%26;
            s[i]=shift+'a';
        }
        return s;
    }
};
