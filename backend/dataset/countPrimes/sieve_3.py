class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 1:
            return 0
        else:
            a = [True]*(n)
            a[0] = a[1] = False
            for i in range(2,n):
                if a[i] == True:
                    for  j in range(i,(n-1)//i + 1):
                        a[i*j]  = False
            return a.count(True)
