class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0)return 0;
        if(n<=9)return 1;
        unordered_map<int,int>m;
        m[9]=1;
        for(int i=9;i<=(INT_MAX-9)/10;i=i*10+9)
        {
            m[i*10+9]=m[i]*10+(i+1);
        }
        int ans=0;
        int div=1;
        int temp=n;
        //cout<<temp<<endl;
        while(temp/10)
        {
            temp/=10;
            div*=10;
        }
        //cout<<div<<endl;
        ans+=(n/div)*m[div-1];
        ans+=(n/div)>1?div:0;
        ans+=(n/div)==1?n%div+1:0;
        ans+=countDigitOne(n%div);
        return ans;
    }
};
