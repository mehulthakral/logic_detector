class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float("inf")] * (amount + 1)  # DP Array of size (Amount +1) initialized to infinity
        dp[0] = 0                           # Initializing no. of coins for [amount == 0] to o

        for currCoin in coins:
            for currAmount in range(currCoin, amount + 1):
                dp[currAmount] = min(dp[currAmount], dp[currAmount - currCoin] + 1)

        return dp[-1] if dp[-1] != float("inf") else -1

