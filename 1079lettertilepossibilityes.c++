class Solution {
public:
    int cnt=0;
    void tiles_possibilities(vector<int>&freq,string ans)
    {
        if(ans!="")
            cnt++;
        for(int i=0;i<freq.size();i++)
        {
            if(freq[i]>=1)
            {
                freq[i]--;
                tiles_possibilities(freq,ans+char(i+'A'));
                freq[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int>freq(26);
        for(int i=0;i<tiles.length();i++)
        {
            freq[tiles[i]-'A']++;
        }
        tiles_possibilities(freq,"");
        return cnt;
    }
};
