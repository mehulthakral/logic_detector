class Solution:
    def coinChange(self, coins: List[int], amt: int) -> int:
        dp = [[0 for i in range(amt+1)]for i in range(len(coins)+1)]
        for j in range(amt+1):
            dp[0][j] = sys.maxsize
        for i in range(1,len(coins)+1):
            for j in range(1,amt+1):
                if coins[i-1] > j:
                    dp[i][j] = dp[i-1][j]
                else:
                    dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j])
        if dp[-1][-1] != sys.maxsize:
            return dp[-1][-1]
        return -1
