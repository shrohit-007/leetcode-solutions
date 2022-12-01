class Solution {
public:
    bool f(string& s1, string& s2,string& s3,int i,int j,int ind,vector<vector<int>>&dp)
    {
        if(i<0 and j<0 and ind<0)return true;
        //cout<<i<<" "<<j<<" "<<ind<<" "<<s1cnt<<" "<<s2cnt<<endl;
        if(i>=0 and j>=0 and dp[i][j]!=-1)
            return dp[i][j];
        if(i>=0 and j>=0 and s1[i]==s3[ind] and s2[j]==s3[ind])
        {
            return dp[i][j]=f(s1,s2,s3,i-1,j,ind-1,dp)||f(s1,s2,s3,i,j-1,ind-1,dp);
        }
        else if(i>=0 and s1[i]==s3[ind])
        { 
            return f(s1,s2,s3,i-1,j,ind-1,dp);
        }
        else if(j>=0 and s2[j]==s3[ind])
        {
            
            return f(s1,s2,s3,i,j-1,ind-1,dp);
        }
        else return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int len=s3.length();
        int n=s1.length();
        int m=s2.length();
        if(n+m!=len)return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(s1,s2,s3,n-1,m-1,s3.length()-1,dp);
    }
};
