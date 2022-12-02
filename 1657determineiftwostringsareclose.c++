class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length())return false;
        int n=word1.length();
        vector<int>fr1(26,0),fr2(26,0);
        for(int i=0;i<n;i++)
        {
            fr1[word1[i]-'a']++;
            fr2[word2[i]-'a']++;
        }
        string s1="",s2="";
        string s3="",s4="";
        for(int i=0;i<26;i++)
        {
            if(fr1[i]!=0)s1+=char(i+'a');s3+=char(fr1[i]+'0');
            if(fr2[i]!=0)s2+=char(i+'a');s4+=char(fr2[i]+'0');
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        sort(s3.begin(),s3.end());
        sort(s4.begin(),s4.end());
        if(s1!=s2 or s3!=s4)return false;
        return true;
        
    }
};
