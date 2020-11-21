class Solution:
    def countPrimes(self, n: int) -> int:
        if n<3: return 0
        def count_primes(n):
            
            # Generate [0,1,0,1,0,1,...]. 
            primes=[0,1]*(n//2) # Note: with this generation, 1 is prime and 2 is not prime. But I return sum of 1s, so it does not matter much
            if n%2!=0: primes+=[0] # add another one if n is odd

            for i in range(3,int(n**0.5)+1,2): # I don't need to check for even numbers
                if primes[i]==1: 
                    primes[i*i:n:i]=[0]*int((n-i*i-1)/i + 1)
            return sum(primes)
        s=count_primes(n)
        return s
