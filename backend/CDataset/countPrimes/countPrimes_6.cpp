class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n+1,0);
        int totalPrimes=0;
        //Making all odd numbers as potential prime numbers bcz except 2(special case) no other number is prime
        for(long long int i=3;i<n;i+=2){
            primes[i]=1;
        }
        //sieve of eratosthenes
        for(long long int i=3;i<n;i++){
            //if the current number is assigned 1 it is a prime number bcz we only assign 1 to prime numbers
            if(primes[i]==1){
                //if the number is prime increase the total count of prime numbers
                totalPrimes++;
                //mark all of its multiple as 0(not prime)
                // we have started the loop from i*i bcz before that the multiples of i are already marked 0 by the previous prime numbers as they were divisible by atleast one previos prime number.
                for(long long int j=i*i;j<=n;j+=i){
                    primes[j]=0;
                }
            }
        }
        //special case to handle 2 as 2 is the only even prime number
        if(n>2){
            totalPrimes++;
        }
        return totalPrimes;
    }
};
