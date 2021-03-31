class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n+1,1);
        int p = 2;

        while (p * p <= n) {
            if (prime[p])
                for (int i = p*p; i < n+1; i += p)        
                    prime[i] = 0;
            
            ++p;
        }
    
        int res = 0;
        for (int k = 2; k < n; ++k)
            if (prime[k])
                ++res;
    
        return res;
    }
};