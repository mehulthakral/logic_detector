class Solution:
    def countPrimes(self, n: int) -> int:
        sieve = [1] * n
        sieve[0:2] = [0,0]
        start = 2
        while start ** 2 < n:
            if sieve[start] == 1:
                for i in range(2 * start, n, start):
                    sieve[i] = 0
            start += 1
        return sum(sieve)