class Solution:
    def numTrees(self, n):
        dp = { 0:1, 1:1 }
        for x in range(2,n+1):
            dp[x] = sum([ dp[y]*dp[x-y-1] for y in range(x) ] )
        return dp[n]
