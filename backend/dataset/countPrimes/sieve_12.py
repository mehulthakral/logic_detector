import math

class Solution:

    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        # the number x is represented by a[x]
        a = [1] * n
        # ignore 0 and 1
        a[0] = a[1] = 0
        nsqrt = math.ceil(math.sqrt(n))
        for i in range(2, nsqrt + 1):
            if not a[i]:
                continue
            j = int(math.pow(i, 2))
            while j < n:
                a[j] = 0
                j += i
        return sum(a)
