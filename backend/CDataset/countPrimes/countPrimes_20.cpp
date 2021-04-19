class Solution {
public:int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> isPrime(n);
        int total = (n - 2) / 2;
        for(int i = 3; i*i < n; i += 2) {
            if(isPrime[i]) continue;
            for(int j = 3*i; j < n; j += 2*i) {
                if(!isPrime[j]) {
                    isPrime[j] = true; total--;
                }
            }
        }
        // return accumulate(isPrime.cbegin() + 2, isPrime.cend(), 0);
        return total + 1;
    }
};