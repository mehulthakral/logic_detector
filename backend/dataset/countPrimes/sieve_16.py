class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 3:
            return 0
        primes = [0, 0] + [1] * (n - 2)
        for i in range(2, int((n - 1)**.5) + 1):
            if not primes[i]:
                continue
            for j in range(i**2, n, i):
                primes[j] = 0
        return sum(primes)
