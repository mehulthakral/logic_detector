class Solution {
public:
    int countPrimes(int n) 
    {
        if(n<=1) return 0;
        vector<int> sieve(n, -1);
        sieve[0] = sieve[1] = 1;
        for(int i=2; i<n; i++)
        {
            if(sieve[i]!=-1) continue;
            for(int j=i+i; j<n; j+=i)
            {
                sieve[j] = 1;
            }
        }
        int ans=0;
        for(int i=2; i<n; i++)
        {
            if(sieve[i]==-1) ans++;
        }
        return ans;
    }
};
