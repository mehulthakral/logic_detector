#fpp-finonaccci of previous to previous
#fp-finonaccci of previous
class Solution:
    fpp=1
    def fib(self, N: int) -> int:
        global fpp
        #base condition
        if N<=0:
            fpp=1
            return 0    #fib(0)= 0
        fp=self.fib(N-1)
        f=fp+fpp
        fpp=fp
        return f
