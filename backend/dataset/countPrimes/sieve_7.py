class Solution:
    def countPrimes(self, n: int) -> int:
        prime = [True for i in range(n+1)]
        p = 2
        while p*p<=n:
            if prime[p]:
                for i in range(p*p,n+1,p):
                    prime[i]=False
            p+=1
        res = []
        for p in range(2,n):
            if prime[p]:
                res.append(p)
        return len(res)
