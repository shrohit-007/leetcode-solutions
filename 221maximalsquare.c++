class Solution {
public:
    // check function for binary search
    // bool check(int mid,vector<vector<int>>&matrix1)
    // {
    //     int n=matrix1.size(),m=matrix1[0].size();
    //     int ans=mid*mid;
    //     if(mid==0)return true;
    //     for(int i=mid-1;i<n;i++)
    //     {
    //         for(int j=mid-1;j<m;j++)
    //         {
    //             int cal=0;
    //             if(i==mid-1 or j==mid-1)
    //             {
    //                 cal+=matrix1[i][j]+((i-mid>=0 and j-mid>=0)?matrix1[i-mid][j-mid]:0)-((i-mid>=0)?matrix1[i-mid][j]:0)-((j-mid>=0)?matrix1[i][j-mid]:0);
    //             }
    //             else
    //             {
    //                 cal+=matrix1[i][j]+matrix1[i-mid][j-mid]-matrix1[i-mid][j]-matrix1[i][j-mid];     
    //             }
    //             if(cal==ans)
    //             {
    //                 return true;
    //             }
    //         }
    //     }return false;
    // }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // binary search approach with calculating prefix sums 
        // vector<vector<int>>matrix1(n,vector<int>(m));
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         matrix1[i][j]=matrix[i][j]-'0';
        //         if(i==0 or j==0)
        //         {
        //             matrix1[i][j]+=i>0?matrix1[i-1][j]:0;
        //             matrix1[i][j]+=j>0?matrix1[i][j-1]:0;
        //         }
        //         else
        //         {
        //             matrix1[i][j]+=matrix1[i-1][j]+matrix1[i][j-1]-matrix1[i-1][j-1];
        //         }
        //     }
        // }
        // int s=0,e=min(m,n);
        // int ans=0;
        // while(s<=e)
        // {
        //     int mid=(s+e)/2;
        //     if(check(mid,matrix1))
        //     {
        //         ans=mid*mid;
        //         s=mid+1;
        //     }
        //     else
        //     {
        //         e=mid-1;
        //     } 
        // }
        // return ans;
        
        
        // dynamic programming approach
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!j or !i or matrix[i][j]=='0')
                {
                    dp[i][j]=matrix[i][j]-'0';
                }
                else
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                ans=max(ans,dp[i][j]);
            }
        }return ans*ans;
    }
};
