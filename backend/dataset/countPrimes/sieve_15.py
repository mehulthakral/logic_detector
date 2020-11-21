from math import sqrt
class Solution:
    def countPrimes(self, n: int) -> int:
        if n==0:
            return 0
        a = [x for x in range(n+1)]
        a[1] = 0
        count = 0
        for i in range(2, int(sqrt(n))+1):
            if a[i] == i:
                for j in range(i+i, n+1, i):
                    a[j] = 0
        for i in range(2, n):
            if a[i] == i:
                count += 1
        return count
