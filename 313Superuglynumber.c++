class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>index(primes.size(),0),ugly(n,INT_MAX);
        ugly[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<primes.size();j++)
            {
                ugly[i]=min(1LL*ugly[i],ugly[index[j]]*(1LL)*primes[j]);
            }
            for(int j=0;j<primes.size();j++)
            {
                if(ugly[i]==ugly[index[j]]*(1LL)*primes[j])
                    index[j]++;
            }
        }
        
        return ugly[n-1];
    }
};
