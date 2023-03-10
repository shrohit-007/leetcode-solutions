class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>prefix(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 or j==0)
                {
                    prefix[i][j]=grid[i][j]+(i>0?prefix[i-1][j]:0)+(j>0?prefix[i][j-1]:0);
                }
                else
                {
                    prefix[i][j]=grid[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
                }
            }
        }
        int ans=1;
        for(int i=2;i<=min(n,m);i++)
        {
            int sz=i;
            int f=0;
            for(int j=0;j<=n-sz;j++)
            {
                for(int k=0;k<=m-sz;k++)
                {
                    int x=j,y=k;
                    int flag=0;
                   // cout<<x<<" "<<y<<endl;
                    int checksum=prefix[x][y+sz-1]-(y>0?prefix[x][y-1]:0)-(x>0?prefix[x-1][y+sz-1]:0)+((x>0 and y>0)?prefix[x-1][y-1]:0);
                    for(int l=y;l<y+sz;l++)
                    {
                        int sum=prefix[x+sz-1][l]-(l>0?prefix[x+sz-1][l-1]:0)-(x>0?prefix[x-1][l]:0)+((x>0 and l>0)?prefix[x-1][l-1]:0);
                        if(sum!=checksum)
                        {
                            flag=1;
                            break;
                        }
                    }
                    for(int l=x;l<x+sz;l++)
                    {
                        int sum=prefix[l][y+sz-1]-(l>0?prefix[l-1][y+sz-1]:0)-(y>0?prefix[l][y-1]:0)+((l>0 and y>0)?prefix[l-1][y-1]:0);
                        if(sum!=checksum)
                        {
                            flag=1;
                            break;
                        }
                    }
                    int d1=0,d2=0,x1=j+sz-1,y1=k;
                    for(int l=0;l<sz;l++)
                    {
                        d1+=grid[x][y];
                        x++;y++;
                        d2+=grid[x1][y1];
                        x1--;
                        y1++;
                    }
                    if(checksum!=d1 or checksum!=d2)
                    {
                        flag=1;
                    }
                    if(!flag)
                    {
                        ans=sz;
                        f=1;
                    }
                    if(f)break;   
                }
                if(f)break;
            }
        }
        return ans;
    }
};
