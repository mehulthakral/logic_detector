from typing import List
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
		
        #1D array
        dp = [float("inf")] * (amount + 1)

        dp[0] = 0
        n = len(coins)

        for i in range(1, n + 1):
            for j in range(amount + 1):
                if coins[i - 1] <= j:
                    dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1)

        return dp[-1] if dp[-1] != float("inf") else -1