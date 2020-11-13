class Solution:
    def numTrees(self, n: int) -> int:
            dp = {0:1, 1:1, 2:2}
            if n < 3: return dp[n]
            for i in range(3, n+1):
                num = 0
                for j in range(i):
                    num += dp[j]*dp[i-j-1]
                dp[i] = num
            return dp[n]
