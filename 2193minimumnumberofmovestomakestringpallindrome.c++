class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int cnt=0;
        int start=0,end=s.length()-1;
        while(start<end)
        {
            if(s[start]==s[end])
            {
                start++;
                end--;
                continue;
            }
            int i=end-1;
            while(i>start and s[i]!=s[start])
            {
                i--;
            }
            if(i==start)
            {
                swap(s[i],s[i+1]);
                cnt++;
                continue;
            }
            while(i<end)
            {
                swap(s[i],s[i+1]);
                cnt++;
                i++;
            }
            start++;
            end--;  
        }return cnt;
    }
};
