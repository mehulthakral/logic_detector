class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0;
        
        vector <int> primes(n+1, 1);
        primes[0] = primes[1] = 0;
        for(int i=2;i*i<=n;i++) {
            if(primes[i] == 1) {
                for(int j=2;i*j<=n;j++) {
                    primes[i*j] = 0;
                }
            }
        }
        
		// just doing this in case there were many test cases (couting number of ones uptill n-1 would have worked too!)
        for(int i=1;i<=n;i++) primes[i] += primes[i-1];
        
        return primes[n-1];
    }
};
