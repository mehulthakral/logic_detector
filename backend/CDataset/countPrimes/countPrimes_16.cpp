int countPrimes(int n) {
        if(n < 2) return 0;
        vector<bool> isPrime(n, true);
        for(int i = 2; i*i < n; i++) {
            if(!isPrime[i]) continue; 
            for(int j = i*i; j < n; j += i) isPrime[j] = false;
        }
        return accumulate(isPrime.cbegin() + 2, isPrime.cend(), 0);
    }