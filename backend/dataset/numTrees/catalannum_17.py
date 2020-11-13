class Solution:
    def numTrees(self, n: int) -> int:
        if n ==1:
            return 1
        if n==2:
            return 2
        if n==3:
            return 5
        
        dp = [0]*(n+1)
        
        dp[0]=1
        dp[1] = 1
        dp[2] = 2
        dp[3] = 5
        for i in range(4, n+1):
            for j in range(0, i):
                dp[i] += dp[j] * dp[i-j-1]
        
        return dp[n]
        
