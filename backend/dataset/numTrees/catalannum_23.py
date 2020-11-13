class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0 for i in range(n+1)]
        dp[0], i = 1, 1
        while i<=n:
            l, r = i-1, 0
            while l >= 0:
                dp[i] += (dp[l]*dp[r])
                l-=1
                r+=1
            i+=1
        return dp[n]
