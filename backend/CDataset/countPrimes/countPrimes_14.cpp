class Solution {
public:
    int countPrimes(int n) {
        //Sieve of Eratosthenes
        int primeNumbers = 0;
        int arr[n+1];
        for(int i=0;i<n;++i) arr[i] =1;
        for(int i=2; i<=sqrt(n); ++i){
            if(arr[i]==1)
                for(int j=i*i; j<n; j+=i)
                    arr[j] = 0;
        }
        for(int i=2;i<n;++i){
            if(arr[i]==1)
                ++primeNumbers;
        }
        return primeNumbers;
    }
};