import math
class Solution:
    def countPrimes(self, n: int) -> int:
        if n == 0 or n == 1:
            return 0
        prime = [True]*(n)
        count = 0
        for i in range(2, int(math.sqrt(n))+1):
            if prime[i]:
                j = i*i
                while j < n:
                    prime[j] = False
                    j += i
        for p in range(2, len(prime)):
            if prime[p]:
                count += 1
        return count
