class Solution {
public:int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> isPrime(n);
        int total = (n - 2);
        for(int i = 2; i*i < n; i++) {
            if(isPrime[i]) continue;
            for(int j = i; i*j < n; j ++) {    // j = i*i; j < n; j += i
                if(!isPrime[j*i]) {
                    isPrime[j*i] = true; total--;
                }
            }
        }
        // return accumulate(isPrime.cbegin() + 2, isPrime.cend(), 0);
        return total;
    }
};