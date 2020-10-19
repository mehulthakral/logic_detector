class Solution:
    def fib(self, N):
        f = {0: 0, 1: 1}
        
        n = 1
        
        while N not in f:
            f[n + 1] = f[n] + f[n - 1]
            
            n += 1
            
        return f[N]
