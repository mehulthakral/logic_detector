class Solution:
    def fib(self, N: int) -> int:      
        def dp(n):
            if memo[n] != None:
                return memo[n]
            memo[n] = 0 if n==0 else 1 if n == 1 else dp(n-1) + dp(n-2)
            return memo[n]  
        
        memo = [None] * (N+1)
        return dp(N)
