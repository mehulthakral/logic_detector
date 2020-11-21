class Solution:
    def countPrimes(self, n: int) -> int:
        if n<3:return 0
        primes = [True]*n
        for i in range(3, n, 2): # skip even
            if primes[i]:
                for j in range(i**2, n, i):
                    primes[j] = False
        primes[0]=primes[1] = False
        for i in range(4,n,2):
            primes[i] = False
        return sum(primes)      
