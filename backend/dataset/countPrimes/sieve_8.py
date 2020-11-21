class Solution(object):
    def countPrimes(self, n:int)->int:
        cnt, prime = n - 2, [True]*n
        for i in range(2, int(n**0.5) + 1):
            if prime[i]:
                for j in range(i*i, n, i):
                    if prime[j]: prime[j], cnt = False, cnt - 1
        return max(0, cnt)
