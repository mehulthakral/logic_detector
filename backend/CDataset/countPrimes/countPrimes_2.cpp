int countPrimes(int n) {
        bool sieve[n+1];
        memset(sieve, true, sizeof(sieve));
        int cnt = 0;
        
         for(int even=4; even< n; even+=2){
             sieve[even] = false;
         }
        
        for(int i=2; i < sqrt(n); i++){
            if(sieve[i] == true){
                for(int j=i*i; j < n; j+=i){
                    sieve[j] = false;
                }
            }
        }
        
        for(int i=2; i < n; i++){
            if(sieve[i]) cnt++;
        }
        return cnt;
        
    }
