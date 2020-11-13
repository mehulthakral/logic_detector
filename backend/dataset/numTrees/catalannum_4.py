class Solution:
    def numTrees(self, n):
        dp = { 0:1, 1:1 }
        for x in range(2,n+1):
            dp[x] = 2 * sum([ dp[y]*dp[x-y-1] for y in range(x//2) ] )
            if x%2:
                dp[x] += dp[x//2]**2
        return dp[n]
