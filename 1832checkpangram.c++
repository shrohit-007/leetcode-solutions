class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>v(26,0);
        for(int i=0;i<sentence.length();i++)
        {
            v[sentence[i]-'a']++;
        }
        for(int i=0;i<=25;i++)
        {
            if(v[i]<=0)
            {
                return false;
            }
        }return true;
    }
};
