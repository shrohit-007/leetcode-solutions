class Solution {
public:
    char findKthBit(int n, int k) {
        if(k==1)
            return '0';
        if(k>1 and (k&(k-1))==0)
        {
            return '1';
        }
        string s="0";
        string temp;
        while(n>0)
        {
            temp=s;
            reverse(temp.begin(),temp.end());
            for(int i=0;i<temp.size();i++)
                temp[i]='1'-temp[i]+'0';
            s+='1';
            s+=temp;
            n--;
        }
        return s[k-1];
    }
};
