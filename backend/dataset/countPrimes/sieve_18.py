class Solution:
    def countPrimes(self, n: int) -> int:
        p = [1]*n
        res = 0
        for i in range(2,n):
            if p[i]: 
                res+=1
                j = 2
                while j*i<n:
                    p[i*j] = 0
                    j+=1
        return res
